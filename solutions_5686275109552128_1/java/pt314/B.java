import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class B {

	public static void main(String[] args) throws Exception {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			int[] P = getPancakes(in);
			int minutes = numMinutes(P);
			out.println("Case #" + t + ": " + minutes);
		}
		out.close();
	}
	
	private static int[] getPancakes(BufferedReader in) throws Exception {
		int D = Integer.parseInt(in.readLine());
		String[] data = in.readLine().split(" ");
		int[] P = new int[D];
		for (int i = 0; i < D; i++)
			P[i] = Integer.parseInt(data[i]);
		return P;
	}

	private static int numMinutes(int[] P) {
		int max = P[0];
		for (int i = 1; i < P.length; i++)
			if (P[i] > max)
				max = P[i];
		
		int minutes = max;
		for (int nonSpecial = 1; nonSpecial <= max; nonSpecial++) {
			int special = 0;
			for (int i = 0; i < P.length; i++)
				if (P[i] > nonSpecial)
					special += (P[i] - 1) / nonSpecial;
			if (nonSpecial + special < minutes)
				minutes = nonSpecial + special;
		}
		return minutes;
	}
}
