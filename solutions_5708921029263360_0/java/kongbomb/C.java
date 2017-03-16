import org.psjava.ds.array.*;
import org.psjava.util.*;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class C implements Runnable {

    private int maxSize;
    private Iterable<Index3D> maxSub;
    private DynamicArray<Index3D> combinations;
    private int k;
    private DynamicArray<Index3D> history;

    @Override
    public void run() {
        Scanner in = new Scanner(System.in);
        for (int casei : ZeroTo.get(in.nextInt())) {
            int n1 = in.nextInt();
            int n2 = in.nextInt();
            int n3 = in.nextInt();
            k = in.nextInt();

            combinations = DynamicArray.create();
            for (int i1 : ZeroTo.get(n1))
                for (int i2 : ZeroTo.get(n2))
                    for (int i3 : ZeroTo.get(n3))
                        combinations.addToLast(new Index3D(i1, i2, i3));

            maxSize = 0;
            maxSub = null;

//            for (Iterable<Index3D> sub : SubSetIterable.create(combinations)) {
//                update(sub);
//            }

            history = DynamicArray.create();
            go(0);

            System.out.print("Case #" + (casei + 1) + ": ");
            System.out.println(maxSize);
            for (Index3D item : maxSub)
                System.out.println((item.i1 + 1) + " " + (item.i2 + 1) + " " + (item.i3 + 1));
        }
    }

    public void go(int index) {
        if (history.size() + (combinations.size() - index) <= maxSize)
            return;
        if (index == combinations.size()) {
            update(history);
        } else {
            go(index + 1);
            history.addToLast(combinations.get(index));
            go(index + 1);
            history.removeLast();
        }
    }

    private void update(Iterable<Index3D> sub) {
        int[][] c12 = new int[3][3];
        int[][] c13 = new int[3][3];
        int[][] c23 = new int[3][3];
        int size = 0;
        for (Index3D t : sub) {
            c12[t.i1][t.i2]++;
            c13[t.i1][t.i3]++;
            c23[t.i2][t.i3]++;
            size++;
        }
        if (isOk(c12, k) && isOk(c13, k) && isOk(c23, k)) {
            if (size > maxSize) {
                maxSize = size;
//                System.out.println(maxSize);
                maxSub = MutableArrayFromIterable.create(sub);
            }
        }
    }

    private boolean isOk(int[][] c12, int k) {
        for (int[] s : c12)
            for (int v : s)
                if (v > k)
                    return false;
        return true;
    }

    public static void main(String[] args) throws Exception {
        System.setIn(new BufferedInputStream(new FileInputStream("/Users/imyoyo/Desktop/C-small-attempt1.in")));
        System.setOut(merge(System.out, new PrintStream("/Users/imyoyo/kb/mavens/solutions/src/main/java/output.txt")));
        new C().run();
    }

    private static PrintStream merge(final PrintStream p1, final PrintStream p2) {
        return new PrintStream(new OutputStream() {
            @Override
            public void write(int b) throws IOException {
                p1.write(b);
                p2.write(b);
            }
        });
    }

}
