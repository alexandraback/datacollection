import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class A {

    private static final char T = 'T';
    private static final char X = 'X';
    private static final char O = 'O';
    private static final char N = 'n';

    public static void main(String[] args) throws FileNotFoundException {
        String name = "A-small-attempt0";
        System.setIn(new FileInputStream(name + ".in"));
        System.setOut(new PrintStream(new FileOutputStream(name + ".out")));
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        for(int i = 0; i < t; i++) {
            char s[][] = new char[4][];
            s[0] = sc.nextLine().toCharArray();
            s[1] = sc.nextLine().toCharArray();
            s[2] = sc.nextLine().toCharArray();
            s[3] = sc.next().toCharArray();
            if(i < t - 1)
                sc.nextLine();
            char r = checkBoard(s);
            String message = "";
            switch (r) {
                case T: message = "Draw";break;
                case X: message = "X won";break;
                case O: message = "O won";break;
                case N: message = "Game has not completed";break;
            }
            System.out.println("Case #"+(i+1)+": " + message);
            sc.nextLine();
        }
    }

    /**
     * O - win O
     * X - win X
     * D - draw
     * N - not finished
     */
    private static char checkBoard(char[][] s) {
        char rs[] = new char[]{T, T, T, T};
        char cs[] = new char[]{T, T, T, T};
        char md = T;
        char od = T;
        for(int i = 0; i < 4;i++) {
            for(int j = 0; j < 4; j++) {
                switch (rs[i]) {
                    case T: rs[i] = s[i][j]; break;
                    case A.X: if(s[i][j] != A.X && s[i][j] != T) rs[i] = N; break;
                    case A.O: if(s[i][j] != A.O && s[i][j] != T) rs[i] = N; break;
                }
                switch (cs[j]) {
                    case T: cs[j] = s[i][j]; break;
                    case A.X: if(s[i][j] != A.X && s[i][j] != T) cs[j] = N; break;
                    case A.O: if(s[i][j] != A.O && s[i][j] != T) cs[j] = N; break;
                }
            }
            switch (md) {
                case T: md = s[i][i]; break;
                case X: if(s[i][i] != X && s[i][i] != T) md = N; break;
                case O: if(s[i][i] != O && s[i][i] != T) md = N; break;
            }
            switch (od) {
                case T: od = s[i][3-i]; break;
                case X: if(s[i][3 - i] != X && s[i][3 - i] != T) od = N; break;
                case O: if(s[i][3 - i] != O && s[i][3 - i] != T) od = N; break;
            }
        }
        if(md == X || md == O) return md;
        if(od == X || od == O) return od;
        for(int i = 0; i < 4; i++){
            if(rs[i] == X || rs[i] == O) return rs[i];
            if(cs[i] == X || cs[i] == O) return cs[i];
        }
        for(char[] r: s) {
            for(char c: r)
                if(c == '.')
                    return N; // NOT finished
        }
        return T;// DRAW
    }
}
