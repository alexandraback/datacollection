import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class pancakes {

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("B-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter("outB.txt"));

		int N = Integer.parseInt(in.readLine());
		for (int i = 1; i <= N; ++i) {
			int D = Integer.parseInt(in.readLine());
			//
			int[] data = new int[D];
			StringTokenizer st = new StringTokenizer(in.readLine());
			for (int j = 0; j < D; ++j) {
				data[j] = Integer.parseInt(st.nextToken());
			}

			int result = solve(data);
			//
			out.println("Case #" + i + ": " + result);
		}
		
		out.close();
		in.close();
	}

	private static int solve(int[] data) {
		//Arrays.sort(data);
		int best = Integer.MAX_VALUE;
		int max_p = 0;
		for (int i = 0; i < data.length; ++i)
			if (data[i] > max_p) max_p = data[i];

		// try different numbers for eat-a-pancake times
		for (int i = 1; i <= max_p; ++i) {
			int eat_a_pancake_minutes = i;
			// all bigger plates have to be split. find time wasted on splits
			int special_minutes = 0;
			for (int j = 0; j < data.length; ++j) {
				// how many splits needed for that plate
				int splits = (data[j] + eat_a_pancake_minutes - 1) / eat_a_pancake_minutes - 1;
				special_minutes += splits;
			}
			int total_time = eat_a_pancake_minutes+special_minutes;
			if (total_time < best) best = total_time;
		}
		
		return best;
	}

}
