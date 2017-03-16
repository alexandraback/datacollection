import java.io.FileInputStream;
import java.util.Scanner;
import java.util.TreeSet;

// Hall of Mirrors
// https://code.google.com/codejam/contest/1460488/dashboard#s=p3

public class D {

	private static TreeSet<Double> s = new TreeSet<Double>();

	private static boolean store(double x1, double y1, double x0, double y0) {
		double d = Math.atan2(y1 - y0, x1 - x0);
		if ( s.contains(d) ) // hmmm rounding? :)
			return false;
		s.add(d);
		return true;
	}

	private static double d(double x, double y, double x0, double y0) {
		return Math.sqrt((x-x0)*(x-x0)+(y-y0)*(y-y0));
	}

	private static String process(Scanner in) {

		int H = in.nextInt();
		int W = in.nextInt();
		int D = in.nextInt();
		in.nextLine();
		s.clear();

		int h = -1;
		int w = -1;

		for(int hh = 0; hh < H; hh++) {
			String row = in.nextLine();
			int ww = row.indexOf('X');
			if ( ww != -1 && h == -1 ) {
				w = ww;
				h = hh;
			}
		}

		double xPos = w - 0.5d;
		double yPos = h - 0.5d;

		double[] xP = new double[100];
		double[] yP = new double[100];
		xP[0] = xPos;
		yP[0] = yPos;

		for(int i = 1; i < xP.length; i++) {
			xP[i] = i % 2 == 0 ? xP[0] + i * (W - 2) : (i + 1) * (W - 2) - xP[0];
			yP[i] = i % 2 == 0 ? yP[0] + i * (H - 2) : (i + 1) * (H - 2) - yP[0];
		}

		int res = 0;

		for(int x = 0; x < xP.length; x++)
			for(int y = 0; y < yP.length; y++) {
				if ( (x != 0 || y != 0) && d(xP[x], yP[y], xPos, yPos) <= D )
					if ( store(xP[x], yP[y], xPos, yPos) )
						res++;
				if ( d(-xP[x], yP[y], xPos, yPos) <= D )
					if ( store(-xP[x], yP[y], xPos, yPos) )
						res++;
				if ( d(xP[x], -yP[y], xPos, yPos) <= D )
					if ( store(xP[x], -yP[y], xPos, yPos) )
						res++;
				if ( d(-xP[x], -yP[y], xPos, yPos) <= D )
					if ( store(-xP[x], -yP[y], xPos, yPos) )
						res++;
			}

		return Integer.toString(res);
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++)
			//if ( i < 4 )
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
