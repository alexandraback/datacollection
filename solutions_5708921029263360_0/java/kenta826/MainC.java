package gcj.y2016.R1C;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MainC {

	static final int INF = 10000000;
	static final int[] flg = {1,2,4,8,16,32,64,128,256,512};
	static final int[] A = {
			1111,
			1221,
			1331,
			2121,
			2211,
			2311,
			3131,
			3231,
			3321,
			1122,
			1232,
			1312,
			2132,
			2212,
			2322,
			3112,
			3222,
			3332,
			1133,
			1213,
			1323,
			2113,
			2223,
			2333,
			3123,
			3233,
			3313,
};

	public static void main(String[] args) throws FileNotFoundException {
		// 問題の読み込み
		Scanner sc = new Scanner(new File("src/A-small-practice.in"));
		//		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int t=1; t<T+1; t++) {
			int J = sc.nextInt();
			int P = sc.nextInt();
			int S = sc.nextInt();
			int K = sc.nextInt();

			solve(t,J,P,S,K);
		}
		sc.close();

	}

	static void solve(int t, int J, int P, int S, int K) {
		System.out.print("Case #" + t + ": ");

		List<String> ans = new ArrayList<String>();

		int end = 0;


		for (int i=0; i<27; i++) {
			int a = A[i];
			int j = a/1000;
			int p = a/100%10;
			int s = a/10%10;
			int k = a%10;

			if (j>J || p>P || s>S) {
				continue;
			}
			if (k>K) {
				break;
			}

			ans.add(j+" "+p+" "+ s);
		}

		System.out.println(ans.size());
		for (int j=0; j<ans.size(); j++) {
			System.out.println(ans.get(j));
		}

	}

}