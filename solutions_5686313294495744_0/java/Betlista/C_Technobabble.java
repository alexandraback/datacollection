import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class C_Technobabble {

	static InputStreamReader isr = new InputStreamReader(System.in, StandardCharsets.US_ASCII);
	static BufferedReader br = new BufferedReader(isr, 20 << 20);

	public static void main(String[] args) throws Exception {
		final ExecutorService es = Executors.newFixedThreadPool(5);

		Result[] res = parseInputAndCreateSolvers(es);
		
		printResults(es, res);
	}
	
	private static Result[] parseInputAndCreateSolvers(ExecutorService es) throws Exception {
		
		int T = Integer.parseInt(br.readLine());
		Result[] res = new Result[T];
		for (int i = 0; i < res.length; i++) {
			int N = Integer.parseInt(br.readLine());
			String[][] top = new String[N][2];
			for (int j = 0; j < N; j++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				top[j][0] = st.nextToken();
				top[j][1] = st.nextToken();
			}
//			if (i == 14) {
//				System.out.println(N);
//				System.out.println(Arrays.deepToString(top));
//			}
			
			res[i] = new Result();
			es.submit(new Solver(res[i], N, top));
		}
		
		return res;
	}

	private static void printResults(ExecutorService es, Result[] res) {
		es.shutdown();
		while (!es.isTerminated()) {
			try {
				Thread.sleep(1000);
			} catch (InterruptedException ie) {
				ie.printStackTrace();
			}
		}
		final StringBuilder sb = new StringBuilder();
		for (int ii = 0; ii < res.length; ii++) {
//			if (ii == 14) {
//				System.out.println(Integer.toBinaryString(res[ii].mask));
//			}
			sb.append("Case #").append(ii+1).append(": ").append(res[ii]).append('\n');
		}
		System.out.print(sb);
	}

	static class Solver extends ResultHolder {
		
		int N;
		String[][] top;
		
		Solver(Result res, int N, String[][] top) {
			super(res);
			this.N = N;
			this.top = top;
		}
		
		@Override
		public void run() {
			for (int mask = 0; mask < (1 << N); mask++) {
				if (isOk(mask)) {
					int bc = Integer.bitCount(mask);
					if (bc > res.cnt) {
						res.cnt = bc;
						res.mask = mask;
					}
				}
			}
		}

		private boolean isOk(int mask) {
			ArrayList<String[]> fakes = new ArrayList<>();
			ArrayList<String[]> nonFakes = new ArrayList<>();
			for (int i = 0; i < N; i++) {
				if ( ((1 << i) & mask) > 0) {
					fakes.add(top[i]);
				} else {
					nonFakes.add(top[i]);
				}
			}
			boolean possible = isPossible(fakes, nonFakes);
//			if (possible) {
//				
//			}
			return possible;
		}

		private boolean isPossible(ArrayList<String[]> stillAvailable, ArrayList<String[]> used) {
			while (stillAvailable.isEmpty() == false) {
				boolean found = findNext(used, stillAvailable);
				if (found == false) return false;
			}
			return true;
		}

		private boolean findNext(ArrayList<String[]> used, ArrayList<String[]> stillAvailable) {
			for (int i = 0; i < used.size(); i++) {
				for (int j = 0; j < used.size(); j++) {
					if (i == j) {
						continue;
					}
					for (int k = 0; k < stillAvailable.size(); k++) {
						String[] ava = stillAvailable.get(k);
						String u0 = used.get(i)[0];
						String u1 = used.get(j)[1];
						if (ava[0].equals(u0) && ava[1].equals(u1) && isUnique(ava, used)) {
							stillAvailable.remove(k);
							used.add(ava);
							return true;
						}						
					}
				}
			}
			return false;
		}

		private boolean isUnique(String[] ava, ArrayList<String[]> used) {
			for (String[] u : used) {
				if (ava[0].equals(u[0]) && ava[1].equals(u[1])) {
					return false;
				}
			}
			return true;
		}
	}
	
	static class ResultHolder extends Thread {
		Result res;

		public ResultHolder(Result res) {
			this.res = res;
		}
		
	}

	static class Result {

		int cnt = 0;
		int mask = 0;
		
		@Override
		public String toString() {
			return Integer.toString(cnt);
		}
	}

}
