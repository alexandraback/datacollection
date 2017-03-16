import java.io.IOException;
import java.util.Iterator;
import java.util.LinkedList;

/**
 * User: jlee
 * Date: 11/1/12
 * Time: 11:30 AM
 */
public class R1Bb2013 extends CodeJam {


    double inf = Double.MAX_VALUE;
    LinkedList<Long> list = new LinkedList<Long>();

    public R1Bb2013(String fileName) throws IOException {
        super(fileName);

    }

    protected void init() {

    }



    protected void solve() {
        try {
            String[] row = br.readLine().split("\\s+");

            int N = Integer.parseInt(row[0]);
            int M = Integer.parseInt(row[1]);

            int[][] matrix = readMatrix(N, M);

            boolean feasible = true;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {

                    /*
                    // go west
                    int k = j - 1;
                    while(k >= 0) {
                        if (matrix[i][k] <= matrix[i][j]) {
                            k--;
                            continue;
                        } else {
                            break;
                        }
                    }

                    if (k < 0) {
                        continue;
                    }


                    // go north

                    k = i - 1;
                    while(k >= 0) {
                        if (matrix[k][j] <= matrix[i][j]) {
                            k--;
                            continue;
                        } else {
                            break;
                        }
                    }

                    if (k < 0) {
                        continue;
                    }

                    // go east
                    k = j + 1;
                    while(k < M) {
                        if (matrix[i][k] <= matrix[i][j]) {
                            k++;
                            continue;
                        } else {
                            break;
                        }
                    }

                    if (k == M) {
                        continue;
                    }
                    // go south
                    k = i + 1;
                    while(k < N) {
                        if (matrix[k][j] <= matrix[i][j]) {
                            k++;
                            continue;
                        } else {
                            break;
                        }
                    }

                    if (k == N) {
                        continue;
                    }
*/

                    int k = 0;
                    while(k < M) {
                        if (matrix[i][k] <= matrix[i][j]) {
                            k++;
                            continue;
                        } else {
                            break;
                        }
                    }

                    if (k == M) {
                        continue;
                    }

                    k = 0;
                    while(k < N) {
                        if (matrix[k][j] <= matrix[i][j]) {
                            k++;
                            continue;
                        } else {
                            break;
                        }
                    }

                    if (k == N) {
                        continue;
                    }
                    printResult("NO");
                    return;

                }
            }
            printResult("YES");

        } catch (Exception e) {
            e.printStackTrace();
        }


    }



    public static void main(String[] args) {

        String fileName = "A-";

        if (args[0].compareTo("small") == 0) {
            fileName += "small";
        } else if (args[0].compareTo("large") == 0) {
            fileName += "large";
        } else if (args[0].compareTo("sample") == 0) {
            fileName += "sample";
        } else {
            System.out.println("small or large or sample");
            return;
        }

        if (args[1].compareTo("1") == 0) {
            fileName += "-practice.in.txt";
        } else {
            fileName += ".in.txt";
        }

        try {
            R1Bb2013 codeJam = new R1Bb2013(fileName);
            codeJam.run();
        } catch (IOException e) {
            System.err.print(e);
        }
    }
}
