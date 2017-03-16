package round1b;
import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class A {

	static String[] NUMS = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

	String solve(String s) {
		int[] ans = new int[10];
		Arrays.fill(ans, -1);
		int[] freq = new int[26];
		for (char ch: s.toCharArray()) freq[ch-'A']++;
		for (int i=0; i<10; i++) {
			boolean found = false;
			int letter = 0;
			int number = 0;
			int[] f2 = new int[26];
			for (int j=0; j<10; j++) {
				if (ans[j] < 0 ) {
					for (char ch: NUMS[j].toCharArray()) f2[ch-'A']++;
				}
			}
			for (int j=0; j<10; j++) {
				if (ans[j] < 0) {
					int[] f3 = new int[26];
					for (char ch: NUMS[j].toCharArray()) f3[ch-'A']++;
					for (int k=0; k<26; k++) {
						if (f2[k]==f3[k] && f2[k]>0) {
							number = j;
							letter = k;
							found = true;
							break;
						}
					}
				}
				if (found) break;
			}
			if (!found) throw new AssertionError();
			int p = 0;
			for (char ch: NUMS[number].toCharArray()) if ((ch-'A')==letter) p++;
			ans[number] = freq[letter]/p;
			for (char ch: NUMS[number].toCharArray()) freq[ch-'A'] -= ans[number];
		}
		String ret = "";
		for (int d=0; d<=9; d++) {
			for (int x=0; x<ans[d]; x++) {
				ret += Integer.toString(d);
			}
		}
		return ret;
	}

	public static void main(String[] args) {
		try {
			File fin = new File("A-large.in");
			Scanner sc = new Scanner(fin);
			File fout = new File("aout.txt");
			PrintWriter pw = new PrintWriter(fout);
			//PrintWriter pw = new PrintWriter(System.out);
			int T = sc.nextInt();
			sc.nextLine();
			for (int cn=1; cn<=T; cn++) {
				String s = sc.nextLine();
				A a = new A();
				pw.write("Case #" + cn + ": " + a.solve(s) + "\n");
			}
			pw.flush();
			pw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
