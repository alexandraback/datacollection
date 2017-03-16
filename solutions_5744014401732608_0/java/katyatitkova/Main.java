import java.io.*;
import java.util.*;

public class Main {
    static int[] next_combination(int[] a, int n) {
        int k = a.length;
        for (int i = k - 1; i >= 0; i--) {
            if (a[i] < n - k + i + 1) {
                a[i]++;
                for (int j = i + 1; j < k; j++) {
                    a[j] = a[j - 1] + 1;
                }
                return a;
            }
        }
        a[0] = -1;
        return a;
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("B-small-attempt0.in"));
        //Scanner in = new Scanner(new File("B-small.in"));
        PrintWriter out = new PrintWriter("out.txt");
        int t = in.nextInt();
        for (int cases = 1; cases <= t; cases++) {
            int b = in.nextInt();
            int m = in.nextInt();
            int[][] a = new int[b][b];
            a[0][b - 1] = 1;
            m--;
            int number = 1;
            if (b > 2) {
                int[] gen = new int[number];
                gen[0] = 0;
                while (m > 0 && number < b - 2) {
                    if (gen[0] == -1) {
                        number++;
                        gen = new int[number];
                        for (int i = 0; i < number; i++) {
                            gen[i] = i;
                        }
                    }
                    boolean ok = true;
                    for (int i = 1; i < gen.length; i++) {
                        if (gen[i] < gen[i - 1]) {
                            ok = false;
                        }
                    }
                    if (ok) {
                        boolean changed = false;
                        int to = 0;
                        int from = 0;
                        if (a[0][gen[0] + 1] != 1) {
                            a[0][gen[0] + 1] = 1;
                            changed = true;
                            for (int i = 0; i < b; i++) {
                                to += a[i][0];
                            }
                            for (int i = 0; i < b; i++) {
                                from += a[gen[0] + 1][i];
                            }
                        }
                        for (int i = 1; i < number; i++) {
                            if (a[gen[i - 1] + 1][gen[i] + 1] != 1) {
                                a[gen[i - 1] + 1][gen[i] + 1] = 1;
                                changed = true;
                                for (int j = 0; j < b; j++) {
                                    to += a[j][gen[i - 1] + 1];
                                }
                                for (int j = 0; j < b; j++) {
                                    from += a[gen[i] + 1][j];
                                }
                            }
                        }
                        if (a[gen[number - 1] + 1][b - 1] != 1) {
                            a[gen[number - 1] + 1][b - 1] = 1;
                            changed = true;
                            for (int j = 0; j < b; j++) {
                                to += a[j][gen[number - 1] + 1];
                            }
                            for (int j = 0; j < b; j++) {
                                from += a[b - 1][j];
                            }
                        }
                        if (changed) {
                            if (to == 0 && from == 0) {
                                m--;
                            } else if (to == 0 || from == 0) {
                                m -= Math.max(to, from);
                            } else {
                                m -= to * from;
                            }
                        }
                    }
                    gen = next_combination(gen, b - 3);
                }
            }
            out.print("Case #" + cases + ": ");
            if (m != 0) {
                out.println("IMPOSSIBLE");
            } else {
                out.println("POSSIBLE");
                for (int i = 0; i < b; i++) {
                    for (int j = 0; j < b; j++) {
                        out.print(a[i][j]);
                    }
                    out.println();
                }
            }
        }
        out.close();
    }
}
