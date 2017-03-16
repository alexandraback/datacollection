import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

import static java.math.BigInteger.ONE;
import static java.math.BigInteger.ZERO;

public class ProblemC2 {
    private static final BigInteger FOUR = new BigInteger("4");
    private static final BigInteger TWO = new BigInteger("2");
    private static final BigInteger THREE = new BigInteger("3");
    BufferedReader rd;

    ProblemC2() throws IOException {
        rd = new BufferedReader(new InputStreamReader(System.in));
        compute();
    }

    private void compute() throws IOException {
        rd.readLine();
        long[] nj = longarr();
        out("Case #1:");
        if(nj[0] == 16) {
            small(nj[1]);
        } else {
            large(nj[0], nj[1]);
        }
    }

    private void small(long cnt) {
        long y = 1000_0000_0000_0001L;
        long z = Long.parseLong(Long.toString(y),2);
        int f = 0;
        while(f < cnt) {
            String s = Long.toString(z,2);
            StringBuilder b = new StringBuilder();
            int j = 2;
            while(j <= 10) {
                long u = Long.parseLong(s, j);
                long v = div(u);
                if(v == 1) {
                    break;
                } else {
                    if(b.length() > 0) {
                        b.append(' ');
                    }
                    b.append(v);
                }
                j++;
            }
            if(j > 10) {
                f++;
                out(s+" "+b);
            }
            z += 2;
        }
    }

    private void large(long len, long cnt) {
        StringBuilder zero = new StringBuilder();
        zero.append('1');
        for(int i=0;i<len-2;i++) {
            zero.append('0');
        }
        zero.append('1');
        BigInteger z = new BigInteger(zero.toString(), 2);
        int f = 0;
        while(f < cnt) {
            String s = z.toString(2);
            StringBuilder b = new StringBuilder();
            int j = 2;
            while(j <= 10) {
                BigInteger u = new BigInteger(s, j);
                BigInteger v = div(u);
                if(v.equals(ONE)) {
                    break;
                } else {
                    b.append(v).append(' ');
                }
                j++;
            }
            if(j > 10) {
                f++;
                out(s+" "+b);
            }
            z = z.add(TWO);
        }
    }

    private static long div(long x) {
        if(x < 4 || x%2 == 0) {
            return (x == 2 || x == 3)?1:2;
        }
        for(long i=3;i*i<=x;i+=2) {
            if(x%i==0) {
                return i;
            }
        }
        return 1;
    }

    private static BigInteger div(BigInteger x) {
        if(x.compareTo(FOUR) < 0 || x.mod(TWO).equals(ZERO)) {
            return (x.equals(TWO) || x.equals(THREE))? ONE:TWO;
        }
        int m = 0;
        for(BigInteger i=THREE;i.multiply(i).compareTo(x)<=0;i = i.add(TWO)) {
            if(x.mod(i).equals(ZERO)) {
                return i;
            }
            m++;
            if(m > 10000) {
                return ONE;
            }
        }
        return ONE;
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
        new ProblemC2();
    }
}
