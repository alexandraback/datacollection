/**
 * Created by riku on 4/8/16.
 */
import java.io.BufferedReader;
import java.io.FileReader;
import java.math.BigInteger;
import java.util.Scanner;

public class Sheep {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new BufferedReader(new FileReader(args[0])));
        int n = in.nextInt();
        for (int x = 0; x < n; x++) {
            BigInteger i = new BigInteger(in.next());
            System.out.println("Case #" + (x+1) + ": " + solve(i));
        }
    }
    public static String solve(BigInteger increment) {
        BigInteger n = BigInteger.ZERO;
        if (increment.equals(BigInteger.ZERO)) {
            return "INSOMNIA";
        }
        boolean[] found = new boolean[10];
        while (!hasAllDigits(found)) {
            n = n.add(increment);
            BigInteger temp = n;
            while (!temp.equals(BigInteger.ZERO)) {
                found[temp.mod(BigInteger.TEN).intValue()] = true;
                temp = temp.divide(BigInteger.TEN);
            }
        }
        return n + "";
    }
    public static boolean hasAllDigits(boolean[] found) {
        for(boolean b: found) {
            if (b==false) {
                return false;
            }
        }
        return true;
    }
}
