import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class D {
	public static void main(String args[]) {
		new D();
	}

	public D() {
		Scanner in = new Scanner(System.in);

		int T = in.nextInt();
		for(int x=1; x<=T; x++) {
			int H = in.nextInt();
			int W = in.nextInt();
			int D = in.nextInt();

			double myX = 0;
			double myY = 0;
			for(int h=0; h<H; h++) {
				String row = in.next();
				if(h==0 || h==H-1) continue;
				for(int w=0; w<W; w++) {
					if(w==0 || w==W-1) continue;
					char c = row.charAt(w);
					if(c == 'X') {
						myX = 0.5 + 1.0 * (w-1);
						myY = 0.5 + 1.0 * (h-1);
					}
				}
			}

			double fw = W - 2;
			double fh = H - 2;
			int repX = (int)(D / fw);
			int repY = (int)(D / fh);

			Set<Double> set = new TreeSet<Double>();
			int y = 0;
			for(int j=-repY-1; j<=repY+1; j++) {
				for(int i=-repX-1; i<=repX+1; i++) {
					if(i == 0 || j == 0) continue;

					double dx = i%2 == 0 ? Math.abs(i) * fw : (Math.abs(i)-1) * fw + 2.0 * (i > 0 ? fw - myX : myX);
					double dy = j%2 == 0 ? Math.abs(j) * fh : (Math.abs(j)-1) * fh + 2.0 * (j > 0 ? fh - myY : myY);
					if(i < 0) dx = -dx;
					if(j < 0) dy = -dy;
					double dist = Math.sqrt(dx * dx + dy * dy);
					if(dist <= D) {
						double theta = Math.atan2(dy, dx);
						if(set.contains(theta)) continue;

						y++;
						set.add(theta);
					}
				}
			}

			if(myX * 2 <= D) y++;
			if(myY * 2 <= D) y++;
			if((fw - myX) * 2 <= D) y++;
			if((fh - myY) * 2 <= D) y++;


			System.out.printf("Case #%d: %d\n", x, y);
		}
	}
}