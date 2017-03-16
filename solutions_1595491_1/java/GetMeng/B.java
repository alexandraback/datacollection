import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class B {

	public String solve(int N, int S, int p, int[] t) {
		int cnt = 0;
		int p1 = Math.max(3*p-2, p);
		int p2 = Math.max(3*p-4, p);
		for (int i=0; i<N; i++) {
			if (t[i] >= p1) {
				cnt ++;
			} else if (t[i] >= p2) {
				if (S > 0) {
					S --;
					cnt ++;
				}
			}
		}
		return Integer.toString(cnt) + "\n";
	}

	////////////////////////////////////////
	// read input
	////////////////////////////////////////
	public String runInput(BufferedReader br) throws IOException {
		String[] items = br.readLine().trim().split("\\s+");
		int idx = 0;
		int N = Integer.parseInt(items[idx++]);
		int S = Integer.parseInt(items[idx++]);
		int p = Integer.parseInt(items[idx++]);
		int[] t = new int[N];
		for (int i=0; i<N; i++) {
			t[i] = Integer.parseInt(items[idx++]);
		}
		return solve(N, S, p, t);
	}

	////////////////////////////////////////
	// main
	////////////////////////////////////////
	public static void main(String[] args) {
		B b = new B();
		try {
			b.parseFile("B-sample");
			b.parseFile("B-small-attempt0");
			b.parseFile("B-large");
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
