package main;

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int T = in.nextInt(); in.nextLine();
		
		for (int i = 1; i <= T; i++) {
			int A = in.nextInt();
			int N = in.nextInt();
			in.nextLine();
			Integer[] ms = new Integer[N];
			for (int j = 0; j < N; j++)
				ms[j] = in.nextInt();
			Arrays.sort(ms);
			System.out.println("Case #" + i + ": " + solve(A, Arrays.asList(ms)));
		}
		
		in.close();
	}

	private static int solve(int a, List<Integer> ms) {		
		if (ms.size() == 0) 
			return 0;
		if (a > ms.get(0))
			return solve(a + ms.get(0), ms.subList(1, ms.size()));
		if (a == 1)
			return ms.size();		
		return Math.min(ms.size(), 1 + solve(a + a - 1, ms));
	}

}
