import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Consonants {
    private final char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    protected BufferedReader reader;
    protected BufferedWriter writer;
    protected Scanner in;

    public static BufferedReader openReader(String inputFile) throws IOException {
        FileInputStream fis = new FileInputStream(new File(inputFile).getAbsoluteFile());
        return new BufferedReader(
                new InputStreamReader(fis, "UTF-8")
        );
    }

    public static BufferedWriter openWriter(String outputFile) throws IOException {
        File file = new File(outputFile);

        FileOutputStream fos = new FileOutputStream(file.getAbsoluteFile());
        return new BufferedWriter(
                new OutputStreamWriter(fos, "UTF-8")
        );
    }

    public Consonants(String fileName) throws IOException {
        init(fileName);
    }

    protected void init(String in) throws IOException {
        String out = in.replace(".in", ".out");
        reader = openReader(in);
        this.in = new Scanner(reader);
        writer = openWriter(out);
    }

    public void close() {

        try {
            in.close();
        } catch (Exception e) {
            // ignore
        }

        try {
            if (reader != null) {
                reader.close();
            }
        } catch (IOException e) {
            //ignore
        }
        try {
            if (writer != null) {
                writer.close();
            }
        } catch (IOException e) {
            //ignore
        }
    }


    public void write(int caseNumber) throws IOException {
        write("Case #" + caseNumber + ":");
    }

    public void write(int caseNumber, String val) throws IOException {
        write("Case #" + caseNumber + ": " + val);
    }

    public void write(String val) throws IOException {
        writer.write(val + "\n");
        writer.flush();
    }

    public void execute() {
        try {
            long startProblem = System.currentTimeMillis();
            int T = in.nextInt();
            System.out.println("Tests:" + T);
            for (int i = 1; i <= T; i++) {
                long startCase = System.currentTimeMillis();
                String result = calculate();
                System.out.println("case:" + i + " took: " + (System.currentTimeMillis() - startCase) + ", ms");
                write(i, "" + result);

            }
            System.out.println("Took: " + (System.currentTimeMillis() - startProblem) + ", ms");
        } catch (Exception ex) {
            ex.printStackTrace();
        } finally {
            close();
        }
    }


    private String calculate() {
        String s = in.next();
        int n = in.nextInt();

        List<Interval> intervals = new ArrayList<Interval>();
        List<Integer> ends = new ArrayList<Integer>();

        int l = 0;
        for (int i = 0; i <= s.length(); i++) {
            if (i < s.length() && isCons(s.charAt(i))) {
                l++;
            } else {
                if (l >= n) {
                    intervals.add(new Interval(i - l, i));
                    ends.add(i - 1);
                }
                l = 0;
            }
        }

        long result = 0;

        for (int i = 0; i < s.length(); i++) {
            int index = Collections.binarySearch(ends, i);

            int nextIndex;
            if (index < 0) {
                nextIndex = -index - 1;
            } else {
                nextIndex = index;
            }

            // check if in interval
            if (nextIndex < intervals.size()) {
                Interval interval = intervals.get(nextIndex);
                if (interval.getStart() <= i - n +1) {
                    result += i - n + 2;
                    continue;
                }
            }


            if (index == -1) {
                continue;
            }
            if (index < 0) {
                index = -index - 2;
            }

            if (index >= 0) {
                long count = ends.get(index) - n + 2;
                if (count > 0) {
                    result += count;
                }
            }
        }

        return "" + result;
    }

    /*private String calculate() {
        String s = in.next();
        int n = in.nextInt();


        long count = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                int l = 0;
                for (int k = i; k <= j; k++) {
                    if (isCons(s.charAt(k))) {
                        l++;
                    } else {
                        l = 0;
                    }
                    if (l >= n) {
                        count++;
                        break;
                    }
                }
            }
        }

        return "" + count;
    }
    */

    private boolean isCons(char c) {
        for (char vow : vowels) {
            if (c == vow) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        //Consonants problem = new Consonants("A-small-attempt0.in");
//        Consonants problem = new Consonants("test.in");
        Consonants problem = new Consonants("A-large.in");

        problem.execute();
    }
}


class Interval {
    //inclusive
    private final int start;
    //exclusive
    private final int end;

    Interval(int start, int end) {
        this.start = start;
        this.end = end;
    }

    public int getStart() {
        return start;
    }

    public int getEnd() {
        return end;
    }
}
