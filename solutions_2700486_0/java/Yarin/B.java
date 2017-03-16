package round1b;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

public class B {
	public static void main(String[] args) throws FileNotFoundException {
		Kattio io;

//		io = new Kattio(System.in, System.out);
//		io = new Kattio(new FileInputStream("src/round1b/B-sample.in"), System.out);
		io = new Kattio(new FileInputStream("src/round1b/B-small-attempt0.in"), new FileOutputStream("src/round1b/B-small-0.out"));
//		io = new Kattio(new FileInputStream("src/round1b/B-large.in"), new FileOutputStream("src/round1b/B-large-0.out"));
        fac = new double[1000010];
        fac[0] = 1;
        for (int i = 1; i < fac.length; i++) {
            fac[i] = fac[i-1] * i;
        }

		int cases = io.getInt();
		for (int i = 1; i <= cases; i++) {
			io.print("Case #" + i + ": ");
			new B().solve(io);
		}
		io.close();
	}

    private static double fac[];

    private double choose(int n, int k) {
        return fac[n] / (fac[k] * fac[n-k]);
    }

	private void solve(Kattio io) {
        int n = io.getInt(), x = io.getInt(), y = io.getInt();

        if ((x + y) % 2 != 0 || y < 0) {
            io.println("0.0");
            return;
        }

        int layer = (Math.abs(x) + y) / 2;
        int sum = 0, next = 1;
        for (int i = 0; i < layer; i++) {
            sum += next;
            next += 4;
        }
        int beforeLayer = sum;
        if (n <= beforeLayer) {
            io.println("0.0");
            return;
        }
        n -= beforeLayer;
        if (n >= next) {
            io.println("1.0");
            return;
        }
        if (x == 0) {
            if (n < next) {
                io.println("0.0");
            } else {
                io.println("1.0");
            }
            return;
        }

        io.println(go(y + 1, 0, n, layer * 2));
	}

    private double go(int left, int right, int n, int maxSize) {
        if (left == 0) {
            return 1.0;
        }
        if (n == 0) {
            return 0.0;
        }
        if (right == maxSize) {
            return go(left - 1, right, n - 1, maxSize);
        }
        return go(left - 1, right, n - 1, maxSize) / 2.0 + go(left, right + 1, n - 1, maxSize) / 2.0;
    }
}
