import java.io.*;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    private static InputStream inputStream;
    private static OutputStream outputStream;
    private static PrintWriter writer;
    private static InputReader reader;
    private static final int MAXN = 1 << 30;

    public static void main(String[] args) throws IOException {
        inputStream = new FileInputStream("E:\\in.txt");
        outputStream = new FileOutputStream("E:\\out.txt");
        reader = new InputReader(inputStream);
        writer = new PrintWriter(outputStream);
        new Main().main();
        writer.close();
    }

    private final static int[] prime = {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
            53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
            101, 103, 107, 109, 113, 127, 131, 137, 139, 149,
            151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
            211, 223, 227, 229, 233, 239, 241
    };

    private void main() {
        int T = reader.nextInt();
        for (int cas = 1; cas <= T; ++cas) {
            int n = reader.nextInt();
            int m = reader.nextInt();
            String result = String.format("Case #%d:\n", cas);
            writer.print(result);
            run(n, m);
        }
    }

    private void run(int n, int m) {
        int tot = 1 << (n - 2);
        int cnt = 0;
        for (int i = 0; i < tot; ++i) {
            boolean flag = true;
            ArrayList<Integer> list = new ArrayList<>();
            for (int j = 2; j <= 10 && flag; ++j) {
                flag &= calc(i, j, n, list);
            }
            if (flag) {
                cnt++;
                String num = Integer.toBinaryString(i);
                int r = (n - 2) - num.length();
                while (r > 0) {
                    --r;
                    num = "0" + num;
                }
                writer.print("1" + num + "1");
                for (Integer integer : list) {
                    writer.print(" " + integer);
                }
                writer.println();
                if (cnt >= m) {
                    return;
                }
            }

        }

    }

    private boolean calc(int num, int base, int n, ArrayList<Integer> list) {
        int N = prime.length;
        for (int i = 0; i < N; ++i) {
            int remain = 0, mul = 1, mod = prime[i];
            for (int j = 0; j < n - 1; ++j) {
                mul = (mul * base) % mod;
                if ((num >> j & 1) == 1) {
                    remain += mul;
                    remain %= mod;
                }
            }
           
            remain = (remain + mul + 1) % mod;
            if (remain == 0) {
                list.add(mod);
                return true;
            }
        }

        return false;
    }


}

class InputReader {
    private StringTokenizer tokenizer;
    private BufferedReader reader;

    public InputReader(InputStream inputStream) {
        tokenizer = null;
        reader = new BufferedReader(new InputStreamReader(inputStream));
    }


    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException();
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }
}
