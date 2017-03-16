import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
import java.util.regex.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;
import static java.lang.Character.*;


public class B {
	

	Object solve() {
		int K = sc.nextInt();
		int L = sc.nextInt();
		int S = sc.nextInt();
		
		char[] alpha = sc.next().toCharArray();
		
		double[] P = new double[256];
		for (char c : alpha) {
			P[c] += 1/(double)alpha.length;
		}
		
		String word = sc.next();
		
		int zzz = word.length();
		for (int i = 1; i < word.length(); i++) {
			if (word.startsWith(word.substring(i))) {
				zzz = i; break;
			}
		}
		
		double max = 0;
		if (S >= word.length()) {
			max = (S-word.length())/zzz + 1;
		}
		
		System.out.println(max);
		
		double e = 1;
		for (int j = 0; j < word.length(); j++) {
			e *= P[word.charAt(j)];
		}
		
		e *= (S - word.length() + 1);
		
		if (e == 0)
			return 0.0;
		
		if (max - e < 0)
			return 0.0;
		return max - e;
	}

	private static Scanner sc; private static PrintWriter fw;

	public static void main(String[] args) throws Exception {
		String inFile = "input.txt", outFile = "output.txt";
//		inFile = "A-small-attempt0.in";
//		inFile = "A-large.in";
		if (args.length == 0) {
			sc = new Scanner(System.in);
	//		sc = new Scanner(new FileInputStream(inFile));
		} else {
			inFile = args[0];
			sc = new Scanner(new FileInputStream(inFile));
			if (args.length > 1)
				outFile = args[1];
			else if (inFile.endsWith(".in"))
				outFile = inFile.substring(0, inFile.length() - 2) + "out";
			System.out.println(inFile + " -> " + outFile);
		}
		
		fw = new PrintWriter(new FileWriter(outFile, false)) {
			public PrintWriter printf(String format, Object... args) {
				System.out.printf(format, args);
				return super.printf(format, args);
			}
		};
		
		int N = sc.nextInt();
		sc.nextLine();
		System.out.println(N + " cases.");
		
		int progress = 0, progress1;
		for (int cas = 1; cas <= N; cas++) {
			fw.printf("Case #" + cas + ": ");
//			fw.println("Case #" + cas + ": ");
			Object res = new B().solve();
			if (res instanceof Double) 
				fw.printf("%.10f\n", res);
			else
				fw.printf("%s\n", res);
			fw.flush();
			if ((progress1 = cas*10/N) > progress) { System.out.println("*" + progress1*10 + "% "); progress = progress1; };
		}
//		System.out.println(" done ");
		fw.close();
		sc.close();
	}
}
