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
	
	static boolean[][] sup = new boolean[11][31];
	static boolean[][] notsup = new boolean[11][31];
	
	static {
		for (int a = 0; a <= 10; a++)
			for (int b = a; b <= min(a+2,10); b++)
				for (int c = b; c <= min(a+2, 10); c++) {
					if (c > a+1)
						sup[c][a+b+c] = true;
					else 
						notsup[c][a+b+c] = true;
				}
	}
	

	Object solve() {
		int N = sc.nextInt();
		int S = sc.nextInt();
		int p = sc.nextInt();
		
		int supc = 0;
		int nsupc = 0;
		for (int i = 0; i < N; i++) {
			int t = sc.nextInt();
			boolean nsupp = false;
			boolean supp = false;
			for (int r = p; r <= 10; r++) {
				if (sup[r][t])
					supp = true;
				if (notsup[r][t])
					nsupp = true;
			}
			
			if (nsupp)
				nsupc++;
			else if (supp)
				supc++;
		}
		
		return nsupc + min(S, supc);
	}

	private static Scanner sc; private static PrintWriter fw;

	public static void main(String[] args) throws Exception {
		String inFile;
//		inFile = "input.txt";
//		inFile = "B-small-attempt0.in";
		inFile = "B-large.in";
		
		sc = new Scanner(System.in);
		sc = new Scanner(new FileInputStream(inFile));
		
		fw = new PrintWriter(new FileWriter("output.txt", false));

		
		int N = sc.nextInt();
		sc.nextLine();
		
		for (int cas = 1; cas <= N; cas++) {
			fw.print("Case #" + cas + ": ");
//			fw.println("Case #" + cas + ": ");
			Object res = new B().solve();
			if (res instanceof Double) 
				fw.printf("%.10f\n", res);
			else
				fw.printf("%s\n", res);
			fw.flush();
		}
		fw.close();
		sc.close();
	}

}
