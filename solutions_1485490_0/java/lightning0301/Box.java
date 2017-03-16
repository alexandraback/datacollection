import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Box implements Runnable {
	private void solve() throws IOException {
		int ntest = nextInt();
		long[] a = new long[105];
		int[] A = new int[105];
		long[] b = new long[105];
		int[] B = new int[105];
		
		for (int test = 1; test <= ntest; test++){
			int N = nextInt();
			int M = nextInt();
			for (int i = 1; i <= N; i++){
				a[i] = nextLong();
			//	System.out.println(a[i]);
				A[i] = nextInt();
			}
			for (int i = 1; i <= M; i++){
				b[i] = nextLong();
				B[i] = nextInt();
			}
			
			long res  = 0;
			for (int div1 = 0; div1 <= M; div1++)
				for (int div2 = div1; div2 <= M; div2++){
					long sum = 0;
					
					long first = 0;
					for (int i = 1; i <= div1; i++)
						if (B[i] == A[1]) first += b[i];
					first = Math.min(first, a[1]);
					sum += first;
					
					if (N > 1){
						long second = 0;
						for (int i = div1 + 1; i <= div2; i++)
							if (B[i] == A[2]) second += b[i];
						second = Math.min(second, a[2]);
						sum += second;
					}
					
					if (N > 2){
						long third = 0;
						for (int i = div2 + 1; i <= M; i++)
							if (B[i] == A[3]) third += b[i];
						third = Math.min(third, a[3]);
						sum += third;
					}
					
					res = Math.max(res, sum);
				}
			if (N == 3 && A[1] == A[3]){
				long sum = 0;
				
				long first = 0;
				for (int i = 1; i <= M; i++)
					if (B[i] == A[1]) first += b[i];
				first = Math.min(first, a[1] + a[3]);
				sum += first;
				res = Math.max(res, sum);
			}
			
			writer.println("Case #" + test + ": " + res);
		}
	}

	public static void main(String[] args) {
		new Box().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
			reader = new BufferedReader(new InputStreamReader(
					new FileInputStream(
							"D:\\workspace\\Code Jam 2012\\C1.in")));
			tokenizer = null;
			writer = new PrintWriter(new File("output.txt"));
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
		String result = tokenizer.nextToken();
		//System.out.println(result);
		return result;
	}
}
