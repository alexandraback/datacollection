package R1C;

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Csmall {
	
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new File("A-small-attempt0 (1).in"));
		int numCases = scanner.nextInt();
		ArrayList<Integer> res = new ArrayList<Integer>();
		double tf = Math.pow(2, 40);
		
		// Each case variables
		double num;
		double den;
		double frac;
		String temp;
		int years;
		
		
		// Each case loop		
		for (int i = 0; i < numCases; i++) {
			temp = scanner.next();
			num = (parseN(temp));
			den = (parseD(temp));
			frac = num / den;
			years = 0;
			
			while (frac < 1) {
				frac *= 2;
				years++;
				if (frac >= 1) {
					frac -= 1;
					res.add(((frac * tf) % 1 == 0) ? years : -1);
					break;
				}
			}
			
		}
		
		PrintWriter result = new PrintWriter(new FileWriter("1CA.txt"));
		for (int i = 0; i < numCases; i++) {
			result.println("Case #" + (i + 1) + ": " + (res.get(i) == -1 ? "impossible" : res.get(i)));
		}
		result.close();
	}
	
	
	
	public static double parseN(String fraction) {
		int len = fraction.length();
		int ind = 0;
		for (int i = 0; i < len; i++) {
			if (fraction.charAt(i) == '/') {
				ind = i;
				break;
			}
		}
		return Double.parseDouble(fraction.substring(0, ind));
	}
	
	public static double parseD(String fraction) {
		int len = fraction.length();
		int ind = 0;
		for (int i = 0; i < len; i++) {
			if (fraction.charAt(i) == '/') {
				ind = i;
				break;
			}
		}
		return Double.parseDouble(fraction.substring(ind + 1));
	}

}
