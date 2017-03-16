import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class A implements Runnable {
    private static BufferedReader reader;
    private static StringTokenizer st;
    private static int[] data;

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
            int k = nextInt();
            int sum = 0;
            data = new int[k];
            for (int j = 0; j < k; j++) {
                int temp = nextInt();
                sum += temp;
                data[j] = temp;
            }
            double[] ans = calcAns(sum);
            writer.print("Case #" + i + ":");
            for (int j = 0; j < k; j++) {
                writer.print(" " + ans[j]);
            }
            writer.println();
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

    static double[] calcAns(int sum) {
        int len = data.length;
        double[] ans = new double[len];
        double curSum = 2 * sum;
        double curElems = len;
        double middleSum = curSum / curElems;
        Set<Integer> zeroAns = new HashSet<Integer>(len);
        int cnt = 0;
        while (cnt < len) {
            if (zeroAns.contains(cnt)) {
                cnt++;
            } else if (data[cnt] > middleSum) {
                zeroAns.add(cnt);
                curSum -= data[cnt];
                curElems--;
                middleSum = curSum / curElems;
                cnt = 0;

            } else {
                cnt++;
            }
        }
        for (int i = 0; i < len; i++) {
            ans[i] = (middleSum - data[i]) / sum * 100;
        }
        for (int a : zeroAns) {
            ans[a] = 0.0;
        }

//        double localSum = 0;
//        for (int i = 0; i < len; i++) {
//            double localAns = 1;
//            for (int j = 0; j < len; j++) {
//                if (i != j) {
//                    localAns = Math.min(localAns, (double)(data[j] - data[i] + sum) / (double)(2 * sum));
//                }
//            }
//            ans[i] = localAns;
//            localSum += localAns;
//        }
//        for (int i = 0; i < len; i++) {
//            ans[i] = ans[i] / localSum * 100;
//        }
        return ans;
    }
}