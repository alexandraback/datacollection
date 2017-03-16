package googlecontest;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;
import java.util.Timer;
import java.util.TimerTask;

public class GoogleContest {

    
    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);
        int numCases = stdin.nextInt();

        int n = stdin.nextInt();
        int j = stdin.nextInt();
        int counter = 0;
        int min = (int) Math.pow(2, n - 3);
        int max = (int) Math.pow(2, n - 2);
        

        System.out.println("Case #" + 1 + ": ");

        for (int i = min ; i < max; i+=2) {
            long[] bases = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (int k = 2; k <= 10; k++) {
                String str2 = "1" + Integer.toString(Integer.parseInt(String.valueOf(i), 10), 2) + "1";
                BigInteger strK = new BigInteger(str2, k);
                if (strK.mod(new BigInteger("2")).intValue() == 0) {
                    bases[k] = 2;
                    continue;
                }
                for (long l = 3; l < 1000; l++ ){//sqrt(strK).longValue(); l++) {
                    long z = strK.mod(new BigInteger(String.valueOf(l))).longValue();
                    if (z != 0) {
                        continue;
                    } else {
                        bases[k] = l;
                        break;
                    }
                }
                if (bases[k] == 0) {
                    break;
                }
            }
            boolean skip = false;
            for (int k = 2; k < 11; k++) {
                if (bases[k] == 0) {
                    skip = true;
                    break;
                }
            }
            if (!skip) {
                String str2 = "1" + Integer.toString(Integer.parseInt(String.valueOf(i), 10), 2) + "1";
                str2 += " ";
                for (int k = 2; k < 11; k++) {
                    str2 += bases[k];
                    if (k != 10) {
                        str2 += " ";
                    }
                }
                System.out.println(str2);
                counter++;
                if (counter == j) {
                    break;
                }
            }
        }
    }

    public static BigInteger sqrt(BigInteger n) {
        BigInteger a = BigInteger.ONE;
        BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
        while (b.compareTo(a) >= 0) {
            BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
            if (mid.multiply(mid).compareTo(n) > 0) {
                b = mid.subtract(BigInteger.ONE);
            } else {
                a = mid.add(BigInteger.ONE);
            }
        }
        return a.subtract(BigInteger.ONE);
    }

}
