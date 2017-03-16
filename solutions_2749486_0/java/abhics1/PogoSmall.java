
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * @author Abhimanyu Singh
 *
 */
public class PogoSmall {
    
    private InputStream input;
    private PrintStream output;
    private Scanner inputSc;
    
    public PogoSmall(InputStream input, PrintStream output) {
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
        int testCaseCount = inputSc.nextInt();
        for (int testN = 1; testN <= testCaseCount; testN++) {
            solveTestCase(testN);
        }
    }
    
    String getMoveString(int d, char positiveMove, char negativeMove) {
        String ans = "";        
        if (d == 0) {
        } else if (d < 0) {
            // d ------- 0 ----- 
            // first move in positive direction
            for (int i = 0; i < (-d); i++) {
                ans += positiveMove;
                ans += negativeMove;
            }
        } else {
            // d>0
            //  ------- 0 -----d
            // first move in negative direction
            for (int i = 0; i < d; i++) {
                ans += negativeMove;
                ans += positiveMove;
            }
        }
        return ans;
    }
    
    private void solveTestCase(int testN) {
        int X = inputSc.nextInt();
        int Y = inputSc.nextInt();
        char positiveX = 'E';
        char negativeX = 'W';
        char positiveY = 'N';
        char negativeY = 'S';
        String ans = getMoveString(X, positiveX, negativeX) + getMoveString(Y, positiveY, negativeY);
        output.println("Case #" + testN + ": " + ans);
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        PogoSmall ps = new PogoSmall(System.in, System.out);
        ps.solve();
    }
}
