package round1b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Random;

public class Lottery {
	private BufferedReader cin;
	Random rnd = new Random();
	
	public Lottery() {
		cin = new BufferedReader(new InputStreamReader(System.in));
	}
	
	public void solve() throws Exception {
		int t = Integer.parseInt(cin.readLine());
		for (int i = 1; i <= t; ++i) {
			System.out.printf("Case #%d: %d\n", i, solveCase());
		}
	}
	
	private int solveCase() throws Exception {
		String[] strs = cin.readLine().split(" ");
		int a = Integer.parseInt(strs[0]);
		int b = Integer.parseInt(strs[1]);
		int k = Integer.parseInt(strs[2]);
		int count = 0;
		for (int i = 0; i < a; ++i) {
			for (int j = 0; j < b; ++j) {
				if ((i & j) < k) {
					++count;
				}
			}
		}
		return count;
	}

	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		new Lottery().solve();
	}

}
