import java.util.Scanner;


public class Fractiles {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int x = 1; x <= T; ++x) {
			int K = sc.nextInt();
			int C = sc.nextInt();
			int S = sc.nextInt();
			if (C*S < K)
				System.out.println("Case #" + x + ": IMPOSSIBLE");
			else {
				System.out.print("Case #" + x + ":");
				//map the terms [0,2,...,C-1], [C,C+1,...,2C-1], [2C,2C+1,...,3C-1] ... [...,K-1,0,0...,0]
				for (int i = 0; i < K; i += C) {
					long tile = 0;
					int term = i;
					for (int j = 0; j < C; ++j) {
						int actualterm;
						if (term >= K)
							actualterm = 0;
						else
							actualterm = term;
						tile = tile * K + actualterm;
						++term;
					}
					System.out.print(" " + (tile+1));
				}
				System.out.println();
			}
		}
		sc.close();
	}

}
/*
5
2 3 2
1 1 1
2 1 1
2 1 2
3 2 3
*/