import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

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

    private boolean isCons(char c) {
        for (char vow : vowels) {
            if (c == vow) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        Consonants problem = new Consonants("A-small-attempt0.in");
        problem.execute();
    }
}


class Interval {
    private final int start;
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
