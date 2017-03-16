package round1;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

public class C {
	public static void main(String[] args) throws FileNotFoundException {
		Kattio io;

//		io = new Kattio(System.in, System.out);
//		io = new Kattio(new FileInputStream("src/round1/C-sample.in"), System.out);
		io = new Kattio(new FileInputStream("src/round1/C-small-0.in"), new FileOutputStream("src/round1/C-small-0.out"));
//		io = new Kattio(new FileInputStream("src/round1/C-large.in"), new FileOutputStream("src/round1/C-large.out"));

		int cases = io.getInt();
		for (int i = 1; i <= cases; i++) {
			io.print("Case #" + i + ": ");
			new C().solve(io);
		}
		io.close();
	}

	private void solve(Kattio io) {
		int n = io.getInt();
		int value[] = new int[n];
		for (int i = 0; i < n; i++) {
			value[i] = io.getInt();
		}
		int sumCnt[] = new int[100000*20+1];
		int pickedSum = -1;
		for (int i = 0; i < (1<<n) && pickedSum <0 ; i++) {
			int sum = 0;
		    for (int j = 0; j < n; j++) {
				if (((1<<j)&i)>0) sum += value[j];
		    }
			if (++sumCnt[sum]>=2) {
				pickedSum = sum;
			}
		}
		if (pickedSum < 0) {
			io.println("Impossible");
		} else {
			io.println();
			int ways = 0;
			for (int i = 0; i < (1<<n) && ways < 2 ; i++) {
				int sum = 0;
				for (int j = 0; j < n; j++) {
					if (((1<<j)&i)>0) sum += value[j];
				}
				if (sum == pickedSum) {
					boolean first = true;
					for (int j = 0; j < n; j++) {
						if (((1<<j)&i)>0) {
							if (!first) io.print(' ');
							io.print(value[j]);
							first = false;
						}
					}
					ways++;
					io.println();
				}
			}
		}
	}
}
