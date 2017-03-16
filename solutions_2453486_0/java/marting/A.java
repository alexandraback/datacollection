import java.util.Scanner;

public class A {
    static Scanner cin = new Scanner(System.in);
    public static void main(String[] args) {
        int T = cin.nextInt();
        for (int I = 0; I < T; I++) {
            System.out.printf("Case #%d: %s\n", I + 1, solve1());
        }
    }
    static char winner(char w, char c) {
        if (c=='.') return '.';
        if (w=='T') return c;
        if (c=='T') return w;
        if (c==w) return c;
        return '.';
    }
    static String solve1() {
        char r = solve();
        switch (r) {
            case 'G': return "Game has not completed";
            case 'D': return "Draw";
            default: return r + " won";
        }
    }
    static char solve() {
        char[][] M = new char[4][];
        for (int i = 0; i < 4; i++)
            M[i] = cin.next().toCharArray();
        boolean f[] = new boolean[2];
        for (int i = 0; i < 4; i++) {
            char w = M[i][0];
            for (int j = 1; j < 4; j++)
                w = winner(w, M[i][j]);
            if (w!='.')
                return w;
            w = M[0][i];
            for (int j = 1; j < 4; j++)
                w = winner(w, M[j][i]);
            if (w!='.')
                return w;
        }
        char w = M[0][0];
        for (int i = 1; i < 4; i++)
            w = winner(w, M[i][i]);
        if (w!='.')
            return w;
        w = M[3][0];
        for (int i = 1; i < 4; i++)
            w = winner(w, M[3-i][i]);
        if (w!='.')
            return w;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (M[i][j]=='.')
                    return 'G';
        return 'D';
    }
}
