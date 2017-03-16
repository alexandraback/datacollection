import java.io.*;
import java.math.*;
import java.util.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class B {

    void solve() {
        double D = inp.nextDouble();
        int N = inp.nextInt();
        int A = inp.nextInt();
        double T[] = new double[N];
        double X[] = new double[N];
        for (int i = 0; i < N; i++) {
            T[i] = inp.nextDouble();
            X[i] = inp.nextDouble();
        }
        if (N>1 && X[0]<D) {
            double v = (X[1]-X[0]) / T[1];
            double endtime = (D - X[0]) / v;
            double acc = 2*D/endtime/endtime;
            for (int i = 0; i < A; i++) {
                double a = inp.nextDouble();
                if (acc < a)
                    out.println(endtime);
                else {
                    double t = sqrt(2*D/a);
                    out.println(t);
                }
            }
        } else {
            for (int i = 0; i < A; i++) {
                double a = inp.nextDouble();
                double t = sqrt(2*D/a);
                out.println(t);
            }
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
            out.printf("Case #%d:\n", I + 1);
            solve();
        }
        out.close();
    }
    public static void main(String[] args) throws Exception {
        _prob = args.length>0 ? args[0].replaceAll(".in", "") : "B";
        new B().run();
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
