import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author Prakhar
 */
public class Q1 {

    public static void main(String... args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 1; i <= t; i++) {
            long count = 0;
            String arr[] = br.readLine().split("/");
            long p = Long.parseLong(arr[0]);
            long q = Long.parseLong(arr[1]);
            double r = (double) p / q;
            int j = 0, flag = 0;
            while (j < 40) {
                int temp = (int) r;
                double temp2 = (double) (r - temp);
                if (r >= 1 && flag == 0) {
                    count = j;
                    flag = 1;
                }
                if (temp2 == 0) {
                    break;
                }
                r = r * 2;
                j++;
            }
            if (count != 0 && j < 40) {
                System.out.println("Case #" + i + ": " + count);
            } else {
                System.out.println("Case #" + i + ": impossible");
            }
        }
    }

}
