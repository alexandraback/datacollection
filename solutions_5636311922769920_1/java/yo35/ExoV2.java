package exo4;

import java.util.ArrayList;
import java.util.List;

public class ExoV2 extends Base {

	public static void main(String[] argv) throws Exception {
		
		Config config = createLargeConfig();
		
		try {
		
			int T = 0;
			TestCase[] testCases = null;
			int currentTestCase = 0;
			
			while (config.input().hasNextLine()) {
				String line = config.input().nextLine();
				
				if(T == 0) {
					T = Integer.parseInt(line);
					testCases = new TestCase[T];
				}
				else {
					String[] s = line.split(" ");
					long K = Long.parseLong(s[0]);
					long C = Long.parseLong(s[1]);
					long S = Long.parseLong(s[2]);
					testCases[currentTestCase] = new TestCase(K, C, S);
					++currentTestCase;
				}
			}
	
			for(int i = 0; i<T; ++i) {
				List<Long> res = solveTestCase(testCases[i]);
				config.output().println("Case #" + (i+1) + ": " + (res == null ? "IMPOSSIBLE" : implode(res)));
			}
			
		}
		finally {
			config.done();
		}
	}
	
	private static class TestCase {
		final long K;
		final long C;
		final long S;
		
		public TestCase(long k, long c, long s) {
			K = k;
			C = c;
			S = s;
		}
	}
	
	private static String implode(List<Long> list) {
		StringBuilder sb = new StringBuilder();
		boolean isFirst = true;
		for(long n : list) {
			if(isFirst) {
				isFirst = false;
			}
			else {
				sb.append(" ");
			}
			sb.append(n);
		}
		return sb.toString();
	}
	
	private static List<Long> solveTestCase(TestCase tc) {
		
		if(tc.S * tc.C < tc.K) {
			return null;
		}
		
		List<Long> res = new ArrayList<>(1 + (int) (tc.K / tc.C));
		for(long digit=0; digit<tc.K; digit += tc.C) {
			res.add(makeTestIndex(digit, tc.K, tc.C));
		}
		return res;
	}
	
	private static long makeTestIndex(long digit0, long K, long C) {
		long res = 0;
		for(long i=0; i<C; ++i) {
			long digit = (digit0 + i) % K;
			res = res * K + digit;
		}
		return 1 + res;
	}
}
