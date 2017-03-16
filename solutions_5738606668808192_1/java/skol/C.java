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
		
		long numBase2 = (1L<<N-1)+1;
		int j = 0;
		for (; numBase2 < (1L<<N) && j < J; numBase2 += 2) {
			String numString = Long.toString(numBase2, 2);
			if (isJamCoin(numString)) {
				List<Integer> divisors = getDivisorsForEveryBase(numString);
				if (divisors == null) 
					continue;
				fw.println();
				fw.print(numString);
				for (int div : divisors) {
					fw.print(" " + div);
				}
				j++;
			}
		}
		
		assert j == J;
		return "";
	}

	private List<Integer> getDivisorsForEveryBase(String numString) {
		ArrayList<Integer> res = new ArrayList<>();
		for (int b = 2; b <= 10; b++) {
			int div = divisorInBase(numString, b);
			if (div == -1)
				return null;
			res.add(div);
		}
		return res;
	}

	private boolean isJamCoin(String numString) {
		for (int b = 2; b <= 10; b++) {
			BigInteger x = new BigInteger(numString, b);
			if (isPrime(x))
				return false;
		}
		return true;
	}
	
	private boolean isPrime(BigInteger x) {
		return x.isProbablePrime(100);
	}

	private int divisorInBase(String numString, int b) {
		BigInteger x = new BigInteger(numString, b);
		for (int i = 2; i < 1000; i++)
			if (x.mod(BigInteger.valueOf(i)).signum() == 0)
				return i;
		return -1;
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
