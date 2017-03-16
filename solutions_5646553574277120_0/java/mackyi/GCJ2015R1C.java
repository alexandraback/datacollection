import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.ArrayList;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeSet;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJ2015R1C implements Runnable {

	private PrintWriter out;
	
	final String file = "C-small-attempt0";
	Random rnd = new Random(42);

	static class InputData {
        int c, d, v;
		TreeSet<Integer> denoms;
		
		ArrayList<Integer> denomList;
		int[] numUsed;
		
		InputData(FastReader in) throws IOException {
            c = in.nextInt();
            d = in.nextInt();
            v = in.nextInt();
            
            denoms = new TreeSet<>();

            for (int i = 0; i < d; ++i) {
                denoms.add(in.nextInt());
            }
		}
		
		void solve(PrintWriter out) {
			int count = 0;
			while(true) {
				denomList = new ArrayList<>(denoms);
				numUsed = new int[denomList.size()];
				
				int canMake = 0;
				for(int i = 1; i <= v; ++i) {
					if(!canMake(i)) {
						count++;
						denoms.add(i);
						break;
					} else {
						canMake++;
					}
				}
				if(canMake == v) {
					out.println(count);;
					return;
				}
			}
		}
		
		boolean canMake(int target) {
			if(target == 0) return true;
			for(int i = 0; i < denomList.size(); i++) {
				if(numUsed[i] < c) {
					if(denomList.get(i) <= target) {
						numUsed[i]++;
						if(canMake(target-denomList.get(i))) {
							numUsed[i]--;
							return true;
						}
						numUsed[i]--;
					}
				}
			}
			return false;
		}
	}
	
	static class Solver implements Callable<String> {

		InputData data;
		
		Solver(InputData data) {
			this.data = data;
		}

		@Override
		public String call() throws Exception {
			StringWriter out = new StringWriter();
			data.solve(new PrintWriter(out));
			return out.toString();
		}
		
	}

	public void run() {
		try {
			FastReader in = new FastReader(new BufferedReader(new FileReader(file + ".in")));
			out = new PrintWriter(file + ".out");
		
//			FastReader in = new FastReader(new BufferedReader(new InputStreamReader(System.in)));
//			out = new PrintWriter(System.out);
			
			ScheduledThreadPoolExecutor service = new ScheduledThreadPoolExecutor(7);
			
			int tests = in.nextInt();
			Future<String>[] ts = new Future[tests];
			for (int test = 0; test < tests; ++test) {
				ts[test] = service.submit(new Solver(new InputData(in)));
			}
			for (int test = 0; test < tests; ++test) {
				while (!ts[test].isDone()) {
					Thread.sleep(500);
				}
				System.err.println("Test " + test);
				out.print("Case #" + (test + 1) + ": ");
				out.print(ts[test].get());
			}
			service.shutdown();
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	static class FastReader {
		public FastReader(BufferedReader in) {
			this.in = in;
			eat("");
		}
		
		private StringTokenizer st;
		private BufferedReader in;
		
		void eat(String s) {
			st = new StringTokenizer(s);
		}
		
		String next() throws IOException {
			while (!st.hasMoreTokens()) {
				String line = in.readLine();
				if (line == null) {
					return null;
				}
				eat(line);
			}
			return st.nextToken();
		}
		
		int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
		
		long nextLong() throws IOException {
			return Long.parseLong(next());
		}
		
		double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new GCJ2015R1C().run();
	}
	
}
