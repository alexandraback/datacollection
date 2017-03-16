package Qualification2013;


import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;



public class FairAndSquare {

	private static char[] a = new char[]{'1','2','3','4','5','6','7','8','9'};
	private static char[] b = new char[]{'0','1','2','3','4','5','6','7','8','9'};
	private static BigInteger min, max;
	private static int[] pointerB;
	private static int numB, pointerA, palinLen;
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		String inFile = "in"+File.separator+"C-large-1.in.txt";
		String outFile = "out"+File.separator+"C-large-1.out";
		
//		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader in = new BufferedReader(new FileReader(inFile));
		PrintWriter out = new PrintWriter(new FileWriter(outFile));

		String s = "";
		String[] sArray = null;
		
		// num examples
		s = in.readLine();
		int t = Integer.parseInt(s);
		
//		int element;
//		TreeSet<Integer> elements;
//		boolean valid;

		long numPalins;
		
		String startString;
		BigInteger biPalindrome, squaredPalindrome;

		for (int i = 0; i < t; i++) {
			s = in.readLine();
			sArray = s.split("\\s+");
			
			min = new BigInteger(sArray[0]);
			max = new BigInteger(sArray[1]);
			startString = sqrt(min).toString();
			
			palinLen = startString.length();
			numB = (palinLen-1)/2;
			pointerB = new int[numB];
			
			// init min
			pointerA = Character.getNumericValue(startString.charAt(0))-1;
			for (int j = 1; j <= numB; j++)
				pointerB[j-1] = Character.getNumericValue(startString.charAt(j));
				
			// create palindrome
			numPalins = 0;
			biPalindrome = createPalindrome();
			squaredPalindrome = biPalindrome.pow(2);
			while (squaredPalindrome.compareTo(max) != 1) { // <= max
				if (squaredPalindrome.compareTo(min) != -1) { // >= min
					

				
				// check square also palin
				
				if (isPalin(squaredPalindrome)) {
					numPalins++;
//					System.out.println(biPalindrome);
				}


				}
//				System.out.println(biPalindrome+"\t"+squaredPalindrome);
				
				updatePointer();
				biPalindrome = createPalindrome();
				squaredPalindrome = biPalindrome.pow(2);
			}
//			System.out.println(biPalindrome+"\t"+squaredPalindrome);
			
			out.println("Case #"+(i+1)+": "+numPalins);
			

			
			


		}
		
		


		in.close();
		out.close();
	}

	private static BigInteger createPalindrome() {
		
		
		StringBuilder palindrome = new StringBuilder(palinLen);
		palindrome.append(a[pointerA]);
		for (int j = 1; j <= numB; j++)
			palindrome.append(b[pointerB[j-1]]);
		
		if (palinLen % 2 == 0)
			for (int j = numB; j >= 0; j--)
				palindrome.append(palindrome.charAt(j));
		else
			for (int j = numB-1; j >= 0; j--)
				palindrome.append(palindrome.charAt(j));
		
		
		
		return new BigInteger(palindrome.toString());
	}
	
	private static void updatePointer() {
		
		int pUpdate;
		boolean hasCarry;
		if (numB > 0) {
			pUpdate = numB-1;
			do {
				if (pointerB[pUpdate] == 9) {
					pointerB[pUpdate] = 0;
					hasCarry = true;
				} else {
					pointerB[pUpdate]++;
					hasCarry = false;
				}
				pUpdate--;
			} while (hasCarry && pUpdate >= 0);
			if (hasCarry)
				pointerA++;
		} else {
			pointerA++;
		}
		
		if (pointerA > 8) {
			pointerA = 0;
			pointerB = Arrays.copyOf(pointerB, pointerB.length+1);
			pointerB[pointerB.length-1] = 0;
			palinLen++;
			numB = (palinLen-1)/2;
		}
	}

	private static boolean isPalin(BigInteger squaredPalindrome) {
		String s = squaredPalindrome.toString();
		int sLen = s.length();
		for (int i = 0; i < sLen/2; i++) {
			if (s.charAt(i) != s.charAt(sLen-(i+1)))
				return false;
		}
		return true;
	}

	private static BigInteger sqrt(BigInteger n) {
		  BigInteger a = BigInteger.ONE;
		  BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
		  while(b.compareTo(a) >= 0) {
		    BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
		    if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
		    else a = mid.add(BigInteger.ONE);
		  }
		  return a.subtract(BigInteger.ONE);
		}

	
	

}
