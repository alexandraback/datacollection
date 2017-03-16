
import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

    public static void main(String args[]) throws Exception {
        final String PATH = "/home/goalboy/software installation/codejam-commandline-1.0-beta4/source/";
        final String FILE = "A-small-1";
        Scanner in = new Scanner(new File(PATH + FILE + ".in"));
        PrintWriter out = new PrintWriter(PATH + FILE + ".out");

        int test = in.nextInt();
        for (int t = 1; t <= test; t++) {
            int N = in.nextInt();
            int s[] = new int[N];
            int sum = 0;
            for (int i = 0; i < s.length; i++) {
                s[i] = in.nextInt();
                sum += s[i];
            }
            int order[] = new int[s.length];
            for (int i = 0; i < order.length; i++) {
                order[i] = i;
            }
            sort(order, s);
            out.print("Case #" + t + ":");
            for (int i = 0; i < s.length; i++) {
                double minM = Double.MAX_VALUE;
                int partCount = 0;
                int partSum = 0;
                for (int j = 0; j < order.length; j++) {
                    if (order[j] == i) {
                        continue;
                    }
                    partCount++;
                    partSum += s[order[j]];
                    double m = (((double) (partSum + sum) / partCount) - s[i]) / sum / (1 + 1.0 / partCount);
                    minM = Math.min(minM, m);
                }
                minM = Math.max(minM, 0);
                out.print(" " + minM * 100);
            }
            out.println();
        }

        out.close();
    }

    static void sort(int order[], int s[]) {
        boolean swap;
        do {
            swap = false;
            for (int i = 0; i < order.length - 1; i++) {
                if (s[order[i]] > s[order[i + 1]]) {
                    int temp = order[i];
                    order[i] = order[i + 1];
                    order[i + 1] = temp;
                    swap = true;
                }
            }
        } while (swap);
    }
}
