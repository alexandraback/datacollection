import java.util.*;

public class A{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int numCases = sc.nextInt();
		for(int caseNum = 1; caseNum <= numCases; caseNum++){
			int a = sc.nextInt();
			int b = sc.nextInt();
			double[] p = new double[a];
			for(int i = 0; i < a; i++){
				if(sc.hasNextDouble()){
					p[i] = sc.nextDouble();
				}
				else{
					p[i] = 1.0 * sc.nextInt();
				}
			}
			double giveUp = b + 2.0;
			double[] expected = new double[a + 1];
			double prob = 1.0;
			for(int i = 0; i < a; i++){
				expected[i] = (prob * (b - a + (2 * (a - i)) + 1)) + ((1.0 - prob) * ((2 * b) - a + (2 * ((a - i) + 1))));
				prob *= p[i];
			}
			expected[a] = (prob * (b - a + 1)) + ((1.0 - prob) * ((2 * b) - a + 2));

			double minExpected = Double.POSITIVE_INFINITY;
			for(double d : expected){
				//System.out.println(d);
				if(d < minExpected){
					minExpected = d;
				}
			}
			//System.out.println(giveUp);
			if(giveUp < minExpected){
				minExpected = giveUp;
			}
			System.out.printf("Case #%d: %.6f\n", caseNum, minExpected);
		}
	}
}