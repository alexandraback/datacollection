import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class ProblemC {

    private long a;

    private long b;

    private static final TreeSet<Long> fair = new TreeSet<Long>();

    static {
        for (int i = 1; i <= 1e7; i++) {
            if (palindrome(i)) {
                long sqr = i;
                sqr *= i;
                if (palindrome(sqr)) {
                    fair.add(((long) i));
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
//        Scanner scanner = new Scanner(System.in);
//        Scanner scanner = new Scanner(new File("input.txt"));
        Scanner scanner = new Scanner(new File("/home/cata/Downloads/C-large-1.in"));

        PrintStream out = new PrintStream("output.txt");
        int T = scanner.nextInt();
        for (int test = 1; test <= T; test++) {
            ProblemC instance = new ProblemC();
            instance.read(scanner);
            int count = instance.getCount();
            out.println("Case #" + test + ": " + count);
            System.out.println("Case #" + test + ": " + count);
        }
    }

    private void read(Scanner scanner) {
        a = scanner.nextLong();
        b = scanner.nextLong();
    }

    private int getCount() {
        long low = fair.ceiling((long) Math.ceil(Math.sqrt(a)));
        long high = fair.floor((long) Math.sqrt(b));
        if (low > high) {
            return 0;
        } else {
            Set<Long> fairNumbersInInterval = fair.subSet(low, true, high, true);
            return fairNumbersInInterval.size();
        }
    }

    private static boolean palindrome(long number) {
        char[] str = String.valueOf(number).toCharArray();
        for (int i = 0; i < str.length / 2; i++) {
            if (str[i] != str[str.length - 1 - i]) {
                return false;
            }
        }
        return true;
    }

}
