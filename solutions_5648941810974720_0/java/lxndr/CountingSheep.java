import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class CountingSheep {
    static int bleh = 1;

    static PrintWriter writer;

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("A-large.in"));
        writer = new PrintWriter("test.txt", "UTF-8");
        String count1 = in.nextLine();
        int count = Integer.parseInt(count1);
        for (int c = 0; c < count; c++) {
            int input = in.nextInt();
            sheeps(input);
        }
        writer.close();
    }

    public static void sheeps(int input) {
        boolean[] saw = new boolean[10];
        saw = seen(input);
        int n = 1;
        if (input == 0) {
            writer.println("Case #" + bleh + ": INSOMNIA");
            bleh++;
        } else {
            while (!allTrue(saw)) {
                n++;
                saw = combine(saw, seen(input * n));
            }
            writer.println("Case #" + bleh + ": " + n * input);
            bleh++;
        }
    }

    public static boolean allTrue(boolean[] b) {
        boolean ret = b[0];
        for (int c = 1; c < b.length; c++) {
            ret = ret && b[c];
        }
        return ret;
    }

    public static boolean[] seen(int n) {
        boolean[] ret = new boolean[10];
        ret[n % 10] = true;
        if (n >= 10) {
            ret = combine(ret, seen(n / 10));
        }
        return ret;
    }

    public static boolean[] combine(boolean[] a, boolean[] b) {
        boolean[] ret = new boolean[10];
        for (int c = 0; c < 10; c++) {
            ret[c] = (a[c] || b[c]);
        }
        return ret;
    }
}