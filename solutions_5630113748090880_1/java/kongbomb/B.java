import org.psjava.util.ZeroTo;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.util.Scanner;

public class B implements Runnable {

    @Override
    public void run() {
        Scanner in = new Scanner(System.in);
        for (int casei : ZeroTo.get(in.nextInt())) {
            System.out.print("Case #" + (casei + 1) + ": ");
            int n = in.nextInt();
            boolean[] odd = new boolean[2501];
            for (int i = 0; i < 2 * n - 1; i++) {
                for (int j = 0; j < n; j++) {
                    int v = in.nextInt();
                    odd[v] = !odd[v];
                }
            }
            boolean first = true;
            for (int i = 0; i <= 2500; i++) {
                if (odd[i]) {
                    if (first)
                        first = false;
                    else
                        System.out.print(" ");
                    System.out.print(i);
                }
            }
            System.out.println();
        }
    }

    public static void main(String[] args) throws Exception {
        System.setIn(new BufferedInputStream(new FileInputStream("solutions/B-large.in")));
        new B().run();
    }

}
