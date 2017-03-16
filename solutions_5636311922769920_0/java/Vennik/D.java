import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class D {

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(new File("D-small-attempt1.in"));
        FileWriter fw = new FileWriter(new File("d.out"));
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            fw.append(String.format("Case #%d: %s", i, new D().solve(sc))).append('\n');
        }
        fw.close();
        sc.close();

    }

    private String solve(Scanner sc) {

        long k = sc.nextInt();
        long c = sc.nextInt();
        long s = sc.nextInt();

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < k; i++) {

            sb.append(i * transpose(k, c) + 1).append(' '); //  + i

        }

        String temp = sb.toString();
        return temp.substring(0, temp.length() - 1);

    }

    private long transpose(long k, long c) {

        return (long) Math.pow(k, c - 1);

    }

}
