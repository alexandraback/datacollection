package google2012;


import java.io.*;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class KingdomRush {

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

    public KingdomRush(String fileName) throws IOException {
        init(fileName);
    }

    protected void init(String fileName) throws IOException {
        String in = fileName;
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
                String result = calculate(in.nextInt());
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


    private String calculate(int n) {
        int a[] = new int[n];
        int b[] = new int[n];

        boolean visited1[] = new boolean[n];
        boolean visited2[] = new boolean[n];

        PriorityQueue<Level> level1 = new PriorityQueue<>(n, new Comparator<Level>() {
            @Override
            public int compare(Level o1, Level o2) {
                return o1.a - o2.a;
            }
        });
        PriorityQueue<Level> level2 = new PriorityQueue<>(n, new Comparator<Level>() {
            @Override
            public int compare(Level o1, Level o2) {
                return o1.b - o2.b;
            }
        });

        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            b[i] = in.nextInt();
            Level level = new Level(i, a[i], b[i]);

            level1.add(level);
            level2.add(level);
        }


        int currentStars = 0;
        int count = 0;

        count = explore(a, b, level2, currentStars, visited1, visited2, count);


        System.out.println("Current stars: " + currentStars + ", n: " + n);
        if (count == -1) {
            return "Too Bad";
        } else {
            return "" + count;
        }
    }

    public int explore(int a[], int b[], PriorityQueue<Level> level2, int currentStars, boolean visited1[], boolean visited2[], int count) {
        while (!level2.isEmpty()) {
            Level level = level2.peek();
            if (level.b <= currentStars) {
                level2.poll();
                if (visited1[level.i]) {
                    currentStars += 1;
                } else {
                    currentStars += 2;
                }
                visited1[level.i] = true;
                visited2[level.i] = true;
                count++;
                continue;
            } else {
                break;
            }
        }

        int minCount = Integer.MIN_VALUE;
        int index = -1;
        for (int i = 0; i < visited1.length; i++) {
            if (!visited1[i] && a[i] < currentStars) {
                currentStars += 1;
                visited1[i] = true;

                int tempCount = explore(a, b, level2, currentStars, visited1, visited2, count);
                if (tempCount < minCount) {
                    minCount = tempCount;
                }
                visited1[i] = false;
                index = i;

            }
        }
        if (minCount < 0) {
            return -1;
        } else {
            return minCount + 1;
        }

    }


    public static void main(String[] args) throws Exception {
//        String fileName = "test.in";
        String fileName = "B-small-attempt2.in";
//        String fileName = "A-large.in";

//        String fileName = "B-large.in";
//        String fileName = "C-large.in";
        KingdomRush problem = new KingdomRush(fileName);
        problem.execute();
    }
}


class Level {
    int i;
    int a;
    int b;

    Level(int i, int a, int b) {
        this.i = i;
        this.a = a;
        this.b = b;
    }
}