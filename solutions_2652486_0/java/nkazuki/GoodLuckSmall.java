import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @author Kazuki Nishiura
 */
public class GoodLuckSmall {
    // debug flags
    private static final boolean debug = false;
    private static final boolean inputFromStdIn = false;

    public static void main(String[] args) throws Exception {
        OutputWriter writer = new OutputWriter("luck.txt");
        Scanner scanner = createScanner("C-small-1-attempt1.in");

        int numOfTestCase = Integer.parseInt(scanner.nextLine());
        for (int i = 1; i <= numOfTestCase; i++) {
            int r = scanner.nextInt(), n = scanner.nextInt(), m = scanner.nextInt(), k = scanner.nextInt();
            writer.println("Case #1:");
            List<Integer> candidate = new ArrayList<Integer>(n);
            int[] products = new int[k];
            for (int j = 0; j < r; j++) {
                candidate.clear();
                for (int l = 0; l < k; l++)
                    products[l] = scanner.nextInt();

                boolean skip = false;
                if (isContainMultiple(products, 100)) {
                    candidate.add(4);
                    candidate.add(5);
                    candidate.add(5);
                } else if (isContainMultiple(products, 60)) {
                    candidate.add(3);
                    candidate.add(4);
                    candidate.add(5);
                } else if (isContainMultiple(products, 45)) {
                    candidate.add(3);
                    candidate.add(3);
                    candidate.add(5);
                } else if (isContainMultiple(products, 48)) {
                    candidate.add(3);
                    candidate.add(4);
                    candidate.add(4);
                } else if (isContainMultiple(products, 80)){
                    candidate.add(4);
                    candidate.add(4);
                    candidate.add(5);
                } else if (isContainMultiple(products, 36)) {
                    candidate.add(3);
                    candidate.add(3);
                    candidate.add(4);
                } else if (isContainMultiple(products, 75)) {
                    candidate.add(3);
                    candidate.add(3);
                    candidate.add(5);
                } else {

                    if (isContainMultiple(products, 3)) {
                        candidate.add(3);
                        if (isContainMultiple(products, 9)) {
                            candidate.add(3);
                            if (isContainMultiple(products, 27)) {
                                candidate.add(3);
                            }
                        }
                    }

                    if (candidate.size() != 3 && isContainMultiple(products, 5) ) {
                        candidate.add(5);
                        if (isContainMultiple(products, 25)) {
                            candidate.add(5);
                            if (isContainMultiple(products, 125)) {
                                candidate.add(5);
                            }
                        }
                    }

                    if (candidate.size() == 2) {
                        if (isContainMultiple(products, 4)) {
                            candidate.add(4);
                        } else if (isContainMultiple(products, 2)) {
                            candidate.add(2);
                        }
                    }
                    if (candidate.size() == 1) {
                        if (isContainMultiple(products, 8) && candidate.get(0) % 2 == 0) {
                            candidate.add(4);
                            if (isContainMultiple(products, 16)) {
                                candidate.add(4);
                            } else {
                                candidate.add(2);
                            }
                        }
                    }

                    for (int l = candidate.size(); l <= 3; l++) {
                        int rand = (int) Math.floor(Math.random() * (m - 1)) + 2;
                        candidate.add(rand);
                    }
                }
                writer.println(candidate.get(0) + "" + candidate.get(1) + "" + candidate.get(2));

            }
        }
        writer.close();
    }

    static boolean isContainMultiple(int[] arr, int num) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] % num == 0)
                return true;
        }
        return false;
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
