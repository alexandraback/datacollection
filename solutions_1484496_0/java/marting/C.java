import java.io.*;
import java.math.*;
import java.util.*;
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class C {
    public static String outs(int A[], int s, int n) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if ((s & (1<<i)) != 0)
                sb.append(A[i]).append(' ');
        }
        return sb.toString();
    }
    public static void main(String[] args) throws Exception {
        String _prob = args.length>0 ? args[0].replaceAll(".in", "") : "C";
        Scanner inp = new Scanner(new File(args.length>0?args[0] : _prob + ".in"));
        PrintWriter out = new PrintWriter(new File(args.length>1?args[1] : _prob+".out"));
        int T = inp.nextInt();
        for (int I = 0; I < T; I++) {
            out.printf("Case #%d: ", I+1);

            int N = inp.nextInt();
            int A[] = new int[N];
            for (int i = 0; i < N; i++) {
                A[i] = inp.nextInt();
            }
            HashMap<Integer,Integer> R = new HashMap<>();
            boolean found = false;
            for (int s = 1; s < 1<<N; s++) {
                int sum = 0;
                for (int i = 0; i < N; i++) {
                    if ((s & (1<<i)) > 0)
                        sum += A[i];
                }
                if (R.containsKey(sum)) {
                    out.println();
                    out.println(outs(A, R.get(sum), N));
                    out.println(outs(A, s, N));
                    found = true;
                    break;
                }
                R.put(sum, s);
            }
            if (!found)
                out.println("Impossible");
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
