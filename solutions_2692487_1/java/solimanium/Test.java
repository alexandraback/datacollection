import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Arrays;

public class Test {
    
    static long[] m;
    
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine());
        int c = 0;
        while (T-- > 0) {
            c++;
            String[] str = br.readLine().split(" ");
            long A = Integer.parseInt(str[0]);
            int N = Integer.parseInt(str[1]);
            m = new long[N];
            
            str = br.readLine().split(" ");
            for (int i = 0; i < N; i++) 
                m[i] = Integer.parseInt(str[i]);
            Arrays.sort(m);
            pw.println("Case #" + c + ": " + solve(new BigDecimal(A), 0));
            
        }
        pw.flush();
        pw.close();
    }
    
    public static long solve(BigDecimal a, int i) {
        if (i == m.length)
            return 0;
        if (a.compareTo(new BigDecimal(m[i])) > 0)
            return solve(a.add(new BigDecimal(m[i])), i + 1);
        else if (a.equals(BigDecimal.ONE))
            return 1 + solve(a, i + 1);
        
        else {
            BigDecimal[] q = h(a, m[i]);
            return Math.min(q[0].intValue() + solve(q[1], i), 1 + solve(a, i + 1));
        }
    }
    
    public static BigDecimal[] h(BigDecimal a, long x) {
        int i = 0;
        while (a.compareTo(new BigDecimal(x)) <= 0) {
            //System.out.println(a);
            a = a.add(a).subtract(BigDecimal.ONE);
            i++;
        }
        BigDecimal[] res = {new BigDecimal(i), a};
        return res;
    }
    
    
}
