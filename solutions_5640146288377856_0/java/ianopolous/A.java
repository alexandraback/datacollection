import java.io.*;
import java.util.*;
import java.util.stream.*;

public class A {
	static boolean print = false;
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new FileReader(args[0]));
		int T = Integer.parseInt(r.readLine());
		for (int i=0; i < T; i++) {
			List<Integer> props = Arrays.asList(r.readLine().split(" ")).stream().map(Integer::parseInt).collect(java.util.stream.Collectors.toList());
			int R = props.get(0);
			int C = props.get(1);
			int W = props.get(2);
			int res = solve(R, C, W);
			System.out.println("Case #"+(i+1)+": " + res);
		}
	}


	public static int solve(int R, int C, int W) {
		if (W == 1)
			return R * C;
		// solve for one row, ruling out the last position in this row
		int oneRow = C/W;

		int total = (R-1)*oneRow;
		// add in end game after first hit
		total += oneRow;
		total += W -1;
		if (C % W != 0)
			total++;
		return total;
	}
}