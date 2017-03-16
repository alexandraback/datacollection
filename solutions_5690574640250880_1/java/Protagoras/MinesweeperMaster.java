import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 * Created by jouke on 4/12/14.
 */
public class MinesweeperMaster {

    private static final char CURSOR = 'c';
    private static final char EMPTY = '.';
    private static final char MINE = '*';
    private static final char SPACE = ' ';
    private static final char NEWLINE = '\n';

    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(new File("input/C-large.in"));
            BufferedWriter outputWriter = new BufferedWriter(new FileWriter(new File("output/MinesweeperMasterOutput")));

            int testCases = scanner.nextInt();

            for (int i = 0; i < testCases; i++) {
                String output = "Case #" + (i + 1) + ":" + handleTestCase(scanner);
                System.out.println(output);
                outputWriter.write(output + "\n");
            }

            scanner.close();
            outputWriter.close();

        } catch (IOException e) {
            System.out.println("IOException !!!");
        }

    }

    public static String handleTestCase(Scanner scanner) {
        int R = scanner.nextInt();
        int C = scanner.nextInt();
        int M = scanner.nextInt();

        int E = R * C - M;

        //transpose if there are more columns than rows
        boolean transpose = C > R;
        if (transpose) {
            int tmp = C;
            C = R;
            R = tmp;
        }

        int[] A = new int[C];

        boolean possible = false;

        //solve
        if (C == 1 || E == 1) {
            possible = true;
            A[0] = E;
        } else if (E >= 4) {

            if (E >= 2*R + 2) {
                possible = true;
                int cols = E/R;
                int remainder = E%R;

                for (int i = 0; i < cols; i++) {
                    A[i] = R;
                }

                if (remainder > 0) {
                    if (remainder == 1) {
                        A[cols-1] = R-1;
                        A[cols] = 2;
                    } else {
                        A[cols] = remainder;
                    }
                }
            } else {
                if (E == 5 || E == 7) {
                    //not possible
                } else if (C == 2) {
                    if (E % 2 == 0) {
                        possible = true;
                        A[0] = E/2;
                        A[1] = E/2;
                    }
                } else {
                    possible = true;
                    if (E % 2 == 0) {
                        A[0] = E/2;
                        A[1] = E/2;
                    } else {
                        A[0] = E/2-1;
                        A[1] = E/2-1;
                        A[2] = 3;
                    }
                }
            }
        }

        //transpose back if previously transposed
        if (transpose) {
            int tmp = C;
            C = R;
            R = tmp;
        }

        if (possible) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < R; i++) {
                sb.append(NEWLINE);
                for (int j = 0; j < C; j++) {

                    if (i == 0 && j == 0) {
                        sb.append(CURSOR);
                    } else {
                        if (!transpose) {
                            if (i < A[j]) {
                                sb.append(EMPTY);
                            } else {
                                sb.append(MINE);
                            }
                        } else {
                            if (j < A[i]) {
                                sb.append(EMPTY);
                            } else {
                                sb.append(MINE);
                            }
                        }
                    }
                }
            }
            return sb.toString();
        } else {
            return "\nImpossible";
        }
    }
}

