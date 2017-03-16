import java.io.*;
import java.util.StringTokenizer;

public class A implements Runnable {
    private static BufferedReader reader;
    private static StringTokenizer st;

    public static void main(String[] args) {
        new Thread(new A()).start();
    }

    @Override
    public void run() {
        try {
            solve();
        } catch (IOException e) {}
    }

    private void solve() throws IOException {
        reader = new BufferedReader(new FileReader("a.in"));
        PrintWriter writer = new PrintWriter(new FileWriter("a.out"));

        int n = nextInt();
        for (int i = 1; i <= n; i++) {
            int alreadyTyped = nextInt();
            int wholeLength = nextInt();
            double[] typed = new double[alreadyTyped];
            for (int j = 0; j < alreadyTyped; j++) {
                typed[j] = nextDouble();
            }
            double ans = calcAns(alreadyTyped, wholeLength, typed);
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

    static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    static double calcAns(int alreadyTyped, int wholeLength, double[] t) {
        int numOfVariants = (1 << alreadyTyped);
        Variant[] variants = new Variant[numOfVariants];
        switch (alreadyTyped) {
            case 1:
                variants[0] = new Variant(wholeLength, new int[] {}, t);
                variants[1] = new Variant(wholeLength, new int[] {0}, t);
                break;
            case 2:
                variants[0] = new Variant(wholeLength, new int[] {}, t);
                variants[1] = new Variant(wholeLength, new int[] {0}, t);
                variants[2] = new Variant(wholeLength, new int[] {1}, t);
                variants[3] = new Variant(wholeLength, new int[] {0, 1}, t);
                break;
            case 3:
                variants[0] = new Variant(wholeLength, new int[] {}, t);
                variants[1] = new Variant(wholeLength, new int[] {0}, t);
                variants[2] = new Variant(wholeLength, new int[] {1}, t);
                variants[3] = new Variant(wholeLength, new int[] {0, 1}, t);
                variants[4] = new Variant(wholeLength, new int[] {2}, t);
                variants[5] = new Variant(wholeLength, new int[] {0, 2}, t);
                variants[6] = new Variant(wholeLength, new int[] {1, 2}, t);
                variants[7] = new Variant(wholeLength, new int[] {0, 1, 2}, t);
                break;
        }
        double min = wholeLength + 2;
        for (int i = 0; i <= alreadyTyped; i++) {
            double ans = 0;
            for (Variant a : variants) {
                ans += a.getProbability(i);
            }
            if (ans < min) {
                min = ans;
            }
        }

        return min;
    }

    static class Variant {
        int len;
        int wholeLen;
        int[] indexes;
        double chance;

        public Variant(int wholeLen, int[] indexes, double[] probabilities) {
            this.wholeLen = wholeLen;
            this.len = probabilities.length;
            this.indexes = indexes;
            chance = 1;
            int indexesCnt = 0;
            for (int i = 0; i < len; i++) {
                if (indexes.length > 0 && i == indexes[indexesCnt]) {
                    if (indexesCnt < indexes.length - 1) {
                        indexesCnt++;
                    }
                    chance *= (1 - probabilities[i]);
                }
                else {
                    chance *= probabilities[i];
                }
            }
        }

        public int getNumOfSteps(int removeElements) {
            if (indexes.length != 0 && indexes[0] < len - removeElements) {
                return 2 * removeElements + 2 * wholeLen - len + 2;
            } else {
                return 2 * removeElements + wholeLen - len + 1;
            }
        }

        public double getProbability(int removeElements) {
            return chance * getNumOfSteps(removeElements);
        }

    }

}