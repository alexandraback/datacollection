import java.util.*;

public class CSmall {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int TC = sc.nextInt();
		for (int i = 1; i <= TC; i++) {

			int S = sc.nextInt();
			int C = sc.nextInt();
			int K = sc.nextInt();
			
			String ans = buildAnswer(K);

			System.out.println("CASE #" + i + ": " + ans);
		}
	}

	private static String buildAnswer(int k) {
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= k; i++) {
			sb.append(i);
			sb.append(" ");
		}
		
		return sb.toString().trim();
	}

}
