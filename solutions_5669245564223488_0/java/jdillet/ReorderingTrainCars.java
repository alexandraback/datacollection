import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;

public class ReorderingTrainCars {

    private void processInput() throws IOException {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();

        for (int testCase = 1; testCase <= T; testCase++) {
            int n = in.nextInt();
            String[] str = new String[n];
            for (int i = 0; i < n; i++) {
                str[i] = in.next();
            }

            long res = go(n, str);

            System.out.printf(Locale.ENGLISH, "Case #%d: %d\n", testCase, res);         
        }

        in.close();
    }

    long MOD = 1000000007;
    long res;
    String[] str;
    private long go(int n, String[] str) {
        res = 0;
        this.str = str;
        
        int[] v = new int[n];
        for (int i = 0; i < n; i++) {
            v[i] = i;
        }
        
        permute(v, 0, n);

        return res;
    }

    private void permute(int[] v, int start, int n) {
        if (start == n - 1) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                sb.append(str[v[i]]);
            }
            if (isOk(sb.toString())) {
                res++;
            }
        } else {
            for (int i = start; i < n; i++) {
                swap(v, start, i);
                permute(v, start + 1, n);
                swap(v, start, i);
            }
        }
    }

    private boolean isOk(String s) {

        for (int i = 'a'; i <= 'z'; i++) {
            int last = -1;
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == i) {
                    if (last != -1 && last != j - 1) {
                        return false;
                    }
                    last = j;
                }
            }
        }
        return true;
    }

    private void swap(int[] v, int i, int j) {
        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;
    }

    public static void main(String[] args) throws Exception {
        ReorderingTrainCars main = new ReorderingTrainCars();
        main.processInput();
    }
}
