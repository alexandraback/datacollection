import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class B {
	
	Object solve() {
		char[] s1 = sc.next().toCharArray();
		char[] s2 = sc.next().toCharArray();
		
		List<Long> poss1 = new ArrayList<>();
		List<Long> poss2 = new ArrayList<>();
		
		allPossible(s1, 0, 0, poss1);
		allPossible(s2, 0, 0, poss2);
		
		Collections.sort(poss1);
		Collections.sort(poss2);
		
		long bestD = Long.MAX_VALUE;
		long l1b = -1, l2b = -1;
		for (long l1 : poss1)
			for (long l2 : poss2) {
				long d = Math.abs(l1 - l2);
				if (d < bestD) {
					bestD = d;
					l1b = l1; l2b = l2;
				}
			}
		return String.format("%0" + s1.length + "d %0" + s2.length + "d", l1b, l2b);
	}
	
	void allPossible(char[] s1, int i, long l, List<Long> res) {
		if (i == s1.length) {
			res.add(l);
			return;
		}
		l *= 10;
		char c = s1[i];
		if (c == '?') {
			for (int k = 0; k < 10; k++)
				allPossible(s1, i+1, l+k, res);
		} else {
			l += (c - '0'); 
			allPossible(s1, i+1, l, res);
		}
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
