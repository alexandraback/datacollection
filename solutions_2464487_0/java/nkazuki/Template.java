import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Kazuki Nishiura
 */
public class Template {

    // debug flags
    private static final boolean debug = false;
    private static final boolean inputFromStdIn = false;

    public static void main(String[] args) throws Exception {
        OutputWriter writer = new OutputWriter("rotate2.txt");
        Scanner scanner = createScanner("A-small-attempt1.in");

        int numOfTestCase = Integer.parseInt(scanner.nextLine());
        for (int i = 1; i <= numOfTestCase; i++) {
            long r = scanner.nextLong();
            long t = scanner.nextLong();
            int count = 0;
            while (t >= 0) {
                t -= (2*r + 1);
                r += 2;
                count++;
            }

            writer.println("Case #" + i + ": " + (count - 1));
        }
        writer.close();
    }

    // IO Utils
    static private Scanner createScanner(String fileName) throws Exception {
        if (inputFromStdIn) {
            return new Scanner(System.in);
        } else {
            File inFile = new File(fileName);
            return new Scanner(inFile);
        }
    }

    private static class OutputWriter {
        private PrintWriter writer;

        public OutputWriter(String fileNameSuffix) {
            if (!debug) {
                try {
                    writer = new PrintWriter(new BufferedWriter(
                            (new FileWriter(new File("output_" + fileNameSuffix)))));
                } catch (Exception e) {
                    System.err.println("File writer creation error.");
                }
            }
        }

        public void print(Object o) {
            if (debug) {
                System.out.print(o);
            } else {
                writer.print(o);
            }
        }

        public void println() {
            if (debug) {
                System.out.println();
            } else {
                writer.println();
            }
        }

        public void println(Object o) {
            if (debug) {
                System.out.println(o);
            } else {
                writer.println(o);
            }
        }

        public void close() {
            if (writer != null) {
                writer.close();
            }
        }
    }
}
