import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by mohamedelsharnouby on 4/9/2016.
 */
public class Pancakes {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = in.nextInt();
        for (int i = 1; i <= t; ++i) {
            int flips = 0;
            String pankackes = in.next();
            if (pankackes.charAt(pankackes.length()-1) == '-') flips++;

            for (int j = 1; j < pankackes.length(); j++) {
                if (pankackes.charAt(j) != pankackes.charAt(j-1)) flips++;
            }
            System.out.println("Case #" + i + ": " + flips);
        }
    }
}
