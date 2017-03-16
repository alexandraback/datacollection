import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class Pogo {
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

    public Pogo(String fileName) throws IOException {
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
        int X = in.nextInt();
        int Y = in.nextInt();

        StringBuilder b = new StringBuilder();

        if (X < 0) {
            X = -X;
            for (int i = 0; i < X; i++) {
                b.append("EW");
            }

        } else if (X > 0) {
            for (int i = 0; i < X; i++) {
                b.append("WE");
            }
        }

        if (Y < 0) {
            Y = -Y;
            for (int i = 0; i < Y; i++) {
                b.append("NS");

            }

        } else if (Y > 0) {
            for (int i = 0; i < Y; i++) {
                b.append("SN");
            }
        }
        return b.toString();
    }


    public static void main(String[] args) throws Exception {
        Pogo problem = new Pogo("B-small-attempt1.in");
        problem.execute();
    }
}

