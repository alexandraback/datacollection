import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.math.*;

/**
 * 
 * Google Code Jam 2013
 * @author Miloš Èernilovský - milhaus
 *
 */
public class Main {
	private static final String FILE_NAME = "C-small-attempt1"; 
	private static boolean TEST = false;

	public static void main(String[] args) throws IOException {
		if(TEST) {
			System.out.println("TEST !!!");
			createTestFile();
		}
		System.setIn(new FileInputStream(FILE_NAME + ".in"));
		System.setOut(new PrintStream(FILE_NAME + ".out"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		
		for (int i = 1; i <= t; i++) {
			long a,b;
			Scanner sc = new Scanner(br.readLine());
			a = sc.nextLong();
			b = sc.nextLong();
			
			//System.out.println("===== " + a + " - " + b + "=====");
			
			double sqrt = Math.sqrt(a);
			long min = (long) sqrt;
			if(sqrt > min) {
				min++;
			}
			
			int numOfCiphers = String.valueOf(min).length();
			int firstHalfOfCiphers = Math.round(numOfCiphers/2f);
			String firstCiphersS = String.valueOf(min).substring(0, firstHalfOfCiphers);
			long firstCiphers = Long.valueOf(firstCiphersS);
			int palindromes = 0;
			while(true) {
				StringBuilder sb = new StringBuilder();
				char[] ciphersArray = firstCiphersS.toCharArray();
				for(int j = (numOfCiphers % 2 == 0 ? ciphersArray.length : ciphersArray.length-1) - 1; j >= 0; j--) {
					sb.append(ciphersArray[j]);
				}
				
				long palindrome = Long.valueOf(firstCiphersS + sb);
				
				firstCiphers++;
				firstCiphersS = String.valueOf(firstCiphers);
				if(firstCiphersS.length() > firstHalfOfCiphers) {
					numOfCiphers++;
					if(numOfCiphers % 2 == 0) {
						firstCiphers = (long) Math.pow(10.0, numOfCiphers/2)/10;
						firstCiphersS = String.valueOf(firstCiphers);
					} else {
						firstHalfOfCiphers++;
					}
				}
				
				long squarePalindrome = (long) Math.pow(palindrome, 2.0);
				if(squarePalindrome <= b) {
					if(squarePalindrome >= a) {
						char[] sp = String.valueOf(squarePalindrome).toCharArray();
						boolean isPalindrome = true;
						for(int j = 0; j < Math.floor(sp.length/2.0); j++) {
							if(sp[j] != sp[sp.length-j-1]) {
								isPalindrome = false;
								break;
							}
						}
						if(isPalindrome) {
							palindromes++;
							//System.out.println("P: " + palindrome + "\t SP: " + squarePalindrome);
						}
					}
				} else {
					break;
				}
			}
			
			
			System.out.println("Case #" + i + ": " + palindromes);
		}
	}
	
	private static void createTestFile() throws FileNotFoundException {
		System.out.println("Creating a test file ...");
		PrintWriter pw = new PrintWriter(FILE_NAME + ".in");
		
		
		
		pw.flush();
		pw.close();
		System.out.println("Done.");
	}

}
