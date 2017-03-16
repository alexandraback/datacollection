import java.io.*;
import java.util.Arrays;
import java.util.Scanner;


public class IHOP {
	public IHOP() {
		Scanner in = new Scanner(System.in);
		int tests = in.nextInt();
		for(int t = 1; t<=tests; t++){
			int n = in.nextInt();
			int[] val = new int[1001];
			for(int i = 0; i<n; i++)
				val[i] = in.nextInt();
			int ans = 1000;
			for(int i = 1; i<1000; i++){
				int mods = 0;
				for(int j = 0; j<n; j++)
					mods += (val[j]-1)/i;
				ans = Math.min(ans, mods+i);
			}
			System.out.printf("Case #%d: %d\n", t, ans);
		}
	}
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream(new File("B-small-attempt1.in")));
		System.setOut(new PrintStream(new File("B-small-attempt1.out")));
		new IHOP();
	}
}
