
import java.io.InputStream;
import java.io.PrintStream;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;

/**
 * @author Abhimanyu Singh
 *
 */
public class TheGreatWallSmall {

    private InputStream input;
    private PrintStream output;
    private Scanner inputSc;

    public TheGreatWallSmall(InputStream input, PrintStream output) {
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

    private void solveTestCase(int testN) {
        int count = inputSc.nextInt();
        long firstAttackDay[] = new long[count];
        long nAttack[] = new long[count];
        long firstW[] = new long[count]; // left
        long firstE[] = new long[count]; // right
        long firstStrength[] = new long[count];
        long deltaDay[] = new long[count];
        long deltaMove[] = new long[count];
        long deltaStrength[] = new long[count];
        for (int i = 0; i < count; i++) {
            firstAttackDay[i] = inputSc.nextLong();
            nAttack[i] = inputSc.nextLong();
            firstW[i] = inputSc.nextLong();
            firstE[i] = inputSc.nextLong();
            firstStrength[i] = inputSc.nextLong();
            deltaDay[i] = inputSc.nextLong();
            deltaMove[i] = inputSc.nextLong();
            deltaStrength[i] = inputSc.nextLong();
        }
        long nextAttackDay[] = new long[count];
        long nextStrength[] = new long[count];
        long nextW[] = new long[count];
        long nextE[] = new long[count];
        long attackDayLimit[] = new long[count];
        for (int i = 0; i < count; i++) {
            nextAttackDay[i] = firstAttackDay[i];
            nextStrength[i] = firstStrength[i];
            nextW[i] = firstW[i];
            nextE[i] = firstE[i];
            attackDayLimit[i] = firstAttackDay[i] + (nAttack[i] - 1) * deltaDay[i];
        }
        long MAX_DAY = 676060;
        long attackCount = 0;
        long wall[] = new long[10000]; // -5000  +5000
        for (int day = 0; day <= MAX_DAY; day++) {
            // find attack
            for (int i = 0; i < count; i++) {
                if (nextAttackDay[i] == day) {
                    long w = nextW[i];
                    long e = nextE[i];
                    for (long index = w; index < e; index++) {
                        int ii = ((int) index) + 5000;
                        if (wall[ii] < nextStrength[i]) {
                            attackCount++;
                            break;
                        }
                    }
                }
            }
            // rebuild wall
            for (int i = 0; i < count; i++) {
                if (nextAttackDay[i] == day) {
                    long w = nextW[i];
                    long e = nextE[i];
                    for (long index = w; index < e; index++) {
                        int ii = ((int) index) + 5000;
                        if (wall[ii] < nextStrength[i]) {
                            wall[ii] = nextStrength[i];
                        }
                    }
                    //update info
                    if (nextAttackDay[i] < attackDayLimit[i]) {
                        nextAttackDay[i] += deltaDay[i];
                        nextW[i] += deltaMove[i];
                        nextE[i] += deltaMove[i];
                        nextStrength[i] += deltaStrength[i];
                    }
                }
            }

        }
        output.println("Case #" + testN + ": " + attackCount);
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        TheGreatWallSmall tgws = new TheGreatWallSmall(System.in, System.out);
        tgws.solve();
    }
}
