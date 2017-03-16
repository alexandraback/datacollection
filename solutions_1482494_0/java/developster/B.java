package codejam.y2012.r1a;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File(args[0]));
        PrintWriter printWriter = new PrintWriter(new File(args[1]));
        int cases = scanner.nextInt();
        for (int ci = 0; ci < cases; ci++) {
            int n = scanner.nextInt();
            int a[] = new int[n];
            int b[] = new int[n];
            int r[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
                b[i] = scanner.nextInt();
                r[i] = 0;
            }
            int s = 0;
            int rem = n;
            int comp = 0;
            boolean run = true;
            while (run) {
                run = false;
                
                boolean fill = true;
                while (fill) {
                    fill = false;
                    for (int i = 0; i < n; i++) {
                        if (r[i] != 2 && s >= b[i]) {
                            s += 2-r[i];
                            r[i] = 2;
                            rem--;
                            comp++;
                            fill = true;
                            run = true;
                        }
                    }
                }
                if (rem == 0) {
                    break;
                }
                int maxP = -1;
                int maxI = -1;
                for (int i = 0; i < n; i++) {
                    if (r[i] == 0 && s >= a[i]) {
                        if (b[i] > maxP) {
                            maxP = b[i];
                            maxI = i;
//                            break;
                        }
                    }
                }
                if (maxI >= 0) {
                    r[maxI] = 1;
                    s += 1;
                    run = true;
                    comp++;
                }
            }
            printWriter.print("Case #" + (ci+1) + ": ");
            if (rem > 0) {
                printWriter.println("Too Bad");
            } else {
                printWriter.println(comp);
            }
        }
        printWriter.close();
        scanner.close();
    }
}
