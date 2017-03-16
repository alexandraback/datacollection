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
		int N = sc.nextInt();
		int J = sc.nextInt();
		
		long numBase2 = (1<<N-1)+1;
		int j = 0;
		for (; numBase2 < (1<<N) && j < J; numBase2 += 2) {
			String numString = Long.toString(numBase2, 2);
			if (isJamCoin(numString)) {
				fw.println();
				fw.print(numString);
				for (int b = 2; b <= 10; b++) {
					fw.print(" " + divisorInBase(numString, b));
				}
				j++;
			}
		}
		
		assert j == J;
		return "";
	}

	private boolean isJamCoin(String numString) {
		for (int b = 2; b <= 10; b++) {
			long x = Long.parseLong(numString, b);
			if (isPrime(x))
				return false;
		}
		return true;
	}
	
	private boolean isPrime(long x) {
		return BigInteger.valueOf(x).isProbablePrime(100);
	}

	private int divisorInBase(String numString, int b) {
		long x = Long.parseLong(numString, b);
		for (int i = 2; ; i++)
			if (x%i == 0)
				return i;
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
			Object res = new C().solve();
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
