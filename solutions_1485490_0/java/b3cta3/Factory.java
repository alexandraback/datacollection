import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Factory implements Runnable {
	int N;
	int M;
	private void solve() throws IOException {
		int test = nextInt();
		for (int t = 1; t <= test; t++) {
			N = nextInt();
			M = nextInt();
			long[][] boxes = new long[N][2];
			long[][] toys = new long[M][2];
			for (int j = 0; j < N; j++) {
				boxes[j][0] = nextLong();
				boxes[j][1] = nextLong();
			}
			for (int j = 0; j < M; j++) {
				toys[j][0] = nextLong();
				toys[j][1] = nextLong();
			}
			BigInteger result = compute(boxes, toys, 0, 0);
			writer.write("Case #" + t + ": " + result.toString() + "\n");
		}
	}
	
	
	private BigInteger compute(long[][] boxes, long[][] toys, int i, int j) {
		// TODO Auto-generated method stub
		BigInteger result = BigInteger.ZERO;
		if (i >= N || j >= M)
			return result;
		if (boxes[i][1] == toys[j][1]) {
			if (boxes[i][0] > toys[j][0]) {
				boxes[i][0] -= toys[j][0];
				result = compute(boxes, toys, i, j + 1).add(new BigInteger(String.valueOf(toys[j][0])));
				boxes[i][0] += toys[j][0];
				
			} else if (boxes[i][0] < toys[j][0]) {
				toys[j][0] -= boxes[i][0];
				result = compute(boxes, toys, i + 1, j).add(new BigInteger(String.valueOf(boxes[i][0])));
				toys[j][0] += boxes[i][0];
			} else {
				result = compute(boxes, toys, i + 1, j + 1).add(new BigInteger(String.valueOf(boxes[i][0])));
			}
		} else {
			BigInteger temp1 = compute(boxes, toys, i + 1, j);
			if (temp1.compareTo(result) > 0)
				result = temp1;
			BigInteger temp2 = compute(boxes, toys, i, j + 1);
			if (temp2.compareTo(result) > 0)
				result = temp2;
		}
			
		return result;
	}


	public static void main(String[] args) {
		new Factory().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;
	String fileName = "Factory";
	public void run() {
		try {
			reader = new BufferedReader(new FileReader(fileName + ".in"));
			tokenizer = null;
			writer = new PrintWriter(new FileWriter(fileName + ".out"));
			solve();
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
}