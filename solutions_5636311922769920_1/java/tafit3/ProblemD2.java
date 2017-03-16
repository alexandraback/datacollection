import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class ProblemD2 {
    BufferedReader rd;

    ProblemD2() throws IOException {
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
        long[] kcs = longarr();
        long k = kcs[0];
        long c = kcs[1];
        long s = kcs[2];
        return large(k,c,s);
    }

    private String large(long k, long c, long s) {
        long ix = 0;
        int level = 1;
        int d = 0;
        List<Long> res = new ArrayList<>();
        while(true) {
            if (level == c) {
                res.add(ix);
                if(d >= k-1) {
                    break;
                }
                d++;
                ix = d;
                level = 1;
            } else {
                ix *= k;
                if(d < k-1) {
                    d++;
                }
                ix += d;
                level++;
            }
        }
        if(res.size() <= s) {
            StringBuilder buf = new StringBuilder();
            for(long x: res) {
                if(buf.length() > 0) {
                    buf.append(' ');
                }
                buf.append(x+1);
            }
            return buf.toString();
        } else {
            return "IMPOSSIBLE";
        }
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

    public String[] split(String s) {
        if(s == null) {
            return new String[0];
        }
        int n = s.length();
        int start = -1;
        int end = 0;
        int sp = 0;
        boolean lastWhitespace = true;
        for(int i=0;i<n;i++) {
            char c = s.charAt(i);
            if(isWhitespace(c)) {
                lastWhitespace = true;
            } else {
                if(lastWhitespace) {
                    sp++;
                }
                if(start == -1) {
                    start = i;
                }
                end = i;
                lastWhitespace = false;
            }
        }
        if(start == -1) {
            return new String[0];
        }
        String[] res = new String[sp];
        int last = start;
        int x = 0;
        lastWhitespace = true;
        for(int i=start;i<=end;i++) {
            char c = s.charAt(i);
            boolean w = isWhitespace(c);
            if(w && !lastWhitespace) {
                res[x++] = s.substring(last,i);
            } else if(!w && lastWhitespace) {
                last = i;
            }
            lastWhitespace = w;
        }
        res[x] = s.substring(last,end+1);
        return res;
    }

    private boolean isWhitespace(char c) {
        return c==' ' || c=='\t';
    }

    private static void out(Object x) {
        System.out.println(x);
    }

    public static void main(String[] args) throws IOException {
        new ProblemD2();
    }
}
