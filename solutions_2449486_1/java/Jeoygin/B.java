package gcj2013.qualification;

import java.util.Scanner;
import java.util.Arrays;

public class B {
    int n, m;
    int[][] lawn;

    class Square implements Comparable<Square> {
        int h;
        int i;
        int j;

        public int compareTo(Square s) {
            return h - s.h;
        }
    }

    int maxInRow(int i) {
        int max = 0;
        for (int k = 0; k < m; k++) {
            if (lawn[i][k] > max) {
                max = lawn[i][k];
            }
        }
        return max;
    }

    int maxInColumn(int j) {
        int max = 0;
        for (int k = 0; k < n; k++) {
            if (lawn[k][j] > max) {
                max = lawn[k][j];
            }
        }
        return max;
    }
    
    void doOneCase(Scanner scan) {
        n = scan.nextInt();
        m = scan.nextInt();
        lawn = new int[n][m];

        Square[] squares = new Square[n * m];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                lawn[i][j] = scan.nextInt();
                squares[i * m + j] = new Square();
                squares[i * m + j].h = lawn[i][j];
                squares[i * m + j].i = i;
                squares[i * m + j].j = j;
            }
        }

        Arrays.sort(squares);

        for (int i = 0; i < squares.length; i++) {
            int h = squares[i].h;
            int max = Math.min(maxInRow(squares[i].i), maxInColumn(squares[i].j));
            if (max > h) {
                System.out.println("NO");
                return;
            }

        }
        System.out.println("YES");
        
    }
    
    public void solve() {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.print("Case #" + i + ": ");
            doOneCase(scan);
        }
    }
    
    public static final void main(final String[] args) {
        new B().solve();
    }

}
