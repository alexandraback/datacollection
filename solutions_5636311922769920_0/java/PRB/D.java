import java.math.BigInteger;
import java.util.Scanner;

public class D {
	private String getTiles(int K, int C, int S) {

		BigInteger bigK = new BigInteger("" + K);
		BigInteger tileDiff = bigK.pow(C - 1);
		BigInteger tile = new BigInteger("1");
		StringBuilder solution = new StringBuilder("1");
		for (int i = 1; i < S; i++) {
			tile = tile.add(tileDiff);
			solution.append(" " + tile.toString());
		}
		return solution.toString();
	}

	public static void main(String[] args) {
		Scanner in = null;
		D d = new D();
		try {
			in = new Scanner(System.in);
			int count = in.nextInt();
			in.nextLine();
			for (int test = 1; test <= count; test++) {
				int K = in.nextInt();
				int C = in.nextInt();
				int S = in.nextInt();
				String result = d.getTiles(K, C, S);
				System.out.println("Case #" + test + ": " + result);
			}
			in.close();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
