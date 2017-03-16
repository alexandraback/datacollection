package codejam;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class repeats {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		for (int i = 1; i <= T; i++) {
			fir = new HashMap<>();
			sec = new HashMap<>();
			ans = 0;
			int words = s.nextInt();
			fakes = new boolean[words];
			for (int j = 0; j < words; j++) fakes[j] = false;
			
			p = new Pair[words];
			for (int j = 0; j < words; j++) {
				p[j] = new Pair(s.next(), s.next());
				if (fir.containsKey(p[j].s1)) {
					fir.put(p[j].s1, fir.get(p[j].s1) + 1);
				} else {
					fir.put(p[j].s1, 1);
				}
				if (sec.containsKey(p[j].s1)) {
					sec.put(p[j].s1, sec.get(p[j].s1) + 1);
				} else {
					sec.put(p[j].s1, 1);
				}
			}
			
			solve(0);
			
			System.out.println("Case #" + i + ": " + ans);
		}
	}
	
	static Map<String, Integer> fir = new HashMap<>();
	static Map<String, Integer> sec = new HashMap<>();
	static Pair[] p;
	static boolean[] fakes;
	
	private static int ans;
	
	public static void solve(int index) {
		if (index == p.length) {
			int newAns = 0;
			for (int i = 0; i < fakes.length; i++) {
				if (fakes[i]) newAns++;
			}
			if (newAns > ans) ans = newAns;
			return;
		}
		
		if (canBeFake(index)) {
			fakes[index] = true;
			solve(index+1);
			fakes[index] = false;
		}
		solve(index+1);
	}
	
	public static boolean canBeFake(int index) {
		boolean firstFake = false;
		boolean secondFake = false;
		
		for (int i = 0; i < p.length; i++) {
			if (i != index && !fakes[i]) {
				firstFake |= p[index].s1.equals(p[i].s1);
				secondFake |= p[index].s2.equals(p[i].s2);
			}
		}
		
		return firstFake && secondFake;
	}
	
	static class Pair {
		String s1, s2;
		
		public Pair(String ss1, String ss2) {
			s1 = ss1;
			s2 = ss2;
		}
	}
	
}
