import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;


public class codejam1bB {
	public static void main(String[] args) {
		int T = in.nextInt();
		for(int t = 0; t < T; t++) {
			String s1 = in.next();
			String s2 = in.next();	
			List<StringBuilder> l1 = getAllPossible(new StringBuilder(s1));
			List<StringBuilder> l2 = getAllPossible(new StringBuilder(s2));
			StringBuilder sb1 = null;
			StringBuilder sb2 = null;
			int maxDiff = Integer.MAX_VALUE;
			for(int i = 0; i < l1.size(); i++) {
				for(int j =0; j < l2.size(); j++) {
					int currDiff = Math.abs(Integer.parseInt(l1.get(i).toString()) - Integer.parseInt(l2.get(j).toString()));
					if(currDiff < maxDiff) {
						maxDiff = currDiff;
						sb1 = l1.get(i);
						sb2 = l2.get(j);
					} else if (currDiff == maxDiff) {
						if(Integer.parseInt(sb1.toString()) > Integer.parseInt(l1.get(i).toString())) {
							sb1 = l1.get(i);
						} else if (Integer.parseInt(sb2.toString()) > Integer.parseInt(l2.get(j).toString()))
							sb2 = l2.get(j);
						}
					}
				}
			System.out.println("Case #"+(t+1)+": "+sb1.toString() + " " + sb2.toString());
			}
		
		
	}
	
	static List<StringBuilder> getAllPossible(StringBuilder sb) {
		List<StringBuilder> temp = new ArrayList<>();
		for(int i = 0; i < sb.length(); i++) {
			if(sb.charAt(i) == '?') {
				for(int j = 0; j < 10; j++) {
					StringBuilder s = new StringBuilder(sb);
					s.setCharAt(i, (char) ('0' + j));
					temp.add(s);
				}
			}
		}
		if(temp.isEmpty()) {
			temp.add(0, sb);
			return temp;
		}
		List<StringBuilder> temp2 = new ArrayList<>();
		for(StringBuilder each: temp) {
			for(int i = 0; i < each.length(); i++) {
				if(each.charAt(i) == '?') {
					for(int j = 0; j < 10; j++) {
						StringBuilder s = new StringBuilder(each);
						s.setCharAt(i, (char) ('0' + j));
						temp2.add(s);
					}
				}
			}
		}
		if(temp2.isEmpty()) return temp;
		List<StringBuilder> temp3 = new ArrayList<>();
		for(StringBuilder each: temp2) {
			for(int i = 0; i < each.length(); i++) {
				if(each.charAt(i) == '?') {
					for(int j = 0; j < 10; j++) {
						StringBuilder s = new StringBuilder(each);
						s.setCharAt(i, (char) ('0' + j));
						temp3.add(s);
					}
				}
			}
		}
		if(temp3.isEmpty()) return temp2;
		return temp3;
	}

	//------------ fast input/ouput--------//
	
	public static Object returnFirst(Object x, Object y) {
		return x;
	}

	public static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	public static FastScanner in = new FastScanner();

	public static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	} //--fast i/o ends here----//
	

}
