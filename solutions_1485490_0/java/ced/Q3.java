import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Q3 {
	private static void run(int CASE) throws Exception {
		StringTokenizer st = new StringTokenizer(readLine());
		int N = parseInt(st.nextToken());
		int M = parseInt(st.nextToken());
		long[] q1 = new long[N];
		long[] t1 = new long[N];
		long[] q2 = new long[M];
		long[] t2 = new long[M];
		st = new StringTokenizer(readLine());
		for (int i = 0; i < N; i++) {
			q1[i] = parseLong(st.nextToken());
			t1[i] = parseLong(st.nextToken());
		}
		st = new StringTokenizer(readLine());
		for (int i = 0; i < M; i++) {
			q2[i] = parseLong(st.nextToken());
			t2[i] = parseLong(st.nextToken());
		}
		//
		long max = bruteForce(0, 0, q1, t1, q2, t2, N, M, 0);
		printf("Case #%d: %d\n", CASE, max);
	}

	private static long bruteForce(int i, int j, long[] q1, long[] t1, long[] q2,
			long[] t2, int N, int M, long sum) {
		if(i>=N) return sum;
		if(j>=M) return sum;
		long maxSum = sum;
		if(t1[i]==t2[j]) {
			long shipment = Math.min(q1[i], q2[j]);
			q1[i] -= shipment;
			q2[j] -= shipment;
			if(q1[i]==0 && q2[j]==0) {
				long s = bruteForce(i+1, j+1, q1, t1, q2, t2, N, M, sum+shipment);
				if(s>maxSum) maxSum = s;
			} else if(q1[i]==0) {
				long s = bruteForce(i+1, j, q1, t1, q2, t2, N, M, sum+shipment);
				if(s>maxSum) maxSum = s;
			} else { // q2[j]==0
				long s = bruteForce(i, j+1, q1, t1, q2, t2, N, M, sum+shipment);
				if(s>maxSum) maxSum = s;
			}
			q1[i] += shipment;
			q2[j] += shipment;
			return maxSum;
		} else {
			// increment i
			long s = bruteForce(i+1, j, q1, t1, q2, t2, N, M, sum);
			if(s>maxSum) maxSum = s;
			s = bruteForce(i, j+1, q1, t1, q2, t2, N, M, sum);
			if(s>maxSum) maxSum = s;
		}
		return maxSum;
	}

	//-- Supporting --//
	static BufferedReader in;
	static PrintWriter out;
	static {
		try {
			in = new BufferedReader(new FileReader("C-small-attempt0.in"));
			out = new PrintWriter(new FileWriter("out.txt"));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) throws Exception {
		int N = Integer.parseInt(readLine());
		for (int c = 1; c <= N; c++) {
			run(c);
		}
		in.close();
		out.close();
	}

	private static String readLine() throws IOException {
		return in.readLine();
	}

	private static void printf(String str, Object... o) {
		System.out.printf(str, o);
		out.printf(str, o);
	}

	private static long parseLong(String t) {
		return Long.parseLong(t);
	}
	
	private static int parseInt(String t) {
		return Integer.parseInt(t);
	}
}
