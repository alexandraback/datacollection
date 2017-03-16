package dancers;
import java.io.BufferedReader;
import java.io.FileReader;
public class Dancing {
	static int solve(int N, int S, int p, int[] ts) {
		int good = 0, improveable = 0;
		for (int i = 0; i < ts.length; ++i) {
			int total = ts[i];
			int simple=0, special=0;
			if (total % 3 == 0) {
				simple = total/3;
				if (simple > 0 && simple < 10) special = simple+1;
			} else if (total % 3 == 1) {
				simple = total/3+1;
				if (total/3 > 0) special = simple;
			} else if (total % 3 == 2) {
				simple = total/3+1;
				special = simple+1;
			}
			if (simple >= p) ++good;
			else if (special >= p) ++improveable;
		}
		return good + Math.min(improveable,S);
	}
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		String line = in.readLine();
		int X = Integer.parseInt(line);
		for (int i = 0; i < X; ++i) {
			line = in.readLine();
			String[] toks = line.split(" ");
			int N = Integer.parseInt(toks[0]);
			int S = Integer.parseInt(toks[1]);
			int p = Integer.parseInt(toks[2]);
			int[] ts = new int[N];
			for (int j = 0; j < N; ++j) {
				ts[j] = Integer.parseInt(toks[3+j]);
			}
			System.out.println("Case #"+(i+1)+": "+solve(N,S,p,ts));
		}
	}
}