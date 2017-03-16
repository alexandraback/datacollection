import java.io.CharConversionException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class B {

	Scanner sc = new Scanner(getClass().getResourceAsStream(IN));
	static final String FILENAME = "B-small-attempt1";
//	 static final String FILENAME = "A-small-practice";
	static final long m = 1000000007;
	static final String IN = FILENAME + ".in";
	static final String OUT = FILENAME + ".out";
	PrintStream out;

	private long auxSolve(String s, HashSet<Integer> set, int n, String[] train) {
		if(s.length()>0){
			HashSet<Character> set1 = new HashSet<Character>();
			char a = s.charAt(0);
			set1.add(a);
			for (int i = 1; i < s.length(); i++) {
				if (s.charAt(i)!=a && !set1.contains(s.charAt(i))) {
					a = s.charAt(i);
					set1.add(a);
				} else if (s.charAt(i) != a && set1.contains(s.charAt(i))) {
					return 0;
				}
			}
		}
		if(set.size()==n)
			return 1;
		
		long sum = 0;
		for (int i = 0; i < n; i++) {
			if (!set.contains(i)) {
				String s1 = s + train[i];
				HashSet<Integer> tmp = new HashSet<>(set);
				tmp.add(i);
				sum += auxSolve(s1, tmp, n, train);
				sum = sum % m;
			}
		}
		return sum;

	}

	private void solveSmall() {
		long m = 1000000007;
		int n = sc.nextInt();
		String[] train = new String[n];
		for(int i =0;i<n;i++){
		String s = sc.next();
		train[i]=s;
		}
		
		long res = auxSolve("", new HashSet<Integer>(), n, train);
		out.print(res);
	}

	private void solve() {
		long m = 1000000007;
		int n = sc.nextInt();
		String s = sc.next();
		String[] train = s.split(" ");

		for (int i = 0; i < n; i++) {
			char sta = train[i].charAt(0);
			char end = train[i].charAt(0);

		}

	}

	private void run() throws Exception {
		sc.useLocale(Locale.US);
		out = new PrintStream(new FileOutputStream(OUT));
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			sc.nextLine();
			out.print("Case #" + i + ": ");
			solveSmall();
			System.out.println("Case #" + i + ": ");
			out.println();
		}
		sc.close();
		out.close();
	}

	public static void main(String args[]) throws Exception {
		new B().run();
	}

}