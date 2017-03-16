import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class A {

	public static void main(String[] args) throws Exception {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			int[] S = getShyness(in);
			int friends = minFriends(S);
			out.println("Case #" + t + ": " + friends);
		}
		out.close();
	}
	
	private static int[] getShyness(BufferedReader in) throws Exception {
		String[] data = in.readLine().split(" ");
		int max = Integer.parseInt(data[0]);
		int[] S = new int[max + 1];
		for (int i = 0; i <= max; i++)
			S[i] = data[1].charAt(i) - '0';
		return S;
	}

	private static int minFriends(int[] S) {
		int standing = 0;
		int friends = 0;
		for (int i = 0; i < S.length; i++) {
			if (standing < i) {
				int extra = i - standing;
				friends += extra;
				standing += extra;
			}
			standing += S[i];
		}
		return friends;
	}
}
