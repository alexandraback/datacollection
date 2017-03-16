import java.io.IOException;
import java.util.PriorityQueue;

/**
 * User: jlee
 * Date: 11/1/12
 * Time: 11:30 AM
 */
public class R1A2013 extends CodeJam {

    char[][] matrix;
    int H, N, M;
    PriorityQueue<triple> pq;
    double inf = Double.MAX_VALUE;

    public R1A2013(String fileName) throws IOException {
        super(fileName);

    }

    class triple implements Comparable<triple>{
        int i;
        int j;
        double time;

        public triple(int i, int j, double time) {
            this.i = i;
            this.j = j;
            this.time = time;
        }

        public int compareTo(triple t) {
            if  (this.time < t.time) {
                return -1;
            } else if (this.time > t.time) {
                return 1;
            } else {
                return 0;
            }
        }

        public boolean equals(Object o) {
            if (o != null && o instanceof triple) {
                triple t = (triple)o;
                return this.i == t.i && this.j == t.j;
            } else {
                return super.equals(o);
            }
        }

        public String toString() {
            return "(" + i + ", " + j + ", " + time + ")";
        }
    }

    protected void solve() {
        try {

            matrix = readCharMatrix(4, 4);
            int count = 0;
            boolean complete = true;
            char first = 0;
            //horizontal
            for (int i = 0; i < 4; i++) {
                first = 0;
                count = 0;

                for (int j = 0; j < 4; j++) {
                    if (matrix[i][j] == '.') {
                        complete = false;
                        break;
                    }

                    if (matrix[i][j] != 'T') {
                        if (first == 0) {
                            first = matrix[i][j];
                        }

                        switch (matrix[i][j]) {
                            case 'O':
                                if (first == 'O') {
                                    count++;
                                }
                                break;
                            case 'X':
                                if (first == 'X') {
                                    count++;
                                }
                                break;
                            case 'T':
                                count++;
                                break;
                        }
                    } else {
                        count++;
                    }
                }

                if (count == 4) {
                    System.out.println("Case #" + currentCase + ": " + first + " won");
                    return;
                }
            }

            //vertical
            for (int j = 0; j < 4; j++) {
                first = 0;
                count = 0;

                for (int i = 0; i < 4; i++) {
                    if (matrix[i][j] == '.') {
                        complete = false;
                        break;
                    }

                    if (matrix[i][j] != 'T') {
                        if (first == 0) {
                            first = matrix[i][j];
                        }

                        switch (matrix[i][j]) {
                            case 'O':
                                if (first == 'O') {
                                    count++;
                                }
                                break;
                            case 'X':
                                if (first == 'X') {
                                    count++;
                                }
                                break;
                            case 'T':
                                count++;
                                break;
                        }
                    } else {
                        count++;
                    }
                }

                if (count == 4) {
                    System.out.println("Case #" + currentCase + ": " + first + " won");
                    return;
                }
            }

            //diagonal
            count = 0;
            first = 0;
            for (int j = 0; j < 4; j++) {


                if (matrix[j][j] == '.') {
                    complete = false;
                    break;
                }

                if (matrix[j][j] != 'T') {
                    if (first == 0) {
                        first = matrix[j][j];
                    }

                    switch (matrix[j][j]) {
                        case 'O':
                            if (first == 'O') {
                                count++;
                            }
                            break;
                        case 'X':
                            if (first == 'X') {
                                count++;
                            }
                            break;
                    }
                } else {
                    count++;
                }
            }

            if (count == 4) {
                System.out.println("Case #" + currentCase + ": " + first + " won");
                return;
            }
            //diagonal2
            count = 0;
            first = 0;
            for (int j = 0; j < 4; j++) {

                if (matrix[j][3-j] == '.') {
                    complete = false;
                    break;
                }

                if (matrix[j][3-j] != 'T') {
                    if (first == 0) {
                        first = matrix[j][3-j];
                    }

                    switch (matrix[j][3-j]) {
                        case 'O':
                            if (first == 'O') {
                                count++;
                            }
                            break;
                        case 'X':
                            if (first == 'X') {
                                count++;
                            }
                            break;
                    }
                } else {
                    count++;
                }

            }

            if (count == 4) {
                System.out.println("Case #" + currentCase + ": " + first + " won");
                return;
            }

            if (complete) {
                System.out.println("Case #" + currentCase + ": Draw");
            } else {
                System.out.println("Case #" + currentCase + ": Game has not completed");
            }

        } catch (IOException e) {
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
            R1A2013 codeJam = new R1A2013(fileName);
            codeJam.run();
        } catch (IOException e) {
            System.err.print(e);
        }
    }
}
