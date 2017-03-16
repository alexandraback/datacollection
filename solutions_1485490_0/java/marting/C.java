import java.io.*;
import java.math.*;
import java.util.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class C {
    int N, M;
    long a[], b[];
    int A[], B[];
    void solve() {
        N = inp.nextInt();
        M = inp.nextInt();
        a = new long[N+1];
        A = new int[N+1];
        b = new long[M+1];
        B = new int[M+1];
        for (int i = 0; i < N; i++) {
            a[i] = inp.nextLong();
            A[i] = inp.nextInt();
        }
        for (int i = 0; i < M; i++) {
            b[i] = inp.nextLong();
            B[i] = inp.nextInt();
        }
        out.print(step(0, 0, a[0], b[0]));
        //solve1();
    }
    long step(int ia, int ib, long ra, long rb) {
        if (ia < N && ib < M) {
            if (A[ia]==B[ib]) {
                long m = min(ra, rb);
                ra -= m;
                rb -= m;
                if (ra==0) {
                    ia++;
                    ra = a[ia];
                }
                if (rb==0) {
                    ib++;
                    rb = b[ib];
                }
                return m + step(ia, ib, ra, rb);
            } else {
                long r1 = step(ia+1, ib, a[ia+1], rb);
                long r2 = step(ia, ib+1, ra, b[ib+1]);
                return max(r1, r2);
            }
        } else
            return 0;
    }
    void solve1() {
        TreeMap<State, Long> D = new TreeMap<State, Long>() {
            public Long get(Object key) {
                Long r = super.get(key);
                if (r==null) return 0l;
                return r;
            }
        };
        State s0 = new State(0, 0, a[0], b[0]);
        D.put(s0, 0l);
        TreeSet<State> Q = new TreeSet<>();
        Q.add(s0);
        while (!Q.isEmpty()) {
            s0 = Q.pollFirst();
            long d0 = D.get(s0);
            if (s0.ia < N && s0.ib < M) {
                if (A[s0.ia] == B[s0.ib]) {
                    long m = min(s0.ra, s0.rb);
                    int ia = s0.ia;
                    int ib = s0.ib;
                    long ra = s0.ra - m;
                    long rb = s0.rb - m;
                    if (ra==0) {
                        ia ++;
                        ra = (ia < N) ? a[ia] : 0;
                    }
                    if (rb==0) {
                        ib ++;
                        rb = (ib < M) ? b[ib] : 0;
                    }
                    State s1 = new State(ia,ib,ra,rb);
                    long d1 = d0 + m;
                    if (!D.containsKey(s1) || D.get(s1) < d1) {
                        D.put(s1, d1);
                        Q.add(s1);
                    }
                    continue;
                }
            }
            if (s0.ia < N) {
                int ia = s0.ia+1;
                State s1 = new State(ia, s0.ib, (ia<N ? a[ia] : 0), s0.rb);
                if (!D.containsKey(s1) || D.get(s1) < d0) {
                    D.put(s1, d0);
                    Q.add(s1);
                }
            }
            if (s0.ib < M) {
                int ib = s0.ib+1;
                State s1 = new State(s0.ia, ib, s0.ra, (ib<M ? b[ib] : 0));
                if (!D.containsKey(s1) || D.get(s1) < d0) {
                    D.put(s1, d0);
                    Q.add(s1);
                }
            }
        }
        long res = D.get(new State(N,M, 0, 0));
        out.print(res);
    }
    class State implements Comparable<State> {
        int ia, ib;
        long ra, rb;
        State(int ia, int ib, long ra, long rb) {
            this.ia = ia;
            this.ib = ib;
            this.ra = ra;
            this.rb = rb;
        }
        public int compareTo(State o) {
            int r = ia - o.ia;
            if (r!=0) return r;
            r = ib - o.ib;
            if (r!=0) return r;
            long l = ra - o.ra;
            if (l!=0) return (int) l;
            l = rb - o.rb;
            return (int) l;
        }
        public String toString() {
            return "{" +
                    "ia=" + ia +
                    ", ib=" + ib +
                    ", ra=" + ra +
                    ", rb=" + rb +
                    '}';
        }
    }

    Scanner inp;
    PrintWriter out;
    static String _prob;
    void run() throws Exception {
        inp = new Scanner(new File(_prob + ".in"));
        out = new PrintWriter(new File(_prob+".out"));
        int T = inp.nextInt();
        for (int I = 0; I < T; I++) {
            out.printf("Case #%d: ", I + 1);
            solve();
            out.println();
        }
        out.close();
    }
    public static void main(String[] args) throws Exception {
        _prob = args.length>0 ? args[0].replaceAll(".in", "") : "C";
        new C().run();
    }
    static <TA extends Comparable<TA>, TB extends Comparable<TB>> Pair<TA, TB> pair(TA a, TB b) {
        return new Pair<TA, TB>(a,b);
    }
    static class Pair<TA extends Comparable<TA>, TB extends Comparable<TB>> implements Comparable<Pair<TA,TB>> {
        TA a;
        TB b;
        public Pair(TA a, TB b) {
            this.a = a; this.b = b;
        }
        public int compareTo(Pair<TA, TB> o) {
            int r = a.compareTo(o.a);
            if (r!=0) return r;
            r = b.compareTo(o.b);
            return r;
        }
        public String toString() {
            return "("+a+","+b+")";
        }
    }
}
