import java.io.*;
import java.math.*;
import java.util.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class A {
    public static void main(String[] args) throws Exception {
        String _prob = args.length>0 ? args[0].replaceAll(".in", "") : "A";
        Scanner inp = new Scanner(new File(args.length>0?args[0] : _prob + ".in"));
        PrintWriter out = new PrintWriter(new File(args.length>1?args[1] : _prob+".out"));
        int T = inp.nextInt();
        for (int I = 0; I < T; I++) {
            out.printf("Case #%d: ", I+1);

            int n = inp.nextInt();
            double S[] = new double[n];
            double X = 0;
            for (int i = 0; i < n; i++) {
                S[i] = inp.nextDouble();
                X += S[i];
            }
            for (int i = 0; i < n; i++) {
                double si = S[i];
                double au = X;
                for (int j = 0; j < n; j++) {
                    if (i!=j && S[j]<si)
                        au -= si - S[j];
                }
                double res = 0;
                if (au <= 0) {
                    res = 0;
                } else {
                    int k = 0;
                    double A[] = new double[n];
                    for (int j = 0; j < n; j++) {
                        if (S[j] > S[i])
                            A[k++] = S[j];
                    }
                    A = copyOf(A, k);
                    sort(A);
                    double lev = si;
                    for (int j = 0; j < k; j++) {
                        double a = n-k+j;
                        a *= A[j] - lev;
                        if (au >= a) {
                            au -= a;
                            lev = A[j];
                        } else {
                            lev += au / (n-k+j);
                            au = 0;
                            break;
                        }
                    }
                    if (au > 0)
                        lev += au / n;
                    res = lev - si;
                }
                out.printf("%f ", 100*res/X);
            }
            out.println();
        }
        out.close();;
    }
    static class Pair<TA extends Comparable<TA>, TB extends Comparable<TB>> implements Comparable<Pair<TA,TB>> {
        TA a;
        TB b;
        public Pair(TA a, TB b) {
            this.a = a; this.b = b;
        }
        @Override
        public int compareTo(Pair<TA, TB> o) {
            int r = a.compareTo(o.a);
            if (r!=0) return r;
            r = b.compareTo(o.b);
            return r;
        }
        @Override
        public String toString() {
            return "("+a+","+b+")";
        }
    }
}
