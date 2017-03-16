import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class RecycledNumbers {

    public static int rotate(int x) {
        if (x < 10)
            return x;
        String s = String.valueOf(x);
        s = s.substring(1) + s.charAt(0);
        return Integer.parseInt(s);       
    }

    public static String rotate(String s) {
        if (s.length() < 2)
            return s;
        return s.substring(1) + s.charAt(0);
    }

    public static void solve(String file) throws Exception {
        
        BufferedReader f = new BufferedReader(new FileReader(file + ".in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(file + ".out")));

        int T = Integer.parseInt(f.readLine());
        for (int i = 0; i < T; i++) {
            String[] s = f.readLine().split(" ");
            int A = Integer.parseInt(s[0]);
            int B = Integer.parseInt(s[1]);

            int n = 0;
            for (int j = A; j <= B; j++) {
                String x = String.valueOf(j);
                String y = x;
                while (!(y = rotate(y)).equals(x)) {
                    int r = Integer.parseInt(y);
                    if (r > j && r <= B)
                        n++;
                }
            }
            System.out.println("Case #" + (i+1) +": " + n);
            out.println("Case #" + (i+1) +": " + n);
        }
        out.close();
    }
    
    public static void main(String[] args) throws Exception {
        
        //String file = "C-test";
        String file = "C-small-attempt0";
        
        solve(file);
    }
}
