import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class RecycledNumbers {
	final static String FILENAME = "C-large";

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader("/home/workshop/Documents/"
				+ FILENAME + ".in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter(
				"/home/workshop/Documents/" + FILENAME + ".out"));
		int T = sc.nextInt();
		sc.nextLine();
		for (int ttt = 0; ttt < T; ttt++) {
			int A = sc.nextInt();
			int B = sc.nextInt();

			int count = 0;
			int digits = new Double(Math.floor(Math.log10(A) + 1)).intValue();
			for (int num = A; num < B; num++) {
				Set<Integer> hs = new HashSet<Integer>();
				for (int lastdigits = 1; lastdigits < digits; lastdigits++) {
					int tailmask = new Double(Math.pow(10, lastdigits))
							.intValue(), headmask = new Double(Math.pow(10,
							digits - lastdigits)).intValue();
					int newnum = num / tailmask + (num % tailmask) * headmask;
					if (num < newnum && !hs.contains(newnum) && newnum <= B) {
						// System.out.println(num + "\t" + newnum);
						count++;
						hs.add(newnum);
					}
				}
				// if (y < z) {
				// System.out.println(num + "\t(1)");
				// count++;
				// }
				// if (x < z || (x == z && x > y)) {
				// System.out.println(num + "\t(2)");
				// count++;
				// }
				// if (x < y && y != z) {
				// System.out.println(num + "\t(3)");
				// count++;
				// }
				// if (x < y && x != z) {
				// System.out.println(num + "\t(4)");
				// count++;
				// }
				// if (x < z || (x == z && x > y)) {
				// int newnum = z * 100 + x * 10 + y;
				// if (newnum <= B) {
				// System.out.println(num + "\t" + newnum + "\t(2)");
				// count++;
				// }
				// }
				// if (x < y || (x == y && y < z)) {
				// int newnum = y * 100 + z * 10 + x;
				// if (newnum <= B) {
				// System.out.println(num + "\t" + newnum + "\t(4)");
				// count++;
				// }
				// }
			}

			bw.write("Case #" + (ttt + 1) + ": " + count);
			bw.newLine();
		}
		bw.close();
		sc.close();
	}
}
