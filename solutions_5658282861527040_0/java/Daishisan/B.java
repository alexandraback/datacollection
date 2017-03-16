package round1b;

import java.util.Scanner;

public class B {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int numTests = in.nextInt();
		for (int test = 1; test <= numTests; ++test) {
			int a = in.nextInt();
			int b = in.nextInt();
			int k = in.nextInt();
			long ans = 0;
			for (int i = 0; i < a; ++i)
				for (int j = 0; j < b; ++j)
					if ((i&j) < k)
						++ans;
			System.out.println("Case #" + test + ": " + ans);
		}
	}

}
