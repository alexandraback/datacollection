package CodeJam2014;

import java.util.ArrayList;
import java.util.Scanner;

public class Round1CB {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		loop:
		for (int casen = 1; casen <= T; casen++) {
			int N = in.nextInt();
			
			boolean[] mid = new boolean[26];
			int[] single = new int[26];
			ArrayList<Pair> pairs = new ArrayList<Pair>();
			boolean[] pairstart = new boolean[26];
			boolean[] pairend = new boolean[26];
			ArrayList<String> strings = new ArrayList<String>();
			for (int i = 0; i < N; i++) {
				strings.add(in.next());
			}
			for (String s : strings) {
				char firstchar = s.charAt(0);
				char lastchar = s.charAt(s.length() - 1);
				if (mid[firstchar - 'a'] || mid[lastchar - 'a']) {
					System.out.println("Case #" + casen + ": 0");
					continue loop;
				}
				/*if (s.length() == 1) {
					single[firstchar - 'a']++;
				} else*/
				if (firstchar == lastchar) {
					for (int j = 1; j < s.length() - 1; j++)
						if (s.charAt(j) != firstchar) {
							System.out.println("Case #" + casen + ": 0");
							continue loop;
						}
					single[firstchar - 'a']++;
				} else {
					int firstnotfirstchar = 1;
					while (s.charAt(firstnotfirstchar) == firstchar)
						firstnotfirstchar++;
					int firstnotlastchar = s.length() - 2;
					while (s.charAt(firstnotlastchar) == lastchar)
						firstnotlastchar--;
					for (int j = firstnotfirstchar; j <= firstnotlastchar; j++) {
						mid[s.charAt(j) - 'a'] = true;
					}
					pairs.add(new Pair(firstchar, lastchar));
					if (pairstart[firstchar - 'a']) {
						System.out.println("Case #" + casen + ": 0");
						continue loop;
					} else
						pairstart[firstchar - 'a'] = true;
					if (pairend[lastchar - 'a']) {
						System.out.println("Case #" + casen + ": 0");
						continue loop;
					} else
						pairend[lastchar - 'a'] = true;
				}
			}
			
			for (int i = 0; i < 26; i++)
				if (mid[i]) {
					if (single[i] > 0 || pairstart[i] || pairend[i]) {
						System.out.println("Case #" + casen + ": 0");
						continue loop;
					}
				}
			
			
			ArrayList<Pair2> classes = new ArrayList<Pair2>();
			int[] thereexistsleft = new int[26];
			int[] thereexistsright = new int[26];
			for (int i = 0; i < 26; i++) {
				if (single[i] > 0) {
					classes.add(new Pair2(new Pair(i), fact(single[i])));
					thereexistsleft[i] = thereexistsright[i] = 1;
				}
			}
			ArrayList<Pair> pairs2 = new ArrayList<Pair>();
			while (!pairs.isEmpty()) {
				boolean donesomething = false;
				for (Pair pair : pairs) {
					boolean mustgosomewhere = false;
					boolean mustlinkboth = false;
					if (thereexistsright[pair.start] == 2) {
						System.out.println("Case #" + casen + ": 0");
						continue loop;
					} else if (thereexistsright[pair.start] == 1) {
						mustgosomewhere = true;
					}
					if (thereexistsleft[pair.end] == 2) {
						System.out.println("Case #" + casen + ": 0");
						continue loop;
					} else if (thereexistsleft[pair.end] == 1) {
						if (mustgosomewhere) {
							mustlinkboth = true;
						} else
							mustgosomewhere = true;
					}
					if (mustlinkboth) {
						
						Pair2 first = null, second = null;
						for (Pair2 pair2 : classes) {
							if (pair2.pair.start == pair.end) {
								 second= pair2;
							} else if (pair2.pair.end == pair.start) {
								first = pair2;
							}
						}
						if (first == null || second == null) {
							System.out.println("Case #" + casen + ": 0");
							continue loop;
						}
						first.count *= second.count;
						first.pair.end = second.pair.end;
						classes.remove(second);
					} else if (mustgosomewhere) {
						for (Pair2 pair2 : classes) {
							if (pair2.pair.start == pair.end) {
								thereexistsleft[pair.end]++;
								if (thereexistsleft[pair.start] != 0) {
									System.out.println("Case #" + casen + ": 0");
									continue loop;
								} else {
									thereexistsleft[pair.start] = 1;
								}
								pair2.pair.start = pair.start;
								donesomething = true;
								break;
							} else if (pair2.pair.end == pair.start) {
								thereexistsright[pair.start]++;
								if (thereexistsright[pair.end] != 0) {
									System.out.println("Case #" + casen + ": 0");
									continue loop;
								} else {
									thereexistsright[pair.end] = 1;
								}
								pair2.pair.end = pair.end;
								donesomething = true;
								break;
							}
						}
						if (!donesomething) {
							throw new RuntimeException("ERROR");
						}
					} else {
						pairs2.add(pair);
					}
				}
				pairs.clear();
				pairs.addAll(pairs2);
				pairs2.clear();
				if (!donesomething) {
					Pair somepair = pairs.remove(0);
					classes.add(new Pair2(somepair, 1));
					thereexistsleft[somepair.start] = thereexistsright[somepair.end] = 1;
				}
			}
			
			long ans = 1;
			for (Pair2 pair2 : classes) {
				ans *= pair2.count;
				ans %= 1000000007;
			}
			ans *= fact(classes.size());
			ans %= 1000000007;
			System.out.println("Case #" + casen + ": " + ans);
		}

	}
	
	private static long fact(int n) {
		int ans = 1;
		for (int i = 2; i <= n; i++) {
			ans *= i;
			ans %= 1000000007;
		}
		return ans;
	}

	static class Pair {
		int start, end;
		Pair(char s, char e) {
			start = s - 'a';
			end = e - 'a';
		}
		Pair(int s, int e) {
			start = s;
			end = e;
		}
		Pair(int se) {
			start = se;
			end = se;
		}
		public String toString() {
			return ((char) (start + 'a')) + "" + ((char) (end + 'a'));
		}
	}
	
	static class Pair2 {
		Pair pair;
		long count;
		Pair2(Pair p, long c) {
			pair = p;
			count = c;
		}
		public String toString() {
			return pair.toString() + "," + count;
		}
	}

}
/*
14
3
ab bbbc cd
4
aa aa bc c
2
abc bcd
4
ba aa aaa ac
3
a ba ab
3
a ba ac
2
ba ab
3
aghjc da ae
3
aghja da ae
3
aaaaa da ae

3
aghja da ea
3
xd ac da
2
ba ca
3
ba ca cb
*/