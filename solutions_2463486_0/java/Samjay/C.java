package con2013Q;

import java.io.*;
import java.util.*;

public class C {
	
	private static final String islarge = "-large";
	private static final String fileName = "results/con2013Q/"+C.class.getSimpleName().toLowerCase();//+islarge;
	private static final String inputFileName = fileName + ".in";
	private static final String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	static ArrayList<Long> result;
	static int MAX = 10000001;
	private void solve() {
		int A = in.nextInt(),
			B = in.nextInt();
		int am = 0;
		int idx = 0;
		// go to the right idx
		while(idx < result.size() && result.get(idx) < A)
			idx++;
		// go to the end
		while(idx < result.size() && result.get(idx) <= B){
			am++;idx++;
		}
		out.println(am);
		
	}

	public static void preproc(){
		ArrayList<Integer> pals = allPalindromic(MAX);
		result = new ArrayList<Long>();
		for(int i:pals){
			long posres = (long)i*i;
			if(isPalindrome(posres))
				result.add(posres);
		}
		Collections.sort(result);
	}
	
    public static boolean isPalindrome(long number) {
        long palindrome = number;
        long reverse = 0;

        while (palindrome != 0) {
            long remainder = palindrome % 10;
            reverse = reverse * 10 + remainder;
            palindrome = palindrome / 10;
        }
        if (number == reverse) {
            return true;
        }
        return false;
    }

	public static ArrayList<Integer> allPalindromic(int limit) {

		ArrayList<Integer> result = new ArrayList<Integer>();

	    for (int i = 0; i <= 9 && i <= limit; i++)
	        result.add(i);

	    boolean cont = true;
	    for (int i = 1; cont; i++) {
	        StringBuffer rev = new StringBuffer("" + i).reverse();
	        cont = false;
	        for (String d : "0123456789".split("")) {
	            int n = Integer.parseInt("" + i + d + rev);
	            if (n <= limit) {
	                cont = true;
	                result.add(n);
	            }
	        }
	    }

	    return result;
	}
	public static void main(String[] args) throws IOException {
		long start = System.currentTimeMillis();
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		preproc();
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new C().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
		long stop = System.currentTimeMillis();
		System.out.println(stop-start+" ms");
	}
}
