import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class B {

	public static void main(String[] args) throws Exception {

//		String inFile = "B-example.in";
//		String outFile = "B-example.out";
		String inFile = "B-small-attempt0.in";
		String outFile = "B-small-attempt0.out";
//		String inFile = "B-large.in";
//		String outFile = "B-large.out";
		Scanner in = new Scanner(new File(inFile));
		try {
			int T = in.nextInt();
			PrintStream out = new PrintStream(outFile);
			try {
				for (int t = 1; t <= T; t++) {
					out.printf("Case #%d: %s\n", t, turn(in));
				}
			} finally {
				out.close();
			}
		} finally {
			in.close();
		}
	}

	private static String turn(Scanner in) {
		int X = in.nextInt();
		int Y = in.nextInt();
		StringBuffer sb = new StringBuffer();
		int n = 1;
		if(Math.abs(X) < Math.abs(Y)) {
			n = makeX(sb, X, n);
			makeY(sb, Y, n);
		} else {
			n = makeY(sb, Y, n);
			makeX(sb, X, n);
		}
		return sb.toString();
	}
	
	private static int makeX(StringBuffer sb, int X, int n) {
		int x = 0;
		if (X > 0) {
			while(X - x >= n ) {
				sb.append("E");
				x += n;
				n++;
			}
			while(X - x > 0) {
				sb.append("WE");
				x++;
				n += 2;
			}
		} else {
			while(-X + x >= n ) {
				sb.append("W");
				x -= n;
				n++;
			}
			while(-X + x > 0) {
				sb.append("EW");
				x--;
				n += 2;
			}
		}
		return n;
	}
	
	private static int makeY(StringBuffer sb, int Y, int n) {
		int y = 0;
		if (Y > 0) {
			while(Y - y >= n ) {
				sb.append("N");
				y += n;
				n++;
			}
			while(Y - y > 0) {
				sb.append("SN");
				y++;
				n += 2;
			}
		} else {
			while(-Y + y >= n ) {
				sb.append("S");
				y -= n;
				n++;
			}
			while(-Y + y > 0) {
				sb.append("NS");
				y--;
				n += 2;
			}
		}
		return n;
	}
}
