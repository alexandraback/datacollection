import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class A_GettingTheDigits {

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
			String s = br.readLine();
			res[i] = new Result();
			es.submit(new Solver(res[i], s.toCharArray()));
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
			sb.append("Case #").append(ii+1).append(": ").append(res[ii]).append('\n');
		}
		System.out.print(sb);
	}

	static char[] significant = { 'Z', 'W', 'G', 'X', 
			'H', 
			'R',
			'F',
			'S',
			'I', 'O' };
	static String[] s = {"ZERO", "TWO", "EIGHT", "SIX", 
			"THREE", 
			"FOUR", 
			"FIVE", 
			"SEVEN", 
			"NINE", "ONE" };
	
	static int val[] = {0, 2, 8, 6, 
			3, 
			4, 
			5, 
			7, 9, 1 };
	
	static class Solver extends ResultHolder {
		
		char[] ca;
		
		Solver(Result res, char[] ca) {
			super(res);
			this.ca = ca;
		}
		
		@Override
		public void run() {
			ArrayList<Integer> list = new ArrayList<>();

			Map<Character, Integer> map = toMap();
			
			for (int i = 0; i < significant.length; i++) {
				while (map.containsKey(significant[i])) {
					remove(map, s[i]);
					list.add(val[i]);
				}
			}
			
			Collections.sort(list);
			this.res.s = A_GettingTheDigits.toString(list);
		}

		private void remove(Map<Character, Integer> map, String string) {
			for (char c : string.toCharArray()) {
				Integer val = map.get(c);
				if (val == 1) map.remove(c);
				else map.put(c, val - 1);
			}
		}

		private Map<Character, Integer> toMap() {
			Map<Character, Integer> map = new HashMap<>();
			for (char c : ca) {
				Integer val = map.get(c);
				if (val == null) val = 0;
				map.put(c, val + 1);
			}
			return map;
		}

	}

	public static String toString(ArrayList<Integer> list) {
		StringBuilder sb = new StringBuilder();
		for (int a : list) {
			sb.append(a);
		}
		return sb.toString();
	}
	
	static class ResultHolder extends Thread {
		Result res;

		public ResultHolder(Result res) {
			this.res = res;
		}
		
	}

	static class Result {
		
		String s;
		
		@Override
		public String toString() {
			return s;
		}
	}
}
