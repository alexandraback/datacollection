import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;

/**
 * Created by IntelliJ IDEA.
 * User: skortzy
 * Date: 13.04.2013
 * Time: 11:46
 * To change this template use File | Settings | File Templates.
 */
public class CodeJam3 {
//    public static void main(String[] args) {
//        for (int i = 0; i < 1000000; i++) {
//            long nr1 = generatePalindrom(i, true);
//            long nr2 = generatePalindrom(i, false);
//            long square1 = nr1 * nr1;
//            long square2 = nr2 * nr2;
//            if (isPalindrom(square1)) {
//                System.out.println(nr1 + " " + square1);
//            }
//            if (isPalindrom(square2)) {
//                System.out.println(nr2 + " " + square2);
//            }
//        }
//    }

    static int count = 0;

    static BigInteger MAX;

    static BigInteger[] values = new BigInteger[41551];

    private static boolean generatePalindrom(String s, boolean last, int sum) {
        int totalSum = sum * 2;
        int length = s.length();
        int lastPosition = length - 1;
        if (!last) {
            char c = s.charAt(length - 1);
            int value = c - '0';
            totalSum -= (value * value);
            lastPosition--;
        }
        if (totalSum >= 10) {
            return false;
        }
        String result = s;
        for (int i = lastPosition; i >= 0; i--) {
            result += s.charAt(i);
        }
        //count++;
        //System.out.println(result);
        BigInteger pal = new BigInteger(result);
        BigInteger square = pal.multiply(pal);

        if (/*isPalindrom(square.toString()) && square.compareTo(A) >= 0 && */square.compareTo(MAX) <= 0) {
            //count++;
            //System.out.println(pal + " " + square);
            values[count++] = square;
        }

        return true;
    }

    public static void generate(String s, int step, int squareSum) {
        if (step > 25) {
            return;
        }

        boolean first = generatePalindrom(s, false, squareSum);
        boolean second = generatePalindrom(s, true, squareSum);

        if (!second && !first) {
            return;
        }

        generate(s + 0, step + 1, squareSum);
        generate(s + 1, step + 1, squareSum + 1);
        generate(s + 2, step + 1, squareSum + 4);
    }

    public static void main(String[] args) {
        //A = new BigInteger("1");
        String res = "1";
        for (int i = 0; i < 100; i++) res += '0';
        MAX = new BigInteger(res);
        generate("1", 1, 1);
        generate("2", 1, 4);
        generate("3", 1, 9);
        Arrays.sort(values);
//        System.out.println(count);

//        for (int i = 0; i < 100; i++) {
//            System.out.println(values[i]);
//        }


        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            String line = br.readLine();
            int K = Integer.parseInt(line);
            for (int i = 1; i <= K; i++) {
                String[] v = br.readLine().split(" ");
                BigInteger A = new BigInteger(v[0]);
                BigInteger B = new BigInteger(v[1]);

                int p1 = Arrays.binarySearch(values, A);
                if (p1 < 0) {
                    p1 = -p1 - 1;
                }
                int p2 = Arrays.binarySearch(values, B);
                if (p2 < 0) {
                    p2 = -p2 - 1;
                } else {
                    p2++;
                }
                int result = p2 - p1;
                //System.out.println(p1 + " " + p2);
                System.out.println("Case #" + i + ": " + result);

            }
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }


    private static boolean isPalindrom(long square2) {
        String s = String.valueOf(square2);
        int length = s.length();
        for (int i = 0; i < length / 2; i++) {
            if (s.charAt(i) != s.charAt(length - i - 1)) {
                return false;
            }
        }
        return true;
    }

    private static boolean isPalindrom(String s) {
        int length = s.length();
        for (int i = 0; i < length / 2; i++) {
            if (s.charAt(i) != s.charAt(length - i - 1)) {
                return false;
            }
        }
        return true;
    }

    private static long generatePalindrom(int i, boolean last) {
        long nr = i;
        if (!last) {
            i /= 10;
        }
        while (i > 0) {
            nr = nr * 10 + (i % 10);
            i /= 10;
        }
        return nr;
    }
}
