import java.util.Scanner;

class B {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		int I = 0;
		while (I++ < T) {
			int E = in.nextInt(), R = in.nextInt(), N = in.nextInt();
			int[] v = new int[N];
			int sum = 0;
			for (int i = 0; i < N; ++i) {
				v[i] = in.nextInt();
				sum += v[i];
			}
			int max = (int) Math.pow(E, N);
			int ans = 0;
			OUT: for (int i = 0; i < max; ++i) {
//System.out.print(String.format("%" + N + "s", Integer.toString(i, E)) + ": ");
				int tmp = 0, tmpE = E;
				char[] amtStr = String.format("%"  + N + "s", Integer.toString(i, E)).replaceAll(" ", "0").toCharArray();
				int[] amts = new int[N];
				for (int j = 0; j < amtStr.length; ++j) {
					amts[j] = amtStr[j] - '0' + 1;
					tmpE -= amts[j];
					if (tmpE < 0) {
//System.out.println();
						continue OUT;
					}
					tmpE = Math.min(E, tmpE + R);
					tmp += v[j] * amts[j];
				}
//System.out.println(tmp);
				ans = Math.max(tmp, ans);
			}
			
			if (R == E)
				ans = sum * R;
			
			System.out.printf("Case #%d: %d\n", I, ans);
		}

	}

}
