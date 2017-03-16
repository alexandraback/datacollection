import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: vors
 * Date: 4/14/12
 * Time: 6:03 PM
 * To change this template use File | Settings | File Templates.
 */
public class A {

    static class Pair implements Comparable<Pair> {
        int v;

        Pair(int v, int num) {
            this.v = v;
            this.num = num;
        }

        int num;

        @Override
        public int compareTo(Pair pair) {
            return v - pair.v;
        }
    }


    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("a.in"));
        PrintWriter out = new PrintWriter(new File("a.out"));

        int TT = in.nextInt();
        for (int cas=1; cas<=TT; cas++) {
            int n = in.nextInt();
            Pair[] a = new Pair[n];
            double sum = 0;
            for (int i=0; i<n; i++) {
                a[i] = new Pair(in.nextInt(), i);
                sum += a[i].v;
            }
            Arrays.sort(a);
            int sum2 = 0;
            double res[] = new double[n];
            for (int i=0; i<n; i++) {
                sum2 += a[i].v;
                if (i == n-1 || (sum2 + sum) / (i + 1) < a[i+1].v) {
                    for (int j=0; j<=i; j++) {
                        res[a[j].num] = ((sum2 + sum) / (i + 1) - a[j].v) / sum;
                    }
                    break;
                }
            }
            out.printf("Case #%d:", cas);
            for (int i=0; i<n; i++) {
                out.printf(" %.8f", 100 * res[i]);
            }
            out.println();
        }
        out.close();
    }

}
