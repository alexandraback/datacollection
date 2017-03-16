import java.util.Scanner;

public class TTTGame {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int testCase = scan.nextInt();
		
		for (int t = 1; t <= testCase; ++t) {
			scan.nextLine();
			String[] ttt = new String[4];
			for (int i = 0; i < 4; ++i) {
				ttt[i] = scan.nextLine();
			}
			boolean unFinish = false;
			for(int i=0; i<4; ++i) {
				for(int j=0; j<4; ++j) {
					if(ttt[i].charAt(j) == '.') {
						unFinish = true;
					}
				}
			}
			
			int winner = 0; // 0-draw, 1-X, 2-O
			for (int i = 0; i < 4; ++i) {
				boolean flag = true;
				// 2 cases for X to win
				for (int j = 0; j < 4; ++j) {
					if (ttt[i].charAt(j) == 'X' || ttt[i].charAt(j) == 'T')
						continue;
					flag = false;
					break;
				}
				if (flag) {
					winner = 1;
					break;
				}
				
				flag = true;
				for(int j=0; j<4; ++j) {
					if(ttt[j].charAt(i) == 'X' || ttt[j].charAt(i) == 'T')
						continue;
					flag = false;
					break;
				}
				if(flag) {
					winner = 1;
					break;
				}
				
				// 2 cases for O to win
				flag = true;
				for (int j = 0; j < 4; ++j) {
					if (ttt[i].charAt(j) == 'O' || ttt[i].charAt(j) == 'T')
						continue;
					flag = false;
					break;
				}
				if (flag) {
					winner = 2;
					break;
				}
				
				flag = true;
				for(int j=0; j<4; ++j) {
					if(ttt[j].charAt(i) == 'O' || ttt[j].charAt(i) == 'T')
						continue;
					flag = false;
					break;
				}
				if(flag) {
					winner = 2;
					break;
				}
				
				
			}
			
			// diagonals
			boolean flag = true;
			for(int i=0; i<4; ++i) {
				if(ttt[i].charAt(i) == 'X' || ttt[i].charAt(i) == 'T') continue;
				flag = false;
				break;
			}
			if(flag) {
				winner = 1;
			}
			
			flag = true;
			for(int i=0; i<4; ++i) {
				if(ttt[i].charAt(3-i) == 'X' || ttt[i].charAt(3-i) == 'T') continue;
				flag = false;
				break;
			}
			if(flag) {
				winner = 1;
			}
			
			flag = true;
			for(int i=0; i<4; ++i) {
				if(ttt[i].charAt(i) == 'O' || ttt[i].charAt(i) == 'T') continue;
				flag = false;
				break;
			}
			if(flag) {
				winner = 2;
			}
			
			flag = true;
			for(int i=0; i<4; ++i) {
				if(ttt[i].charAt(3-i) == 'O' || ttt[i].charAt(3-i) == 'T') continue;
				flag = false;
				break;
			}
			if(flag) {
				winner = 2;
			}

			
			
			System.out.print("Case #" + t + ": ");
			if(winner == 0) {
				if(unFinish) {
					System.out.println("Game has not completed");
				}
				else {
					System.out.println("Draw");
				}
			}
			
			else if(winner == 1) {
				System.out.println("X won");
			}
			
			else if(winner == 2) {
				System.out.println("O won");
			}
			
		}
	}

}
