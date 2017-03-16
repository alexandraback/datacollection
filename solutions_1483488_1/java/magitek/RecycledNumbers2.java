import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class RecycledNumbers2 {

    public static int rotate(int x) {
        if (x < 10)
            return x;
        int m = 1;
        int x_ = x / 10;
        while (x_ > 0) {
            m *= 10;
            x_ /= 10;
        }
        while (x % 10 == 0)
            x /= 10;
        x_ = (x % 10) * m;
        x_ += x / 10;
        return x_;       
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
                int x = j;
                while ((x = rotate(x)) != j) {
                    if (x > j && x <= B)
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
        //String file = "C-stress-test";
        //String file = "C-small-attempt0";
        String file = "C-large";
        
        solve(file);
    }
}
