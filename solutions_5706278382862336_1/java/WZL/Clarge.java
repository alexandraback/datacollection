package R1C;

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Scanner;

public class Clarge {

	
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new File("A-large.in"));
		int numCases = scanner.nextInt();
		ArrayList<Integer> res = new ArrayList<Integer>();
		BigDecimal tf = new BigDecimal(Math.pow(2, 40));
		BigDecimal one = new BigDecimal(1);
		BigDecimal zero = new BigDecimal(0);
		
		// Each case variables
		BigDecimal num;
		BigDecimal den;
		BigDecimal frac;
		String temp;
		int years;
		
		
		// Each case loop		
		for (int i = 0; i < numCases; i++) {
			temp = scanner.next();
			num = (parseN(temp));
			den = (parseD(temp));
			frac = zero;
			try {
				frac = num.divide(den);
			} catch (ArithmeticException e) {
				res.add(-1);
				continue;
			}
			years = 0;

			while (frac.compareTo(one) == -1) {
				frac = frac.multiply(new BigDecimal(2));
				years++;
				if (frac.compareTo(one) >= 0) {
					frac = frac.subtract(one);
					res.add(((frac.multiply(tf)).remainder(one).compareTo(zero) == 0) ? years : -1);
					break;
				}
			}
			
		}
		
		PrintWriter result = new PrintWriter(new FileWriter("1CAL.txt"));
		for (int i = 0; i < numCases; i++) {
			result.println("Case #" + (i + 1) + ": " + (res.get(i) == -1 ? "impossible" : res.get(i)));
		}
		result.close();
	}
	
	
	
	public static BigDecimal parseN(String fraction) {
		int len = fraction.length();
		int ind = 0;
		for (int i = 0; i < len; i++) {
			if (fraction.charAt(i) == '/') {
				ind = i;
				break;
			}
		}
		return new BigDecimal(Double.parseDouble(fraction.substring(0, ind)));
	}
	
	public static BigDecimal parseD(String fraction) {
		int len = fraction.length();
		int ind = 0;
		for (int i = 0; i < len; i++) {
			if (fraction.charAt(i) == '/') {
				ind = i;
				break;
			}
		}
		return new BigDecimal(Double.parseDouble(fraction.substring(ind + 1)));
	}

}
