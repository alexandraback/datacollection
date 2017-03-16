import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class DoIt {
	final private static String inputFileName = "C:\\Users\\kitinon\\Downloads\\C-small-attempt0.in";
//	final private static String inputFileName = "C:\\Users\\kitinon\\Downloads\\A-large.in";
//	final private static String inputFileName = "C:\\Users\\kitinon\\Desktop\\Csample.in";

//	final private static String outFileName = "C:\\Users\\kitinon\\Desktop\\A-Large.out";

	static Scanner in;
	static PrintStream out; 

	public static void main(String[] args) throws FileNotFoundException {
		in = new Scanner(new File(inputFileName));
//		out = new PrintStream(new File(outFileName));
		out = System.out; 
		int T = in.nextInt();		// the number of test cases
		
		for (int t=1; t<=T; t++) {
			int[] wall = new int[2000001];
			int TRIBES = in.nextInt();
			int[] attackday = new int[TRIBES];
			int[] attacks =  new int[TRIBES];
			int[] west =  new int[TRIBES];
			int[] east =  new int[TRIBES];
			int[] strength =  new int[TRIBES];
			int[] dd =  new int[TRIBES];
			int[] dp =  new int[TRIBES];
			int[] ds =  new int[TRIBES];
			int nsuccess = 0;
			for (int tr=0; tr<TRIBES; tr++) {
				attackday[tr] = in.nextInt();
				attacks[tr] = in.nextInt();
				west[tr] = in.nextInt();
				east[tr] = in.nextInt();
				strength[tr] = in.nextInt();
				dd[tr] = in.nextInt();
				dp[tr] = in.nextInt();
				ds[tr] = in.nextInt();
			}
			int nextattack = Integer.MAX_VALUE;
			int day = 0;
			boolean moreattack = false;
			do {
				moreattack = false;
				int[] dwall = new int[2000001];
				for (int tr=0; tr<TRIBES; tr++) {
					if (attacks[tr] > 0) moreattack = true;
					if (attackday[tr] == day) {
						boolean success = false;
						for (int i=west[tr]; i<east[tr]; i++) {
							if (wall[i+1000000] < strength[tr]) {
								success = true;
								if (dwall[i+1000000] < strength[tr]) dwall[i+1000000] = strength[tr];
							}
						}
						if (success) nsuccess += 1;
						if (--attacks[tr]>0) {
							attackday[tr] += dd[tr];
							west[tr] += dp[tr];
							east[tr] += dp[tr];
							strength[tr] += ds[tr];
						} else
							attackday[tr] = Integer.MAX_VALUE;
					}
					if (tr==0) nextattack = attackday[0];
					else if (nextattack > attackday[tr]) nextattack = attackday[tr];
				}
				for (int i=0; i<2000001; i++) {
					if (dwall[i] > 0) wall[i] = dwall[i];
				}
				day = nextattack;
			} while (moreattack == true);
			out.printf("Case #%d: %d\n", t, nsuccess);
		}
	}
}
