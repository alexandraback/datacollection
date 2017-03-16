import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class ProblemB4 {
    BufferedReader rd;

    ProblemB4() throws IOException {
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
        String[] s = split(rd.readLine());
        int n = s[0].length();
        String[] res = null;
        for(int i=0;i<=n;i++) {
            for(char up='0';up<='9';up++) {
                for(char dn='0';dn<='9';dn++) {
                    if(up != dn) {
                        String[] cur = solve(s,i,up,dn);
                        if(cur != null) {
                            if (res == null || less(cur, res)) {
                                res = cur;
                            }
                        }
                    }
                }
            }
        }
        return res[0]+" "+res[1];
    }

    private boolean less(String[] a, String[] b) {
        if(a == null) {
            return false;
        }
        long a0 = Long.parseLong(a[0]);
        long a1 = Long.parseLong(a[1]);
        long b0 = Long.parseLong(b[0]);
        long b1 = Long.parseLong(b[1]);

        long aAbs = Math.abs(a0-a1);
        long bAbs = Math.abs(b0-b1);
        return aAbs < bAbs || (aAbs == bAbs && a0 < b0) || (aAbs == bAbs && a0 == b0 && a1 < b1);
    }

    private String[] solve(String[] s, int eqLen, char up, char dn) {
        char[][] v = new char[2][];
        v[0] = s[0].toCharArray();
        v[1] = s[1].toCharArray();
        int n = v[0].length;
        for(int i=0;i<eqLen;i++) {
            char c = v[0][i];
            char d = v[1][i];
            if(c == '?') {
                if(d == '?') {
                    v[0][i] = '0';
                    v[1][i] = '0';
                } else {
                    v[0][i] = d;
                }
            } else if(d == '?') {
                v[1][i] = c;
            } else if(c != d) {
                return null;
            }
        }
        if(eqLen < n) {
            char c = v[0][eqLen];
            char d = v[1][eqLen];
            if (c == '?') {
                if (d == '?') {
                    v[0][eqLen] = up;
                    v[1][eqLen] = dn;
                } else if (d == dn) {
                    v[0][eqLen] = up;
                } else {
                    return null;
                }
            } else if (d == '?') {
                if (c == up) {
                    v[1][eqLen] = dn;
                } else {
                    return null;
                }
            } else if (c != up || d != dn) {
                return null;
            }
            boolean cgr = up > dn;
            for (int i = eqLen + 1; i < n; i++) {
                c = v[0][i];
                d = v[1][i];
                if (c == '?') {
                    if (d == '?') {
                        if (cgr) {
                            v[0][i] = '0';
                            v[1][i] = '9';
                        } else {
                            v[0][i] = '9';
                            v[1][i] = '0';
                        }
                    } else {
                        v[0][i] = cgr ? '0' : '9';
                    }
                } else if (d == '?') {
                    v[1][i] = cgr ? '9' : '0';
                }
            }
        }
        return new String[] { new String(v[0]), new String(v[1]) };
    }

    private int pint() throws IOException {
        return pint(rd.readLine());
    }

    private int pint(String s) {
        return Integer.parseInt(s);
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
        new ProblemB4();
    }
}
