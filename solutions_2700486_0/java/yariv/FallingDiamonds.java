package round1b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class FallingDiamonds {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(reader.readLine());
		for (int i=1; i<=T; i++) {
			String line = reader.readLine();
			StringTokenizer tok = new StringTokenizer(line);
			int N = Integer.parseInt(tok.nextToken());
			int X = Integer.parseInt(tok.nextToken());
			int Y = Integer.parseInt(tok.nextToken());
			int layer = (Math.abs(X)+Y)/2;
			int belowLayer = 2*layer*layer-layer;
			double probability;
			int inLayer = N - belowLayer;
			if (inLayer <= Y) {
				probability = 0.0;
			}
			else if (X==0) {
				if (inLayer >= 4*layer+1) {
					probability = 1.0;
				}
				else {
					probability = 0.0;
				}
			}
			else {
				if (inLayer > Y + 2*layer) {
					probability = 1.0;
				}
				else {
					BigInteger configurations = BigInteger.valueOf(0);
					BigInteger coefficient = BigInteger.valueOf(1);
					for (int j=inLayer; j>Y; j--) {
						configurations = configurations.add(coefficient);
						coefficient = coefficient.multiply(BigInteger.valueOf(j)).divide(BigInteger.valueOf(inLayer-j+1));
					}
					BigDecimal prob = new BigDecimal(configurations);
					for (int j=0; j<inLayer; j++) {
						prob = prob.divide(BigDecimal.valueOf(2));
					}
					probability = prob.doubleValue();
				}
			}
			System.out.printf("Case #%d: %f\n", i, probability);
		}
	}
}
