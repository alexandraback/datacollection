import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class A {

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(new File("A-small-attempt1.in"));
        FileWriter fw = new FileWriter(new File("a.out"));
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            fw.append(String.format("Case #%d: %s", i, new A().solve(sc))).append('\n');
        }
        fw.close();
        sc.close();

    }

    private String solve(Scanner sc) {

        long number = sc.nextInt();

        boolean[] counter = new boolean[10];
        int up = 0;

        if (number == 0) return "INSOMNIA";

        int trunc = 0;
        if (number % 10 == 0) {
            while (number % 10 == 0) {
                number /= 10;
                trunc++;
            }
            counter[0] = true;
            up++;
        }

        int i = 1;
        for (; up != 10; i++) {

            long current = number * i;

            while (current > 0) {

                int loc = (int) (current % 10);
                current /= 10;

                boolean prev = counter[loc];

                counter[loc] = true;

                if (prev != counter[loc]) {
                    up++;
                }

            }

        }

        while (trunc > 0) {
            number *= 10;
            trunc--;
        }

        return Long.toString((i - 1) * number);

    }

}
