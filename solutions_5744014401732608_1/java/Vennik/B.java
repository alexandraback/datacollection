import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class B {

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(new File("B-large (1).in"));
        FileWriter fw = new FileWriter(new File("b.out"));
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            fw.append(String.format("Case #%d: %s", i, new B().solve(sc))).append('\n');
        }
        fw.close();
        sc.close();

    }

    private String solve(Scanner sc) {

        int B = sc.nextInt();
        long M = sc.nextLong();

        long max = pow(2, B - 2);
        if (M > max) return "IMPOSSIBLE";

        return construct(B, M);

    }

    private String construct(int B, long M) {
        int[][] out = new int[B][B];

        for (int i = 0; i < B; i++) {
            for (int j = B - 1; j >= 0 && i < j; j--) {
                out[i][j] = 1;
            }
        }

        long remove = pow(2, B - 2) - M;

//        System.out.println(Integer.toBinaryString(remove));

        int test = B - 1;
        while (remove > 0) {
//            System.out.println("->" + (remove & 1));
            if((remove & 1) == 1) {
                out[0][test - 1] = 0;
            }
            remove = remove >> 1;
            test--;
        }

        StringBuilder sb = new StringBuilder();
        sb.append("POSSIBLE\n");
        for (int i = 0; i < B; i++) {
            for (int j = 0; j < B; j++) {
                sb.append(out[i][j]);
            }
            sb.append('\n');
        }
        String temp = sb.toString();
        return temp.substring(0, temp.length() - 1);
    }

    long pow(long a, long b) {
        if (b == 0) return 1;
        if (b == 1) return a;
        if (b % 2 == 0) return pow(a * a, b / 2);
        else return a * pow(a * a, b / 2);
    }

}
