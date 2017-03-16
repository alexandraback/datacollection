import java.util.List;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

public class ProblemD {

    public static void main(String[] args) throws Exception {

        int t, c;
        SortedSet<Double> bks, bns;

        Scanner in = new Scanner(System.in);

        t = in.nextInt();

        for(int t_ = 0; t_ < t; t_++) {
            c = in.nextInt();

            bns = new TreeSet<>();
            bks = new TreeSet<>();

            for(int i = 0; i < c; i++)
                bns.add(in.nextDouble());

            for(int i = 0; i < c; i++)
                bks.add(in.nextDouble());

            SortedSet<Double> bns2 = new TreeSet<>(bns);
            SortedSet<Double> bks2 = new TreeSet<>(bks);

            int sw = sw(bns2, bks2, c);
            int sdw = sdw(bns, bks, c);

            System.out.format("Case #%d: %d %d\n", (t_+1), sdw, sw);
        }
    }

    public static int sw(SortedSet<Double> bn, SortedSet<Double> bk, int c) {

        int s = 0;

        for(int i = 0; i < c; i++) {
            double n = bn.last();
            bn.remove(n);

            SortedSet<Double> l = bk.tailSet(n);
            if(l.size() > 0) {
                bk.remove(l.first());
            } else {
                bk.remove(bk.first()); s++;
            }
        }

        return s;
    }

    public static int sdw(SortedSet<Double> bn, SortedSet<Double> bk, int c) {

        int s = 0;

        for(int i = 0; i < c; i++) {
            double n = bn.first();
            bn.remove(n);

            double k = bk.first();
            if(n > k) {
                bk.remove(k); s++;
            } else {
                bk.remove(bk.last());
            }
        }

        return s;
    }

}
