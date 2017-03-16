import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Passwd {

	public static void main(String[] args) throws Exception {		
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		in.nextLine();
		for (int i = 0; i < T; i++) {
			int A = in.nextInt();
			int B = in.nextInt();
			List<Double> P = new ArrayList<Double>();
			for (int p = 0; p < A; p++)
				P.add(in.nextDouble());
			double answer = compute(A, B, P);
			System.out.println("Case #" + (i + 1) + ": " + answer);
		}
	}

	private static double compute(int A, int B, List<Double> P) {
		double res = B + 2;
		for (int bs = 0; bs <= A; bs++) {
			double p = 1;
			for (int x = 0; x < A - bs; x++)
				p *= P.get(x);
			double keysOk = bs + (B - A + bs) + 1;
			double keysKo = keysOk + B + 1;
			double exp = p * keysOk + (1 - p) * keysKo;
//			System.out.println("BS: " + bs + " -> " + exp);
			res = Math.min(res, exp);
		}
		return res;
	}
	
}
