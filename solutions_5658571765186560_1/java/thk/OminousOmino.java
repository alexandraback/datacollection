import java.util.*;
public class OminousOmino {
	
	private static String player1 = "RICHARD";
	private static String player2 = "GABRIEL";
	private static int maxOminoesWithoutHole = 6;
	public static void main(String args[]){

		try{
			
			//Read inputs
			Scanner s = new Scanner(System.in);
			int T = s.nextInt();//no of test cases
			int testCaseNum = 0;
			int[][] testCases = new int[T][3];
			while(testCaseNum < T){
				testCases[testCaseNum][0] = s.nextInt();//X - ominoes
				testCases[testCaseNum][1] = s.nextInt();//R in RXC grid
				testCases[testCaseNum][2] = s.nextInt();//C in RXC grid
				testCaseNum++;
			}
			testCaseNum = 0;
			while(testCaseNum < T){
				
				System.out.println("Case #"+(testCaseNum+1)+": "+computeWinner(testCases[testCaseNum][0],testCases[testCaseNum][1],testCases[testCaseNum][2]));
				testCaseNum++;
			}
			
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	private static String computeWinner(int X,int R,int C){
	
		if(R < C){
			//swap
			int temp;
			temp = R;
			R = C;
			C = temp;
		}
		
		//if X greater than maxOminoesWithoutHole always one possibility exists where hole can be created
		if(X > maxOminoesWithoutHole){
			return player1;//player 1 wins
		}else if(X > R && X > C){
			return player1;//player 1 wins
		}else if(X == 1){
			return player2;//player 2 wins
		}else if((R * C) % X != 0){
			return player1;//player 1 wins
		}else if((X + 1) / 2 > C){
			return player1;//player 1 wins
		}else if( X == 2 || X == 3 ){
			return player2;//player 2 wins
		}else if( X == 4 ){
			return C > 2 ? player2 : player1;//
		}else if( X == 5 ){
			return !(C==3 && R ==5)? player2 : player1;//
		}else if( X == 6 ){
			return C > 3 ? player2 : player1;//
		}else{
			return player2;
		}
		
	}

	
}
