import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author OleGG
 */
public class QualTaskC {
    public static void main(String[] args) throws Throwable {
        Scanner sc = new Scanner(new FileReader("C-large.in.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("C-large.out.txt"));
        int t = sc.nextInt();

        for (int test = 1; test <= t; ++test) {
            int a = sc.nextInt();
            int b = sc.nextInt();

            int mul = 1;
            while (mul <= a) {
                mul *= 10;
            }
            mul /= 10;

            int res = 0;
            for (int i = a; i < b; ++i) {
                int curr = i;
                do {
                    int temp = curr % 10;
                    curr /= 10;
                    curr += temp * mul;
                    if (curr > i && curr <= b) {
                        ++res;
                    }
                } while (curr != i);
            }

            pw.printf("Case #%d: %d\n", test, res);
        }
        pw.close();
    }
}
