package round1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	int AA;
	int NN;
	int[] arr;
	int[][] mem = new int[2000005][105];
	public static void main(String[] args) throws Exception {
		new A().solve();
	}

	private void solve() throws Exception {
		Scanner s = new Scanner(new File("C:\\dev\\gcj\\a\\input.txt"));
		int T = s.nextInt();
		for (int i = 0; i < T; i++) {
			AA = s.nextInt();
			NN = s.nextInt();
			for(int k0 = 0; k0 < 2000005; k0++)
				for(int k1 = 0; k1 < 105; k1++)
					mem[k0][k1] = -1;
			arr = new int[NN];
			for (int j = 0; j < NN; j++) {
				arr[j] = s.nextInt();
			}
			System.out.println("Case #" + (i + 1) + ": " + go());
		}
		s.close();
	}

	int f(int A, int p) {
		int A0 = A, p0 = p;
		if(mem[A0][p0] != -1)
			return mem[A0][p0];
		while (p < NN && arr[p] < A) {
			A += arr[p];
			p++;
		}
		if(p > NN - 1)
			return 0;
		int o1 = f(A, p + 1) + 1;
		
		int s = 0;
		if(A == 1) {
			mem[A0][p0] = o1;
			return o1;
		}
		while(A <= arr[p]) {
			A += A - 1;
			s++;
		}
		int o2 = f(A, p) + s;
		mem[A0][p0] = Math.min(o1, o2);
		return mem[A0][p0];
	}

	int go() {
		Arrays.sort(arr);
		return f(AA, 0);
	}

}
