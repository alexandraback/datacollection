import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class B{
    public static void main(String[] args) throws Exception{
        new B().run();
    }

    public static boolean nextPermutation(int[] a) {
        for (int i = a.length - 1; i > 0; --i) {
            if (a[i - 1] < a[i]) {
                int swapIndex = find(a[i - 1], a, i, a.length - 1);
                int temp = a[swapIndex];
                a[swapIndex] = a[i - 1];
                a[i - 1] = temp;
                Arrays.sort(a, i, a.length);
                return true;
            }
        }
        return false;
    }
 
    private static int find(int dest, int[] a, int s, int e) {
        if (s == e) {
            return s;
        }
        int m = (s + e + 1) / 2;
        return a[m] <= dest ? find(dest, a, s, m - 1) : find(dest, a, m, e);
    }

    private static final int MOD = 1000000007;
    int n;
    String[] ts;

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available

        int T = sc.nextInt();
        for(int o = 1; o <= T; o++){
            System.out.printf("Case #%d: ", o);
            n = sc.nextInt();
            ts = new String[n];
            int len = 0;
            for(int i = 0; i < n; i++){
                ts[i] = sc.next();
                len += ts[i].length();
            }
            int[] a = new int[n];
            for(int i = 0; i < n; i++)
                a[i] = i;
            int ans = 0;
            do{
                StringBuilder sb = new StringBuilder("");
                for(int i = 0; i < n; i++)
                    sb.append(ts[a[i]]);
                //System.out.println("s=" + s);
                char[] s = sb.toString().toCharArray();
                boolean[] used = new boolean[26];
                boolean ok = true;
                for(int i = 0; i < len; i++){
                    char c = s[i];
                    int index = c-'a';
                    if(used[index]){
                        ok = false;
                        break;
                    }
                    used[index] = true;
                    i++;
                    while(i < len && s[i] == c)
                        i++;
                    i--;
                }
                if(ok)
                    ans++;
            }while(nextPermutation(a));
            System.out.println(ans);
        }
    }
}
