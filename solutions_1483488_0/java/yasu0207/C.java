import java.util.*;
import java.io.*;

public class C {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		System.setOut(new PrintStream(new File("C.out")));
		int T = sc.nextInt();
		for(int ca = 1; ca <= T; ca++) {
			int A = sc.nextInt();
			int B = sc.nextInt();
			int ans = 0;
			Set<Integer> set = new TreeSet<Integer>();
			for(int n=A; n<B; n++) {
				String s = n +"";
				for(int j=0; j<s.length()-1; j++) {
					String pre = s.substring(0, j+1);
					String suf = s.substring(j+1);
					if(suf.charAt(0) == '0')continue;
					int m = Integer.parseInt(suf + pre);
					if(n < m && m <= B) {
						set.add(m);
					}
				}
				ans += set.size();
				set.clear();
			}
			System.out.printf("Case #%d: %d\n", ca, ans);
		}
	}
}
