import java.util.*;

public class A {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		StringBuilder br = new StringBuilder();
		int numCases = in.nextInt();
		for(int caseNum = 1; caseNum <= numCases; ++caseNum) {
			int a = in.nextInt();
			int b = in.nextInt();
			double minimum = 2*b + 10;
			double temp;
			double[] probs = new double[a+1];
			probs[0] = 1.0;
			for(int i = 0; i <= a; ++i) {
				if(i != 0)
					probs[i] = probs[i-1] * (in.nextDouble());
				temp = ( (a-i) + (b - i) + 1) * probs[i] + ( (a-i) + (b-i) + 1 + b + 1) * (1 - probs[i]);
				minimum = Math.min( minimum, temp);
			}
			//also do the case where we immediately give up
			temp = b + 2;
			minimum = Math.min(minimum, temp);
			br.append( String.format("Case #%d: %f\n", caseNum, minimum));
		}
		System.out.print(br);
	}
}