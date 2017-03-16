import java.util.ArrayList;
import java.util.Scanner;


public class ProblemA {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int numTestCases = sc.nextInt();
		
		for(int i = 0; i < numTestCases; i++){
			runTest(sc, i + 1);
		}
	}
	
	public static void runTest(Scanner sc, int testNum){
		int numTyped = sc.nextInt(); // A
		int totalChars = sc.nextInt(); // B
		
		double[] probs = new double[numTyped];
		for(int i = 0; i < probs.length; i++){
			probs[i] = sc.nextDouble(); // doubles for each test
		}
		
		// double[] perms = perms(probs);
		
		double exp = checkAll(numTyped, totalChars, probToPt(probs));
		
		print("Case #" + testNum + ": " + exp);
	}
	
	public static double inv(double val){
		return 1 - val;
	}
	
	public static double checkAll(int numTyped, int totalChars, double[] probs){
		double yay = Double.MAX_VALUE;
		
		for(int i = 0; i <= numTyped; i++){
			double val = expected(probs, i, totalChars);
			
			yay = val < yay ? val : yay;
		}
		
		// hit enter straight off
		if(totalChars + 2 < yay){
			yay = totalChars + 2;
		}
		
		return yay;
	}
	
	public static double expected(double[] probs, int backSpaces, int totalChars){
		double ex = 0;
		
		int baseKeys = totalChars - probs.length + 1;
		int backSpaceAdditions = backSpaces * 2;
		int incKeys = totalChars + 1;
		
		// prob for being right or wrong
		double rightProb = probs.length - 1 - backSpaces < 0 ? 1 : probs[probs.length - 1 - backSpaces];
		double wrongProb = 1 - rightProb;
		
		int rightKeys = baseKeys + backSpaceAdditions;
		int wrongKeys = baseKeys + backSpaceAdditions + incKeys;
		if(backSpaces == probs.length){
			wrongKeys -= incKeys;
		}
		
		ex = (rightProb * rightKeys) + (wrongProb * wrongKeys);
		//print(" bs: " + backSpaces + " ri: " + rightKeys + " wr: " + wrongKeys + " rp: " + rightProb + " wp: " + wrongProb + " ex: " + ex);
		return ex;
	}
	
	//public static int numSafe(int backSpaces, int numTyped, int totalChars){
		
	//}
	
	// find probs of reaching pt
	public static double[] probToPt(double[] probs){
		double[] toPt = new double[probs.length];
		
		double cumu = probs[0];
		toPt[0] = cumu;
		
		for(int i = 1; i < toPt.length; i++){
			cumu *= probs[i];
			toPt[i] = cumu;
		}
		
		return toPt;
	}
	
	public static double[] perms(double[] probs){
		if(probs.length == 1){
			return probs;
		} else if(probs.length == 2){
			double[] res = new double[4];
			res[0] = probs[0] * probs[1];
			res[1] = probs[0] * inv(probs[1]);
			res[2] = inv(probs[0]) * probs[1];
			res[3] = inv(probs[0]) * inv(probs[1]);
					
		    return res;
		} else {
			double[] res = new double[8];
			double[] p = probs;
			
			res[0] = p[0] * p[1] * p[2];
			res[1] = inv(p[0]) * p[1] * p[2];
			res[2] = p[0] * inv(p[1]) * p[2];
			res[3] = p[0] * p[1] * inv(p[2]);
			res[4] = inv(p[0]) * inv(p[1]) * p[2];
			res[5] = inv(p[0]) * p[1] * inv(p[2]);
			res[6] = p[0] * inv(p[1]) * inv(p[2]);
			res[7] = inv(p[0]) * inv(p[1]) * inv(p[2]);
			
			return res;
		}
		
		
	}
	
	public static double route1(int numTyped, int totalChars, double[] probs, double[] perms){
		double count = 0;
		
		
		
		return count;
	}
	
	public static double route2(int numTyped, int totalChars, double[] probs){
		double count = 0;
		
		
		
		return count;
	}
	
	public static double route3(int numTyped, int totalChars, double[] probs){
		return totalChars + 2; // length plus 2 enters
	}

	public static void print(String str){
		System.out.println(str);
	}
}
