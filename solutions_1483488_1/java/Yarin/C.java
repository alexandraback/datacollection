package qual2012;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.HashSet;

public class C {
	public static void main(String[] args) throws FileNotFoundException {
		Kattio io;

//		io = new Kattio(System.in, System.out);
//		io = new Kattio(new FileInputStream("src/qual2012/C-sample.in"), System.out);
//		io = new Kattio(new FileInputStream("src/qual2012/C-small-0.in"), new FileOutputStream("src/qual2012/C-small-0.out"));
		io = new Kattio(new FileInputStream("src/qual2012/C-large-0.in"), new FileOutputStream("src/qual2012/C-large-0.out"));

		int cases = io.getInt();
		for (int i = 1; i <= cases; i++) {
			io.print("Case #" + i + ": ");
			new C().solve(io);
		}
		io.close();
	}

	private void solve(Kattio io) {
		int A = io.getInt(), B = io.getInt();
		int noDig = 0, t = A;
		while (t > 0) {
			noDig++;
			t /= 10;
		}

		int cnt = 0;
		for(int n = A; n <= B; n++) {
			String s = "" + n;
			HashSet<String> used = new HashSet<String>();
			for (int i = 0; i < noDig - 1; i++) {
			    s = s.substring(1) + s.charAt(0);
				if (used.contains(s)) continue;
				used.add(s);
				int q = Integer.parseInt(s);
				if (q > n && q <= B) {
					cnt++;
				}
			}
		}
		io.println(cnt);
	}
}
