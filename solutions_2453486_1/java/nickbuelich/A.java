import java.util.Scanner;


public class A {
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		int T = sc.nextInt();
		for(int t=1;t<=T;t++){
			int[][] board = new int[4][4];
			boolean flag= false;
			for(int a=0;a<4;a++){
				String in = sc.next();
				for(int b=0;b<4;b++){
					if(in.charAt(b)=='X'||in.charAt(b)=='T')board[a][b]+=1;
					if(in.charAt(b)=='O'||in.charAt(b)=='T')board[a][b]+=2;
					if(in.charAt(b)=='.')flag=true;
				}
			}
			int ans = 0;
			ans = Math.max(board[0][0]&board[1][1]&board[2][2]&board[3][3],ans);
			ans = Math.max(board[3][0]&board[2][1]&board[1][2]&board[0][3],ans);
			for(int a=0;a<4;a++){
				ans = Math.max(board[a][0]&board[a][1]&board[a][2]&board[a][3],ans);
				ans = Math.max(board[0][a]&board[1][a]&board[2][a]&board[3][a],ans);
			}
			System.out.printf("Case #%d: ",t);
			if(ans==1)System.out.println("X won");
			else if(ans==2)System.out.println("O won");
			else if(flag)System.out.println("Game has not completed");
			else System.out.println("Draw");
		}
	}

}
