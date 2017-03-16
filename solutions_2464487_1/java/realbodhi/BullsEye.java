import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BullsEye {
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
        String[] rt = br.readLine().split(" ");
        long r = Long.parseLong(rt[0]);
        long t = Long.parseLong(rt[1]);
        long n = 1;

        while (true) {
            long n2 = n*n;
            if (n2 < n || n2 > t) break;
            long n3 = n2*2;
            if (n3 < n2 || n3 > t) break;
            n3 -= n;
            n2 = 2*n*r;
            if (n2 < n || n2 < r || n2 > t) break;
            n2 = n3 + n2;
            if (n2 < n3 || n2 > t) break;
            n3 = n * 2;
            if (n3 < n) break;
            n = n3;
        }
        if (n == 1) return 1;
        long start = n/2;
        long end = n;

        long mx = 0;
        while (start <= end) {
            n = start + (end-start)/2;
            long n2 = n*n;
            if (n2 < n || n2 > t) {end = n-1; if (end == mx) return end; else continue;}
            long n3 = n2*2;
            if (n3 < n2 || n3 > t) {end = n-1; if (end == mx) return end; else continue;}
            n3 -= n;
            n2 = 2*n*r;
            if (n2 < n || n2 < r || n2 > t) {end = n-1; if (end == mx) return end; else continue;}
            n2 = n3 + n2;
            if (n2 < n3 || n2 > t) {end = n-1; if (end == mx) return end; else continue;}
            if (n2 <= t) {
                start = n+1;
                mx = Math.max(mx, n);
            }
        }
        return mx;
    }
}
