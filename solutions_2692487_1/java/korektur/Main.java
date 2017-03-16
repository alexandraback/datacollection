
import java.util.*;
import java.io.*;

public class Main {
    public static long[] x;
    public static int n;
    public static long res(long ans, long a, int i){
        if(i == n) return ans;
        if (a > x[i]) return res(ans, a + x[i], i + 1);
        if(a > 1){
            long tmp = a;
            long j = 0;
            while(tmp <= x[i]){
                tmp += tmp - 1;
                j++;
            }
            return Math.min(res(ans + j, tmp + x[i] , i + 1), ans + n- i);
        }
        return ans + n - i;
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner in = new Scanner(new FileReader("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int t = in.nextInt();
        for(int tt = 0; tt < t; tt++){
            long a = in.nextLong();
            n = in.nextInt();
            x = new long[n];
            for(int i = 0; i < n; i++){
                x[i] = in.nextLong();
            }
            Arrays.sort(x);
            int i = 0;
            long ans = 0;
            ans = res(0, a, 0);
            out.print("Case #" + (tt + 1) + ": " + ans + "\n");
        }
        out.close();
    }
}