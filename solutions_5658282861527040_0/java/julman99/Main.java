import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

/**
 * @autor: julio
 */
public class Main {

    public static void main(String[] args) throws IOException {


        Scanner scanner = new Scanner(new InputStreamReader(Thread.currentThread().getContextClassLoader().getResourceAsStream("in.small")));
        int T = scanner.nextInt();
        for(int t=0;t<T;t++) {
            int A = scanner.nextInt();
            int B = scanner.nextInt();
            int K = scanner.nextInt();

            int count = 0;
            for (int a = 0; a < A; a++) {
                for (int b = 0; b < B; b++) {
                    if ((a & b) < K) {
                        count++;
                    }
                }
            }

            System.out.println("Case #" + (t+1) + ": " + count);
        }
    }

}
