import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class ProblemC {

    private long a;

    private long b;

    public static void main(String[] args) throws Exception {
//        Scanner scanner = new Scanner(System.in);
//        Scanner scanner = new Scanner(new File("input.txt"));
        Scanner scanner = new Scanner(new File("/home/cata/Downloads/C-small-attempt0.in"));
        PrintStream out = new PrintStream("output.txt");
        int T = scanner.nextInt();
        for (int test = 1; test <= T; test++) {
            ProblemC instance = new ProblemC();
            instance.read(scanner);
            out.println("Case #" + test + ": " + instance.getCount());
            System.out.println("Case #" + test + ": " + instance.getCount());
        }
    }

    private void read(Scanner scanner) {
        a = scanner.nextLong();
        b = scanner.nextLong();
    }

    private int getCount() {
        int count = 0;
        int low = (int) Math.sqrt(a);
        if (low * low < a) {
            low++;
        }
        int high = (int) Math.sqrt(b);
        for (int i = low; i <= high; i++) {
            if (palindrome(i)) {
                long sqr = i;
                sqr *= i;
                if (palindrome(sqr)) {
                    count++;
                }
            }
        }
        return count;
    }

    private boolean palindrome(long number) {
        char[] str = String.valueOf(number).toCharArray();
        for (int i = 0; i < str.length / 2; i++) {
            if (str[i] != str[str.length - 1 - i]) {
                return false;
            }
        }
        return true;
    }

}
