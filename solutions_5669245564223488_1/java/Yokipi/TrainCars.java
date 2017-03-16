package round1c_14;

import java.io.*;
import java.util.*;


public class TrainCars {
	static BufferedReader in;
	static StringTokenizer st;
	static FileWriter out;
	static FileWriter out2;
	
	static int getint() throws Exception {
		if (!st.hasMoreElements()) st = new StringTokenizer(in.readLine());
		return Integer.parseInt(st.nextToken());
	}
	
	static int N;
	static String[] cars;
	static long MOD = 1000000007L;
	
	static long[] factorial = new long[101];
	public static long fact(int n) {
		if (n <= 0) {
			factorial[0] = 1L;
			return 1L;
		}
		long sol = (n * fact(n-1)) % MOD;
		factorial[n] = sol;
		return sol;
	}
	
	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new FileReader("src/round1c_14/B-large.in"));
		st = new StringTokenizer(in.readLine());
		out = new FileWriter("src/round1c_14/B.out");
		//out2 = new FileWriter("src/round1c_14/B2.out");
		
		fact(100);
		
		int T = getint();
		for (int t = 1; t <= T; t++) {
			N = getint();
			cars = new String[N];
			
			st = new StringTokenizer(in.readLine());
			for (int i = 0; i < N; i++) {
				cars[i] = st.nextToken();
			}
			
			boolean possible = true;
			int[] loops = new int[26];
			for (int i = 0; i < N; i++) {
				HashSet<Character> isolated = new HashSet<Character>();
				String s = cars[i];
				char[] c = s.toCharArray();
				int j = 1;
				while (j < c.length && c[j] == c[0]) j++;
				while (j < c.length-1) {
					if (c[j] != c[j+1]) {
						possible &= isolated.add(c[j]);
						if (!possible) break;
					}
					j++;
				}
				if (!possible) break;
				for (Character ch : isolated) {
					for (int k = 0; k < N; k++) {
						if (i != k && cars[k].indexOf(ch) != -1) {
							possible = false;
							break;
						}
					}
					if (!possible) break;
				}
				if (!possible) break;
				if (c[0] == c[c.length-1]) {
					loops[c[0]-'a']++;
					char first = c[0];
					for (int k = 1; k < c.length-1; k++) {
						if (c[k] != first) {
							possible = false;
							break;
						}
					}
				}
				if (!possible) break;
			}
			
			long ans = 0;
			if (possible) {
				HashSet<Character> exists = new HashSet<Character>();
				HashMap<Character,Character> from = new HashMap<Character,Character>();
				HashMap<Character,Character> to = new HashMap<Character,Character>();
				for (int i = 0; i < N; i++) {
					char c1 = cars[i].charAt(0);
					char c2 = cars[i].charAt(cars[i].length()-1);
					if (c1 != c2) {
						if (to.get(c1) != null || from.get(c2) != null) {
							possible = false;
							break;
						} else {
							from.put(c2, c1);
							to.put(c1, c2);
							exists.add(c1); exists.add(c2);
						}
					}
				}
				if (possible) {
					
					TreeSet<Character> notvisited = new TreeSet<Character>();
					for (char c = 'a'; c <= 'z'; c++) {
						notvisited.add(c);
					}
					int islands = 0;
					while (!notvisited.isEmpty()) {
						char c = notvisited.pollFirst();
						if (loops[c-'a'] > 0 || exists.contains(c)) islands++;
						else continue;
						Character x = c;
						while (to.get(x) != null) {
							x = to.get(x);
							//if (t == 1 && x == 's') System.out.println(notvisited);
							boolean b = notvisited.remove(x);
							if (!b) {
								possible = false;
								break;
							}
						}
						x = c;
						while (from.get(x) != null) {
							x = from.get(x);
							//if (t == 1 && x == 's') System.out.println(notvisited);
							boolean b = notvisited.remove(x);
							if (!b) {
								//System.out.println(t + " " + x);
								possible = false;
								break;
							}
						}
						//if (t == 1 && notvisited.contains(new Character('s'))) System.out.println(notvisited);
						if (!possible) break;
					}
					if (possible) {
					
						ans = 1L;
						ans *= factorial[islands];
						ans %= MOD;
						for (int i = 0; i < 26; i++) {
							if (loops[i] != 0) {
								ans *= factorial[loops[i]];
								ans %= MOD;
							}
						}
					}
				}
			}
			
			out.write(String.format("Case #%d: %s\n", t, Long.toString(ans)));
			
			/*
			System.out.println(t);
			if (N < 9) {
				long ans2 = bruteforce();
				out2.write(String.format("Case #%d: %s\n", t, Long.toString(ans2)));
			}*/
		}
		
		in.close();
		out.close();
		//out2.close();
	}
	
	public static long bruteforce() {
		return bruteforcehelp(0, 0, new StringBuilder()); 
	}
	
	public static long bruteforcehelp(int taken, int num, StringBuilder sb) {
		if (num == N) {
			String s = sb.toString();
			for (char c = 'a'; c <= 'z'; c++) {
				int a = s.indexOf(c);
				int b = s.lastIndexOf(c);
				for (int i = a+1; i < b; i++) {
					if (s.charAt(i) != c) return 0;
				}
			}
			return 1;
		} else {
			long sum = 0;
			for (int i = 0; i < N; i++) {
				if ((taken | (1<<i)) != taken) {
					StringBuilder sb2 = new StringBuilder(sb);
					sum += bruteforcehelp(taken|(1<<i), num+1, sb2.append(cars[i]));
					sum %= MOD;
				}
			}
			return sum % MOD;
		}
	}
}
