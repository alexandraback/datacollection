import java.util.Scanner;


public class A {
	static Scanner scan;
	
	
	public static void main(String[] args) {
		scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		//int n = testCases;
		int n=0;
		scan.nextLine();
		char board[][] = new char[4][4];
		
		while(testCases>0){
			testCases--;
			n++;
			
			int status = 1;
			//0 : Game has not completed
			//1 : Draw
			//2 : X won
			//3 : O won
			
			//read input
			for(int i=0; i<4; i++){
				String line = scan.nextLine();
				//System.out.println("line("+i+")"+line);
				for(int j=0; j<4; j++){
					board[i][j] = line.charAt(j);
					if(board[i][j] == '.')
						status = 0;
				}
			}
			scan.nextLine();
			
			//check horizontal

			for(int j=0; j<4; j++){
				boolean check = true;
				for(int i=0; i<4; i++){
					if(!(board[j][i]=='X' || board[j][i]=='T'))
						check = false;
				}
				if(check)
					status = 2;
				
				check = true;
				for(int i=0; i<4; i++){
					if(!(board[j][i]=='O' || board[j][i]=='T'))
						check = false;
				}
				if(check)
					status = 3;
			}
			
			//check vertical
			for(int i=0; i<4; i++){
				boolean check = true;
				for(int j=0; j<4; j++){
					if(!(board[j][i]=='X' || board[j][i]=='T'))
						check = false;
				}
				if(check)
					status = 2;
				
				check = true;
				for(int j=0; j<4; j++){
					if(!(board[j][i]=='O' || board[j][i]=='T'))
						check = false;
				}
				if(check)
					status = 3;		
			}			
			
			//check diagonal
			boolean check = true;
			for(int i=0; i<4; i++){
				if(!(board[i][i]=='X' || board[i][i]=='T'))
					check = false;
			}
			if(check)
				status = 2;
			
			check = true;
			for(int i=0; i<4; i++){
				if(!(board[i][3-i]=='X' || board[i][3-i]=='T'))
					check = false;
			}
			if(check)
				status = 2;
			
			check = true;
			for(int i=0; i<4; i++){
				if(!(board[i][i]=='O' || board[i][i]=='T'))
					check = false;
			}
			if(check)
				status = 3;
			
			check = true;
			for(int i=0; i<4; i++){
				if(!(board[i][3-i]=='O' || board[i][3-i]=='T'))
					check = false;
			}
			if(check)
				status = 3;
			
			System.out.print("Case #"+n+": ");
			
			switch(status){
			case 0:
				System.out.println("Game has not completed");
				break;
			case 1:
				System.out.println("Draw");
				break;
			case 2:
				System.out.println("X won");
				break;
			case 3:
				System.out.println("O won");
				break;
				
			}
			
		}
		
//		System.out.println();
//		for(int a = 0; a<n; a++){
//			System.out.print("Case #"+(a+1)+": ");
//			
//			System.out.println();
//		}
	}

}
