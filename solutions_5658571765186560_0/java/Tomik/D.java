/*
 * Copyright (c) 2015. Made just for fun.
 */

package qualification;

import java.util.Scanner;

/**
 * @author Tomáš Kypta
 */
public class D {

    private static final int[][][] TROMINO = new int[][][]{
        {
            {1,1,1}
        },
        {
            {1,1},
            {1,0}
        }
    };
    private static final int[][][] TETROMINO = new int[][][]{
        {
            {1,1,1,1}
        },
        {
            {1,1,1},
            {1,0,0}
        },
        {
            {1,1,1},
            {0,1,0}
        },
        {
            {1,1,0},
            {0,1,1}
        },
        {
            {1,1},
            {1,1}
        }
    };
    private static final int[][][] PENTOMINO = new int[][][]{
        {
            {1,1,1,1,1}
        },
        {
            {1,1,1,1},
            {1,0,0,0}
        },
        {
            {1,1,1,1},
            {0,1,0,0}
        },
        {
            {1,1,1,0},
            {0,0,1,1}
        },
        {
            {1,1,1},
            {0,1,1}
        },
        {
            {1,1,1},
            {1,0,1}
        },
        {
            {1,0,0},
            {1,1,1},
            {0,1,0}
        },
        {
            {1,0,0},
            {1,1,1},
            {1,0,0}
        },
        {
            {1,0,0},
            {1,0,0},
            {1,1,1}
        },
        {
            {1,0,0},
            {1,1,0},
            {0,1,1}
        },
        {
            {1,1,0},
            {0,1,0},
            {0,1,1}
        },
        {
            {0,1,0},
            {1,1,1},
            {0,1,0}
        }
    };
    private static final int[][][] HEXOMINO = new int[][][]{
        {
            {1,1,1,1,1,1}
        },
        {
            {1,1,1,1,1},
            {1,0,0,0,0}
        },
        {
            {1,1,1,1,1},
            {0,1,0,0,0}
        },
        {
            {1,1,1,1,1},
            {0,0,1,0,0}
        },
        {
            {1,1,1,1,0},
            {0,0,0,1,1}
        },
        {
            {1,1,1,1},
            {0,0,1,1}
        },
        {
            {1,1,1,1},
            {0,1,0,1}
        },
        {
            {1,1,1,1},
            {1,0,0,1}
        },
        {
            {1,1,1,1},
            {0,1,1,0}
        },
        {
            {1,1,1,1},
            {0,0,0,1},
            {0,0,0,1}
        },
        {
            {1,1,1,1},
            {0,0,1,0},
            {0,0,1,0}
        },
        {
            {0,0,0,1},
            {1,1,1,1},
            {0,0,0,1}
        },
        {
            {0,0,1,0},
            {1,1,1,1},
            {0,0,0,1}
        },
        {
            {0,1,0,0},
            {1,1,1,1},
            {0,0,0,1}
        },
        {
            {1,0,0,0},
            {1,1,1,1},
            {0,0,0,1}
        },
        {
            {0,1,0,0},
            {1,1,1,1},
            {0,0,1,0}
        },
        {
            {0,0,1,0},
            {1,1,1,1},
            {0,0,1,0}
        },
        {
            {1,1,1,0},
            {0,0,1,1},
            {0,0,1,0}
        },
        {
            {1,1,1,0},
            {1,0,1,1}
        },
        {
            {1,1,1,0,0},
            {0,0,1,1,1}
        },
        {
            {1,1,1,0},
            {0,1,1,1}
        },
        {
            {1,1,1},
            {1,1,1}
        },
        {
            {0,0,1,0},
            {1,1,1,0},
            {0,0,1,1}
        },
        {
            {0,0,1},
            {1,1,1},
            {0,1,1}
        },
        {
            {0,1,0,0},
            {1,1,1,0},
            {0,0,1,1}
        },
        {
            {1,1,1,0},
            {0,0,1,0},
            {0,0,1,1}
        },
        {
            {1,1,1,0},
            {0,0,1,1},
            {0,0,0,1}
        },
        {
            {1,1,1},
            {0,0,1},
            {0,1,1}
        },
        {
            {1,1,1},
            {0,1,0},
            {0,1,1}
        },
        {
            {0,1,1},
            {1,1,0},
            {0,1,1}
        },
        {
            {1,1,0,0},
            {0,1,1,1},
            {0,0,0,1}
        },
        {
            {1,1,1},
            {0,1,1},
            {0,0,1}
        },
        {
            {1,1,0},
            {1,1,1},
            {0,1,0}
        },
        {
            {1,1,0},
            {1,1,0},
            {0,1,1}
        },
        {
            {1,1,0,0},
            {0,1,1,0},
            {0,0,1,1}
        }
    };

