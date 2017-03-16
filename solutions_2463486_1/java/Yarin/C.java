package qual2013;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class C {
    public static final int MAX = 27;

	public static void main(String[] args) throws FileNotFoundException {
		Kattio io;

        numbers.add(new BigInteger("9"));
        generateEven(new StringBuilder(), 0);
        generateOdd(new StringBuilder(), 0);

        Collections.sort(numbers);
        System.out.println("Done generating " + numbers.size() + " fair and square primes");

//        io = new Kattio(System.in, System.out);
//		io = new Kattio(new FileInputStream("src/qual2013/C-sample.in"), System.out);
//		io = new Kattio(new FileInputStream("src/qual2013/C-small-attempt0.in"), new FileOutputStream("src/qual2013/C-small-attempt0.out"));
		io = new Kattio(new FileInputStream("src/qual2013/C-large-1.in"), new FileOutputStream("src/qual2013/C-large-1.out"));

		int cases = io.getInt();
		for (int i = 1; i <= cases; i++) {
			io.print("Case #" + i + ": ");
			new C().solve(io);
		}
		io.close();
	}

    private static boolean isPalindrome(BigInteger x) {
        String s = String.valueOf(x);
        for(int i=0;i<s.length()/2;i++) {
            if (s.charAt(i) != s.charAt(s.length() - i - 1)) return false;
        }
        return true;
    }

    private static boolean isRootOfFairAndSquarePalindrome(BigInteger bi) {
        if (!isPalindrome(bi)) return false;
        bi = bi.pow(2);
        return isPalindrome(bi);
    }

    private static String evenPalin(String s) {
        // 1234 -> 12344321
        return s + new StringBuilder(s).reverse().toString();
    }

    private static String oddPalin(String s) {
        // 1234 -> 1234321
        return s + new StringBuilder(s).deleteCharAt(s.length() - 1).reverse().toString();
    }

    private static void generateEven(StringBuilder current, int ones) {
        if (current.length() >= MAX || ones >= 5) return;

        for (int i=0;i<=2;i++) {
            if (current.length() == 0 && i==0) continue;
            current.append(i);
            int newOnes = i == 1 ? (ones + 1) : ones;

            String s = evenPalin(current.toString());
            test(s);

            if (current.length() == 1 || i < 2) {
                generateEven(current, newOnes);
            }

            current.deleteCharAt(current.length() - 1);
        }
    }

    private static void generateOdd(StringBuilder current, int ones) {
        if (current.length() >= MAX || ones >= 5) return;

        for (int i=0;i<=2;i++) {
            if (current.length() == 0 && i==0) continue;
            current.append(i);
            int newOnes = i == 1 ? (ones + 1) : ones;

            String s = oddPalin(current.toString());
            test(s);

            if (current.length() == 1 || i < 2) {
                generateOdd(current, newOnes);
            }

            current.deleteCharAt(current.length() - 1);
        }
    }

    private static List<BigInteger> numbers = new ArrayList<BigInteger>();
    private static void test(String s) {
        BigInteger bi = new BigInteger(s);
        if (isRootOfFairAndSquarePalindrome(bi)) {
            numbers.add(bi.pow(2));
//            System.out.println(s);
        }
    }

    private void solve(Kattio io) {
        BigInteger a = new BigInteger(io.getWord());
        BigInteger b = new BigInteger(io.getWord());
        int start = find(a), stop = find(b);
        start = Math.max(0, start - 2);
        stop = Math.min(stop + 2, numbers.size());
        while (start < numbers.size() && numbers.get(start).compareTo(a) < 0) start++;
        while (stop >= 0 && numbers.get(stop).compareTo(b) > 0) stop--;
        io.println(Math.max(0, stop - start + 1));
    }

    private int find(BigInteger a) {
        int lo = 0, hi = numbers.size();
        while (lo < hi) {
            int x = (lo+hi) / 2;
            int diff = numbers.get(x).compareTo(a);
            if (diff < 0) {
                lo = x + 1;
            } else {
                hi = x;
            }
        }
        return lo;
    }
}
