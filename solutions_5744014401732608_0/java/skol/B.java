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
		int B = sc.nextInt();
		long M = sc.nextLong();
		boolean[][] ad = new boolean[B][B];
		
		long res = find(ad, M, B-1);
		if (res < M)
			return "IMPOSSIBLE\n";
		
		fw.println("POSSIBLE");
		for (int i = 0; i < B; i++) {
			for (int j = 0; j < B; j++) {
				fw.print(ad[i][j] ? 1 : 0);
			}
			if (i < B - 1);
				fw.println();
		}
		return "";
	}

	private long find(boolean[][] ad, long m, int i) {
		if (i == 0)
			return 1;
		long res = 0;
		for (int j = i-1; j >= 0 && m > 0; j--) {
			ad[j][i] = true;
			long found = find(ad, m, j);
			res += found;
			m -= found;
		}
		return res;
	}

	private static Scanner sc; private static PrintWriter fw;

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
			Object res = new B().solve();
			if (res instanceof Double) 
				fw.printf("%.10f", res);
			else
				fw.printf("%s", res);
			fw.flush();
			if ((progress1 = cas*10/N) > progress) { System.out.println("*" + progress1*10 + "% "); progress = progress1; };
		}
		fw.close();
		sc.close();
	}
}
