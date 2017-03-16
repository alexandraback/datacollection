import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
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
            pw.println("Case #" + c + ": " + solve(A, 0));
            
        }
        pw.flush();
        pw.close();
    }
    
    public static long solve(long a, int i) {
        if (i == m.length)
            return 0;
        if (m[i] < a)
            return solve(a + m[i], i + 1);
        else if (a == 1)
            return 1 + solve(a, i + 1);
        
        else {
            long[] q = h(a, m[i]);
            return Math.min(q[0] + solve(q[1], i), 1 + solve(a, i + 1));
        }
    }
    
    public static long[] h(long a, long x) {
        int i = 0;
        while (a <= x) {
            //System.out.println(a);
            a = a*2 - 1;
            i++;
        }
        long[] res = {i, a};
        return res;
    }
    
    
}
