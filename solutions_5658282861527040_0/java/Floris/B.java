import java.io.*;
import java.util.*;

public class B {
    public static void main(String[] args) throws Exception {
//        InputStream in = System.in;
        InputStream in = new FileInputStream("/home/floris/Downloads/B-small-attempt0.in");
        System.setOut(new PrintStream("/home/floris/temp/codejam2014/src/B.out"));
        Scanner sc = new Scanner(in);

        for (int c = 1, cases = sc.nextInt(); c <= cases; c++) {
            int A = sc.nextInt();
            int B = sc.nextInt();
            int K = sc.nextInt();
            long count = 0;
            for (int i = 0; i < A; i++) for (int j = 0; j < B; j++) {
                if ((i&j) < K) count++;
            }
            System.out.printf("Case #%d: %d%n", c, count);
        }
    }
}
