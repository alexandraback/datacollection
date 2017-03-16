
public class A2 {
	
	public static void main(String...args){
		FastScanner s = new FastScanner("input.txt");
		
		int T = s.nextInt();
		for (int t = 1; t <= T; t++) {
			System.out.println("Case #" + t + ": " + calc(s.nextInt(),s.nextInt(),s.nextInt()));
		}
		
	}
	
	static int calc(int R,int C,int W){
		int begin = (R - 1) * (C / W);
//		_(begin);
		if(C % W == 0) return begin + (C / W + W - 1);
		return begin + (C / W + W);
	}
	
	static void _(Object... obj) {
		System.out.println(java.util.Arrays.deepToString(obj));
	}
	
	public static class FastScanner {
		java.io.BufferedReader br;
		java.util.StringTokenizer st;

		public FastScanner() {
			init();
		}

		public FastScanner(String name) {
			init(name);
		}

		public FastScanner(boolean isOnlineJudge) {
			if (!isOnlineJudge || System.getProperty("ONLINE_JUDGE") != null) {
				init();
			} else {
				init("input.txt");
			}
		}

		private void init() {
			br = new java.io.BufferedReader(new java.io.InputStreamReader(
					System.in));
		}

		private void init(String name) {
			try {
				br = new java.io.BufferedReader(new java.io.FileReader(name));
			} catch (java.io.FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new java.util.StringTokenizer(br.readLine());
				} catch (java.io.IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}

	}
}


