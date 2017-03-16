import java.util.Arrays;
import java.util.Scanner;


public class Technobabble {
	
	public int max(int i, String[] f, String[] s) {
		if(i >= f.length)
			return 0;
		if(thief(i, f, s)) {
			int a = max(i+1, f,s);
			String s1 = f[i];
			String s2 = s[i];
			f[i] = "";
			s[i] = "";
			int b = max(i+1, f, s) + 1;
			f[i] = s1;
			s[i] = s2;
			return Math.max(a, b);
		} else {
			return max(i+1, f, s);
		}
	}
	
	public boolean thief(int i, String[] f, String[] s) {
		if(f[i].length() < 1) return false;
		for(int j = 0; j < f.length; j++) {
			if(i == j)continue;
			if(f[i].equals(f[j])) {
				for(int k = 0; k < f.length; k++) {
					if(k == j || k == i)continue;
					if(s[k].length() < 1)continue;
					if(s[i].equals(s[k])) {
						return true;
					}
				}
			}
		}
		return false;
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int tests = s.nextInt();
		for(int t = 1; t <= tests; t++) {
			int n = s.nextInt();
			String[] first = new String[n];
			String[] second = new String[n];
			for(int i = 0; i < n; i++) {
				first[i] = s.next();
				second[i] = s.next();
			}
			Technobabble tech = new Technobabble();
			int fake = tech.max(0, first, second);
			System.out.println("Case #"+t+": "+fake);
		}
	}

}
