
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * @author Abhimanyu Singh
 *
 */
public class B {

    private InputStream input;
    private PrintStream output;
    private Scanner inputSc;

    public B(InputStream input, PrintStream output) {
        this.input = input;
        this.output = output;
        init();
    }

    private void init() {
        inputSc = new Scanner(input);
    }

    static int lineToInt(String line) {
        return Integer.parseInt(line);
    }

    public void solve() {
        int testCaseCount = lineToInt(inputSc.nextLine());
        for (int testN = 1; testN <= testCaseCount; testN++) {
            solveTestCase(testN);
        }
    }

    private void solveTestCase(int testN) {
        Scanner tempSc = new Scanner(inputSc.nextLine());
        int A = tempSc.nextInt();
        int B = tempSc.nextInt();
        int K = tempSc.nextInt();
        int ans = 0;
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                if ((i & j) < K) {
                    ans++;
                }
            }
        }
        output.println("Case #" + testN + ": " + ans);
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        B b = new B(System.in, System.out);
        b.solve();
    }
}
