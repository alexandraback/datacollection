import java.io.FileInputStream;
import java.util.Scanner;

public class C {

	private static String process(Scanner in) {
		long[] wall = new long[1000000];
		long[] wallh = new long[1000000];
		int origo = wall.length / 2;
		int[] changePos = new int[wall.length];
		long[] changeVal = new long[wall.length];
		int changeCount;
		int[] changePosh = new int[wall.length];
		long[] changeValh = new long[wall.length];
		int changeCounth;
		int N = in.nextInt();
		int[] d = new int[N];
		int[] n = new int[N];
		int[] w = new int[N];
		int[] e = new int[N];
		int[] s = new int[N];
		int[] delta_d = new int[N];
		int[] delta_p = new int[N];
		int[] delta_s = new int[N];
		for(int i = 0; i < N; i++) {
			d[i] = in.nextInt();
			n[i] = in.nextInt();
			w[i] = in.nextInt();
			e[i] = in.nextInt();
			s[i] = in.nextInt();
			delta_d[i] = in.nextInt();
			delta_p[i] = in.nextInt();
			delta_s[i] = in.nextInt();
		}

		long res = 0;

		// minden napra
		for(int day = 0; day < 676070; day++) {

			changeCount = 0;
			changeCounth = 0;
			int tribeChance = 0;

			// adott napon 
			for(int tribe = 0; tribe < N; tribe++) {

				if ( n[tribe] > 0 )
					tribeChance++;

				if ( d[tribe] != day || n[tribe] <= 0 )
					continue;

				// fal erositese
				boolean succeed = false;
				for(int i = w[tribe]; i <= e[tribe]; i++) { 
					if ( wall[i + origo] < s[tribe] ) {
						changePos[changeCount] = i;
						changeVal[changeCount] = s[tribe];
						changeCount++;
						succeed = true;
					}
					if ( i < e[tribe] && wallh[i + origo] < s[tribe] ) {
						changePosh[changeCounth] = i;
						changeValh[changeCounth] = s[tribe];
						changeCounth++;
						succeed = true;
					}
				}

				// ertekek update
				if ( succeed ) {
					/*
					System.out.println("----"); 
					System.out.println("day: " + day); 
					System.out.println("tribe: " + (tribe + 1)); 
					System.out.println("s: " + s[tribe]); 
					System.out.println("w,e: " + w[tribe] + "," + e[tribe]);
					 */

					res++;
				}

				s[tribe] += delta_s[tribe];
				w[tribe] += delta_p[tribe];
				e[tribe] += delta_p[tribe];
				d[tribe] += delta_d[tribe];
				n[tribe]--;
			}

			// wall update
			for(int i = 0; i < changeCount; i++) 
				if ( wall[changePos[i] + origo] < changeVal[i] )
					wall[changePos[i] + origo] = changeVal[i];

			for(int i = 0; i < changeCounth; i++) 
				if ( wallh[changePosh[i] + origo] < changeValh[i] )
					wallh[changePosh[i] + origo] = changeValh[i];

			if ( tribeChance == 0 )
				break;
		}

		return Long.toString(res);
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
