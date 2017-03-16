import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

/**
 * @autor: julio
 */
public class Main {

    public static void main(String[] args) throws IOException {


        Scanner scanner = new Scanner(new InputStreamReader(Thread.currentThread().getContextClassLoader().getResourceAsStream("in.large")));
        int T = scanner.nextInt();
        for(int t=0;t<T;t++) {
            long A = scanner.nextInt();
            long B = scanner.nextInt();
            long K = scanner.nextInt();

            long count = 0;
            int tries = 0;
            for (long a = 0; a < A - K; a++) {
                for (long b = 0; b < B - K; b++) {
                    tries++;
                    if ((a & b) < K) {
                        count++;
                        //System.out.println(a + "," + b);
                    }
                }
            }

            System.out.println("Case #" + (t+1) + ": " + count);
        }
    }

}
