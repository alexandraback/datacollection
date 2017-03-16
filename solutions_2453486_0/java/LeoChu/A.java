import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.util.Scanner;


public class A {
	Scanner scanner = new Scanner(System.in);
		
	//row, column
	char[][] square;
	
	void read() {
		square = new char[4][4];
		for(int row = 0; row < 4 ; row++){
			String arow = scanner.next();
//			System.out.println("arow["+row+"]:"+arow);
			for(int column=0; column<4; column++){
				square[row][column] = arow.charAt(column);
//				System.out.print("square["+row+"]["+column+"]:"+square[row][column]);
			}
//			System.out.println();
		}
		return;
	}
	
	Character getWinner(char[][] square){	
		Character winner = null;
		
		winner = getColumnWinner(square);
		if(winner != null){
			return winner;
		}
		
		winner = getRowWinner(square);
		if(winner != null){
			return winner;
		}
		
		winner = getCrossWinner(square);
		if(winner != null){
			return winner;
		}
		
		return null;
	}
	
	Character getColumnWinner(char[][] square){		
		for(int column = 0; column<4; column++){
//			System.out.println("check column:"+column);			
			String plays =  "";
			for(int row=0; row<4; row++){
				plays += square[row][column];
			}
			Character winner = findWinner(plays);
			if (winner!=null){
				return winner;
			}
		}
		return null;
	}
	
	Character findWinner(String plays){
		if(plays.contains(".")){
			return null;
		}
		if(plays.contains("X") && plays.contains("O")){
			return null;
		}
		for(int i=0; i<4; i++){
			char winner = plays.charAt(i);
			if(winner != 'T'){
				return winner;
			}
		}		
		return 'T';		
	}
		
	
	Character getRowWinner(char[][] square){
		for(int row = 0; row<4; row++){
//			System.out.println("check row:"+row);			
			String plays =  "";
			for(int column=0; column<4; column++){
				plays += square[row][column];
			}
			Character winner = findWinner(plays);
			if (winner!=null){
				return winner;
			}
		}
		return null;
	}
	
	Character getCrossWinner(char[][] square){
		String plays ="";
		plays += square[0][0];
		plays += square[1][1];
		plays += square[2][2];
		plays += square[3][3];
		Character winner = findWinner(plays);
		if (winner!=null){
			return winner;
		}
		
		plays ="";
		plays += square[0][3];
		plays += square[1][2];
		plays += square[2][1];
		plays += square[3][0];
		winner = findWinner(plays);
		if (winner!=null){
			return winner;
		}
		return null;
	}
	
	boolean isComplete(char[][] square){
		for(int row = 0; row < 4 ; row++){
			for(int column=0; column<4; column++){
				if (square[row][column] == '.'){
					return false;
				}
			}
		}
		return true;
	}
	
	void solve() {
		Character winner = getWinner(square);
		if(winner != null){
			System.out.print(winner+" won");
			return;
		}
		
		if (!isComplete(square)){
			System.out.print("Game has not completed");
			return;
		}		
		
		System.out.print("Draw");
	}
	
	void run() {
		int caseN = scanner.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read();
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.println();
			//System.out.println("==================================");
			System.out.flush();
		}
	}
	

	public static void main(String[] args) {
		try {
			//System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (A.class.getName() + ".in"))));
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : ("A-small-attempt0.in"))));
		} catch (Exception e) {
			e.printStackTrace();
		}
		new A().run();
	}
}
