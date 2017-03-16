import java.util.*;
public class B {
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		for (int ii = 1; ii<=T; ++ii) {
			int N = sc.nextInt();
			int M = sc.nextInt();
			int [] MAX_C = new int [M];
			int [] MAX_R = new int [N];
			int [][] val = new int [N][M];
			for (int i = 0; i<N; ++i) {
				for (int j = 0; j<M; ++j) {
					val[i][j] = sc.nextInt();
					if (val[i][j] >= MAX_C[j]) MAX_C[j] = val[i][j];
					if (val[i][j] >= MAX_R[i]) MAX_R[i] = val[i][j];
				}
			}
			boolean possible = true;
			for (int i = 0; i<N; ++i) {
				for (int j = 0; j<M; ++j) {
					if (val[i][j] < MAX_R[i] && MAX_C[j] != val[i][j]) possible = false;
					if (val[i][j] < MAX_C[j] && MAX_R[i] != val[i][j]) possible = false;
				}
			}
			String ans = (possible) ? "YES" : "NO";
				
			
			//Something
			System.out.printf("Case #%d: %s\n",ii,ans);
		}
	}
	public static char verdict(char ... stuff) {
		char [] tmp = new char [256];
		for (char c : stuff) tmp[c]++;
		if (tmp['X'] == 3 && tmp['T'] == 1) return 'X';
		if (tmp['X'] == 4) return 'X';
		if (tmp['O'] == 3 && tmp['T'] == 1) return 'O';
		if (tmp['O'] == 4) return 'O';
		return (char)0;
	}
}