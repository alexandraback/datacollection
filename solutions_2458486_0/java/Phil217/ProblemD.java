import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;


public class ProblemD {
	
	static String winning = "";
	
	static HashSet<ArrayList<Boolean>> cache = new HashSet<ArrayList<Boolean>>();
	
	static class state {
		public int[] keys;
		ArrayList<Boolean> opened;
		int N;
		int d = 0;
		public state(int n) {
			opened = new ArrayList<Boolean>(n);
			for (int i = 0; i < n; i++) {
				opened.add(false);
			}
			keys = new int[201];
			N = n;
		}
	}
	
	public static void solve(Scanner sc) {
		winning = "";
		int K = sc.nextInt();
		int N = sc.nextInt();
		int[][] keys = new int[N][];
		int[] types = new int[N];
		state s = new state(N);
		for (int i = 0; i < K; i++) {
			s.keys[sc.nextInt()]++;
		}
		for (int i = 0; i < N; i++) {
			types[i] = sc.nextInt();
			int Ki = sc.nextInt();
			keys[i] = new int[Ki];
			for (int j = 0; j < Ki; j++) {
				keys[i][j] = sc.nextInt();
			}
		}
		for (int i = 0; i < N; i++) {
			if (s.keys[types[i]] > 0) {
				if (rec(s, keys, types, i)) {
					System.out.println(winning);
					return;
				}
			}
		}
		System.out.println("IMPOSSIBLE");
	}
	
	public static boolean rec(ProblemD.state s, int[][] keys, int[] types, int pos) {
		s.d++;
		if (s.d==s.N) {
			winning = "" + (pos + 1);
			return true;
		}
		s.opened.set(pos, true);
		if (cache.contains(s.opened)) {
			s.d--;
			s.opened.set(pos, false);
			return false;
		}
		ArrayList<Boolean> clone = (ArrayList<Boolean>) s.opened.clone();
		cache.add(clone);
		s.keys[types[pos]]--;
		for(int i = 0 ;i < keys[pos].length; i++) {
			s.keys[keys[pos][i]]++;
		}
		
		for (int i = 0; i < s.N; i++) {
			if (s.keys[types[i]] > 0 && !s.opened.get(i)) {
				if (rec(s, keys, types, i)) {
					winning = (pos + 1) + " " + winning;
					return true;
				}
			}
		}
		
		s.d--;
		s.opened.set(pos, false);
		s.keys[types[pos]]++;
		for(int i = 0;i < keys[pos].length; i++) {
			s.keys[keys[pos][i]]--;
		}
		return false;
	}
	
	
	
	
	public static void main(String[] args) throws FileNotFoundException {
//		 Scanner sc = new Scanner(new File("D-practice.in"));
		 Scanner sc = new Scanner(new File("D-small-attempt1.in"));
//		Scanner sc = new Scanner(new File("A-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			solve(sc);
		}
		sc.close();
	}
}
