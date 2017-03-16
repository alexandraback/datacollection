import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new FileInputStream(new File("large.txt")));
		int T = scanner.nextInt();
		scanner.nextLine();
		List<Long> palis = new ArrayList<Long>();
		for (long i = 1; i < 10000000L; i++) {
			if (isPali(i) && isPali(i * i)) {
				palis.add(i * i);
			}
		}
		for (int t = 0; t < T; t++) {
			long A = scanner.nextLong();
			long B = scanner.nextLong();
			int c = 0;
			for (int i = 0; i < palis.size(); i++) {
				if (palis.get(i) >= A && palis.get(i) <= B) {
					c++;
				} else if (palis.get(i) > B) {
					break;
				}
			}
			System.out.println("Case #" + (t + 1) + ": " + c);
		}
	}
	
	private static boolean isPali(long n) {
		char[] s = String.valueOf(n).toCharArray();
		
		for (int i = 0; i < s.length; i++) {
			if (s[i] != s[s.length - i - 1]) {
				return false;
			}
		}
		return true;
	}

}
