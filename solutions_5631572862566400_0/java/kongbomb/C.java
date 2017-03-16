import org.psjava.ds.array.ArrayReverser;
import org.psjava.ds.array.ArraySwapper;
import org.psjava.ds.array.MutableArray;
import org.psjava.ds.array.MutableArrayFromIterable;
import org.psjava.goods.GoodSortingAlgorithm;
import org.psjava.util.DefaultComparator;
import org.psjava.util.SubSetIterable;
import org.psjava.util.ZeroTo;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.util.Comparator;
import java.util.Scanner;

public class C implements Runnable {

    static public <T> boolean stepNext(MutableArray<T> a, Comparator<T> comp) {
        int p = -1;
        for (int i = a.size() - 2; i >= 0; i--)
            if (comp.compare(a.get(i), a.get(i + 1)) < 0) {
                p = i;
                break;
            }

        if (p == -1)
            return false;

        ArrayReverser.reverse(a, p + 1, a.size());

        for (int i = p + 1; i < a.size(); i++)
            if (comp.compare(a.get(i), a.get(p)) > 0) {
                ArraySwapper.swap(a, p, i);
                break;
            }
        return true;
    }

    @Override
    public void run() {
        Scanner in = new Scanner(System.in);
        for (int casei : ZeroTo.get(in.nextInt())) {
            System.out.print("Case #" + (casei + 1) + ": ");
            int n = in.nextInt();
            int[] f = new int[n];
            for (int i : ZeroTo.get(n))
                f[i] = in.nextInt();
            int max = 0;
            for (Iterable<Integer> sub : SubSetIterable.create(ZeroTo.get(n))) {
                MutableArray<Integer> permutation = MutableArrayFromIterable.create(sub);
                GoodSortingAlgorithm.getInstance().sort(permutation, new DefaultComparator<Integer>());
                do {
                    boolean ok = true;
                    int size = permutation.size();
                    for (int i : ZeroTo.get(size)) {
                        int bff = f[permutation.get(i)] - 1;
                        int left = (i + size - 1) % size;
                        int right = (i + 1) % size;
                        if (permutation.get(left) != bff && permutation.get(right) != bff)
                            ok = false;
                    }
                    if (ok)
                        max = Math.max(max, permutation.size());
                }
                while (stepNext(permutation, new DefaultComparator<Integer>()));
            }
            System.out.println(max);
        }
    }

    public static void main(String[] args) throws Exception {
        System.setIn(new BufferedInputStream(new FileInputStream("solutions/C-small-attempt0.in")));
        new C().run();
    }

}
