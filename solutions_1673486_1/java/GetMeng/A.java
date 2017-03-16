import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class A {

	public String solve(int A, int B, double[] p) {
		// 3
		double ans = 1 + B + 1;
		// 1
		double tmp1 = B - A + 1;
		double tmp2 = 1;
		for (int i=0; i<p.length; i++) {
			tmp2 *= p[i];
		}
		tmp2 = 1 - tmp2;
		tmp1 += tmp2 * (B+1);
		ans = Math.min(ans,  tmp1);
		// 2
		int cnt = A + B + 1;
		double pp = 1;
		for (int i=0; i<p.length; i++) {
			ans = Math.min(ans, pp*cnt+(1-pp)*(cnt+B+1));
			cnt -= 2;
			pp *= p[i];
		}
		return Double.toString(ans) + "\n";
	}

	////////////////////////////////////////
	// read input
	////////////////////////////////////////
	public String runInput(BufferedReader br) throws IOException {
		String[] items = br.readLine().trim().split("\\s+");
		int A = Integer.parseInt(items[0]);
		int B = Integer.parseInt(items[1]);
		items = br.readLine().trim().split("\\s+");
		double[] p = new double[A];
		for (int i=0; i<A; i++) {
			p[i] = Double.parseDouble(items[i]);
		}
		return solve(A, B, p);
	}

	////////////////////////////////////////
	// main
	////////////////////////////////////////
	public static void main(String[] args) {
		A a = new A();
		try {
			a.parseFile("A-sample");
			a.parseFile("A-small-attempt0");
			a.parseFile("A-large");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	////////////////////////////////////////
	// library
	////////////////////////////////////////
	public void parseFile(String filePrefix) throws IOException {
		String fileIn = filePrefix + ".in";
		String fileOut = filePrefix + ".out";

		BufferedReader br = new BufferedReader(new FileReader(fileIn));
		BufferedWriter bw = new BufferedWriter(new FileWriter(fileOut));

		int n = Integer.parseInt(br.readLine());
		for (int i=1; i<=n; i++) {
			String ret = "Case #" + i + ": ";
			ret += runInput(br);
			System.out.print(ret);
			bw.write(ret);
		}
		br.close();
		bw.close();
	}

}
