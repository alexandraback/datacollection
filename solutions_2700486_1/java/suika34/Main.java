import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String line = br.readLine();
			int T = Integer.parseInt(line);
			
			for (int i=1; i<=T; i++) {
				line = br.readLine();
				String[] a = line.split(" ");
				int N = Integer.parseInt(a[0]);
				int X = Integer.parseInt(a[1]);
				int Y = Integer.parseInt(a[2]);
				String sol = main.solve(N, X, Y);
				System.out.println("Case #"+i+": "+sol);
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public String solve(int N, int X, int Y) {
		int index = 0;
		int sum = 0;
		for (int i=0; i<N; i++) {
			if (N < sum + 4*i+1) {
				index = i-1;
				break;
			}
			sum += 4*i+1;
		}
		int res = N - sum;
		//System.out.println(index+" "+res);
		if (Math.abs(X) + Y <= 2*index) {
			return "1.0";
		} else if (Math.abs(X)+Y != 2*(index+1) || X == 0) {
			return "0.0";
		} else if (Y < res - 2*(index+1)) {
			return "1.0";
		} else {
			double ratio = 0.0;
			double r = Math.pow(0.5, res);
			//System.out.println(r);
			for (int num=Y+1; num<=res; num++) {
				ratio += comb(res, num, r);
			}
			return "" + ratio;
		}
	}

	public double comb(int n, int m, double r) {
		if (n < 2*m) {
			m = n-m;
		}
		double ratio = r;
		for (int i=0; i<m; i++) {
			ratio = ratio * (n-i) / (i+1);
		}
		//System.out.println(ratio);
		return ratio;
	}
}
