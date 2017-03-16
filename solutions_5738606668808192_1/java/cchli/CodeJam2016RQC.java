import java.io.*;

/**
 * @auther chao
 * @date 16/4/9
 */
public class CodeJam2016RQC {

    static int count;
    static int odd;
    static int even;
    static int len;
    static int[] a;
    static int[] mod=new int[]{0,0,3,2,5,2,7,2,3,2,11};
    static FileWriter out;
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("/Users/chao/Downloads/C-large.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        out = new FileWriter("/Users/chao/Desktop/C-large.txt");
        String[] s = in.readLine().split(" ");
        int T = Integer.parseInt(s[0]);

        a = new int[100];
        for (int cases = 1; cases <= T; cases++) {
            out.write("Case #"+cases+":\n");
            s = in.readLine().split(" ");
            len = Integer.parseInt(s[0]) - 2;
            count = Integer.parseInt(s[1]);
            odd = 0;
            even = 0;
            dfs(0);
        }
        out.flush();
        out.close();
        in.close();
    }
    private static void dfs(int p) {
        if (count == 0){
            return;
        }
        if (p == len) {
            if (odd == even) {
                count--;
                printAns();
            }
            return;
        }
        a[p]=0;
        dfs(p + 1);
        a[p]=1;
        if (p%2==0) {
            even++;
            dfs(p + 1);
            even--;
        } else {
            odd++;
            dfs(p+1);
            odd--;
        }
    }
    private static void printAns() {
        //verifyAns();
        StringBuffer sb =  new StringBuffer();
        sb.append("1");
        for (int i = 0; i < len; i++) {
            sb.append(a[i]);
        }
        sb.append("1");
        for (int i = 2; i <= 10; i++) {
            sb.append(" "+mod[i]);
        }
        sb.append("\n");
        try {
            out.write(sb.toString());
        } catch (IOException e) {
        }
    }
    /*
    private static void verifyAns() {
        for (int base = 2; base <= 10; base++) {
            long x = 1;
            for (int i = 0; i < len; i++) {
                x = (x*base+a[i])%mod[base];
            }
            x = x*base+1;
            if (x%mod[base] != 0) {
                System.out.println("error");
            }
        }
    }*/
}
    /*
    private static int cnt = 0;
    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("/Users/chao/Downloads/B-large.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        //FileWriter out = new FileWriter("/Users/chao/Desktop/B-large.txt");
        String s = "1";
        dfs(s,2,16);
    }
    private static void dfs(String s, int p, int n) {
        if (cnt == 50) return;
        if (p == n) {
            gao(s+"1");
            return;
        }
        dfs(s+"0", p+1, n);
        dfs(s+"1", p+1, n);
    }
    private static void gao(String s) {
        for (int base = 2; base <= 10; base++) {
            long x = 0;
            for (int i = 0; i < s.length(); i++) {
                x = (x*base)+(s.charAt(i)-'0');
            }
            if (isPrime(x)) return;
        }
        System.out.println(s);
    }
    private static boolean isPrime(long x) {
        if (x <= 1) return false;
        for (long i = 2; i < x; i++) {
            if (x%i==0) return false;
        }
        return true;
    }
}*/
