import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Arrays;

class Main
{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static Scanner sc = new Scanner(new InputStreamReader(System.in));

	public static void main (String[] args) throws java.lang.Exception {
		int T = Integer.parseInt(br.readLine());
		for (int i=0; i<T; i++){
			solve(i);
		}
	}

	public static void solve(int num) throws IOException{
		StringTokenizer st = new StringTokenizer(br.readLine());
		int C = Integer.parseInt(st.nextToken()); // count can use coins each
		int D = Integer.parseInt(st.nextToken()); // kind of coins
		int V = Integer.parseInt(st.nextToken()); // max value
		st = new StringTokenizer(br.readLine());
		int[] coins = new int[D];
		for (int i=0; i<D; i++) {
			coins[i] = Integer.parseInt(st.nextToken());
		}

		boolean[] list = new boolean[V+1];
		list[0] = true;
		for (int i=0; i<=V; i++) list[i] = false;
		int pattern = (int)Math.pow(C+1, D);
		for (int i=0; i<pattern; i++) {
			int tmp = i;
			int price = 0;
			for (int k=0; k<D; k++) {
				int coin = tmp % (C+1);
				tmp = (tmp - coin) / (C+1);
				price += coins[k] * coin;
			}

			if (price <= V) list[price] = true;
		}

		int addCoins = 0;
		int[] newCoins = new int[V];
		for (int i=0; i<D; i++) {
			newCoins[i] = coins[i];
		}
		boolean[] maxList = Arrays.copyOf(list, list.length);

		while (true) {
			boolean check = true;
			for (int i=0; i<maxList.length; i++) {
				check = check && maxList[i];
			}
			if (check) break;
			int maxNum = 0;
			int maxRewrite = 0;
			boolean[] tmpMaxList = Arrays.copyOf(list, list.length);
			for (int i=1; i<=V; i++) {
				int rewriteCount = 0;

				boolean coinsCheck = true;
				for (int x=0; x<=coins.length+addCoins-1; x++) {
					if(newCoins[x] == i) coinsCheck = false;
				}
				if (coinsCheck == false) continue;

				boolean[] tmpList = Arrays.copyOf(maxList, maxList.length);
				for (int k=0; k<=V; k++) {
					if (i+k <= V) {
						if (tmpList[i+k] == false) rewriteCount++;
						tmpList[i+k] = true;
					}
				}

				if (maxRewrite < rewriteCount) {
					maxNum = i;
					maxRewrite = rewriteCount;
					tmpMaxList = Arrays.copyOf(tmpList, tmpList.length);
				}
			}

			newCoins[coins.length+addCoins] = maxNum;
			addCoins++;
			maxList = Arrays.copyOf(tmpMaxList, tmpMaxList.length);
		}

		System.out.println("Case #" + (num+1) + ": " + addCoins);
	}

}

