
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * @author Abhimanyu Singh
 *
 */
public class Consonants {

    private InputStream input;
    private PrintStream output;
    private Scanner inputSc;
    private boolean isConsonent[];

    public Consonants(InputStream input, PrintStream output) {
        this.input = input;
        this.output = output;
        init();
    }

    private void init() {
        isConsonent = new boolean[26];
        for (int i = 0; i < 26; i++) {
            isConsonent[i] = true;
        }
        isConsonent['a' - 'a'] = false;
        isConsonent['e' - 'a'] = false;
        isConsonent['i' - 'a'] = false;
        isConsonent['o' - 'a'] = false;
        isConsonent['u' - 'a'] = false;
        inputSc = new Scanner(input);
    }

    static int lineToInt(String line) {
        return Integer.parseInt(line);
    }

    public void solve() {
        int testCaseCount = Integer.parseInt(inputSc.next());
        for (int testN = 1; testN <= testCaseCount; testN++) {
            solveTestCase(testN);
        }
    }

    private void solveTestCase(int testN) {
        String str = inputSc.next();
        int l = str.length();
        int n = Integer.parseInt(inputSc.next());
        int state = 0;
        int startIndex = 0;
        long ans = 0;
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            int index = ch - 'a';
            if (isConsonent[index]) {
                if (state < n) {
                    state++;
                }
            } else {
                state = 0;
            }
            if (state == n) {
                //found
                int foundStartIndex = i - n + 1;
                int foundEndIndex = i;
                long leftCount = foundStartIndex - startIndex + 1;
                long rightCount = l - foundEndIndex;
                ans += (leftCount * rightCount);
                startIndex = foundStartIndex + 1;
            }
        }
        output.println("Case #" + testN + ": " + ans);
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Consonants cs = new Consonants(System.in, System.out);
        cs.solve();
    }
}
