package RC;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("A-large(1).in"));
		PrintWriter pw = new PrintWriter(new File("outA_Large"));
//		Scanner sc = new Scanner(System.in);
//		PrintWriter pw = new PrintWriter(System.out);
		int T = Integer.parseInt(sc.nextLine());
		
		BigInteger deno[] = new BigInteger[41];
		BigInteger org = BigInteger.ONE;
		for(int i = 0; i <= 40; i++) {
			deno[i] = org;
			org = org.add(org);
		}
		
		L:for(int t = 1; t <= T; t++) {
			String line = sc.nextLine();
			String tmp[] = line.split("/");
			
			BigInteger P = new BigInteger(tmp[0]);
			BigInteger Q = new BigInteger(tmp[1]);
			
			BigInteger gcd = P.gcd(Q);
			P = P.divide(gcd);
			Q = Q.divide(gcd);
			
			int idx = Arrays.binarySearch(deno, Q);
			if(idx < 0) {
				pw.println("Case #"+t+": "+"impossible");
			} else {
				int ans = 1;
				for(int i = 0; i <= idx; i++) {
					if(Q.divide(deno[i]).compareTo(P) <= 0) {
						ans = i;
						break;
					}
				}
				pw.println("Case #"+t+": "+ans);
			}
		}
		
		pw.flush();
	}
}
