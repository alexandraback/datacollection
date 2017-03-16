import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class ProblemA {
	
	static int n;
	
	static int firstGroup(String s) {
		int l = s.length();
		int i = 0;
		int j = 0;
		while (j < l) {
			i = j;
			while (i < l && "aeiou".contains(s.charAt(i) + ""))
				i++;
			j = i;
			while (j < l && !"aeiou".contains(s.charAt(j) + ""))
				j++;
			if (j - i >= n)
				return i;
		}		
		
		
		return -1;
	}
	

	static void nextCase(Scanner sc, PrintStream ps) {
		String name = sc.next();
		n = sc.nextInt();
		
		int i = firstGroup(name);
		long nValue = 0;
		while (i != -1) {
			nValue += (i + 1L) * (name.length() - i - n + 1);
			name = name.substring(i + 1);
			i = firstGroup(name);
		}
		
		ps.println(nValue);

	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File(args[0] + ".in"));
		PrintStream ps = new PrintStream(args[0] + ".out");
		int t = sc.nextInt();
		sc.nextLine();

		for (int c = 1; c <= t; c++) {
			System.out.printf("Case #%d:%n", c);
			ps.printf("Case #%d: ", c);
			nextCase(sc, ps);
		}
	}
}
