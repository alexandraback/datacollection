import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;


public class Diamonds {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new File("B-small-attempt0(1).in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("B-small-attempt0(1).out"),false));
		int t = scanner.nextInt();
		scanner.nextLine();
		for (int i = 0; i < t; i++){
			int n = scanner.nextInt();
			int x = scanner.nextInt();
			int y = scanner.nextInt();

			double prob = calcProb(n,x,y);
			
			writer.write("Case #"+(i+1)+": "+prob+" \n");
		}
		scanner.close();
		writer.close();
	}

	private static double calcProb(int n, int x, int y) {
		int sum = Math.abs(x) + Math.abs(y);
		int stufe = sum-1;
		
		int needed;
		if (stufe == 1) {
			needed = 1;
		} else {
			needed = 2*stufe*stufe-stufe;
		}
		
		if (n>= needed) {
			return 1;
		}
		
		int maxstufe;
		if (n < 6) maxstufe = 1;
		else {
			maxstufe = findMaxstufe(n);
		}
		
		if (sum <= (maxstufe-1) * 2) {
			return 1;
		}
		
		int restN = n - 2*maxstufe*maxstufe-maxstufe;
		
		int maxfalsch = 2*maxstufe-2;
		
		if (restN - y > maxfalsch) {
			return 1;
		}
		if (restN-y <=0) return 0;
		return 1 - probRechts(restN-y,restN);
	}

	private static double probRechts(int k, int n) {
		return binCoeff(n,k).intValue() * Math.pow(0.5, n);
	}
	
	// from http://www.java-forum.org/mathematik/81941-binomialkoeffizient.html
	public static BigInteger binCoeff(int n, int k)
	{
	    if ((n < 0) || (k < 0) || (k > n))
	        throw new IllegalArgumentException(n + ", " + k);
	    if (k > n/2) k = n - k;
	 
	    BigInteger result = BigInteger.ONE;
	 
	    for (int i = n - k + 1; i <= n; i++)
	        result = result.multiply(new BigInteger("" + i));
	    for (int i = 2; i <= k; i++)
	        result = result.divide(new BigInteger("" + i));
	 
	    return result;
	}

	private static int findMaxstufe(int n) {
		int min = 2;
        int max = 710;
 
        int last = 1;
 
        while(min < max) {
        	int mid = (min+max)/2;
        	if (n >= 2 * mid*mid -mid) { // rechts weiter
	        	last = mid;
	        	min = mid+1;
	        } else if (n < 2 * mid*mid -mid) { // links weiter
	        	max = mid-1;
	        }
        	
        	if (min == max) {
        		if (n >= 2 * min*min -min) { // rechts weiter
    	        	last = min;
        		}
        	}
        }
        
        return last;
	}

}
