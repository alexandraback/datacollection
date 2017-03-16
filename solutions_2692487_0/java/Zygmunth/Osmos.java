import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.Writer;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class Osmos {
    static int solve(long a, long[] ms, int i, int n) {
        if (i==n) {
            return 0;
        }
        if (ms[i] < a) {
            a = a+ms[i];
            return solve(a,ms,i+1,n);
        }
        int whenRemoving = n - i;
        int insertCount = 0;
        if (a<2) {
            return whenRemoving;
        }
        while (a <= ms[i]) {
            a += a-1;
            insertCount++;
        }
        a+= ms[i];
        int whenInserting = insertCount + solve(a,ms,i+1,n);
        return Math.min(whenInserting,whenRemoving);
    }
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        InputStream resourceAsStream = Osmos.class.getClassLoader().getResourceAsStream("in.txt");
        Scanner scanner = new Scanner(resourceAsStream);
        Writer out = new FileWriter("c:\\temp\\2013.txt");

        int tcc = scanner.nextInt();
        for (int ci = 0; ci < tcc; ci++) {
            long a = scanner.nextLong();
            int n = scanner.nextInt();
            long[] ms = new long[n];
            for (int i = 0; i < n; i++) {
                ms[i] = scanner.nextLong();
            }
            Arrays.sort(ms);
            int minC = solve(a,ms,0,n);
            String res = String.format("Case #%d: %d\n", ci + 1, minC);
            out.write(res);

        }
        out.close();
        return;
    }
}
