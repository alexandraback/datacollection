import java.io.*;
import java.util.*;

public class C implements Runnable {

    private static final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;

    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer tok = new StringTokenizer("");

    private void init() throws FileNotFoundException {
        Locale.setDefault(Locale.US);
        String fileName = "";
        if (ONLINE_JUDGE && fileName.isEmpty()) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else {
            if (fileName.isEmpty()) {
                in = new BufferedReader(new FileReader("input.txt"));
                out = new PrintWriter("output.txt");
            } else {
                in = new BufferedReader(new FileReader(fileName + ".in"));
                out = new PrintWriter(fileName + ".out");
            }
        }
    }

    String readString() {
        while (!tok.hasMoreTokens()) {
            try {
                tok = new StringTokenizer(in.readLine());
            } catch (Exception e) {
                return null;
            }
        }
        return tok.nextToken();
    }

    int readInt() {
        return Integer.parseInt(readString());
    }

    long readLong() {
        return Long.parseLong(readString());
    }

    double readDouble() {
        return Double.parseDouble(readString());
    }

    int[] readIntArray(int size) {
        int[] a = new int[size];
        for (int i = 0; i < size; i++) {
            a[i] = readInt();
        }
        return a;
    }

    public static void main(String[] args) {
        //new Thread(null, new _Solution(), "", 128 * (1L << 20)).start();
        new C().run();
    }

    long timeBegin, timeEnd;

    void time() {
        timeEnd = System.currentTimeMillis();
        System.err.println("Time = " + (timeEnd - timeBegin));
    }

    @Override
    public void run() {
        try {
            timeBegin = System.currentTimeMillis();
            init();
            solve();
            out.close();
            time();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }

    String caseNum(int number) {
        return "Case #" + number + ": ";
    }

    int[] friends;

    int answer = 1;

    List<int[]>[] permutations;

    void permute(int[] arr, int k) {
        for (int i = k; i < arr.length; i++) {
            int t = arr[k];
            arr[k] = arr[i];
            arr[i] = t;
            permute(arr, k + 1);
            t = arr[k];
            arr[k] = arr[i];
            arr[i] = t;
        }
        if (k == arr.length - 1) {
            permutations[arr.length].add(Arrays.copyOf(arr, arr.length));
        }
    }

    private void solve() {

        permutations = new List[11];
        for (int length = 1; length <= 10; length++) {
            permutations[length] = new ArrayList<>();
            int[] permutation = new int[length];
            for (int i = 0; i < length; i++) {
                permutation[i] = i;
            }
            permute(permutation, 0);
        }

        int T = readInt();
        for (int test = 1; test <= T; test++) {
            answer = 0;
            int n = readInt();
            friends = new int[n];
            for (int i = 0; i < n; i++) {
                friends[i] = readInt() - 1;
            }

            for (int[] p : permutations[n]) {
                int k = n;
                for (int i = 0; i < k; i++) {
                    for (int j = i + 1; j < k; j++) {
                        boolean good = true;
                        for (int l = i; l <= j; l++) {
                            int left = l > i ? p[l - 1] : p[j];
                            int right = l < j ? p[l + 1] : p[i];
                            good &= (left == friends[p[l]] || right == friends[p[l]]);
                        }
                        if (good) {
                            answer = Math.max(answer, j - i + 1);
                        }
                    }
                }
            }

            out.println(caseNum(test) + answer);
        }
    }
}
