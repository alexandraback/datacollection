import java.io.*;
import java.util.*;

public class Main {
	
	Scanner in;
	PrintWriter out;
	
	static final String path = "C:/gcj/";
	static final String problemName = "A2";
	
	
	void solveOne() {
		int n = in.nextInt();
		int s [] = new int[n];
		int x = 0;
		for (int i = 0; i < n; i++) {
			s[i] = in.nextInt();
			x += s[i];
		}
		
		for (int i = 0; i < n; i++) {
			int hasValue = s[i];
			
			double low = 0;
			double high = 1;
			while (true) {
				double mid = (low + high) / 2.0;
				
				if (high - low < 1e-12) {
					break;
				}
				
				double score = hasValue + x * mid;

				double sumPer = 0;
				for (int j = 0; j < n; j++) {
					if (j != i) {
						double per2 = (score - s[j]) / (x + 0.0);
						if (per2 > 0) {
							sumPer += per2;
						}
					}
				}
				if (sumPer + 1e-12 < 1 - mid) {
					low = mid;
				} else {
					high = mid;
				}
			}
			
			out.printf(Locale.US, "%.8f", 100.0 * high);
			out.print(" ");
		}
		
	}
	
	void solve() {
		int t = in.nextInt();
		for (int i = 1; i <= t; i++) {
			out.print("Case #" + i + ": ");
			solveOne();
			out.println();
		}
	}
	
	static void asserT(boolean e) {
		if (!e) {
			throw new Error();
		}
	}
	
	
	public void run() {
		try {
			in = new Scanner(new FileReader(path + problemName + ".in"));
			out = new PrintWriter(path + problemName + ".out");
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
		}
		
		try {
			solve();
		} finally {
			out.close();
		}
	}
	
	public static void main(String[] args) {
		new Main().run();
	}

}