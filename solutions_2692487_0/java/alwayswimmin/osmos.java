import java.io.*;
import java.util.*;

class osmos {
	private static int N, array[];
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("osmos.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"osmos.out")));
		int T = Integer.parseInt(f.readLine());
		for(int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(f.readLine());
			int A = Integer.parseInt(st.nextToken());
			N = Integer.parseInt(st.nextToken());
			array = new int[N];
			st = new StringTokenizer(f.readLine());
			for(int k = 0; k < N; k++) {
				array[k] = Integer.parseInt(st.nextToken());
			}
			Arrays.sort(array);
			out.println("Case #" + t + ": " + recur(0, A));
		}
		out.close();
		System.exit(0);
	}
	private static int recur(int index, int A) {
		if(index == N) {
			return 0;
		}
		if(A > array[index]) {
			return recur(index + 1, A + array[index]);
		} else {
			if(A <= 1) {
				return 1 + recur(index + 1, A);
			}
			int a = A;
			int count = 0;
			while(a <= array[index]) {
				a = 2*a - 1;
				count++;
			}
			a += array[index];
			return Math.min(count + recur(index + 1, a), 1 + recur(index + 1, A));
		}
	}
}
