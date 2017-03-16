package qualification;

import java.util.Scanner;

public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		
		for(int t=1;t<=T;t++){
			char[][] field = new char[4][4];
			s.nextLine();
			for(int i=0;i<4;i++){
				field[i] = s.nextLine().toCharArray();
			}
			
			if(checkWon(field,'X')){
				System.out.println("Case #" + t + ": X won");
			}else if(checkWon(field,'O')){
				System.out.println("Case #" + t + ": O won");
			}else if(checkEmpty(field)){
				System.out.println("Case #" + t + ": Game has not completed");
			}else{
				System.out.println("Case #" + t + ": Draw");
			}
					
		}
	}
	public static boolean checkEmpty(char[][] f){
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(f[i][j]=='.') return true;
				
			}
		}
		return false;

	}
	
	public static boolean checkWon(char[][] f, char p){
		boolean won = false;
		for(int i=0;i<4;i++){
			won = true;
			for(int j=0;j<4;j++){
				if(f[i][j]!=p && f[i][j]!='T') won = false;
				
			}
			if(won) return true;
			won = true;
			for(int j=0;j<4;j++){
				if(f[j][i]!=p && f[j][i]!='T') won = false;
				
			}
			if(won) return true;
		}
		won = true;
		for(int i=0;i<4;i++){
			if(f[i][i]!=p && f[i][i]!='T' ) won = false;
		}
		if(won) return true;
		won=true;
		for(int i=0;i<4;i++){
			if(f[i][3-i]!=p && f[i][3-i]!='T' ) won = false;
		}
		if(won) return true;
		return false;
	}
	

}
