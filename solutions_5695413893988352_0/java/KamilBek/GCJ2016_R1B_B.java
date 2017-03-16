import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

/**
 * Created by Kamil Khadiev
 */
public class GCJ2016_R1B_B {
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
    static String s1,s2;
    public static StringBuilder ans;
    static HashMap<Character, Integer> d;

    private static void init(BufferedReader in) throws IOException {
        String s = in.readLine().trim();
        StringTokenizer st = new StringTokenizer(s);
        s1 = st.nextToken();
        s2 = st.nextToken();
    }

    private static void solve() {
        while (s1.length()<s2.length()){
            s1 = "0" + s1;
        }
        while (s1.length()>s2.length()){
            s2 = "0" + s2;
        }
        n = s1.length();
        x1 = new long[n];
        x2 = new long[n];
        for (int i = 0; i < n; i++){
            x1[i] = (s1.charAt(i)=='?')? -1 : Integer.valueOf("" + s1.charAt(i));
            x2[i] = (s2.charAt(i)=='?')? -1 : Integer.valueOf("" + s2.charAt(i));
        }
        int k = -1;
        minans = Long.MAX_VALUE;
        x10 = new long[n];
        x20 = new long[n];
        go(0,-1);

        ans = new StringBuilder();
        for (int i = 0; i < n; i++){
            if (x10[i]>9) throw new RuntimeException("1 " + i);
            ans.append(x10[i]);
        }
        ans.append(" ");
        for (int i = 0; i < n; i++){
            if (x20[i]>9) throw new RuntimeException("2 " + i);
            ans.append(x20[i]);
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
        out.print("Case #"+cn+": "+ans.toString());
    }
}
