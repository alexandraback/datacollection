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


public class C {
	
	Object solve() {
		N = sc.nextInt();
		String[] w1 = new String[N];
		String[] w2 = new String[N];
		for (int i = 0; i < N; i++) {
			w1[i] = sc.next();
			w2[i] = sc.next();
		}
		
		int best = N;		
		for (int bm = 0; bm < (1<<N); bm++) {
			if (valid(w1, w2, bm)) {
				if (cnt(bm) < best) {
					best = cnt(bm);
				}
			}
		}
		return N - best;
	}

	private boolean valid(String[] w1, String[] w2, int bm) {
		HashSet<String> ww1 = new HashSet<>();
		HashSet<String> ww2 = new HashSet<>();
		for (int i = 0; i < N; i++) {
			if (((bm>>i)&1) == 1) {
				ww1.add(w1[i]);
				ww2.add(w2[i]);
			}
		}
		
		for (int i = 0; i < N; i++) {
			if (((bm>>i)&1) == 0) {
				if (!ww1.contains(w1[i]) || !ww2.contains(w2[i]))
					return false;
			}
		}
		
		return true;
	}

	private int cnt(int bm) {
		return Integer.bitCount(bm);
	}

	private static Scanner sc; private static PrintWriter fw;

	private int N;

	public static void main(String[] args) throws Exception {
		String inFile = "input.txt", outFile = "output.txt";
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
			Object res = new C().solve();
			if (res instanceof Double) 
				fw.printf("%.10f\n", res);
			else
				fw.printf("%s\n", res);
			fw.flush();
			if ((progress1 = cas*10/N) > progress) { System.out.println("*" + progress1*10 + "% "); progress = progress1; };
		}
		fw.close();
		sc.close();
	}
}
