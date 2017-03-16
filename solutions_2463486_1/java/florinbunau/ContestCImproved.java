package contest;
import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class ContestCImproved {

	String OUTPUT_FOLDER = "input-contest/";
	String IN_NAME = "C-large-1.in";
	String OUT_NAME = "C-large-1.out";
	
	int T;
	String A, B;

	Set<String> generatorSet = new HashSet<String>();
	ArrayList<BigInteger> generatorsAsBigIntegers = new ArrayList<BigInteger>();
	ArrayList<BigInteger> fairAndSquareNumbersAsBigIntegers = new ArrayList<BigInteger>();
	
	
    public static void main(String[] args) throws IOException {
    	ContestCImproved problem = new ContestCImproved();
    	
		problem.readInput();
	}
    
    public void gen(String str, int len, int sumDigitSquare) {
    	if (len >= 26) {
    		return;
    	}
    	generatorSet.add(str + reverseString(str));
    	for (int i = 0; i <= 2; ++i) {
    		if (2 * sumDigitSquare + (i*i) < 10) {
    			generatorSet.add(str + i + reverseString(str));
    		}
    	}
    	for (int i = 0; i <= 2; ++i) {
    		if (2 * (sumDigitSquare + (i*i)) < 10) {
    			gen(str + i, len + 1, sumDigitSquare + (i*i));
    		}
    	}
    }
    
    public static String reverseString(String r) {
		int length = r.length();
		StringBuilder reverse = new StringBuilder();
		for(int i = length; i > 0; --i) {
			char result = r.charAt(i-1);
			reverse.append(result);
		}
		return reverse.toString();
	}
    
    public void preCompute() {
    	gen("0", 1, 0);
    	gen("1", 1, 1);
    	gen("2", 1, 4);
    	generatorSet.add("1");
    	generatorSet.add("2");
    	generatorSet.add("3");
    	
    	for (String s : generatorSet) {
    		generatorsAsBigIntegers.add(new BigInteger(s));
    	}
    	Collections.sort(generatorsAsBigIntegers);
    	while (generatorsAsBigIntegers.remove(new BigInteger("0")));
    	
    	//System.out.println("Generator numbers size : " + generatorsAsBigIntegers.size());
    	
    	for (BigInteger bi : generatorsAsBigIntegers) {
    		if (isPalindrome(bi.toString())) {
    			BigInteger square = bi.multiply(bi);
    			if (isPalindrome(square.toString())) {
    			    fairAndSquareNumbersAsBigIntegers.add(square);
    			}
    		}
    		
    	}
    	
    	Collections.sort(fairAndSquareNumbersAsBigIntegers);
    }

    public void solveCase(int testCase) throws IOException  {
    	int match1 = Collections.binarySearch(fairAndSquareNumbersAsBigIntegers, new BigInteger("" + A));
    	int match2 = Collections.binarySearch(fairAndSquareNumbersAsBigIntegers, new BigInteger("" + B));
    	
    	if (match1 < 0) {
    		match1 = Math.abs(match1);
    	}
    	else {
    		match1++;
    	}
    	if (match2 < 0) {
    		match2 = Math.abs(match2);
    	}
    	else {
    		match2 += 2;
    	}
    	
    	writeOutput(testCase, match2 - match1);
    }
    
	public boolean isPalindrome(String s) {
		int l = s.length();
		for (int i = 0; i < l / 2; ++i) {
			if (s.charAt(i) != s.charAt(l-1-i)) {
				return false;
			}
		}
		return true;
	}

    public void readInput() throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(OUTPUT_FOLDER + IN_NAME));

		preCompute();
		
		String line = br.readLine();
		T = Integer.parseInt(line);
	
		try {
			for (int t = 0; t < T; ++t) {
				line = br.readLine();
				String nbs[] = line.split(" ");
				A = nbs[0];
				B = nbs[1];
				solveCase(t);
			}

		} finally {
			br.close();
		}
	}
    
    public void writeOutput(int testCase, int answer) throws IOException {
    	boolean appendToFile = !(testCase == 0);
    	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(OUTPUT_FOLDER + OUT_NAME, appendToFile)));
    	out.printf("Case #%d: %d", testCase+1, answer);
    	if (testCase < T-1) {
    		out.println();
    	}
        out.close();
    }
}
