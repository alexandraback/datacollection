package gcj2013.qualification;
import java.util.Scanner;

public class A{
    static int doit(int v) {
        if (v == 4 || v == 67) {
            System.out.println("X won");
            return 1;
        }
        if (v == 32 || v == 88) {
            System.out.println("O won");
            return 2;
        }
        return 0;
    }

    static int calc(char[][] squares, int i, int j, int di, int dj) {
        int res = 0;
        for (int k = 0; k < 4; k++) {
            res += squares[i+di*k][j+dj*k];
        }
        return res;
    }
    
    static void solve(Scanner scan) {
        char[][] squares = new char[4][];
        boolean completed = true;
        
        for (int i = 0; i < 4; i++) {
            String str = scan.next();
            squares[i] = str.toCharArray();
            for (int j = 0; j < 4; j++) {
                if (squares[i][j] == 'X') {
                    squares[i][j] = 1;
                } else if (squares[i][j] == 'O') {
                    squares[i][j] = 8;
                } else if (squares[i][j] == 'T') {
                    squares[i][j] = 64;
                } else {
                    squares[i][j] = 0;
                    completed = false;
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            if (doit(calc(squares, i, 0, 0, 1)) != 0) {
                return;
            }
            if (doit(calc(squares, 0, i, 1, 0)) != 0) {
                return;
            }
        }
        if (doit(calc(squares, 0, 0, 1, 1)) != 0) {
            return;
        }
        if (doit(calc(squares, 0, 3, 1, -1)) != 0) {
            return;
        }

        if (completed) {
            System.out.println("Draw");
        } else {
            System.out.println("Game has not completed");
            
        }
    }
    public static final void main(final String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.print("Case #" + i + ": ");
            solve(scan);
        }
    }
}
