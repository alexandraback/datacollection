import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main implements Runnable {

	private static final boolean USE_FILES = true;

	private static final String FILE_IN = "in.txt";
	private static final String FILE_OUT = "out.txt";

	BufferedReader in;
	PrintWriter out;
	StringTokenizer tokenizer = new StringTokenizer("");

	public static void main(String[] args) {
		new Thread(new Main()).start();
	}
	
	private void solve() throws IOException {
		// solve here
		int T;
		T = nextInt();
		for(int tst = 1; tst <= T; ++tst) {
			BigInteger r, t, start, end, mid, TWO = new BigInteger("2");
			r = nextBigInt();
			t = nextBigInt();
			r = r.multiply(TWO);
			start = BigInteger.ONE;
			end = new BigInteger("1000000000");
			mid = new BigInteger("500000000");
			
			while(start.compareTo(end) == -1) {
				if(valid(mid, r, t)) {
					start = mid;
				}else {
					end = mid.subtract(BigInteger.ONE);
				}
				mid = start.add((end.subtract(start).add(BigInteger.ONE)).divide(TWO));
			}
			out.println("Case #" + tst + ": " + mid);
		}
		
	}

	private boolean valid(BigInteger val, BigInteger r, BigInteger t) {
		
		BigInteger f = val.subtract(BigInteger.ONE).multiply(new BigInteger("4"));
		f = f.multiply(val);
		f = f.divide(new BigInteger("2"));
		f = r.add(BigInteger.ONE).multiply(val).add(f);
		
		if(f.compareTo(t) == 1)
			return false;
		return true;
	}

	public void run() {
		
		long timeStart = System.currentTimeMillis();
		boolean fileIO = USE_FILES;
		try {

			if (fileIO) {
				in = new BufferedReader(new FileReader(FILE_IN));
				out = new PrintWriter(new FileWriter(FILE_OUT));
			} else {
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(new OutputStreamWriter(System.out));
			}
			
			solve();
			
			in.close();
			out.close();
		} catch (IOException e) {
			throw new IllegalStateException(e);
		}
//		long timeEnd = System.currentTimeMillis();

//		if (fileIO) {
//			System.out.println("Time spent: " + (timeEnd - timeStart) + " ms");
//		}
	}

	private String nextToken() throws IOException {
		while (!tokenizer.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			tokenizer = new StringTokenizer(line);
		}
		return tokenizer.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private BigInteger nextBigInt() throws IOException {
		return new BigInteger(nextToken());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

}