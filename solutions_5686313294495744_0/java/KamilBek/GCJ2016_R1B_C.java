import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

/**
 * Created by Kamil Khadiev
 */
public class GCJ2016_R1B_C {
    public static void main(String[] args) throws IOException {
//        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//        PrintWriter out = new PrintWriter(System.out);
        BufferedReader in = new BufferedReader(new FileReader("c:/inputs/input.txt"));
        PrintWriter out = new PrintWriter("c:/inputs/output.txt");
        t = Integer.parseInt(in.readLine().trim());

        for (int i = 0; i < t; i++) {
            System.out.println(i + 1);
            init(in);
            solve();

            print(out, i+1);
        }

            in.close();
            out.close();

    }
    public static int n,p,t;
    public static long[] x1,x2, x10,x20;
    static String[] s1,s2;
    public static long ans;
    static HashMap<Character, Integer> d;

    private static void init(BufferedReader in) throws IOException {
        n = Integer.parseInt(in.readLine().trim());
        s1 = new String[n];
        s2 = new String[n];
        for (int i = 0; i < n; i++) {
            String s = in.readLine().trim();
            StringTokenizer st = new StringTokenizer(s);
            s1[i] = st.nextToken();
            s2[i] = st.nextToken();
        }
    }

    private static void solve() {
        ans = 0;
//        for (int i = 0; i < n; i++){
//            boolean b1 = false, b2 = false;
//            for (int j = 0; j < n; j++)
//            if (i!=j){
//                if (s1[i].equals(s1[j])) b1 = true;
//                if (s2[i].equals(s2[j])) b2 = true;
//            }
//            if (b1 && b2) ans++;
//        }
        for (int i = 0; i < 1<<n; i++){
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                if ((i & (1<<j)) >0){
                    boolean b1 = false, b2 = false;
                    for (int q = 0; q< n; q++)
                        if ((i & (1<<q))==0){
                            if (s1[q].equals(s1[j])) b1 = true;
                            if (s2[q].equals(s2[j])) b2 = true;
                        }
                    if (b1 && b2) sum++;
                }
            }
            ans = Math.max(ans,sum);
        }
    }
    private static long minans;
    static void go (int i, int k){
        if (i == n){
            long x = Math.abs(toSan(x1)-toSan(x2));

            if (x<minans){
                minans = x;
                x10 = Arrays.copyOf(x1,n);
                x20 = Arrays.copyOf(x2,n);
            }
            return;
        }
        if (k==-1){
            if (x1[i] == -1 && x2[i] ==-1){
                x1[i] = 0;
                x2[i] = 0;
                go(i+1,k);
                x1[i] = 0;
                x2[i] = 1;
                go(i+1,1);
                x1[i] = 1;
                x2[i] = 0;
                go(i+1,2);
            }
            else
            if (x1[i] == -1){
                if (x2[i]!=0){
                    x1[i] = x2[i]-1;
                    go(i+1,1);
                }
                x1[i] = x2[i];
                go(i+1,-1);
                if (x2[i]!=9){
                    x1[i] = x2[i]+1;
                    go(i+1,2);
                }
                x1[i] = -1;
            }
            else
            if (x2[i] == -1){
                if (x1[i]!=0){
                    x2[i] = x1[i]-1;
                    go(i+1,2);
                }
                x2[i] = x1[i];
                go(i+1,-1);
                if (x1[i]!=9){
                    x2[i] = x1[i]+1;
                    go(i+1,1);
                }
                x2[i] = -1;
            }
            else {
                k = (x1[i] == x2[i] ? -1 : (x1[i]>x2[i] ? 2 : 1));
                go(i + 1, k);
            }
        }
        else{
            long xx1 = x1[i];
            long xx2 = x2[i];
            if (k == 1){
                if (x1[i] == -1){
                    x1[i] = 9;
                }

                if (x2[i] == -1){
                    x2[i] = 0;
                }
            }
            else{
                if (x2[i] == -1){
                    x2[i] = 9;
                }

                if (x1[i] == -1){
                    x1[i] = 0;
                }
            }
            go(i+1,k);
            x1[i] = xx1;
            x2[i] = xx2;
        }

    }

    private static long toSan(long[] x1) {
        long r = 0;
        for (int i = 0; i < x1.length; i++){
            r = r*10+x1[i];
        }
        return r;
    }


    private static void print(PrintWriter out, int cn) throws IOException {
        if (cn != 1) out.println();
        out.print("Case #"+cn+": "+ans);
    }
}
