package gcj2012R1C;

import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) {
		new A().run(new Scanner(System.in));
	}

	void run(Scanner sc) {
		int n = sc.nextInt();
		for(int i = 1; n-- > 0; i++)
			solve(sc, i);
	}

	void WarshallFloyd(int[][] matrix) {
		int n = matrix.length;
		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					if(matrix[i][j] > matrix[i][k] + matrix[k][j])
						matrix[i][j] = matrix[i][k] + matrix[k][j];
	}
	
	void solve(Scanner sc, int case_num) {
		int n = sc.nextInt();
		int[][] matrix = new int[n][n];
		int BIG = 1 << 28;
		for(int i = 0; i < n; i++) {
			Arrays.fill(matrix[i], BIG);
		}
		ArrayList<ArrayList<Integer>> in = new ArrayList<ArrayList<Integer>>();
		for(int i = 0; i < n; i++) {
			int m = sc.nextInt();
			in.add(new ArrayList<Integer>());
			for(int j = 0; j < m; j++) {
				int M = sc.nextInt() - 1;
				matrix[i][M] = 1;
				in.get(i).add(M);
			}
		}
		WarshallFloyd(matrix);
		boolean res = false;
		a:for(int i = 0; i < n; i++) {
			if(in.get(i).size() >= 2) {
				ArrayList<Integer> list = in.get(i);
				for(int j = 0; j < list.size(); j++) {
					int J = list.get(j);
					for(int k = j + 1; k < list.size(); k++) {
						int K = list.get(k);
						if(matrix[J][K] < BIG || matrix[K][J] < BIG) {
							res = true; break a;
						}
						for(int l = 0; l < n; l++) if(l != J && l != K && l != i) {
							if(matrix[J][l] < BIG && matrix[K][l] < BIG) {
//								System.out.println(J+" "+K+" "+l);
								res = true; break a;
							}
						}
					}
				}
			}
		}
		
		System.out.printf("Case #%d: %s\n", case_num, res ? "Yes" : "No");
	}
}
