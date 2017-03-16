package codejam.CJ2016.QR;

import java.util.Scanner;

public class QRC {

	private static long pow(long base, int exponent) {
		if (exponent == 0) return 1l;
		long halfExp = pow(base, exponent/2);
		return ((exponent % 2 == 1) ? base : 1)*halfExp*halfExp;
	}
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int i=1; i<=t; i++){
			int n = in.nextInt();
			int j = in.nextInt();
			
			System.out.println("Case #" + i + ":");
			int logPossibilities = n/2-2;
			if (j>(1<<logPossibilities)) {
				System.out.println("Sorry!");
			} else {
				int repeatedMult = (n+1)/2;
				long curNum = 1l + pow(10, logPossibilities+1);
				long[] steps = new long[logPossibilities+1];
				steps[0] = 10;
				steps[1] = 90;
				long toAdd = 800;
				for (int k = 2; k<logPossibilities+1; k++) {
					steps[k] = steps[k-1] + toAdd;
					toAdd *= 10;
				}
				StringBuilder factorsBuilder = new StringBuilder();
				for (int k = 0; k<9; k++) {
					factorsBuilder.append(" ");
					factorsBuilder.append(1l + pow(k+2, repeatedMult));
				}
				String factors = factorsBuilder.toString();
				for (int k = 0; k < j; k++) {
					if (k>0) {
						int exponent = 0;
						while (k % (1<<(++exponent)) == 0) {}
						curNum += steps[exponent-1];
					}
					System.out.print(curNum);
					if (n%2==1) {
						System.out.print("0");
					}
					System.out.println(curNum + factors);
				}
			}
		}
		
		in.close();
	}
}
