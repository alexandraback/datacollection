import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class RecycledNumbers {
    private PrintWriter out;
    private Scanner in;

    private void init() {
    }

    private void solve() {
        int A = in.nextInt();
        int B = in.nextInt();

        int r = 0;
        for (int i = A; i <= B; i++) {
            int j = rotate(i);
            while (i != j) {
                if (i < j && j <= B) {
                    r++;
                }
                j = rotate(j);
            }
        }
        out.println(r);
    }

    private int rotate(int number) {
        int pos = 1;
        while (number % 10 == 0) {
            pos *= 10;
            number /= 10;
        }
        int rest = number % 10;
        number /= 10;
        int numberCopy = number;
        while (numberCopy > 0) {
            pos *= 10;
            numberCopy /= 10;
        }
        return rest * pos + number;
    }

    private void runTests() {
        init();

        int T = Integer.parseInt(in.nextLine());
        for (int i = 0; i < T; i++) {
            out.print("Case #" + (i + 1) + ": ");
            solve();
        }
    }

    private void run() {
        try {
            runTests();
        } finally {
            close();
        }
    }

    private void close() {
        out.close();
        in.close();
    }

    public RecycledNumbers() throws FileNotFoundException {
        this.in = new Scanner(new File("C-small-attempt0.in"));
        this.out = new PrintWriter(new File("C-small-attempt0.out"));
    }

    public static void main(String[] args) throws FileNotFoundException {
        new RecycledNumbers().run();
    }
}
