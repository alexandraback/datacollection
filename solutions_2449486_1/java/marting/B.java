import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
    static Scanner cin;
    static PrintWriter cout;
    public static void main(String[] args) throws FileNotFoundException {
        cin = new Scanner(new File("B.in"));
        cout = new PrintWriter(new File("B.out"));
        int T = cin.nextInt();
        for (int I = 0; I < T; I++) {
            String res = solve();
            res = String.format("Case #%d: %s", I+1, res);
            System.out.println(res);
            cout.println(res);
        }
        cout.close();
    }

    private static String solve() {
        int n = cin.nextInt(),
                m = cin.nextInt();
        int A[][] = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                A[i][j] = cin.nextInt();
        int R[][] = new int[n][m];
        for (int i = 0; i < n; i++)
            Arrays.fill(R[i], 100);
        for (int i = 0; i < n; i++) {
            int mx = 0;
            for (int j = 0; j < m; j++)
                mx = Math.max(mx, A[i][j]);
            for (int j = 0; j < m; j++)
                R[i][j] = Math.min(R[i][j], mx);
        }
        for (int j = 0; j < m; j++) {
            int mx = 0;
            for (int i = 0; i < n; i++)
                mx = Math.max(mx, A[i][j]);
            for (int i = 0; i < n; i++) 
                R[i][j] = Math.min(R[i][j], mx);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (R[i][j] != A[i][j])
                    return "NO";
        return "YES";
    }
}
