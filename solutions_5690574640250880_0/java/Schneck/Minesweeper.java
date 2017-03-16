import java.io.*;
import java.util.*;

public class Minesweeper {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        int R = scan.nextInt();
        int C = scan.nextInt();
        int M = scan.nextInt();
        if (R == 1) showOneRow(C, M);
        else if (C == 1) showOneColumn(R, M);
        else if (R == 2) showTwoRows(C, M);
        else if (C == 2) showTwoColumns(R, M);
        else {
            int dot = C*R - M;
            if (dot == 1) showOneDot(R, C);
            else if (dot == 4) showFourDots(R, C);
            else if (dot == 6) showSixDots(R, C);
            else if (dot < 8) {
                System.out.println("Impossible");
                return;
            } else showGeneral(R, C, dot);
        }
    }
    
    void showGeneral(int R, int C, int dot) {
        if (dot <= C*2 + 1) {
            if (dot % 2 == 0) {
                showTwoRowsOfDots(R, C, dot);
            } else {
                showTwoRowsOfDotsThenThree(R, C, dot);
            }
        } else {
            if (dot % C == 1) {
                showLotsThenThree(R, C, dot);
            } else {
                showLots(R, C, dot);
            }
        }
    }

    void showLotsThenThree(int R, int C, int dot) {
        for (int i = 0; i < dot/C - 1; i++) {
            for(int j = 0; j < C; j++) {
                if (i ==0 && j == 0) System.out.print("c");
                else System.out.print(".");
            }
            System.out.println();
        }
        for (int i = 0; i < C - 1; i++) {
            System.out.print(".");
        }
        System.out.println("*");
        for (int i = 0; i < 2; i++) {
            System.out.print(".");
        }
        for (int i = 0; i < C - 2; i++) {
            System.out.print("*");
        }
        System.out.println();
        for (int i = 0; i < R - 1 - dot/C; i++) {
            for(int j = 0; j < C; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }

    void showLots(int R, int C, int dot) {
        for (int i = 0; i < dot/C; i++) {
            for(int j = 0; j < C; j++) {
                if (i ==0 && j == 0) System.out.print("c");
                else System.out.print(".");
            }
            System.out.println();
        }
        if (dot % C > 0) {
            for (int i = 0; i < dot % C; i++) {
                System.out.print(".");
            }
            for (int i = 0; i < C - dot % C; i++) {
                System.out.print("*");
            }
            System.out.println();
        }
        for (int i = 0; i < R - (dot % C > 0 ? 1 : 0) - dot/C; i++) {
            for(int j = 0; j < C; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
    
    void showTwoRowsOfDots(int R, int C, int dot) {
        for (int i = 0; i < dot/2; i++) {
            if (i == 0) System.out.print("c");
            else System.out.print(".");
        }
        for (int i = 0; i < C - dot/2; i++) {
            System.out.print("*");
        }
        System.out.println();
        for (int i = 0; i < dot/2; i++) {
            System.out.print(".");
        }
        for (int i = 0; i < C - dot/2; i++) {
            System.out.print("*");
        }
        System.out.println();
        for (int i = 0; i < R - 2; i++) {
            for (int j = 0; j < C; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }

    void showTwoRowsOfDotsThenThree(int R, int C, int dot) {
        for (int i = 0; i < (dot-3)/2; i++) {
            if (i == 0) System.out.print("c");
            else System.out.print(".");
        }
        for (int i = 0; i < C - (dot-3)/2; i++) {
            System.out.print("*");
        }
        System.out.println();
        for (int i = 0; i < (dot-3)/2; i++) {
            System.out.print(".");
        }
        for (int i = 0; i < C - (dot-3)/2; i++) {
            System.out.print("*");
        }
        System.out.println();
        for (int i = 0; i < 3; i++) {
            System.out.print(".");
        }
        for (int i = 0; i < C - 3; i++) {
            System.out.print("*");
        }
        System.out.println();
        for (int i = 0; i < R - 3; i++) {
            for (int j = 0; j < C; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }

    void showOneDot(int R, int C) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (i == 0 && j == 0) System.out.print("c");
                else System.out.print("*");
            }
            System.out.println();
        }
    }

    void showFourDots(int R, int C) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (i == 0 && j == 0) System.out.print("c");
                else if (i < 2 && j < 2) System.out.print(".");
                else System.out.print("*");
            }
            System.out.println();
        }
    }

    void showSixDots(int R, int C) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (i == 0 && j == 0) System.out.print("c");
                else if (i < 2 && j < 3) System.out.print(".");
                else System.out.print("*");
            }
            System.out.println();
        }
    }

    void showOneRow(int C, int M) {
        System.out.print("c");
        for (int i = 0; i < (C - M - 1); i++) {
            System.out.print(".");
        }
        for (int i = 0; i < M; i++) {
            System.out.print("*");
        }
        System.out.println();
    }

    void showOneColumn(int R, int M) {
        System.out.println("c");
        for (int i = 0; i < (R - M - 1); i++) {
            System.out.println(".");
        }
        for (int i = 0; i < M; i++) {
            System.out.println("*");
        }
    }

    void showTwoRows(int C, int M) {
        if (M + 1 < C * 2 && (M % 2 == 1 || M + 2 == 2 * C)) {
            System.out.println("Impossible");
            return;
        }
        System.out.print("c");
        for (int i = 0; i < (C - M/2 - 1); i++) {
            System.out.print(".");
        }
        for (int i = 0; i < M/2 && i + 1 < C; i++) {
            System.out.print("*");
        }
        System.out.println();
        if (M + 1 == C * 2) {
            System.out.print("*");
        } else {
            for (int i = 0; i < (C - M/2); i++) {
                System.out.print(".");
            }
        }
        for (int i = 0; i < M/2; i++) {
            System.out.print("*");
        }
        System.out.println();
    }

    void showTwoColumns(int R, int M) {
        if (M + 1 < R * 2 && (M % 2 == 1 || M + 2 == 2 * R)) {
            System.out.println("Impossible");
            return;
        }
        if (M + 1 == R* 2) {
            System.out.println("c*");
        } else System.out.println("c.");
        for (int i = 0; i < (R - M/2 - 1); i++) {
            System.out.println("..");
        }
        for (int i = 0; i < M/2; i++) {
            System.out.println("**");
        }
    }


    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ":\n");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new Minesweeper().run();
    }

}
