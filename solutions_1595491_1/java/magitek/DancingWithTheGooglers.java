import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class DancingWithTheGooglers {

    public static int max(int N, int S, int p, int[] T) {
        int max = 0;
        for (int i = 0; i < T.length; i++) {
            int a = T[i] / 3;
            if (T[i] == 0) {
                if (0 >= p)
                    max++;
            }
            else if (T[i] == 1) {
                if (1 >= p)
                    max++;
            }
            else if (T[i] == 2) {
                if (1 >= p)
                    max++;
                else if (2 >= p && S > 0) {
                    max++;
                    S--;
                }
            }
            else if (T[i] % 3 == 0) {
                if (a >= p)
                    max++;
                else if (a + 1 >= p && S > 0) {
                    max++;
                    S--;
                }
            }
            else if (T[i] % 3 == 1) {
                if (a + 1 >= p)
                    max++;                
            }
            else { // T[i] % 3 == 2
                if (a + 1 >= p)
                    max++;
                else if (a + 2 >= p && S > 0) {
                    max++;
                    S--;
                }
            }
        }
        return max;
    }

    public static void solve(String file) throws Exception {
        
        BufferedReader f = new BufferedReader(new FileReader(file + ".in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(file + ".out")));

        int T = Integer.parseInt(f.readLine());
        for (int i = 0; i < T; i++) {
            String[] s = f.readLine().split(" ");
            int N = Integer.parseInt(s[0]);
            int S = Integer.parseInt(s[1]);
            int p = Integer.parseInt(s[2]);
            int[] totals = new int[N];
            for (int j = 0; j < N; j++)
                totals[j] = Integer.parseInt(s[j + 3]);
            int max = max(N, S, p, totals);
            System.out.println("Case #" + (i+1) +": " + max);
            out.println("Case #" + (i+1) +": " + max);
        }
        out.close();
    }
    
    public static void main(String[] args) throws Exception {
        
        //String file = "B-test";
        //String file = "B-small-attempt1";
        String file = "B-large";
        
        solve(file);
    }
}
