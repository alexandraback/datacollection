import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;


public class B {
	private static Scanner sc;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) {
			System.out.printf("Case #%d: %s\n", i + 1, exec().mod(BigInteger.valueOf(1000000007)));
		}
	}
	
	public static BigInteger exec() {
		int n = sc.nextInt();
		String[] s = new String[n];
		int[][] S = new int[n][];
		for (int i = 0; i < n; i++) s[i] = sc.next();
		
		StringBuilder sb = new StringBuilder();
		// strip consecutive letters.
		for (int i = 0; i < n; i++) {
			sb.setLength(0);
			char prev = '1';
			for (int j = 0 ; j < s[i].length(); j++) {
				char c = s[i].charAt(j);
				if (c == prev) continue;
				prev = c;
				sb.append(c);
			}
			s[i] = sb.toString();
		}
		
		// Step 1: "pre-join" all trains that need joining.
		int[] interchar = new int[26];
		Arrays.fill(interchar, -1);
		
		for (int i = 0; i < n; i++) {
			int firstChar = s[i].charAt(0) - 'a';
			int lastChar = s[i].charAt(s[i].length() - 1) - 'a';
			for (int j = 0; j < interchar.length; j++) {
				int k = interchar[j];
				if (k != -1) {
					k = -2;
					if (j == firstChar || j == lastChar) {
						return BigInteger.ZERO;
					}
				}
			}
			boolean asFirst = true;
			boolean onFirst = true;
			boolean onLast = false;
			
			for (int j = 1; j < s[i].length() - 1; j++) {
				int iChar = s[i].charAt(j) - 'a';
				if (onFirst && iChar == firstChar) continue;
				onFirst = false;
				int lastPos = interchar[iChar];
				if (lastPos == -1 || lastPos == j - 1) interchar[iChar] = j;
				else {
					return BigInteger.ZERO;
				}
				if (iChar == firstChar && !asFirst) {
					return BigInteger.ZERO;
				}
				if (iChar != firstChar) asFirst = false;
				if (iChar != lastChar && onLast) {
					return BigInteger.ZERO;
				}
				if (iChar == lastChar) onLast = true;
				if (firstChar == lastChar && iChar != firstChar) return BigInteger.ZERO;
			}
			
			S[i] = new int[] {firstChar, lastChar};
		}
		
		Arrays.sort(S, new Comparator<int[]>() {
			@Override public int compare(int[] o1, int[] o2) {
				int c = o1[0] - o2[0];
				if (c != 0) return c;
				if (o1[0] == o1[1]) {
					if (o2[0] == o2[1]) return 0;
					return -1;
				}
				if (o2[0] == o2[1]) return +1;
				return o1[1] - o2[1];
			}
		});
		
		// If any 2 non-homogenous trains start with the same letter or end in the same letter, it's over.
		int[] starts = new int[26];
		int[] ends = new int[26];
		for (int i = 0; i < S.length; i++) {
			if (S[i][0] == S[i][1]) continue;
			if (++starts[S[i][0]] > 1) return BigInteger.ZERO;
			if (++ends[S[i][1]] > 1) return BigInteger.ZERO;
		}
		
		List<Integer> subtrains = new ArrayList<Integer>();
		
		int head = -1;
		int chain = 0;
		List<int[]> simpler = new ArrayList<int[]>();
		for (int i = 0; i < n; i++) {
			if (S[i][0] == S[i][1]) {
				if (head == S[i][0]) {
					chain++;
					continue;
				}
				
				if (chain > 1) subtrains.add(chain);
				head = S[i][1];
				chain = 1;
				simpler.add(S[i]);
				continue;
			}
			
			simpler.add(S[i]);
			if (chain > 1) subtrains.add(chain);
			head = -1;
			chain = 0;
		}
		
		if (chain > 1) subtrains.add(chain);
		
		List<int[]> simpler2 = new ArrayList<int[]>();
		List<int[]> hetero = new ArrayList<int[]>();
		
		for (int i = 0; i < simpler.size(); i++) {
			boolean remove = false;
			int fc = simpler.get(i)[0];
			int ec = simpler.get(i)[1];
			if (fc != ec) {
				hetero.add(simpler.get(i));
				continue;
			}
			for (int j = 0; j < simpler.size(); j++) {
				if (i == j) continue;
				int fc2 = simpler.get(j)[0];
				int ec2 = simpler.get(j)[1];
				if (fc == ec2 || ec == fc2) remove = true;
			}
			if (!remove) simpler2.add(simpler.get(i));
		}
		
		int toJoin1 = -1;
		int toJoin2 = -1;
		top:
		while (true) {
			if (toJoin1 != -1) {
				int f = hetero.get(toJoin1)[0];
				int e = hetero.get(toJoin2)[1];
				hetero.remove(toJoin1);
				if (toJoin2 > toJoin1) hetero.remove(toJoin2 -1);
				else hetero.remove(toJoin2);
//				System.out.printf("J: %d %d %d %d\n", toJoin1, toJoin2, f, e);
				if (f == e) return BigInteger.ZERO;
				hetero.add(new int[] {f, e});
				toJoin1 = -1;
				toJoin2 = -1;
			}
			
			for (int i = 0; i < hetero.size(); i++) {
				int fc = hetero.get(i)[0];
				int ec = hetero.get(i)[1];
				for (int j = 0; j < hetero.size(); j++) {
					if (i == j) continue;
					int fc2 = hetero.get(j)[0];
					int ec2 = hetero.get(j)[1];
					if (fc2 == ec) {
						toJoin1 = i;
						toJoin2 = j;
						continue top;
					} else if (ec2 == fc) {
						toJoin1 = j;
						toJoin2 = i;
						continue top;
					}
				}
			}
			
			break;
		}
		
//		System.out.println("HOMO: " + Arrays.deepToString(simpler2.toArray(new int[0][])));
//		System.out.println("HETERO: " + Arrays.deepToString(hetero.toArray(new int[0][])));
		
		int splits = simpler2.size() + hetero.size();
		if (splits > 1) subtrains.add(splits);
		
		BigInteger bi = BigInteger.ONE;
		for (int z : subtrains) {
			BigInteger zi = BigInteger.ONE;
			for (int zz = 2; zz <= z; zz++) zi = zi.multiply(BigInteger.valueOf(zz));
			bi = bi.multiply(zi);
		}
		return bi;
	}
}
