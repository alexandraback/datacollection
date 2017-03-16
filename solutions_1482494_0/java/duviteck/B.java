import java.io.*;
import java.util.StringTokenizer;

public class B implements Runnable {
    private static BufferedReader reader;
    private static StringTokenizer st;

    public static void main(String[] args) {
        new Thread(new B()).start();
    }

    @Override
    public void run() {
        try {
            solve();
        } catch (IOException e) {}
    }

    private void solve() throws IOException {
        reader = new BufferedReader(new FileReader("b.in"));
        PrintWriter writer = new PrintWriter(new FileWriter("b.out"));

        int n = nextInt();
        for (int i = 1; i <= n; i++) {
            int lines = nextInt();
            int[] numA = new int[lines];
            int[] numB = new int[lines];
            for (int j = 0; j < lines; j++) {
                numA[j] = nextInt();
                numB[j] = nextInt();
            }
            //System.out.println("Test #" + i);
            String ans = calcAns(lines, numA, numB);

            writer.println("Case #" + i + ": " + ans);
        }

        writer.close();
    }

    static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(reader.readLine());
        }
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    static String calcAns(int numOfLines, int[] star1, int[] star2) {
        int curStar = 0;
        int curSteps = 0;
        boolean changesAreMade = true;
        while (changesAreMade && curStar < 2 * numOfLines) {
            changesAreMade = false;
            int index = -1;
            for (int i = 0; i < numOfLines; i++) {
                if (star2[i] >= 0 && star2[i] <= curStar) {
                    if (star1[i] >= 0) {
                        //System.out.println("2 at once: " + i);
                        star2[i] = -1;
                        star1[i] = -1;
                        curStar += 2;
                        curSteps ++;
                        changesAreMade = true;
                        break;
                    } else {
                        index = i;
                    }
                }
            }
            if (changesAreMade) {
                continue;
            }
            if (index >= 0) {
                //System.out.println("star2 at " + index);
                star2[index] = -1;
                curStar++;
                curSteps++;
                changesAreMade = true;
                continue;
            }
            int max = -1;
            int maxIndex = -1;
            for (int i = 0; i < numOfLines; i++) {
                if (star1[i] >= 0 && star1[i] <= curStar) {
                    if (star2[i] > max) {
                        maxIndex = i;
                        max = star2[i];
                    }
                }
            }
            if (maxIndex >= 0) {
                star1[maxIndex] = -1;
                //System.out.println("star1 at " + maxIndex);
                curStar++;
                curSteps++;
                changesAreMade = true;
            }
        }
        if (curStar < 2 * numOfLines) {
            return "Too Bad";
        } else {
            return String.valueOf(curSteps);
        }
    }

}