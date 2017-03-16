
import codejam.StoreCredit;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author java
 */
public class DancingGooglers {

    static BufferedReader in;

    private static void open() {
        in = new BufferedReader(new InputStreamReader(System.in));
    }

    private static void close() {
        try {
            in.close();
        } catch (IOException ex) {
            Logger.getLogger(StoreCredit.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private static int readInt() throws IOException {
        Integer i = Integer.parseInt(in.readLine());
        return i;
    }

    private static int[] readInts() throws IOException {
        String[] vals = in.readLine().split(" ");
        int[] arr = new int[vals.length];
        for (int i = 0; i < vals.length; i++) {
            arr[i] = Integer.parseInt(vals[i]);
        }
        return arr;
    }

    public static void main(String[] args) throws IOException {
        open();
        int T = readInt();
        for (int t = 0; t < T; t++) {
            int[] line = readInts();
            int N = line[0];
            int s = line[1];
            int p = line[2];
            int pCount = 0;
            int[] scores = new int[line.length - 3];
            System.arraycopy(line, 3, scores, 0, scores.length);
            if (p == 0) {
                pCount = scores.length;
            } else {
                for (int i = 0; i < scores.length; i++) {
                    int score = scores[i];
                    int minSum = p + (2 * (p - 2) < 0 ? 0 : 2 * (p - 2));
                    if (p == 1) {
                        if (score >= p) {
                            pCount++;
                        }
                    } else if ((score == minSum || score == minSum + 1) && s > 0) {
                        pCount++;
                        s--;
                    } else if (score > minSum + 1) {
                        pCount++;
                    }
                }
            }
            System.out.println("Case #" + (t + 1) + ": " + pCount);
        }

        close();
    }
}
