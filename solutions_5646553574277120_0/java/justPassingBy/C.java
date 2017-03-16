import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class C {

	public static void main(String args[]) throws FileNotFoundException,
			UnsupportedEncodingException {
		C main = new C();
		main.answer();
	}

	public void answer() throws FileNotFoundException,
			UnsupportedEncodingException {
		Scanner scan = new Scanner(new File("C-small-attempt3.in"));
		//Scanner scan = new Scanner(System.in);
		int T = Integer.parseInt(scan.nextLine());
		PrintWriter writer = new PrintWriter("Csmall.out", "UTF-8");
		for (int cas = 1; cas <= T; cas++) {
			String[] s = scan.nextLine().split(" ");
			int C = Integer.parseInt(s[0]);
			int D = Integer.parseInt(s[1]);
			long V = Long.parseLong(s[2]);
			System.out.println(C+" "+D+" "+V);
			String[] denoms = scan.nextLine().split(" ");
			long[] coins = new long[D];
			for (int i = 0; i < D; i++) {
				coins[i] = Integer.parseInt(denoms[i]);
				System.out.print(coins[i]+" ");
			}
			System.out.println();
			long answer = 0;
			if (coins[0] != 1) {
				answer = 1;
				long[] sub = new long[D + 1];
				for (int i = 0; i < D; i++) {
					sub[i] = coins[i];
				}
				sub[D] = 1;
				coins = new long[D + 1];
				for (int i = 0; i < D + 1; i++) {
					coins[i] = sub[i];
				}
				Arrays.sort(coins);
			}
			long h = 0;
			for (int i = 0; h<V ; i++) {
				long sum = 0;
				for (int j = 0; j < i; j++) {
					sum += coins[j] * C;
				}
				h= sum + coins[i] * C;
				if ((i==coins.length-1 || sum + coins[i] * C < coins[i + 1] - 1)
						&& sum + coins[i] * C < V) {
					int l = coins.length;
					long[] sub = new long[l + 1];
					for (int j = 0; j < l; j++) {
						sub[j] = coins[j];
					}
					sub[l] = sum + coins[i] * C + 1;
					coins = new long[l + 1];
					for (int j = 0; j < l + 1; j++) {
						coins[j] = sub[j];
					}
					Arrays.sort(coins);
					answer++;
					//System.out.println(sub[l] + " is unattainable");
				}
			}
			
			writer.println("Case #" + cas + ": " + answer);
			System.out.println("Case #" + cas + ": " + answer);
		}
		writer.close();
	}
}
