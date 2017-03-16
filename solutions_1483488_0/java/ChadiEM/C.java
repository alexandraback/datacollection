import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 *
 * @author Chadi
 */

class TestCase {
	int A;
	int B;
	public TestCase() {

	}
	public int solve() {
		int count = 0;
		for (int i = A; i <= B; i++) {
			count += getAllCombinations(i, B);
		}
		return count;
	}

	public int getAllCombinations(int num, int B) {
		Set<Integer> set = new HashSet<Integer>();
		String s = Integer.toString(num);
		//System.out.println(s);
		for (int i = s.length() - 1; i > 0; i--) {
			String cur = s.substring(i) + s.substring(0, i);
			int t = Integer.parseInt(cur);
			if (t > num && t <= B) {
				set.add(t);
			}
		}
		return set.size();
	}
	

}

public class C {
    public static void main(String[] args) throws FileNotFoundException, IOException {
		/* READ INPUT + DATA STRUCTURES */
		String input = "C-small-attempt0.in";
		//String input = "C-large.in";
		String output = input.replace(".in", ".out");
		File f = new File(input);
		Scanner sc = new Scanner(f);

		int T = Integer.parseInt(sc.nextLine());
		TestCase[] cases = new TestCase[T];
		for (int i = 0; i < T; i++) {
			cases[i] = new TestCase();

			/* Add inputs to this case */
			
			cases[i].A = sc.nextInt();
			cases[i].B = sc.nextInt();
			//sc.nextLine();

			
		}
		/* END READ INPUT + DATA STRUCTURES */

		File out = new File(output);
		if (out.exists()) {
			out.delete();
		}
		PrintWriter pw = new PrintWriter(new FileOutputStream(out, true));

		for (int i = 0; i < T; i++) {
			System.out.println("Solving case: " + "#" + (i+1));
			String result = "Case #" + (i+1) + ": " + cases[i].solve();
			if (i <= T-2) { pw.println(result); }
			else { pw.print(result); }
		}
		pw.close();
    }
}