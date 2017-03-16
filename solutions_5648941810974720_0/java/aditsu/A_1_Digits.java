import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class A_1_Digits {
	public void solve(final Scanner sc, final PrintWriter pw) {
		final String s = sc.nextLine();
		final int[] f = new int[128];
		final List<Integer> l = new ArrayList<>();
		for (int i = 0; i < s.length(); ++i) {
			f[s.charAt(i)]++;
		}
		for (int i = 0; i < f['Z']; ++i) {
			l.add(0);
			f['E']--;
			f['R']--;
			f['O']--;
		}
		for (int i = 0; i < f['X']; ++i) {
			l.add(6);
			f['S']--;
			f['I']--;
		}
		for (int i = 0; i < f['G']; ++i) {
			l.add(8);
			f['E']--;
			f['I']--;
			f['H']--;
			f['T']--;
		}
		for (int i = 0; i < f['U']; ++i) {
			l.add(4);
			f['F']--;
			f['O']--;
			f['R']--;
		}
		for (int i = 0; i < f['W']; ++i) {
			l.add(2);
			f['T']--;
			f['O']--;
		}
		for (int i = 0; i < f['F']; ++i) {
			l.add(5);
			f['I']--;
			f['V']--;
			f['E']--;
		}
		for (int i = 0; i < f['H']; ++i) {
			l.add(3);
			f['T']--;
			f['R']--;
			f['E']-=2;
		}
		for (int i = 0; i < f['O']; ++i) {
			l.add(1);
			f['N']--;
			f['E']--;
		}
		for (int i = 0; i < f['S']; ++i) {
			l.add(7);
			f['E']-=2;
			f['V']--;
			f['N']--;
		}
		for (int i = 0; i < f['I']; ++i) {
			l.add(9);
		}
		Collections.sort(l);
		for (int x : l) {
			pw.print(x);
		}
		pw.println();
	}
	
	public static void main(final String... args) throws IOException {
		final String fname = "A-small-attempt0";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		sc.nextLine();
		
		for (int i = 1; i <= t; ++i) {
			System.out.println(i);
			pw.print("Case #" + i + ": ");
			new A_1_Digits().solve(sc, pw);
		}
		pw.close();
	}
}
