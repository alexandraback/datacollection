import java.util.*;

public class ProblemA {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();

		for (int cs = 0; cs < cases; cs++) {
			int A = sc.nextInt();
			int B = sc.nextInt();

			double[] p = new double[A];

			for (int i = 0; i < A; i++) {
				p[i] = sc.nextDouble();
			}

			double[] prod = new double[1 << A];
			double[] poss = new double[5];
			boolean []vis = new boolean[5];
			vis[0] = true;
			vis[4] = true;
			
			if (A == 1) {
				prod[0] = p[0];
				prod[1] = 1 - p[0];
			} else if (A == 2) {
				prod[0] = p[0] * p[1];
				prod[1] = p[0] * (1 - p[1]);
				prod[2] = (1 - p[0]) * p[1];
				prod[3] = (1 - p[0]) * (1 - p[1]);
			} else {
				prod[0] = p[0] * p[1] * p[2];
				prod[1] = p[0] * p[1] * (1 - p[2]);
				prod[2] = p[0] * (1 - p[1]) * p[2];
				prod[3] = p[0] * (1 - p[1]) * (1 - p[2]);

				prod[4] = (1 - p[0]) * p[1] * p[2];
				prod[5] = (1 - p[0]) * p[1] * (1 - p[2]);
				prod[6] = (1 - p[0]) * (1 - p[1]) * p[2];
				prod[7] = (1 - p[0]) * (1 - p[1]) * (1 - p[2]);
			}

			for (int i = 0; i < prod.length; i++) {
				if (i == 0) {
					poss[0] += (B - A + 1) * prod[i];
				} else {
					poss[0] += (2 * B - A + 2) * prod[i];
				}

				if (A > 0) {
					vis[1] = true;
					if (i <= 1) {
						poss[1] += prod[i] * (B - A + 3);
					} else {
						poss[1] += prod[i] * (2 * B - A + 4);
					}
				}

				if (A > 1) {
					vis[2] = true;
					if (i <= 3) {
						poss[2] += prod[i] * (B - A + 5);
					} else {
						poss[2] += prod[i] * (2 * B - A + 6);
					}
				}

				if (A > 2){
					vis[3] = true;
					poss[3] = B + 4;
				}	

				poss[4] = B + 2;
			}
			double result = Double.MAX_VALUE;
			
			for(int i = 0 ; i < poss.length; i++){
				if(vis[i]){
					result = Math.min(poss[i],result);
				}
			}
			System.out.println("Case #" + (cs + 1) + ": " + result);
		}
	}

}
