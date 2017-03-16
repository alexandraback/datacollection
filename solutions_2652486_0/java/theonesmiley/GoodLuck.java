import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;

public class GoodLuck {
	public static BufferedReader BR;
	public static final Random random = new Random();
	
	public static String readLine() {
		try {
			return BR.readLine();
		} catch(Exception E) {
			System.err.println(E.toString());
			return null;
		}
	}
	
	
	// ****** MAIN ******
	
	public static void main(String [] args) throws Exception {
		BR = new BufferedReader(new InputStreamReader(System.in));
	
		int testcases = Integer.parseInt(readLine());
		for (int t = 1; t <= testcases; t++) {
			GoodLuck instance = new GoodLuck();
			instance.solve(t);
		}
	}
	
	// ****** GLOBAL VARIABLES ******
	
	
	
	public GoodLuck() {
	}
	
	public int[] generateCards(int N, int M) {
		int[] result = new int[N];
		for (int i = 0; i < N; ++i) result[i] = 2+random.nextInt(M-1);
		Arrays.sort(result);
		return result;
	}
	
	public int[] generateProducts(int[] card, int K) {
		int[] result = new int[K];
		for (int p = 0; p < K; ++p) {
			int product = 1;
			for (int i = 0; i < card.length; ++i) {
				if (random.nextDouble() < 0.5) product *= card[i];
			}
			result[p] = product;
		}
		Arrays.sort(result);
		return result;
	}
	
	public boolean solve(int caseNumber) {
		StringTokenizer st = new StringTokenizer(readLine());
		int R = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		System.out.println("Case #" + caseNumber + ":");
		for (int s = 0; s < R; ++s) {
			int[] product = new int[K];
			st = new StringTokenizer(readLine());
			for (int p = 0; p < K; ++p) {
				product[p] = Integer.parseInt(st.nextToken());
			}
			Arrays.sort(product);
			int[] best = null;
			int bestMatch = 0;
			for (int c = 0; best == null || c < 1000; ++c) {
				int[] card = generateCards(N, M);
				int matchCount = 0;
				for (int d = 0; d < 1000; ++d) {
					int[] trial = generateProducts(card, K);
					if (Arrays.equals(product, trial)) ++matchCount;
				}
				if (matchCount > bestMatch) {
					bestMatch = matchCount;
					best = card;
				}
			}
			for (int i = 0; i < N; ++i) System.out.print(best[i]);
			System.out.println();
		}
		return false;
	}


}
