package google2012;


import java.io.*;
import java.util.*;

public class PasswordProblem {

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

    public PasswordProblem(String fileName) throws IOException {
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
                String result = calculate(in.nextInt(), in.nextInt());
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


    private String calculate(int A, int B) {
        double p[] = new double[A];

        double p1 = 1;
        int num1  = 0;
        double expected1;

        double p2 = 1;
        int num2  = 0;
        double expected2;

        double bestExpected;

        double p3 = 1;
        int num3  = 0;

        for (int i = 0; i < A; i++) {
            p[i] = in.nextDouble();
            p1 = p1*p[i];
        }

        // strat 1
        num1 = B - A + 1;
        expected1 = p1 * num1 + (1-p1)*(num1 + B + 1);
        bestExpected = expected1;

        //strat 2
        expected2 = B + 2;
        if(expected2 < bestExpected) {
            bestExpected = expected2;
        }

        //strat 3
        double currp = 1;
        double expected3;

        for (int i = 0; i < A; i++) {
            currp = currp*p[i];
            
            int total =  A - (i + 1)  + B - (i + 1) + 1;

            expected3 = currp*(total) + (1-currp)*(total + B+1);
            if(expected3 < bestExpected) {
                bestExpected = expected3;
            }
        }


        return String.format("%1$20.10f ", bestExpected);
    }


    public static void main(String[] args) throws Exception {
//        String fileName = "test.in";
//        String fileName = "A-small-attempt0.in";
        String fileName = "A-large.in";

//        String fileName = "B-large.in";
//        String fileName = "C-large.in";
        PasswordProblem problem = new PasswordProblem(fileName);
        problem.execute();
    }
}
