import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Round1A_A {


	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Round1A_A main = new Round1A_A();
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			String line = bf.readLine();
			int T = Integer.parseInt(line);
			for (int testcaseIndex=0; testcaseIndex<T; testcaseIndex++) {

				String testCase = bf.readLine();
				String[] array = testCase.split(" ");
				int A = Integer.parseInt(array[0]);
				int B = Integer.parseInt(array[1]);
				testCase = bf.readLine();
				array = testCase.split(" ");
				double[] prob = new double[A];
				for (int i=0; i<A; i++) {
					prob[i] = Double.parseDouble(array[i]);
				}
						
				double out = main.solve(A,B, prob);
				
				System.out.print("Case #"+(testcaseIndex+1)+": ");
				System.out.println(out);
				
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public double solve(int A, int B, double[] prob) {
		double p = 1.0;
		for (double pp : prob) {
			p *= pp;
		}
		double ret = (B-A + 1) * p + (B-A+1 + B + 1) * (1-p);

		for (int i=1; i<=A; i++) {
			p = p / prob[A-i];
			int type = B-A+2*i + 1;
			double temp = type * p + (type + B+1) * (1-p);
			if (ret > temp) {
				ret = temp;
			}
		}
		
		if (ret > B+2) {
			ret = B+2;
		}
		return ret;
	}
}
