
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.BitSet;
import java.util.Formatter;
import java.util.Locale;

/**
 *
 * @author edemairy
 */
public class Main {

    private int nbTC;
    private StringBuilder result = new StringBuilder();

    private static class EndException extends RuntimeException {
    }

    public void run() throws IOException {
        //        Scanner scanner = new Scanner(System.in);
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        nbTC = readInt(reader);
//         nbTC = Integer.MAX_VALUE;
//        scanner.nextLine();
        try {
            for (int tc = 1; tc <= nbTC; ++tc) {
                result.append("Case #" + tc + ": ");
                result.append(oneTestCase(reader));
                result.append('\n');
            }
        } catch (EndException e) {
        }
        System.out.print(result);
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        Main main = new Main();
        main.run();
    }

    public long gcd(long A, long B) {
        BigInteger b1 = BigInteger.valueOf(A); // there's a better way to do this. I forget.
        BigInteger b2 = BigInteger.valueOf(B);
        BigInteger gcd = b1.gcd(b2);
        return gcd.longValue();
    }

    private StringBuilder oneTestCase(BufferedReader reader) throws IOException {
        Formatter formatter = new Formatter(Locale.ENGLISH);
        StringBuilder output = new StringBuilder();
//        for (int i = 0; i < 5; ++i) {
//            formatter.format("%3d", n[i]);
//        }

        String[] parts = reader.readLine().split("/");
        long A = Long.parseLong(parts[0]);
        long B = Long.parseLong(parts[1]);
        long f = gcd(A, B);
        A /= f;
        B /= f;

        if (Long.bitCount(B) != 1) {
            formatter.format("impossible");
        } else {

            boolean possible = false;
            int r = 1;
            while (A < B) {
                B >>= 1;
                if (A - B >= 0) {
                    possible = true;
                    break;
                }
                r++;
            }
            if (possible) {
                formatter.format("%d", r);
            } else {
                formatter.format("impossible");
            }
        }
        output.append(formatter.out());
        return output;
    }

    private int readInt(BufferedReader reader) throws IOException {
        int r = 0;
        boolean positive = true;
        char currentChar = (char) reader.read();

        while ((currentChar == ' ') || (currentChar == '\n')) {
            currentChar = (char) reader.read();
        }
        if (currentChar == (char) -1) {
            throw new IOException("end of stream");
        }
        if (currentChar == '-') {
            positive = false;
            currentChar = (char) reader.read();
        }
        while ((currentChar >= '0') && (currentChar <= '9')) {
            r = r * 10 + currentChar - '0';
            currentChar = (char) reader.read();
        }
        if (positive) {
            return r;
        } else {
            return -r;
        }
    }

    private long readLong(BufferedReader reader) throws IOException {
        long r = 0;
        boolean positive = true;
        char currentChar = (char) reader.read();

        while ((currentChar == ' ') || (currentChar == '\n')) {
            currentChar = (char) reader.read();
        }
        if (currentChar == (char) -1) {
            throw new IOException("end of stream");
        }
        if (currentChar == '-') {
            positive = false;
            currentChar = (char) reader.read();
        }
        while ((currentChar >= '0') && (currentChar <= '9')) {
            r = r * 10 + currentChar - '0';
            currentChar = (char) reader.read();
        }
        if (positive) {
            return r;
        } else {
            return -r;
        }
    }

    private char readChar(BufferedReader reader) throws IOException {
        return (char) reader.read();
    }
}
