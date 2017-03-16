import org.psjava.algo.math.optimization.Memoization;
import org.psjava.algo.math.optimization.MemoizationFunction;
import org.psjava.ds.array.MutableArrayUsingCharArray;
import org.psjava.formula.MaxInIterable;
import org.psjava.goods.GoodMemoizationFactory;
import org.psjava.util.DefaultComparator;
import org.psjava.util.ZeroTo;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.util.Scanner;

public class A implements Runnable {

    @Override
    public void run() {
        Scanner in = new Scanner(System.in);
        for (int casei : ZeroTo.get(in.nextInt())) {
            System.out.print("Case #" + (casei + 1) + ": ");
            System.out.println(GoodMemoizationFactory.getInstance().create(new MemoizationFunction<String, String>() {
                @Override
                public String get(String s, Memoization<String, String> memo) {
                    if (s.length() == 0)
                        return "";
                    char max = MaxInIterable.max(MutableArrayUsingCharArray.wrap(s.toCharArray()), new DefaultComparator<Character>());
                    String best = null;
                    for (int i = 0; i < s.length(); i++) {
                        if (s.charAt(i) == max) {
                            String candidate = max + memo.get(s.substring(0, i)) + s.substring(i + 1);
                            if (best == null || candidate.compareTo(best) > 0)
                                best = candidate;
                        }
                    }
                    return best;
                }
            }).get(in.next()));
        }
    }

    public static void main(String[] args) throws Exception {
        System.setIn(new BufferedInputStream(new FileInputStream("solutions/A-large (1).in")));
        new A().run();
    }

}
