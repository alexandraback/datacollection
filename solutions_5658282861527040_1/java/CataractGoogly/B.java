package gcj2014_1b;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class B {

	static int[] a;
	static int[] b;
	static int[] k;
	static long[][][][] memo;

	static long calc2(int pos, int aless, int bless, int kless) {
		long res = 0;
		for (int aa=0; aa<2; aa++) {
			for (int bb=0; bb<2; bb++) {
				int kk = aa & bb;
				if (aless==0 && aa > a[pos])
					continue;
				if (bless==0 && bb > b[pos])
					continue;
				if (kless==0 && kk > k[pos])
					continue;
				int aless2 = aless;
				if (aa < a[pos]) aless2 = 1;
				int bless2 = bless;
				if (bb < b[pos]) bless2 = 1;
				int kless2 = kless;
				if (kk < k[pos]) kless2 = 1;
				res += calc(pos-1, aless2, bless2, kless2);
			}
		}
		return res;
	}

	static long calc(int pos, int aless, int bless, int kless) {
		if (pos==-1) {
			if (aless==1 && bless==1 && kless==1)
				return 1;
			return 0;
		}
		if (memo[pos][aless][bless][kless] >= 0)
			return memo[pos][aless][bless][kless];
		memo[pos][aless][bless][kless] = calc2(pos, aless, bless, kless);
		return memo[pos][aless][bless][kless];
	}

	static String solve(int A, int B, int K) {
		a = new int[32];
		b = new int[32];
		k = new int[32];
		for (int i=0; i<32; i++) {
			a[i] = A % 2; A /= 2;
			b[i] = B % 2; B /= 2;
			k[i] = K % 2; K /= 2;
		}
		memo = new long[32][2][2][2];
		for (int i=0; i<32; i++)
			for (int j=0; j<2; j++)
				for (int x=0; x<2; x++)
					for (int y=0; y<2; y++)
						memo[i][j][x][y] = -1;
		return Long.toString(calc(31, 0, 0, 0));
	}

	public static void main(String[] args) {
		try {
			File fin = new File("B-large.in");
			Scanner sc = new Scanner(fin);
			File fout = new File("B-out.txt");
			PrintWriter pw = new PrintWriter(fout);
			//PrintWriter pw = new PrintWriter(System.out);
			int T = sc.nextInt();
			for (int cn=1; cn<=T; cn++) {
				int A = sc.nextInt();
				int B = sc.nextInt();
				int K = sc.nextInt();
				pw.write("Case #" + cn + ": " + solve(A, B, K) + "\n");
			}
			pw.flush();
			pw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
