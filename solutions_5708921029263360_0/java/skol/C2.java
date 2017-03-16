import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;


public class C2 {

	static List<Outfit>[][][][] pre = new List[4][4][4][11];
	
	static {
		for (int j = 1; j <= 3; j++) {
			for (int p = 1; p <= 3; p++) {
				for (int s = 1; s <= 3; s++) {
					C2 c2 = new C2();
					c2.J = j;
					c2.P = p;
					c2.S = s;
					c2.prep();
					
					for (int k = 1; k <= 10; k++) {
						System.out.println(j + " " + p + " " + s + " " + k);
						c2.K = k;
						pre[j][p][s][k] = c2.sol();
					}
				}
			}
		}
	}
	
	
	Object solve() {
		J = sc.nextInt();
		P = sc.nextInt();
		S = sc.nextInt();
		K = sc.nextInt();
		
		List<Outfit> best = pre[J][P][S][K];
		
		fw.println(best.size());
		for (Outfit out : best) {
			fw.println(out);
		}
		return "";
	}
	
	int[] memo;
	
	private void prep() {
		outfits = new  ArrayList<>();
		for (int j = 1; j <= J; j++) {
			for (int p = 1; p <= P; p++) {
				for (int s = 1; s <= S; s++) {
					outfits.add(new Outfit(j, p, s));
				}
			}
		}
		M = P*S*J;
		memo = new int[1<<M];
	}
	
	private List<Outfit> sol() {
		if (K >= 3) {
			return decode((1<<M)-1);
		}
		
		int max = 0;
		int best = 0;
		for (int b = 1; b < (1<<M); b++) {
			int cn = cnt(b);
			if (cn > max) {
//				System.out.println(out);
				if (valid(b)) {
					max = cn;
					best = b;
				}
			}
		}
		
		return decode(best);
	}

	int maxCnt(int bm) {
		if (memo[bm] != 0)
			return memo[bm];
		List<Outfit> out = decode(bm);
		clearCnts();
		for (Outfit o : out) {
			cntsp(o.s, o.p);
			cntjp(o.j, o.p);
			cntjs(o.j, o.s);
		}
		return memo[bm] = maxCnt();
	}
	
	private boolean valid(int bm) {
		return maxCnt(bm) <= K;
	}
	
	private void clearCnts() {
		mapsp.clear();
		mapjp.clear();
		mapjs.clear();
	}

	HashMap<Pair,Integer> mapsp = new HashMap<>();
	void cntsp(int s, int p) {
		cnt(s, p, mapsp);
	}
	
	HashMap<Pair,Integer> mapjp = new HashMap<>();
	void cntjp(int j, int p) {
		cnt(j, p, mapjp);
	}
	
	HashMap<Pair,Integer> mapjs = new HashMap<>();
	void cntjs(int j, int s) {
		cnt(j, s, mapjs);
	}
	
	void cnt(int a, int b, Map<Pair,Integer> map) {
		Pair p = new Pair(a, b);
		Integer c = map.get(p);
		if (c == null)
			map.put(p, 1);
		else
			map.put(p, c+1);
	}
	
	boolean checkCnt(Map<Pair,Integer> map) {
		for (int c : map.values())
			if (c > K)
				return false;
		return true;
	}
	
	int maxCnt(Map<Pair,Integer> map) {
		int max = 0;
		for (int c : map.values())
			max = Math.max(max, c);
		return max;
	}
	
	int maxCnt() {
		return Math.max(Math.max(maxCnt(mapjp), maxCnt(mapsp)), maxCnt(mapjs));
	}
	
	boolean checkCnt() {
		return checkCnt(mapjp) && checkCnt(mapsp) && checkCnt(mapjs);
	}
	
	static class Pair {
		int a, b;

		public Pair(int a, int b) {
			super();
			this.a = a;
			this.b = b;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + a;
			result = prime * result + b;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pair other = (Pair) obj;
			if (a != other.a)
				return false;
			if (b != other.b)
				return false;
			return true;
		}
	}
	

	private int cnt(int b) {
		return Integer.bitCount(b);
	}
	
	List<Outfit> decode(int bm) {
		ArrayList<Outfit> res = new ArrayList<>();
		for (int j = 0; j < M; j++) {
			if (((bm>>j)&1) == 1) {
				res.add(outfits.get(j));
			}
		}
		return res;
	}
	
	static class Outfit {
		int j, p, s;

		public Outfit(int j, int p, int s) {
			this.j = j;
			this.p = p;
			this.s = s;
		}

		public int cntEq(Outfit o2) {
			int cnt = 0;
			if (j == o2.j)
				cnt++;
			if (p == o2.p)
				cnt++;
			if (s == o2.s)
				cnt++;
			return cnt;
		}
		
		@Override
		public String toString() {
			return j + " " + p + " " + s;
		}
	}
	

	private static Scanner sc; private static PrintWriter fw;

	private int J;

	private int P;

	private int S;

	private int K;

	private int M;

	private ArrayList<Outfit> outfits;

	public static void main(String[] args) throws Exception {
		String inFile = "input.txt", outFile = "output.txt";
		if (args.length == 0) {
			sc = new Scanner(System.in);
	//		sc = new Scanner(new FileInputStream(inFile));
		} else {
			inFile = args[0];
			sc = new Scanner(new FileInputStream(inFile));
			if (args.length > 1)
				outFile = args[1];
			else if (inFile.endsWith(".in"))
				outFile = inFile.substring(0, inFile.length() - 2) + "out";
			System.out.println(inFile + " -> " + outFile);
		}
		
		fw = new PrintWriter(new FileWriter(outFile, false)) {
			public PrintWriter printf(String format, Object... args) {
				System.out.printf(format, args);
				return super.printf(format, args);
			}
		};
		
		int N = sc.nextInt();
		sc.nextLine();
		System.out.println(N + " cases.");
		
		int progress = 0, progress1;
		for (int cas = 1; cas <= N; cas++) {
			fw.printf("Case #" + cas + ": ");
//			fw.println("Case #" + cas + ": ");
			Object res = new C2().solve();
			if (res instanceof Double) 
				fw.printf("%.10f\n", res);
			else
				fw.printf("%s\n", res);
			fw.flush();
			if ((progress1 = cas*10/N) > progress) { System.out.println("*" + progress1*10 + "% "); progress = progress1; };
		}
		fw.close();
		sc.close();
	}
}
