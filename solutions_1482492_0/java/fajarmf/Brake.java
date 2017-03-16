import java.util.Scanner;

public class Brake {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int T = reader.nextInt();
		for(int nc = 1 ; nc<= T ; nc++) {
			double d = reader.nextDouble();
			int n = reader.nextInt(), a = reader.nextInt();
			double[][] pos = new double[n][2];
			double[] acc = new double[a];
			for(int i = 0 ; i < n ; i ++) {
				pos[i][0] = reader.nextDouble();
				pos[i][1] = reader.nextDouble();
			}
			for(int i = 0 ; i < a ; i ++) {
				acc[i] = reader.nextDouble();
			}
			System.out.printf("Case #%d:\n", nc);
			doit(d, pos, acc);
//			System.out.println();
		}
	}

	private static void doit(double d, double[][] pos, double[] acc) {
		for(double a : acc) {
			solve(d, a, pos);
		}
	}

	private static void solve(double d, double a, double[][] pos) {
		int n = pos.length;
		double lastV = 0;
		double position = 0;
		double res = 0;
		for(int i = 0 ; i < n -1 ; i ++) {
			double v = (pos[i+1][1] - pos[i][1]) / (pos[i+1][0]-pos[i][0]);
			double relV = lastV - v;
			double t = (-relV + Math.sqrt(relV*relV+2*a*pos[i][1]))/a;
			double s = position + 0.5 * a * t * t;
//			System.out.println(s + " s");
			if(s >= d) {
				res += (-lastV + Math.sqrt(lastV*lastV + 2*a * (d-position))) / a;
			} else {
				double left = Math.min(d,pos[i+1][1]) - s;
				res += t + (left/v);
				position = pos[i+1][1];
				lastV=v;
//				System.out.println(left);
//				System.out.println(res);
			}
		}
		System.out.println(res);
	}
}
