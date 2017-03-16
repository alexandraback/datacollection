package codejam.y2012.r1a;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File(args[0]));
        PrintWriter printWriter = new PrintWriter(new File(args[1]));
        int cases = scanner.nextInt();
        for (int ci = 0; ci < cases; ci++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            double p[] = new double[a];
            double sol = 0;
            double pcorr=1;
            for (int i = 0; i < a; i++) {
                p[i] = scanner.nextDouble();
                pcorr *= p[i];
            }
            // when hit enter
            double sol1 = b+2;
            // when continue
            double sol2 = (b+a+3) * (1 - pcorr) + pcorr * (b-a+1);
            // try possibilities
            int ac = 1 << a;
            double sol3 = 10000000;
            System.out.println("-----------");
            for (int i = 1; i < a; i++) {
                System.out.println("backspaces: " + i);
                double s = 0;
                for (int j = 0; j < ac; j++) {
                    double prob = 1;
                    boolean mistake = false;
                    for (int k = 0; k < a; k++) {
                        if ((j>>k&1)==0) {
                            prob *= p[k];
                        } else {
                            prob *= 1-p[k];
                            if (k < i) mistake = true;
                        }
                    }
                    int keystrokes;
                    if (mistake) {
                        keystrokes = 2*i + b - a + b + 2; 
                    } else {
                        keystrokes = 2*i + b - a + 1;
                    }
                    s += keystrokes * prob;
                    System.out.print(" " + prob);
                }
                sol3 = Math.min(sol3, s);
                System.out.println();
            }
            
            printWriter.println("Case #" + (ci+1) + ": " + Math.min(sol3, Math.min(sol1, sol2)));
            
        }
        printWriter.close();
        scanner.close();
    }
}
