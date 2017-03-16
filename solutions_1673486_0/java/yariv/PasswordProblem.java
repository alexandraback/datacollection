package round1A;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class PasswordProblem {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(reader.readLine());
		for (int i=1; i<=T; i++) {
			String line = reader.readLine();
			StringTokenizer tok = new StringTokenizer(line);
			int A = Integer.parseInt(tok.nextToken());
			int B = Integer.parseInt(tok.nextToken());
			line = reader.readLine();
			tok = new StringTokenizer(line);
			double[] goodPrefixP = new double[A+1];
			int j = 0;
			double prod = 1;
			while (tok.hasMoreTokens()) {
				Double p = Double.valueOf(tok.nextToken());
				goodPrefixP[j++] = prod;
				prod*=p;
			}
			goodPrefixP[A] = prod;
			double minCost = B+2;
			for (int k=0; k<=A; k++) {
				double cost = goodPrefixP[A-k]*(B-A+1+2*k)+(1-goodPrefixP[A-k])*(2*B-A+2+2*k);
				if (minCost > cost) minCost = cost;
			}
			System.out.printf("Case #%d: %f\n", i, minCost);
		}
	}

}
