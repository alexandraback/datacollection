import java.io.*;

public class CodeJam2014Q3 {
    public static void main(String[] args) {
        try {
            //BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("C-small.in")));
            //PrintWriter pw = new PrintWriter(new FileOutputStream("C-small.out"));
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("C-large.in")));
            PrintWriter pw = new PrintWriter(new FileOutputStream("C-large.out"));
            String line = br.readLine();
            int T = Integer.parseInt(line);
            for (int i = 0; i < T; i++) {
                System.out.println((i + 1) + " / " + T + "...");

                line = br.readLine();
                String[] values = line.split(" ");
                int R = Integer.parseInt(values[0]);
                int C = Integer.parseInt(values[1]);
                int M = Integer.parseInt(values[2]);

                String result = solve(R, C, M);

                pw.print("Case #" + (i + 1) + ":\n" + result);
            }
            pw.close();
            System.out.println("DONE");
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    private static String solve(int r, int c, int m) {
        char matrix[][] = new char[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                matrix[i][j] = '.';
            }
        }
        if (r * c == m + 1) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    matrix[i][j] = '*';
                }
            }
            matrix[r - 1][c - 1] = 'c';
            return buildResult(matrix);
        }
        int total = 0;
        int full = m / c;
        if (full > r - 2) {
            full = Math.max(r - 2, 0);
        }

        for (int i = 0; i < full; i++) {
            for (int j = 0; j < c; j++) {
                matrix[i][j] = '*';
                total++;
            }
        }
        //System.out.println(buildResult(matrix));

        for (int i = full; i < r - 2; i++) {
            for (int j = 0; j < c - 2; j++) {
                if (total < m) {
                    matrix[i][j] = '*';
                    total++;
                } else {
                    matrix[i][j] = '.';
                }
            }
        }

        if (total == m) {
            matrix[r - 1][c - 1] = 'c';
            return buildResult(matrix);
        }


        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                matrix[i][j] = '.';
            }
        }


        total = 0;
        full = m / r;
        if (full > c - 2) {
            full = Math.max(c - 2, 0);
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < full; j++) {
                matrix[i][j] = '*';
                total++;
            }
        }

        for (int i = 0; i < r - 2; i++) {
            for (int j = full; j < c - 2; j++) {
                if (total < m) {
                    matrix[i][j] = '*';
                    total++;
                } else {
                    matrix[i][j] = '.';
                }
            }
        }

        if (total == m) {
            matrix[r - 1][c - 1] = 'c';
            System.out.println("HERE");
            return buildResult(matrix);
        }

        for (int R = 0; R < r - 1; R++) {
            for (int C = 0; C < c - 1; C++) {
                int extraRows = Math.max(0, r - R - 2);
                int extraCols = Math.max(0, c - C - 2);
                if (R * c + C * r - R * C <= m && R * c + C * r - R * C + extraRows * extraCols >= m) {
                    total = 0;
                    for (int i = 0; i < r; i++) {
                        for (int j = 0; j < c; j++) {
                            if (i < R || j < C) {
                                matrix[i][j] = '*';
                                total++;
                            } else {
                                matrix[i][j] = '.';
                            }
                        }
                    }
                    for (int i = R; i < r - 2; i++) {
                        for (int j = C; j < c - 2; j++) {
                            if (total < m) {
                                total++;
                                matrix[i][j] = '*';
                            }
                        }
                    }

                    matrix[r - 1][c - 1] = 'c';
                    System.out.println("EQUATION - R = " + R + " C = " + C + " Extra: " + (m - (R * c + C * r - R * C)));
                    return buildResult(matrix);
                }
            }
        }



        return "Impossible\n";
    }

    private static String buildResult(char[][] matrix) {
        StringBuffer result = new StringBuffer();
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                result.append(matrix[i][j]);
            }
            result.append('\n');
        }
        return result.toString();
    }

}