    public static boolean test(int X, int R, int C) {
        if (X == 1) {
            return false;
        }
        if (X == 2) {
            return (R*C)%2 == 1;
        }
        if (X == R*C) {
            return X > 2;
        }
        if (X >= 7) {
            return true;
        }
        if (R*C % X != 0) {
            return true;
        }

        int[][] A = new int[R][C];
        switch (X) {
            case 3:
                return !testCover(A, TROMINO);
            case 4:
                return !testCover(A, TETROMINO);
            case 5:
                return !testCover(A, PENTOMINO);
            case 6:
                return !testCover(A, HEXOMINO);
        }
        return true;
    }

    static boolean testCover(int[][] A, int[][][] M) {
        o:
        for (int i = 0; i < M.length; i++) {
            int[][] CM = M[i];
            boolean mok = false;
            for (int j = 0; j < 4; j++) {
                if (tryCover(A, CM, M)) {
                    mok = true;
                    continue o;
                }
                CM = rotate(CM);
            }
            CM = M[i];
            CM = mirror(CM);
            for (int j = 0; j < 4; j++) {
                if (tryCover(A, CM, M)) {
                    mok = true;
                    continue o;
                }
                CM = rotate(CM);
            }
            if (!mok) {
                return false;
            }
        }
        return true;
    }

    static boolean tryCover(int[][] A, int[][] CM, int[][][] M) {
        if (CM.length > A.length || CM[0].length > A[0].length) {
            return false;
        }
        for (int i = 0; i <= A.length - CM.length; i++) {
            for (int j = 0; j <= A[0].length - CM[0].length; j++) {
                addMi(A, CM, i, j);
                int r = checkA(A);
                if (r < 0) {
                    removeMi(A, CM, i, j);
                    continue;
                } else if (r == 1) {
                    removeMi(A, CM, i, j);
                    return true;
                } else {
                    boolean res = false;
                    res = tryCoverRecurse(A, M);
                    removeMi(A, CM, i, j);
                    if (res) {
                        return res;
                    }
                }
            }
        }
        return false;
    }

    private static boolean tryCoverRecurse(int[][] A, int[][][] M) {
        for (int ii = 0; ii < M.length; ii++) {
            int[][] CM2 = M[ii];
            for (int jj = 0; jj < 4; jj++) {
                if (tryCover(A, CM2, M)) {
                    return true;
                }
                CM2 = rotate(CM2);
            }
            CM2 = M[ii];
            CM2 = mirror(CM2);
            for (int jj = 0; jj < 4; jj++) {
                if (tryCover(A, CM2, M)) {
                    return true;
                }
                CM2 = rotate(CM2);
            }
        }
        return false;
    }

    private static void addM(int[][] A, int[][] CM) {
        for (int i = 0; i <= A.length - CM.length; i++) {
            for (int j = 0; j <= A[0].length - CM[0].length; j++) {
                addMi(A, CM, i, j);
            }
        }
    }

    private static void addMi(int[][] A, int[][] CM, int i, int j) {
        for (int k = 0; k < CM.length; k++) {
            for (int l = 0; l < CM[0].length; l++) {
                A[i+k][j+l] += CM[k][l];
            }
        }
    }

    private static void removeM(int[][] A, int[][] CM) {
        for (int i = 0; i <= A.length - CM.length; i++) {
            for (int j = 0; j <= A[0].length - CM[0].length; j++) {
                removeMi(A, CM, i, j);
            }
        }
    }

    private static void removeMi(int[][] A, int[][] CM, int i, int j) {
        for (int k = 0; k < CM.length; k++) {
            for (int l = 0; l < CM[0].length; l++) {
                A[i+k][j+l] -= CM[k][l];
            }
        }
    }

    private static int checkA(int[][] A) {
        int all1 = 1;
        for (int i = 0; i < A.length; i++) {
            for (int j = 0; j < A[0].length; j++) {
                if (A[i][j] > 1) {
                    return -1;
                }
                if (A[i][j] == 0) {
                    all1 = 0;
                }
            }
        }
        return all1;
    }

    static int[][] rotate(int[][] M) {
        int[][] R = new int[M[0].length][M.length];
        for (int i = 0; i < M.length; i++) {
            for (int j = 0; j < M[0].length; j++) {
                R[j][i] = M[i][j];
            }
        }
        return R;
    }
    static int[][] mirror(int[][] M) {
        int[][] R = new int[M.length][M[0].length];
        for (int i = 0; i < M.length; i++) {
            for (int j = 0; j < M[0].length; j++) {
                R[M.length-i-1][j] = M[i][j];
            }
        }
        return R;
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            int X = sc.nextInt();
            int R = sc.nextInt();
            int C = sc.nextInt();

            boolean richard = test(X, R, C);
            System.out.println("Case #" + i + ": " + (richard ? "RICHARD" : "GABRIEL"));
        }
    }
}
