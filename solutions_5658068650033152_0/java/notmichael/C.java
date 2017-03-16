import java.util.*;

public class C {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		for (int t=0; t<cases; t++) {
			int n = in.nextInt();
			int m = in.nextInt();
			int k = in.nextInt();
			if (t!=cases-1) in.nextLine();
			int x = 1;
			int h = 1;
			int w = 1;
			while (x < k && (h < n || w < m)) {
				if ((h<w && h < n) || w==m) {
					h++;
					x = calculate(h,w);
				}
				else {
					w++;
					x = calculate(h,w);
				}
				//System.out.println(h + ", " + w + ": " + x);
			}
			int xp=0;
			if (x<k) {
				int x2 = 2*Math.abs(w-h);
				if (x+x2<k) {
					xp = k - x - x2;
				}
			}
			int ans = x - calculate(h-2, w-2) + xp;
			if (h==1 || w==1) {
				ans = k;
			}
			System.out.println("Case #" + (t+1) + ": " + ans);
		}
	}
	
	private static int calculate(int h, int w) {
		if (h<w) {
			return 2*(sum(h/2) + sum(h-h/2)) + h*(w-2*(h-h/2));
		}
		else {
			return 2*(sum(w/2) + sum(w-w/2)) + w*(h-2*(w-w/2));
		}
	}
	
	private static int sum(int x) {
		return (x*x + x)/2;
	}

}
