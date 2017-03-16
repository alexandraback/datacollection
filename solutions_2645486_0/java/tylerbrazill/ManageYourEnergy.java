import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;


public class ManageYourEnergy {
	public ManageYourEnergy() {
		Scanner in = new Scanner(System.in);
		int tests  =in.nextInt();
		for(int te = 1; te<=tests; te++){
			E = in.nextInt();
			R = in.nextInt();
			int n = in.nextInt();
			v = new long[n];
			for(int i = 0; i<n; i++)
				v[i] = in.nextLong();
			memo = new long[n][E+1];
			for(long[] a: memo)
				Arrays.fill(a, -1);
			System.out.println("Case #"+te+": "+go(0, E));
		}
	}
	long[][] memo;
	long[] v;
	int E, R;
	long go(int i, int e){
		if(i == v.length) return 0;
		if(memo[i][e] != -1) return memo[i][e];
		long ans = go(i+1, Math.min(e+R, E));
		if(e > 0) ans = Math.max(ans, go(i, e-1)+v[i]);
		return memo[i][e] = ans;
	}
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream(new File("manage.in")));
		System.setOut(new PrintStream(new File("manage.out")));
		new ManageYourEnergy();
	}

}
