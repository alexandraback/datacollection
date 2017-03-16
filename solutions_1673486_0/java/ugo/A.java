package gcj2012.R1A;

import java.util.Arrays;
import java.util.Scanner;

public class A {

	/**
	 * @param args
	 */
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] f){
				
		long numCases = Long.parseLong(sc.nextLine());
		for(long kase = 0 ; kase < numCases ; kase++){
			double min = Double.MAX_VALUE;
			double val = 0;
			int typed = sc.nextInt();
			int len = sc.nextInt();
			double[] probs = new double[typed];
			double[] probTimes = new double[typed];
			for(int i = 0 ; i < typed; i ++)
				probs[i] = sc.nextDouble();
			
			double tmp = 1;
			for(int i = 0 ; i < typed ; i++){
				tmp *= probs[i];
				probTimes[i] = tmp;
			}
//			System.out.println(Arrays.toString(probTimes));
			
			// gogo
			val = probTimes[typed-1] * (len-typed+1) + (1-probTimes[typed-1]) * (len-typed+1 + len+1);
//			System.out.println(val);
			min = Math.min(val, min);
			
			for(int backs = 1 ; backs < typed ; backs++){
				val = probTimes[typed-1-backs] * (2*backs+len-typed+1)
						+ (1-probTimes[typed-1-backs]) * (2*backs+len-typed+1 + len + 1);
//				System.out.println(val);
				min = Math.min(min, val);
			}
			
			
			min = Math.min(min, 1+ len+1);
//			System.out.println(val);
			System.out.println("Case #" + (kase+1) + ": " + min);
			
		}
	}

}
/* 
3
2 5
0.6 0.6
1 20
1
3 4
1 0.9 0.1
Case #1: 7.000000
Case #2: 20.000000
Case #3: 4.500000
*/