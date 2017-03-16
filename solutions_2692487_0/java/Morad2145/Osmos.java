import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Arrays;

public class Osmos {

	public static void main(String[] args) throws Exception {
		String filename = "A-small-attempt0.in";
		BufferedReader in = new BufferedReader(new FileReader(filename));

		int T = Integer.parseInt(in.readLine());

		for (int test = 1; test <= T; test++) {
			String[] tokens = in.readLine().split(" ");
			long A = Long.parseLong(tokens[0]);
			int N = Integer.parseInt(tokens[1]);
			long[] sizes = new long[N];
			tokens = in.readLine().split(" ");
			for (int i = 0; i < tokens.length; i++) {
				sizes[i] = Long.parseLong(tokens[i]);
			}
			Arrays.sort(sizes);
			System.out.println("Case #" + test + ": " + solve(A, sizes, 0));
		}
		in.close();
	}

	private static long solve(long a, long[] sizes, int idx) {
		if(a<=1){
			return sizes.length;
		}
		while (idx < sizes.length && a > sizes[idx]) {
			a += sizes[idx];
			idx++;
		}
		if (idx >= sizes.length) {
			return 0;
		}
		if(idx==sizes.length-1){
			return 1;
		}

		long option1 = sizes.length - idx;

		long option2 = 0;
		while (a <= sizes[idx]) {
			a += (a - 1);
			option2++;
		}
		a += sizes[idx];

		if (option1 <= option2) {
			return option1;
		}

		option2 += solve(a, sizes, idx + 1);

		if (option1 <= option2) {
			return option1;
		} else {
			return option2;
		}
	}
}
