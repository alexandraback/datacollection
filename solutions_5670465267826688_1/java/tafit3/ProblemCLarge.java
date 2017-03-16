import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ProblemCLarge {
    BufferedReader rd;
    private static final int[][] MUL = new int[][] {
            { 1,2,3,4 },
            { 2,-1,4,-3 },
            { 3,-4,-1,2 },
            { 4,3,-2,-1 }
    };

    private ProblemCLarge() throws IOException {
        rd = new BufferedReader(new InputStreamReader(System.in));
        compute();
    }

    private void compute() throws IOException {
        int n = pint();
        for(int i=0;i<n;i++) {
            out("Case #" + (i + 1) + ": " + solve());
        }
    }

    private String solve() throws IOException {
        long x = longarr()[1];
        String s = rd.readLine();
        char[] sc = s.toCharArray();
        int[] map = new int[200];
        int n = s.length();
        map['1'] = 1;
        map['i'] = 2;
        map['j'] = 3;
        map['k'] = 4;
        int[] p = new int[n+1];
        p[0] = 1;
        for(int i=0;i<n;i++) {
            p[i+1] = mul(p[i],map[sc[i]]);
        }
        boolean ok = false;
        if(pow(p[n],x) == -1) {
            outer: for(int f=0;f<4;f++) {
                int af = pow(p[n],f);
                for(int i=0;i<=n-1;i++) {
                    if(mul(af,p[i])==2) {
                        for(int j=i+1;j<=n;j++) {
                            if(mul(af,p[j]) == 4) {
                                if(f+1 <= x) {
                                    ok = true;
                                    break outer;
                                }
                            }
                        }
                    }
                }
            }
            if(!ok) {
                outer2: for(int f=0;f<4;f++) {
                    int af = pow(p[n],f);
                    for(int i=0;i<=n-1;i++) {
                        if(mul(af,p[i])==2) {
                            for(int g=0;g<4;g++) {
                                int ag = pow(p[n], f+g+1);
                                for(int j=0;j<=n;j++) {
                                    if(mul(ag,p[j]) == 4) {
                                        if(f+g+2 <= x) {
                                            ok = true;
                                            break outer2;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return ok?"YES":"NO";
    }

    private static int mul(int a, int b) {
        int sa = Math.abs(a)-1;
        int sb = Math.abs(b)-1;
        int c = 1;
        if((a < 0 && b > 0) || (a > 0 && b < 0)) {
            c = -1;
        }
        return c*MUL[sa][sb];
    }

    private static int pow(int a, long b) {
        if(b == 0) {
            return 1;
        } else if(b == 1) {
            return a;
        }
        int res = pow(a,b/2);
        res = mul(res, res);
        if(b%2==1) {
            res = mul(res, a);
        }
        return res;
    }

    private int pint() throws IOException {
        return pint(rd.readLine());
    }

    private int pint(String s) {
        return Integer.parseInt(s);
    }

    private long[] longarr() throws IOException {
        return longarr(rd.readLine());
    }

    private long[] longarr(String s) {
        String[] q = split(s);
        int n = q.length;
        long[] a = new long[n];
        for(int i=0;i<n;i++) {
            a[i] = Long.parseLong(q[i]);
        }
        return a;
    }

    private String[] split(String s) {
        int n = s.length();
        int sp = 0;
        for(int i=0;i<n;i++) {
            if(s.charAt(i)==' ') {
                sp++;
            }
        }
        String[] res = new String[sp+1];
        int last = 0;
        int x = 0;
        for(int i=0;i<n;i++) {
            char c = s.charAt(i);
            if(c == ' ') {
                res[x++] = s.substring(last,i);
                last = i+1;
            }
        }
        res[x] = s.substring(last,n);
        return res;
    }

    private static void out(Object x) {
        System.out.println(x);
    }

    public static void main(String[] args) throws IOException {
        new ProblemCLarge();
    }
}
