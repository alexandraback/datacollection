import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class C {

	public String solve(int A, int B) {
		int cnt = 0;
		int[] v = new int[B+1];
		for (int i=A; i<=B; i++) {
			int mul = 1;
			int ii = i;
			int dig = 0;
			while (ii > 0) {
				mul *= 10;
				ii /= 10;
				dig ++;
			}
			mul /= 10;
			int right = i;
			int left = 0;
			for (int d=0; d<dig-1; d++) {
				left /= 10;
				left += (right % 10) * mul;
				right /= 10;
				int k = left + right;
				if (k > i && k <= B) {
					if (v[k] != i) {
						cnt ++;
						v[k] = i;
					}
				}
			}
		}
		return cnt + "\n";
	}

	////////////////////////////////////////
	// read input
	////////////////////////////////////////
	public String runInput(BufferedReader br) throws IOException {
		String[] items = br.readLine().trim().split("\\s+");
		int A = Integer.parseInt(items[0]);
		int B = Integer.parseInt(items[1]);

		return solve(A, B);
	}

	////////////////////////////////////////
	// main
	////////////////////////////////////////
	public static void main(String[] args) {
		C c = new C();
		try {
			c.parseFile("C-sample");
			c.parseFile("C-small-attempt0");
			//c.parseFile("C-large");
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
