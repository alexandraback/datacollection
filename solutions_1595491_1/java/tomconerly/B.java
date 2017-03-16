import java.util.*;
import static java.lang.Math.*;

public class B {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int zz = 1; zz <= T; zz++) {
			System.err.println(zz);
			int N = in.nextInt();
			int S = in.nextInt();
			int P = in.nextInt();
			int num11 = 0;
			int num10 = 0;
			int num01 = 0;
			int num00 = 0;
			for (int i = 0; i < N; i++) {
				int sum = in.nextInt();
				boolean reg = false;
				boolean sup = false;
				for(int a = 0; a <= 10; a++) {
					for(int b = 0; b <= 10; b++) {
						for(int c = 0; c <= 10; c++) {
							int min = min(a, min(b, c));
							int max = max(a, max(b, c));
							if (max-min > 2 || a + b + c != sum || max < P)
								continue;
							if (max-min == 2)
								sup = true;
							else
								reg = true;
						}
					}
				}
				if (sup && reg)
					num11++;
				else if (!sup && reg)
					num01++;
				else if(sup && !reg)
					num10++;
				else
					num00++;
			}
//			System.out.println(num00+ " "+num10+" "+num01+" "+num11);
			int ans = 0;
			for(int a = 0; a <= num11; a++) {
				for(int b = 0; b <= num10; b++) {
					for(int c = 0; c <= num01; c++) {
						int d = S - (a + b + c);
						if (d > num00 || d < 0)
							continue;
						ans = max(ans, num11 + b + num01-c);
					}
				}
			}
			
			System.out.format("Case #%d: %d\n", zz, ans);
		}
	}
}
