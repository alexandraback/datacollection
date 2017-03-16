import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class ProblemA {
    private final int n;

    public ProblemA(int n) {
        this.n = n;
    }

    public String solution() {
        if (n == 0) return "INSOMNIA";
        int digits = getDigits(n);
        int last = n;
        int expected = (1 << 10) - 1;
        while (digits != expected) {
            last += n;
            digits |= getDigits(last);
        }
        return last + "";
    }

    private int getDigits(int n) {
        if (n == 0) return 0;
        return (1 << (n % 10)) | getDigits(n / 10);
    }

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("A.in"));
//        PrintStream out = System.out;
        PrintStream out = new PrintStream("A.out");
        int TOTAL_TESTS = in.nextInt();
        for (int t = 1; t <= TOTAL_TESTS; t++) {
            int n = in.nextInt();
            out.println("Case #" + t + ": " + new ProblemA(n).solution());
        }
    }

}
