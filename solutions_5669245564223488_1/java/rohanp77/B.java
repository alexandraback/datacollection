import java.io.*;
import java.util.*;

public class B {
	static StringTokenizer st;
	static BufferedReader in;
	static PrintWriter out;
	
	static String nextToken() throws IOException {
		while (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	static final int MOD = 1000000007;
	
	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader("B.in"));
		out = new PrintWriter(new FileWriter("B.out"));
		
		int ttt = nextInt();
		for (int tt=1; tt<=ttt; tt++) {
			out.printf("Case #%d: ", tt);
			
			int num = nextInt();
			String[] store = new String[num];
			for (int i=0; i<num; i++)
				store[i] = nextToken();
			
			Arrays.sort(store, new Comparator<String>() {
				private int help(String s) {
					return Math.abs(s.charAt(0) - s.charAt(s.length()-1));
				}
				
				@Override
				public int compare(String o1, String o2) {
					int help1 = help(o1), help2 = help(o2);
					if (help1 == help2) return o1.compareTo(o2);
					else return help1 - help2;
				}
			});
			
			Map<Character, Character> startMap = new HashMap<Character,Character>();
			Map<Character, Character> endMap = new HashMap<Character,Character>();
			Set<Character> seen = new HashSet<Character>();
			
			int[] countSelfs = new int[26];
			long ans = 1;
			
			for (String s : store) {
				
				char f = s.charAt(0), l = s.charAt(s.length()-1);
				int midStart = 0, midEnd = s.length()-1;
				while(midStart <= midEnd && (s.charAt(midStart) == f || s.charAt(midEnd) == l)) {
					if (s.charAt(midStart) == f) midStart++;
					if (s.charAt(midEnd) == l) midEnd--;
				}
				
				if (f==l && midStart <= midEnd) ans = 0;
				
				for (int j=midStart; j<=midEnd; j++) {
					char c = s.charAt(j);
					if (c == s.charAt(j-1)) continue;
					if (seen.contains(c)) {
						ans = 0; break;
					}
					seen.add(c);
				}
				
				int falseCount = 0;
				if (seen.contains(f) && !endMap.containsKey(f)) falseCount++;
				if (seen.contains(l) && !startMap.containsKey(l)) falseCount++;
				if (f != l) falseCount++;
				if (falseCount > 1)
					ans = 0;
				seen.add(f); seen.add(l);
				
				if (f==l) {
					ans *= ++countSelfs[f-'a'];
					ans %= MOD;
				}
				
				if (f != l && endMap.containsKey(f) && endMap.get(f) == l) ans = 0;
				if (endMap.containsKey(f))
					f = endMap.remove(f);
				if (startMap.containsKey(l))
					l = startMap.remove(l);
				startMap.put(f, l);
				endMap.put(l, f);
			}
			
//			for (String s : store) {
//				char f = s.charAt(0);
//				char l = s.charAt(s.length()-1);
//				if (f == l) {
//					ans *= ++countSelfs[f-'a'];
//					ans %= MOD;
//					if (!startMap.containsKey(f) && !endMap.containsKey(f)) {
//						startMap.put(f, f);
//						endMap.put(f, f);
//					}
//				} else {
//					if (endMap.containsKey(f))
//						f = endMap.remove(f);
//					if (startMap.containsKey(l))
//						l = startMap.remove(l);
//					startMap.put(f, l);
//					endMap.put(l, f);
//				}
//			}
			
			for (int i=2; i<=startMap.size(); i++) {
				ans *= i; ans %= MOD;
			}
			
			out.println(ans);
		}
		out.close();
	}

//	private static boolean checkPossible(String[] store) {
//		Set<Character> seen = new HashSet<Character>();
//		Set<Character> starts = new HashSet<Character>();
//		Set<Character> ends = new HashSet<Character>();
//		for (String s : store) {
//			char prev = s.charAt(0);
//			char last = s.charAt(s.length()-1);
//			if (prev != last) {
//				if (starts.contains(prev) || ends.contains(last))
//					return false;
//				starts.add(prev); ends.add(last);
//			}
//			
//			for (char c : s.toCharArray()) {
//				if (c!=prev && c!= last && seen.contains(c)) return false;
//				if (prev == last && c != prev) return false;
//				seen.add(c);
//				prev = c;
//			}
//		}
//		return true;
//	}
}
