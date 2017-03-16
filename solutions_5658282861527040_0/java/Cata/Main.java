import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {

    public static void main(String... args) throws Exception {
        Scanner sc = new Scanner(System.in);
//        PrintStream out = System.out;
		PrintStream out = new PrintStream(new File("f.out"));
        int t, T;
        int a, b, k;
        for (t = 1, T = sc.nextInt(); t <= T; t++) {
            a = sc.nextInt();
            b = sc.nextInt();
            k = sc.nextInt();
            int res = 0;
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    if ((i & j) < k) {
                        res++;
                    }
                }
            }
            out.println(String.format("Case #%d: %d", t, res));
        }
    }

}
