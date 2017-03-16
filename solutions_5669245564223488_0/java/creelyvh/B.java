import java.util.*;

public class B {

	public static void main(String[] args) {
		long mod = 1000000007L;
		Scanner sc = new Scanner(System.in);
		
		int ncs = sc.nextInt();
		out: for(int cs = 0; cs < ncs; cs++) {
			int ncar = sc.nextInt();
			
			Set<String> set = new HashSet<>();
			Map<Character, String> start = new HashMap<Character, String>();
			Map<Character, String> end = new HashMap<Character, String>();
			int[] map = new int[1000];
			int[] count = new int[1000];
			
			List<String> aaa = new ArrayList<>();
			for(int i = 0; i < ncar; i++) aaa.add(sc.next());
			
			for(String s : aaa) {
//				String s = sc.next();
				
				char[] collapse = s.replaceAll("(.)\\1+", "$1").toCharArray();
				boolean[] charseen = new boolean[1000];
				for(char c : collapse) {
					if(charseen[c]) {
						
//						for(; i < ncar; i++) sc.next();
						System.out.printf("Case #%d: %d\n", cs + 1, 0);
						continue out;
					}
					charseen[c] = true;
				}
				
				char fchar = s.charAt(0);
				char echar = s.charAt(s.length() - 1);
				if(s.replace(s.subSequence(0, 1), "").equals("")) {
					map[fchar] += s.length();
					count[fchar]++;
				}
				else {
					if(start.containsKey(fchar) || end.containsKey(echar)) {
//						for(; i < ncar; i++) sc.next();
						System.out.printf("Case #%d: %d\n", cs + 1, 0);
						continue out;
					}
					else {
						start.put(fchar, s);
						end.put(echar, s);
						set.add(s);
					}
				}
			}
			
			
			for(String so : set) {
				String s = so.replaceAll("(.)\\1+", "$1");
				for(int i = 1; i < s.length() - 1; i++) {
					char c = s.charAt(i);
					
					for(String s2 : set) {
						if(so.equals(s2)) continue;
						
						for(char c2 : s2.toCharArray()) {
							if(c2 == c) {
								System.out.printf("Case #%d: %d\n", cs + 1, 0);
								continue out;
							}
						}
					}
				}
			}
			
			for(int i = 0; i < map.length; i++) {
				if(map[i] == 0) continue;
				StringBuilder sb = new StringBuilder();
				for(int j = 0; j < map[i]; j++) {
					sb.append((char)i);
				}
				String ss = sb.toString();
				set.add(ss);
				if(!start.containsKey(ss.charAt(0))) start.put(ss.charAt(0), ss);
				if(!end.containsKey(ss.charAt(ss.length() - 1))) end.put(ss.charAt(ss.length() - 1), ss);
			}
			
			long ans = 1;
			
			
			
			for(int c : count) {
				if(c == 0) continue;
				
				long acc = 1;
				for(int i = 1; i <= c; i++) {
					acc *= i;
					acc %= mod;
				}
				
				ans *= acc;
				ans %= mod;
			}
			
//			while(true) {
//				
//				boolean found = false;
//				Set<String> nset = new HashSet<>();
//				Set<String> seen = new HashSet<>();
//				for(String s : set) {
//					if(seen.contains(s)) continue;
//					StringBuilder sb = new StringBuilder(s);
//					String curr = s;
//					seen.add(s);
//					while(start.containsKey(curr.charAt(curr.length() - 1))) {
//						String next = start.get(curr.charAt(curr.length() - 1));
//						sb.append(next);
//						seen.add(next);
//						curr = next;
//						seen.add(next);
//						found = true;
//					}
//					nset.add(sb.toString());
//				}
//				
//				set = nset;
//				if(!found) break;
//			}
			
			int numnum = 0;
			
			for(String s : set) {
				if(!end.containsKey(s.charAt(0)) || end.get(s.charAt(0)).equals(s)) numnum++;
			}
			
			long acc = 1;
			for(int i = 1; i <= numnum; i++) {
				acc *= i;
				acc %= mod;
			}
			
			ans *= acc;
			ans %= mod;
//			System.err.println(numnum);
			
			if(numnum == 0) ans = 0;
			
			System.out.printf("Case #%d: %d\n", cs + 1, ans);
			
			// check single cars
			// check car interior
			
		}
	}

}
