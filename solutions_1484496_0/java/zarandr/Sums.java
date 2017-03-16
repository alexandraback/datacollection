import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Andrey Zarubin
 */
public class Sums {
    public static void main(String... args) throws IOException {
        long now = System.currentTimeMillis();
//        String fileName = "C-large.in";
        String fileName = "C-small-attempt0.in";
//        String fileName = "sums-test.in.txt";
        BufferedReader r = new BufferedReader(new FileReader(fileName));
        PrintWriter w = new PrintWriter(fileName.split("\\.")[0] + ".out.txt");
        int T = Integer.parseInt(r.readLine());
        loop:
        for (int X = 0; X < T; X++) {
            w.println("Case #" + (X + 1) + ":");
            Scanner sc = new Scanner(r.readLine());
            int n = sc.nextInt();
            int[] s = new int[n];
            for (int i = 0; i < n; i++)
                s[i] = sc.nextInt();
            for (int i = 0; i < (1 << n) - 1; i++) {
                for (int j = i + 1; j < (1 << n); j++) {
                    if ((i & j) != 0)
                        continue;
                    int k = i;
                    int l = 0;
                    int s1 = 0;
                    while (k > 0) {
                        if (k % 2 == 1)
                            s1 += s[l];
                        k >>>= 1;
                        l++;
                    }
                    k = j;
                    l = 0;
                    int s2 = 0;
                    while (k > 0) {
                        if (k % 2 == 1)
                            s2 += s[l];
                        k >>>= 1;
                        l++;
                    }
                    if (s1 == s2) {
                        k = i;
                        l = 0;
                        while (k > 0) {
                            if (k % 2 == 1)
                                w.print(s[l] + " ");
                            k >>>= 1;
                            l++;
                        }
                        w.println();
                        k = j;
                        l = 0;
                        while (k > 0) {
                            if (k % 2 == 1)
                                w.print(s[l] + " ");
                            k >>>= 1;
                            l++;
                        }
                        w.println();
                        continue loop;
                    }
                }
            }
            w.println("Impossible");
        }
        r.close();
        w.close();
        System.out.println((System.currentTimeMillis() - now) / 1e3);
    }
}
