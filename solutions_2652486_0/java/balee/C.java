import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class C {

	static int[] items = {2, 3, 4, 5, 6, 7, 8};
	static int[] values = new int[7];
	static int N;
	static int M;
	static int K;
	static int[] k;
	static int[] kk;
	static int[] state;
	static int ok;

	public static boolean comb1(int index, int mul) {

		if ( index < N ) {
			state[index] = 0;
			if ( comb1(index + 1, mul) )
				return true;
			state[index] = 1;
			if ( comb1(index + 1, mul * values[index]) )
				return true;
			state[index] = 0;
		}
		else {
			//System.out.println("\n" + state[0] + " " + state[1] + " " + state[2] + " -> " + mul);
			for(int i = 0; i < K; i++)
				if ( k[i] > 0 && mul == k[i] ) {
					k[i] = 0;
					ok++;
					//System.out.println("\njooo");
					if ( ok == K ) 
						return true;
				}
		} 

		return false;		
	}


	public static boolean comb(int index) {

		if ( index < N ) {
			for(int i = 0; i < M; i++) {
				values[index] = items[i];
				if ( comb(index + 1) )
					return true;
			}
		}
		else {
			ok = 0;
			k = Arrays.copyOf(kk, kk.length);
			/*
			System.out.println("\n--------------");
			for(int i = 0; i < N; i++) 
				System.out.print(values[i] + " ");
			System.out.println("");
			for(int i = 0; i < K; i++) 
				System.out.print(k[i] + " ");
				*/
			if ( comb1(0, 1) ){
				//System.out.println("ok");
				return true;
			}
		}

		return false;
	}	

	private static String process1(Scanner in) {
		kk = new int[K];
		state = new int[N];
		for(int i = 0; i < K; i++) 
			kk[i] = in.nextInt();
		String res = "";
		comb(0);
		for(int i = 0; i < N; i++)
			res += values[i];
		return res;
	}

	private static String process(Scanner in) {
		int R = in.nextInt();
		N = in.nextInt();
		M = in.nextInt();
		K = in.nextInt();
		String res = "";
		for(int i = 1; i <= R; i++)
			res += "\n" + process1(in);
		return res;
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
		//N = 4; M = 3; comb(0);
	}
}
