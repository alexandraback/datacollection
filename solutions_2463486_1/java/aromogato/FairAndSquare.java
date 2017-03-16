import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.TreeSet;

public class FairAndSquare {
	public static void main(String[] args) throws FileNotFoundException {
		TreeSet<Long> set = new TreeSet<Long>();
		for (long i = 1; i <= 10000000; i++) {
			if (isPalindrome(i) && isPalindrome(i*i)) {
				set.add(i*i);
			}
		}
		
		Scanner in = new Scanner(new File("src/input3"));
		int trials = in.nextInt();
		
		for (int trial = 1; trial <= 5000; trial++) {
			System.out.println("Case #" + trial + ": " + set.subSet(in.nextLong(), true, in.nextLong(), true).size());
		}
	}
	
	public static boolean isPalindrome(long x) {
		int len = 0;
		for (long i = x; i > 0; i = i/10) len++;
		StringBuffer buf = new StringBuffer(len);
		for (long i = x; i > 0; i = i/10) buf.append(i % 10);
		return buf.toString().equals(buf.reverse().toString());
	}
}
