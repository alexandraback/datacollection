import java.io.BufferedReader;
import java.io.InputStreamReader;

public class A {
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int nt = Integer.parseInt(in.readLine());

		for (int t = 1; t <= nt; t++) {
			String s = in.readLine();
			System.out.println("Case #" + t + ": " + solve(s));
		}
	}

	private static String solve(String s) {
		if(s.isEmpty())
			return "";	
		int max = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) >= s.charAt(max))
				max = i;
		}
		StringBuilder sb = new StringBuilder();
		sb.append( s.charAt( max ) );
		sb.append(solve(s.substring(0, max)));
		sb.append(s.substring(max + 1, s.length()));
		return sb.toString();
	}
}
