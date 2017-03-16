import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by vitalii on 30.04.2016.
 */
public class B {
    PrintWriter out;
    Scanner in;


    long bestL, bestR;

    public void solveStupid() {
        int[] first = fFirst;
        int[] second = fSecond;
        int pow = 1;
        for (int i = 0; i < first.length; i++) {
            pow *= 10;
        }
        bestL = 0;
        bestR = Long.MAX_VALUE / 2;
        for (int i = 0; i < pow; i++) {
            for (int j = 0; j < pow; j++) {
                if (valid(i,first) && valid(j, second)) {
                    update(i,j);
                }
            }
        }
        out.println(toStr(bestL,first.length) + " " + toStr(bestR,first.length));
    }

    private boolean valid(int n, int[] first) {
        for (int i = first.length-1; i>=0; i--) {
            if (first[i] != '?' && first[i] !=n %10) {
                return  false;
            }
            n /= 10;
        }
        return true;
    }

    int[] fFirst;
    int[] fSecond;

    public void solve() {
        int[] first = readDigNumber();
        int[] second = readDigNumber();
        fFirst  = first.clone();
        fSecond = second.clone();
        bestL = 0;
        bestR = Long.MAX_VALUE / 2;

        for (int i = 0; i < first.length; i++) {
            if (first[i] != '?' && second[i] != '?') {
                if (first[i] > second[i]) {
                    update(getVal(fillZero(first)), getVal(fillNine(second)));
                    break;
                }
                if (first[i] < second[i]) {
                    update(getVal(fillNine(first)), getVal(fillZero(second)));
                    break;
                }
            } else if (first[i] == '?' && second[i] == '?') {
                int[] firstClone = first.clone();
                int[] secondClone = second.clone();
                firstClone[i] = 1;
                secondClone[i] = 0;
                update(getVal(fillZero(firstClone)), getVal(fillNine(secondClone)));
                firstClone = first.clone();
                secondClone = second.clone();
                firstClone[i] = 0;
                secondClone[i] = 1;
                update(getVal(fillNine(firstClone)), getVal(fillZero(secondClone)));
                first[i] = 0;
                second[i] = 0;
            } else if (first[i] == '?') {
                if (second[i] < 9) {
                    int[] firstClone = first.clone();
                    int[] secondClone = second.clone();
                    firstClone[i] = second[i] + 1;
                    update(getVal(fillZero(firstClone)), getVal(fillNine(secondClone)));
                }
                if (second[i] > 0) {
                    int[] firstClone = first.clone();
                    int[] secondClone = second.clone();
                    firstClone[i] = second[i] - 1;
                    update(getVal(fillNine(firstClone)), getVal(fillZero(secondClone)));
                }
                first[i] = second[i];
            } else {
                if (first[i] < 9) {
                    int[] firstClone = first.clone();
                    int[] secondClone = second.clone();
                    secondClone[i] = first[i] + 1;
                    update(getVal(fillNine(firstClone)), getVal(fillZero(secondClone)));
                }
                if (first[i] > 0) {
                    int[] firstClone = first.clone();
                    int[] secondClone = second.clone();
                    secondClone[i] = first[i] - 1;
                    update(getVal(fillZero(firstClone)), getVal(fillNine(secondClone)));
                }
                second[i] = first[i];
            }
        }
        update(getVal(fillZero(first)), getVal(fillNine(second)));
        out.print(toStr(bestL,first.length) + " " + toStr(bestR,first.length));
    }

    private int[] readDigNumber() {
        String str = in.next();
        int[] ans = new int[str.length()];
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '?') {
                ans[i] = str.charAt(i);
            } else {
                ans[i] = str.charAt(i) - '0';
            }
        }
        return ans;
    }

    private String toStr(long bestL, int length) {
        String ans = "";
        for (int i = 0; i < length; i++) {
            ans = bestL % 10L + ans;
            bestL /= 10;
        }
        return ans;
    }

    private void update(long f, long r) {
        if (Math.abs(r - f) < Math.abs(bestR - bestL) || (Math.abs(r - f) == Math.abs(bestR - bestL) && f < bestL)
                || (Math.abs(r - f) == Math.abs(bestR - bestL) && f == bestL && r < bestR)) {
            bestL = f;
            bestR = r;
        }
    }

    private long getVal(int[] a) {
        long ans = 0;
        for (int i = 0; i < a.length; i++) {
            ans = ans * 10L + a[i];
        }
        return ans;
    }

    private int[] fillNine(int[] second) {
        for (int i = 0; i < second.length; i++) {
            if (second[i] == '?') {
                second[i] = 9;
            }
        }
        return second;
    }

    private int[] fillZero(int[] firstClone) {
        for (int i = 0; i < firstClone.length; i++) {
            if (firstClone[i] == '?') {
                firstClone[i] = 0;
            }
        }
        return firstClone;
    }

    public void run() throws IOException {
        in = new Scanner(new File("B.in"));
        out = new PrintWriter("B.out");
        int t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            System.err.println(i);
            out.print("Case #" + i + ": ");
            solve();
//            out.print(" ");
//            solveStupid();
            out.println();
        }
        in.close();
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new B().run();
    }
}
