


import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;

public class Fractiles {

    public static void main(String[] args) throws Exception {
        solve(System.in, System.out);
    }
    
    public static void solve(final InputStream in, final PrintStream out) throws Exception {
        final BufferedReader br = new BufferedReader(new InputStreamReader(in));
        final int t = Integer.parseInt(br.readLine());
        for (int i = 1; i <= t; i++) {
            out.print("Case #" + i + ":");
            String line = br.readLine();
            String[] parts = line.split(" ");
            int k = Integer.valueOf(parts[0]);
            int c = Integer.valueOf(parts[1]);
            int s = Integer.valueOf(parts[2]);

            if (k == 1) {
                out.println(" 1");
                continue;
            }
            
            if (c == 1) {
                if (s < k) {
                    out.println(" IMPOSSIBLE");
                    continue;
                }
                
                for (int j = 1; j <=k; j++) {
                    out.print(' ');
                    out.print(j);
                }
                out.println();
                continue;
            }
            
            int min = (k / 2);
            if ((k % 2) != 0) {
                min++;
            }
       
            if (s < min) {
                out.println(" IMPOSSIBLE");
                continue;
            }
            
            for (int j = 1; j <= min; j++) {
                BigInteger J = BigInteger.valueOf(j);
                BigInteger index = J.pow(c);
                index = index.add(J);
                out.print(' ');
                out.print(index);
            }
            out.println();
        }
    }
}
