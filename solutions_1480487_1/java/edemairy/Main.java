
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Formatter;
import java.util.Locale;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author edemairy
 */
public class Main {

    private final static Logger logger = Logger.getLogger(Main.class.getName());
    private static int nbTC;
    private static StringBuilder result = new StringBuilder();

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        logger.setLevel(Level.OFF);
//        Scanner scanner = new Scanner(System.in);
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        nbTC = readInt(reader);
//        scanner.nextLine();
        for (int tc = 1; tc <= nbTC; ++tc) {
            result.append("Case #");
            result.append(tc);
            result.append(": ");
            result.append(oneTestCase(reader));
            result.append('\n');
        }
        System.out.print(result);
    }
    public static int[] J = new int[200];
    public static int[] J2 = new int[200];
    public static int N;
    public static int X;

    private static StringBuilder oneTestCase(BufferedReader reader) throws IOException {
        Formatter formatter = new Formatter(Locale.ENGLISH);
        StringBuilder result = new StringBuilder();
        N = readInt(reader);
        X = 0;


        for (int i = 0; i < N; ++i) {
            J[i] = readInt(reader);
            J2[i] = J[i];
            X += J[i];
        }
        Arrays.sort(J2, 0, N);
        int m1 = J2[0];
        int m2 = J2[1];
        for (int i = 0; i < N; ++i) {

            int m = (J[i] == m1) ? m2 : m1;
            double res = find(0, 1, i);
            formatter.format("%2.6f", res*100);
            if (i < (N - 1)) {
                formatter.format(" ");
            }
        }
//        for (int i = 0; i < 5; ++i) {
//            formatter.format("%3d", n[i]);
//        }
        result.append(formatter.out());
        return result;
    }

    private static int readInt(BufferedReader reader) throws IOException {
        int result = 0;
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
            result = result * 10 + currentChar - '0';
            currentChar = (char) reader.read();
        }
        if (positive) {
            return result;
        } else {
            return -result;
        }
    }

    private static char readChar(BufferedReader reader) throws IOException {
        return (char) reader.read();
    }

    private static double find(double s, double e, int i) {
        if (Math.abs(s - e) < 1e-9) {
            return s;
        }
        double m = (s + e) / 2;
        double gi = m * X + J[i];
        double sum = m;
        for (int a = 0; a < N; ++a) {
            if (a != i) {
                sum += Math.max(0, (1.0 * gi - J[a]) / X);
            }
        }
        if (sum >= 1) {
            return find(s, m, i);
        } else {
            return find(m, 3, i);
        }

    }
}
