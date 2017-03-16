package y2013.q;

import static java.util.Arrays.deepToString;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {
	Scanner sc = new Scanner(System.in);
	Set<Double> palindromes;
	int A, B;
	
	public void read() {
		A = sc.nextInt();
		B = sc.nextInt();
	}

	public void solve() {
		int count = 0;
		for (Double a : palindromes) {
			if(A <= a && B >= a) {
				count++;
			}
		}
		System.out.println(count);
	}
	
	public static Set<Double> allPalindromes(double limit) {

	    Set<Double> result = new HashSet<Double>();
	    Set<Double> square = new HashSet<Double>();

	    result.add(1.0);
	    for (int i = 1; i <= 9 && i <= limit; i++) {
	    	result.add((double) i);
	    	if(result.contains(Math.sqrt(i))){
	    		square.add((double) i);
	    	}	    	
	    }

	    boolean go = true;
	    for (int i = 1; go; i++) {
	        StringBuffer rev = new StringBuffer("" + i).reverse();
	        go = false;
	        for (String d : "0123456789".split("")) {
	            double n = Double.parseDouble("" + i + d + rev);
	            if (n <= limit) {
	                go = true;
	                result.add(n);	                	
	                if(result.contains(Math.sqrt(n))){
	                	square.add(n);
	                }
	            }
	        }
	    }

	    return square;
	}
	

	public void run() {
		palindromes = allPalindromes(Math.pow(10,4));
		int caseT = sc.nextInt();
		for (int caseID = 1; caseID <= caseT; caseID++) {
			read();
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}

	public void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(
					args.length > 0 ? args[0] : (C.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new C().run();
	}
}
