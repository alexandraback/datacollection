import java.util.*;
public class A {
	Scanner sc = new Scanner(System.in);
	char board[][] = new char[4][4];
	boolean win(char c)
	{
		for(int h = 0; h < 4; h++) {
			int t = 0, my = 0;
			for(int w = 0; w < 4; w++) {
				if(board[h][w] == c) my++;
				else if(board[h][w] == 'T') t++;
			}
			if(my == 4 || (my == 3 && t == 1)) return true;
		}

		for(int w = 0; w < 4; w++) {
			int t = 0, my = 0;
			for(int h = 0; h < 4; h++) {
				if(board[h][w] == c) my++;
				else if(board[h][w] == 'T') t++;
			}
			if(my == 4 || (my == 3 && t == 1)) return true;
		}
		{
			int t = 0, my = 0;
			for(int h = 0; h < 4; h++) {
				int w = h;
				if(board[h][w] == c) my++;
				else if(board[h][w] == 'T') t++;
			}
			if(my == 4 || (my == 3 && t == 1)) return true;
			
		}
		{
			int t = 0, my = 0;
			for(int h = 0; h < 4; h++) {
				int w = 4 - 1 - h;
				if(board[h][w] == c) my++;
				else if(board[h][w] == 'T') t++;
			}
			if(my == 4 || (my == 3 && t == 1)) return true;
			
		}
		return false;
	}
	int solve()
	{
		boolean completed = true;
		for(int h = 0; h < 4; h++) {
			String line = sc.next();
			board[h] = line.toCharArray();
			for(int w = 0; w < 4; w++) {
				if(board[h][w] == '.') completed = false;
				//System.out.print(board[h][w]);
			}
			//System.out.println();
		}
		if(win('X')) return 0;
		if(win('O')) return 1;
		if(completed) return 2; // Draw
		else return 3; // not completed
	}
	void doIt()
	{
		int T = sc.nextInt();
		for(int t = 1; t <= T; t++) {
			int state = solve();
			System.out.print("Case #" + t + ": ");
			switch (state) {
			case 0: System.out.println("X won"); break;
			case 1: System.out.println("O won"); break;
			case 2: System.out.println("Draw"); break;
			case 3: System.out.println("Game has not completed"); break;
			}
		}
	}
	public static void main(String[] args) {
		new A().doIt();

	}

}
