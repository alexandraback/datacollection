package round1C;


import java.util.*;

public class a {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			// TODO
			int r = in.nextInt();
			int c = in.nextInt();
			int w = in.nextInt();
			
			int remain = c % w;
			int tries = c / w;
			
			int cnt = r * tries + w - 1;
			if (remain > 0) cnt ++;
			System.out.printf("Case #%d: %d\n", t, cnt);
		}
	}
}
