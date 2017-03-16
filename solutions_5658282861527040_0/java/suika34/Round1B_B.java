import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;


public class Round1B_B {

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String line = br.readLine();
			int T = Integer.parseInt(line);

			for (int i=1; i<=T; i++) {
				line = br.readLine();
				String[] a = line.split(" ");
				int A = Integer.parseInt(a[0]);
				int B = Integer.parseInt(a[1]);
				int K = Integer.parseInt(a[2]);
				String result = solve(A, B, K);

				System.out.println("Case #"+i+": "+result);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static String solve(int A, int B, int K) {
		if (A > B) {
			int t = A;
			A = B;
			B = t;
		}
		int ret = 0;
		for (int i=0; i<A; i++) {
			for (int j=0; j<B; j++) {
				if ((i & j) < K) {
					//System.out.println(i+" "+j);
					ret += 1;
				}
			}
		}
		return ""+ret;
	}
}
