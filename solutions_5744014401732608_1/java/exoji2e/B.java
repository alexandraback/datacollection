import java.util.Scanner;
public class B {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int i = 1; i<=T; i++) {
			int B = sc.nextInt();
			String s = sc.next();
			long M = Long.parseLong(s);
			long p2 = p(B-1);
			if(p2<M) {
				System.out.println("Case #" + i + ": IMPOSSIBLE");
				continue;
			}
			System.out.println("Case #" + i + ": POSSIBLE");
			boolean[][] board = new boolean[B][B];
			for(int r = 0; r<B; r++) {
				for(int c = r+1; c<B; c++) {
					board[r][c] = true;
				}
			}
			long diff = p2-M;
			int d = 1;
			while(diff>0) {
				if(diff%2 == 1) {
					board[d][B-1] = false;
				}
				diff /=2;
				d++;
			}
			StringBuilder sb = new StringBuilder();
			for(int r = 0; r<B; r++) {
				for(int c = 0; c<B; c++) {
					if(board[r][c]) 
						sb.append('1');
					else
						sb.append('0');	
				}
				sb.append('\n');
			}
			System.out.print(sb);
			
			
		}
	}
	public static long p(int B) {
		long prod = 1;
		for(int i = 2; i<=B; i++) {
			prod*=2;
		}
		return prod;
	}
}