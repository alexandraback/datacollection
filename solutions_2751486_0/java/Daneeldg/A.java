package round1c;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;
import java.util.Set;

public class A {
	Scanner sc;
	PrintWriter out;

	public static void main(String[] args) throws IOException {
		long iniTime = System.currentTimeMillis();
		
		Locale.setDefault(Locale.US);
		File in = new File("round1c/" + A.class.getSimpleName() + "1.in");
		File out = new File(in.getAbsolutePath().replace(".in", ".out"));
		new A(new Scanner(in), new PrintWriter(out)).solve();
		
		System.out.println("Time: " + (System.currentTimeMillis() - iniTime));
	}

	private void solveCase() throws IOException {
		String name = sc.next();
		int n = sc.nextInt();
		
		Set <int []>sc = new HashSet<int []>();  
		Set <String> ss = new HashSet<String>();
		
		int cc = 0;
		
		for (int i = 0; i < name.length(); i++) {
			char l = name.charAt(i);
			
			if (l != 'a' && l != 'e' && l != 'i' && l != 'o' && l != 'u') {
				cc++;
				
				for (int j = n; j <= cc; j++) {
					sc.add(new int[]{i - j + 1, i + 1});
				}
			} else {
				cc = 0;
			}
		}
		
		for (int [] interval : sc) {
			for (int x = 0; x <= interval[0]; x++) {
				for (int y = interval[1]; y <= name.length(); y++) {
					ss.add(x + "_" + y);
				}
			}
		}
		
		out.println(ss.size());
		System.out.println(ss.size());
	}

	public A(Scanner sc, PrintWriter out) {
		this.sc = sc;
		this.out = out;
	}

	public void solve() throws NumberFormatException, IOException {
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.printf("Case #%d: ", i);
			out.printf("Case #%d: ", i);
			solveCase();
		}

		sc.close();
		out.close();
	}
}