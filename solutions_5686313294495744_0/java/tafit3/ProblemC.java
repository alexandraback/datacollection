import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import static java.util.Collections.emptySet;

public class ProblemC {
    BufferedReader rd;
    int[][] d;
    Map<Set<Integer>, Integer> m;

    ProblemC() throws IOException {
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
        int n = pint();
        Map<String, Integer> translate = new HashMap<>();
        d = new int[n][2];
        int seq = 0;
        for(int i=0;i<n;i++) {
            String[] h = split(rd.readLine());
            for(int j=0;j<2;j++) {
                Integer key = translate.get(h[j]);
                if(key == null) {
                    key = seq++;
                    translate.put(h[j], key);
                }
                d[i][j] = key;
            }
        }
        m = new HashMap<>();
        return Integer.toString(solve(emptySet(), emptySet(), emptySet()));
    }

    private int solve(Set<Integer> first, Set<Integer> second, Set<Integer> idx) {
        Integer res = m.get(idx);
        if(res == null) {
            int n = d.length;
            int base = 0;
            Set<Integer> nidx = new HashSet<>(idx);
            List<Integer> candidates = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (!idx.contains(i)) {
                    if (first.contains(d[i][0]) && second.contains(d[i][1])) {
                        nidx.add(i);
                        base++;
                    } else {
                        candidates.add(i);
                    }
                }
            }
            int maxFake = 0;
            for (Integer cand : candidates) {
                Set<Integer> s1 = new HashSet<>(first);
                s1.add(d[cand][0]);
                Set<Integer> s2 = new HashSet<>(second);
                s2.add(d[cand][1]);
                Set<Integer> n2idx = new HashSet<>(nidx);
                n2idx.add(cand);
                maxFake = Math.max(maxFake, solve(s1, s2, n2idx));
            }
            res = maxFake + base;
            m.put(idx, res);
        }
        return res;
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
        new ProblemC();
    }
}
