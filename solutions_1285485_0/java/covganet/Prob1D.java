import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.TreeSet;


public class Prob1D {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("D-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int t = Integer.parseInt(br.readLine());
		for(int x = 1; x <= t; x++) {
			String[] strs = br.readLine().split(" ");
			int h = Integer.parseInt(strs[0]);
			int w = Integer.parseInt(strs[1]);
			int d = Integer.parseInt(strs[2]);
			
			int initX = -1, initY = 0;
			for(int i = 0; i < h; i++) {
				String s = br.readLine();
				if(initX == -1) {
					initX = s.indexOf("X");
					if(initX >= 0) {
						initY = i;
					}
				}
			}
			w -= 2;
			h -= 2;
			
			TreeSet<Fraction> set = new TreeSet<Fraction>();
			for(int kx = 0; kx <= d; kx++) {
				int[] sxs = new int[] {w * kx * 2, -w * kx * 2, w * kx * 2 + initX * 2 - 1, -(w * kx * 2 + w * 2 - initX * 2 + 1)};
				for(int ky = 0; ky <= d; ky++) {
					int[] sys = new int[] {h * ky * 2, -h * ky * 2, h * ky * 2 + initY * 2 - 1, -(h * ky * 2 + h * 2 - initY * 2 + 1)};
					
					boolean allOver = true;
					for(int i = 0; i < sxs.length; i++) {
						for(int j = 0; j < sys.length; j++) {
							int tsq = sxs[i] * sxs[i] + sys[j] * sys[j];
							if(tsq > 0 && tsq <= d * d) {
								allOver = false;
								Fraction f = new Fraction(sxs[i], sys[j]);
								set.add(f);
							}
						}
					}
					if(allOver) {
						break;
					}
				}
			}
			
			pw.println("Case #" + x + ": " + set.size());
		}
		
		br.close();
		pw.close();
	}
}

class Fraction implements Comparable<Fraction> {
	public int a = 0, b = 1;
	
	public Fraction(int a, int b) {
		this.a = a;
		this.b = b;
	}

	@Override
	public int compareTo(Fraction f) {
		if(b == 0 && f.b == 0) {
			if(a > 0 && f.a > 0) {
				return 0;
			}
			if(a < 0 && f.a < 0) {
				return 0;
			}
			return a - f.a;
		}
		if(a == 0 && f.a == 0) {
			if(b > 0 && f.b > 0) {
				return 0;
			}
			if(b < 0 && f.b < 0) {
				return 0;
			}
			return b - f.b;
		}
		if(b == 0 || f.b == 0) {
			return b - f.b;
		}
		if(a == 0 || f.a == 0) {
			return a - f.a;
		}
		return a * f.b - b * f.a;
	}
	
	@Override
	public String toString() {
		return a + "/" + b;
	}
}