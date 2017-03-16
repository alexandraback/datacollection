package qual2012;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

/**
 * Magicka
 */
public class B {
	public static void main(String[] args) throws FileNotFoundException {
		Kattio io;

//		io = new Kattio(System.in, System.out);
//		io = new Kattio(new FileInputStream("src/qual2012/B-sample.in"), System.out);
		io = new Kattio(new FileInputStream("src/qual2012/B-small-attempt1.in"), new FileOutputStream("src/qual2012/B-small-1.out"));
//		io = new Kattio(new FileInputStream("src/qual2012/B-large.in"), new FileOutputStream("src/qual2012/B-large.out"));

		int cases = io.getInt();
		for (int i = 1; i <= cases; i++) {
			io.print("Case #" + i + ": ");
			new B().solve(io);
		}
		io.close();
	}

	private void solve(Kattio io) {
		int n = io.getInt(), m = io.getInt(), p = io.getInt();

		boolean[] okNormal = new boolean[31];
		boolean[] okSurprising = new boolean[31];

		for (int i = 0; i <= 10; i++) {
			for (int j = i; j <= 10; j++) {
			    for (int k = j; k <= 10; k++) {
			   		if (k > i+2) continue;
					if (k >= p) {
						if (k > i+1)
							okSurprising[i+j+k] = true;
						else
							okNormal[i+j+k] = true;
					}
			    }
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
		    int score = io.getInt();
			if (okNormal[score]) cnt++;
			else if (m > 0 && okSurprising[score]) { cnt++; m--; }
		}
		io.println(cnt);

	}
}
