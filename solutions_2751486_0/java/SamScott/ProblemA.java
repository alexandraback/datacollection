package round1C;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class ProblemA {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("round1C/A-small-attempt2.in"));
		PrintWriter out = new PrintWriter(new File("round1C/out.txt"));
		
		int T = sc.nextInt();
		sc.nextLine();
		
		for (int tc = 1; tc <= T; tc++) {
			
			String L = sc.next();
			int n = sc.nextInt();
			BigInteger answer = new BigInteger("0");
			BigInteger one = new BigInteger("1");
			
			int counts[] = new int[L.length()];
			boolean in = false;
			counts[L.length()-1] = isVowel(L.charAt(L.length()-1))?0:1;
			//System.out.println(counts[L.length()-1]);
			for (int i=L.length()-2; i>=0; i--) {
				if (isVowel(L.charAt(i)))
					counts[i] = 0;
				else
					counts[i] = counts[i+1]+1;
			}
			
			//for (int i=0 ; i<L.length(); i++)
			//	System.out.println(counts[i]);
			long count = 0;
			for (int i=0; i<L.length(); i++) {
				if (counts[i] >= n) {
					count += L.length() - (i+n-1);
				//	System.out.println(i+" "+count);
				}
				else 
				for (int j=i+1; j<L.length()-n+1; j++) {
					if (counts[j] >= n) {
						count += (L.length() - (j+n-1));
				//		System.out.println(j+" "+count);
						j=L.length();
					}
				}
			}

			printSolution(out, tc, ""+count);
		}
		out.close();
		sc.close();
	}

		public static boolean isVowel(char c) {
			return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
		}
	public static void printSolution(PrintWriter out, int tc, String soln) {
		out.println("Case #"+tc+": "+soln);
		out.flush();
		System.out.println("Case #"+tc+": "+soln);
		
	}
}