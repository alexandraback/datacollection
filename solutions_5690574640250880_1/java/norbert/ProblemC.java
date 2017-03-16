import java.util.Scanner;

public class ProblemC {

    public static void main(String[] args) throws Exception {

        int t, c, r, m, f;

        Scanner in = new Scanner(System.in);
        
        t = in.nextInt();

        for(int t_ = 0; t_ < t; t_++) {

            r = in.nextInt();
            c = in.nextInt();
            m = in.nextInt();
            f = r*c - m;

            char g[][] = new char[r+2][c+2];

            for(int i = 1; i <= r+1; i++)
                for(int j = 1; j <= c+1; j++)
                    g[i][j] = '*';

            g[1][1] = 'c';

            System.out.println("Case #" + (t_+1) + ":");

            if(r < 2 || c < 2) {
                print1(g, f, c, r);
            } else if(f == 1) {
                print(g, r, c);
            } else if(f == 2 || f == 3 || f == 5 || f == 7) {
                System.out.println("Impossible");
            } else if(f == 4) {
                print6(g, r, c);
            } else if(f > 4 && f % 2 == 0) {
                print7(g, r, c, f);
            } else if(f >= 9 && r >= 3 && c >= 3) {
                print8(g, r, c, f);
            } else {
                System.out.println("Impossible");
            }

        }
    }

    public static void print1(char g[][], int f, int c, int r) {
        f--;
        if(r == 1) {
            for(int j = 2; j <= c && f > 0; j++, f--) g[1][j] = '.';
        } else {
            for(int i = 2; i <= r && f > 0; i++, f--) g[i][1] = '.';
        }
        print(g, r, c);
    }

    public static void print6(char g[][], int r, int c) {
        g[1][2] = g[2][1] = g[2][2] = '.';
        print(g, r, c);
    }

    public static void print7(char g[][], int r, int c, int f) {
        f -= 4;
        g[1][2] = g[2][1] = g[2][2] = '.';
        for(int j = 3; j <= c && f > 0; j++, f -= 2) { g[1][j] = g[2][j] = '.'; }

        for(int i = 3; i <= r && f > 0; i++) {
            for(int j = 1; j+1 <= c && f > 0; j += 2, f -= 2) {
                g[i][j] = g[i][j+1] = '.';
            }
        }

        for(int i = 3; i <= r && f > 0; i++, f--) g[i][c] = '.';

        print(g, r, c);
    }

    public static void print8(char g[][], int r, int c, int f) {
        f -= 9;
        g[1][2] = g[2][1] = g[2][2] = '.';
        g[1][3] = g[2][3] = g[3][1] = g[3][2] = g[3][3] = '.';

        for(int j = 4; j <= c && f > 0; j++, f -= 2) { g[1][j] = g[2][j] = '.'; }
        for(int j = 4; j+1 <= c && f > 0; j += 2, f -= 2) { g[3][j] = g[3][j+1] = '.'; }
        for (int i = 4; i <= r && f > 0; i++) {
            for (int j = 1; j + 1 <= c-1 && f > 0; j += 2, f -= 2) {
                g[i][j] = g[i][j + 1] = '.';
            }
        }

        if(c % 2 == 0) {
            if(r >= 4) {
                for (int i = 4; i <= r && f > 0; i++, f--) g[i][c-1] = '.';
            }

            for(int i = 3; i <= r && f > 0; i++, f--) g[i][c] = '.';
        } else {
            for(int i = 4; i <= r && f > 0; i++, f--) g[i][c] = '.';
        }

        print(g, r, c);
    }

    public static void print(char g[][], int r, int c) {
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) { System.out.print(g[i][j]); }
            System.out.println();
        }
    }
}
