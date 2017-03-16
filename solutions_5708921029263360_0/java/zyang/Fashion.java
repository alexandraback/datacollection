package fashion;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

import javax.naming.directory.SearchControls;
import javax.xml.bind.ValidationEvent;

import countingSheep.Gen;

public class Fashion {
	
	public static int J, P, S, K;
	public static int N;
	public static int[][] comb;
	public static int max, tmp;
	public static int[][] ans;

	public static void main(String[] args) throws FileNotFoundException {

		File input = new File("input.txt");
		Scanner scanner = new Scanner(input);
		
		int T = scanner.nextInt();
		for (int i = 0; i < T; i++) {
			
			J = scanner.nextInt();
			P = scanner.nextInt();
			S = scanner.nextInt();
			K = scanner.nextInt();
			
			Gen();

			System.out.printf("Case #%d: ", i + 1);
			calc();
		}
		
		scanner.close();
	}

	private static void Gen() {
		
		N = J * P * S;
		comb = new int[N][3];
		ans = new int[N][3];
		int count = 0;
		for (int i = 1; i <= J; i++)
			for (int j = 1; j <= P; j++)
				for (int k = 1; k <= S; k++) {
					
					comb[count][0] = i;
					comb[count][1] = j;
					comb[count][2] = k;
					count++;
				}
	}
	

	private static int calc() {
		
		max = 0;
		tmp = N;
		
		search(0);
		
		return max;
	}

	private static void search(int i) {
		
		if (tmp <= max)
			return;
		
		if (i == N) {
			
			if (valid()) {
				
				max = tmp;
				System.out.println(max);
				for (int j = 0; j < N; j++)
					if (comb[j][0] != 0)
					System.out.printf("%d %d %d\n", comb[j][0], comb[j][1], comb[j][2]);
			}
		}
		else {
			
			if (exceed(i)) {
				
				int[] backup = comb[i].clone();
				comb[i][0] = 0;
				comb[i][1] = 0;
				comb[i][2] = 0;
				
				tmp--;
				
				search(i + 1);
				
				tmp++;
				comb[i] = backup;
			}
			
			search(i + 1);
		}
		
	}
	
	public static boolean valid() {
		
		for (int i = 0; i < N; i++)
			if (comb[i][0] != 0) {
			
				if (exceed(i))
					return false;
			}
		
		return true;
	}
	
	public static boolean exceed(int x) {
		
		int[] count = new int[3];
		for (int j = 0; j < N; j++) {
			
			if (comb[x][0] == comb[j][0] && comb[x][1] == comb[j][1])
				count[0]++;
			if (comb[x][0] == comb[j][0] && comb[x][2] == comb[j][2])
				count[1]++;
			if (comb[x][1] == comb[j][1] && comb[x][2] == comb[j][2])
				count[2]++;
		}
		
		if (count[0] > K || count[1] > K || count[2] > K)
			return true;

		return false;
	}
}
