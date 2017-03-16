package exo2;

public class Exo extends Base {

	public static void main(String[] argv) throws Exception {
		
		Config config = createLargeConfig();
		
		try {
		
			int T = 0;
			String[] in = null;
			int currentTestCase = 0;
			
			while (config.input().hasNextLine()) {
				String line = config.input().nextLine();
				
				if(T == 0) {
					T = Integer.parseInt(line);
					in = new String[T];
				}
				else {
					in[currentTestCase] = line;
					++currentTestCase;
				}
			}
	
			for(int i = 0; i<T; ++i) {
				config.output().println("Case #" + (i+1) + ": " + solveTestCase(in[i]));
			}
			
		}
		finally {
			config.done();
		}
	}
	
	//private static String stateToString(boolean[] state) {
	//	StringBuilder sb = new StringBuilder();
	//	for(boolean b : state) {
	//		sb.append(b ? '+' : '-');
	//	}
	//	return sb.toString();
	//}
	
	private static int solveTestCase(String in) {
		int L = in.length();
		if(L == 0) {
			return 0;
		}
		
		int res = in.charAt(L-1) == '-' ? 1 : 0;
		for(int i=1; i<L; ++i) {
			if(in.charAt(i) != in.charAt(i-1)) {
				++res;
			}
		}
		return res;
		
		//boolean[] state = parse(in);
		//int res = 0;
		//int last = state.length - 1;
		//
		//debug("I " + stateToString(state));
		//while(last >= 0) {
		//	if(state[last]) {
		//		--last;
		//	}
		//	else {
		//		boolean hasPreparedBigFlip = prepareBigFlip(state);
		//		if(hasPreparedBigFlip) {
		//			debug("P " + stateToString(state));
		//		}
		//		doBigFlip(state, last);
		//		res += hasPreparedBigFlip ? 2 : 1;
		//		debug("B " + stateToString(state));
		//	}
		//}
		//
		//return Integer.toString(res);
	}
	
	//private static boolean prepareBigFlip(boolean[] state) {
	//	int i = 0;
	//	while(state[i]) {
	//		state[i] = false;
	//		++i;
	//	}
	//	return i > 0;
	//}
	//
	//private static void doBigFlip(boolean[] state, int last) {
	//	int first = 0;
	//	while(first < last) {
	//		boolean val = state[first];
	//		state[first] = !state[last];
	//		state[last] = !val;
	//		++first;
	//		--last;
	//	}
	//	if(first == last) {
	//		state[first] = !state[first];
	//	}
	//}
	//
	//private static boolean[] parse(String in) {
	//	int lg = in.length();
	//	boolean[] res = new boolean[lg];
	//	for(int i=0; i<lg; ++i) {
	//		res[i] = in.charAt(i) == '+';
	//	}
	//	return res;
	//}
}
