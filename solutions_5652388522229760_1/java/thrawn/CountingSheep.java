import java.io.BufferedReader;
import java.io.InputStreamReader;

public class CountingSheep {

    public static void main(String[] args) throws Exception {
        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int t = Integer.parseInt(br.readLine());
        for (int i = 1; i <= t; i++) {
            final long value =  Long.parseLong(br.readLine());
            if (value == 0L) {
                System.out.println("Case #" + i + ": INSOMNIA");
                continue;
            }
            
            final long result = process(value, 1, new boolean[10], 0);
            System.out.println("Case #" + i + ": " + result);
        }
    }

    public static long process(final long value, final int i, final boolean[] digits, int seen) {
        long current = value * i;
        while (current > 0L) {
            int digit = (int) (current % 10);
            if (!digits[digit]) {
                digits[digit] = true;
                seen++;
                if (seen >= 10) {
                    return value * i;
                }
            }
            current = current / 10;
        }
        return process(value, i+1, digits, seen);
    }
}
