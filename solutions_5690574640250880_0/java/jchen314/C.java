import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for (int caseNum = 1; caseNum <= cases; caseNum++) {
            int R = sc.nextInt();
            int C = sc.nextInt();
            int M = sc.nextInt();
            int numEmpty = R * C - M;

            boolean possible = false;
            int[][] board = new int[R][C];
            board[0][0] = 2;
            if (numEmpty == 1) {
                possible = true;
            } else if (R == 1) {
                possible = true;
                for (int i = 1; i < numEmpty; i++) {
                    board[0][i]++;
                }
            } else if (C == 1) {
                possible = true;
                for (int i = 1; i < numEmpty; i++) {
                    board[i][0]++;
                }
            } else if (R == 2) {
                possible = ((numEmpty % 2 == 0) && numEmpty >= 4);
                if (possible) {
                    for (int i = 0; i * 2 < numEmpty; i++) {
                        board[0][i]++;
                        board[1][i]++;
                    }
                }
            } else if (C == 2) {
                possible = ((numEmpty % 2 == 0) && numEmpty >= 4);
                if (possible) {
                    for (int i = 0; i * 2 < numEmpty; i++) {
                        board[i][0]++;
                        board[i][1]++;
                    }
                }
            } else {

                if (numEmpty % 2 == 0) {
                    possible = (numEmpty >= 4);
                } else {
                    possible = (numEmpty >= 9);
                }
                if (possible) {
                    int s, r = 2, c = 2;
                    for (s = 4; s <= R + C; s++) {
                        r = Math.min(R, s / 2);
                        c = s - r;
                        if (c > C) {
                            c = C;
                            r = s - c;
                        }
                        if (r * c > numEmpty) {
                            s--;
                            break;
                        }
                    }
                    if (s > R + C) {
                        s = R + C;
                    }

                    int r2 = Math.min(R, s / 2);
                    int c2 = s - r2;
                    if (c2 > C) {
                        c2 = C;
                        r2 = s - c2;
                    }
                    int remaining = numEmpty - r2 * c2;
                    int covered = 0;
                    for (int i = 0; i < r2; i++) {
                        for (int j = 0; j < c2; j++) {
                            board[i][j]++;
                            covered++;
                        }
                    }
                    if (remaining == 1) {
                        board[r2 - 1][c2 - 1] = 0;
                        covered--;
                    }
                    if (r2 < r) {
                        for (int j = 0; j < numEmpty - covered; j++) {
                            board[r2][j]++;
                        }
                    } else {
                        for (int i = 0; i < numEmpty - covered; i++) {
                            board[i][c2]++;
                        }
                    }
                }
            }

            System.out.println("Case #" + caseNum + ":");
            if (possible) {
                for (int i = 0; i < R; i++) {
                    for (int j = 0; j < C; j++) {
                        System.out.print(toChar(board[i][j]));
                    }
                    System.out.println();
                }
            } else {
                System.out.println("Impossible");
            }
        }
    }

    private static char toChar(int i) {
        if (i == 0) {
            return '*';
        } else if (i == 1) {
            return '.';
        } else {
            return 'c';
        }
    }
}
