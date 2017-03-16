import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ManageEnergy {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int t = Integer.parseInt(br.readLine());
            for (int i = 0; i < t; i++) {
                System.out.println("Case #" + (i + 1) + ": " + find(br));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static long find(BufferedReader br) throws IOException {
        String[] line = br.readLine().split(" ");
        long e = Long.parseLong(line[0]);
        long r = Long.parseLong(line[1]);
        long n = Long.parseLong(line[2]);
        line = br.readLine().split(" ");
        long[] vs = new long[(int)n];
        for (int i = 0; i < vs.length; i++) {
            vs[i] = Long.parseLong(line[i]);
        }
        if (r >= e) {
            long sum = 0;
            for (int i = 0; i < vs.length; i++) {
                sum += vs[i];
            }
            return sum * e;
        }
        return find(e, r, vs, n-1);
    }

    private static long find(long e, long r, long[] vs, long n) {
        long mx = 0;
        if (n == 0) return e*vs[0];
        for (long i = r; i <= e; i++) {
            mx = Math.max(mx, vs[(int)n]*i + find(e-(i-r), r, vs, n-1));
        }
        return mx;
    }
}
