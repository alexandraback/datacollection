import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.*;

public class C {
    public static void main(String[] args) throws FileNotFoundException {
        FileInputStream fin = new FileInputStream("C-small-attempt0.in.txt");
        Scanner scanner = new Scanner(fin);
        FileOutputStream fout = new FileOutputStream("C-small-attempt0.out.txt");
        PrintWriter writer = new PrintWriter(fout);
        int testCount = scanner.nextInt();
        for (int testCase = 1; testCase <= testCount; ++testCase) {
            int n = scanner.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = scanner.nextInt() - 1;
            }

            writer.printf("Case #%d: %d\n", testCase, solve(a));
        }
        writer.close();
    }

    private static boolean nextPermutation(int[] array) {
        int i = array.length - 1;
        while (i > 0 && array[i - 1] >= array[i])
            i--;

        if (i <= 0)
            return false;

        int j = array.length - 1;
        while (array[j] <= array[i - 1])
            j--;

        int temp = array[i - 1];
        array[i - 1] = array[j];
        array[j] = temp;

        j = array.length - 1;
        while (i < j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }

        return true;
    }

    private static boolean check(int[] a, int i, int j, int k) {
        return a[i] == j || a[i] == k;
    }

    private static int solve(int[] a) {
        int n = a.length;
        int res = 0;
        for (int i = 0; i < (1 << n); ++i) {
            List<Integer> l = new ArrayList<>();
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j)) > 0) {
                    l.add(j);
                }
            }
            int k = l.size();
            if (k <= res) {
                continue;
            }
            int[] ar = new int[k];

            for (int j = 0; j < k; ++j) {
                ar[j] = l.get(j);
            }
            if (k == 3 && ar[0] == 1 && ar[1] == 2 && ar[2] == 3) {
                System.out.println();
            }
            do {
                boolean good = true;
                for (int j = 0; j < k && good; ++j) {
                    good = good && check(a, ar[j], ar[(j - 1 + k) % k], ar[(j + 1) % k]);
                }
                if (good) {
                    res = Math.max(res, k);
                    break;
                }
            } while (nextPermutation(ar));
        }
        return res;
    }
}
