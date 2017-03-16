import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class G_2 {

    static int n, s, p;
    static int[] tt;

    public static void main(String[] args) throws IOException {
        PrintWriter bw = new PrintWriter(new FileWriter("1.txt"));
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        scan.nextLine();
        for (int i = 0; i < t; i++) {
            n = scan.nextInt();
            s = scan.nextInt();
            p = scan.nextInt();
            tt = new int[n];
            int a = 3 * p - 4;
            if (p == 1) {
                a = 1;
            }
            if (p == 0) {
                a = 0;
            }
            // int b = 3 * p + 4;
            int c = 3 * p - 2;
            // int d = 3 * p + 2;
            int count = 0;

            for (int j = 0; j < n; ++j) {
                tt[j] = scan.nextInt();
                if (c <= tt[j]) {
                    count++;
                    continue;
                }
                if (a <= tt[j] && s != 0) {
                    s--;
                    count++;
                    continue;
                }
            }

            System.out.println(String.format("Case #%d: %d", (i + 1), count));
            bw.write(String.format("Case #%d: %d\n", (i + 1), count));
        }
        bw.flush();
        bw.close();
    }
}
