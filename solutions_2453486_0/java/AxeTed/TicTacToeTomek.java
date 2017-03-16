package com.cbs.trials.cj13;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;

public class TicTacToeTomek {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//System.out.println("Test");
		
		//input
		String[] in=null;
		try{
			BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\Admin\\Downloads\\A-small-attempt1.in"));
			String line=null;
			ArrayList<String> ins 	= new ArrayList<>(); 
			while((line=br.readLine())!=null){
				ins.add(line);
			}
			in=ins.toArray(new String[]{});
		}catch(Exception e){
			System.out.println("Error finding/reading file.");
		}

		int numcases = Integer.parseInt(in[0]);
		
		
		//Const
		String[] resultstr=new String[]{"X won","O won","Draw","Game has not completed"};
		
		//Output
		String[] out = new String[numcases];
		char[][] board = new char[4][4];
		for(int i=0;i<numcases;i++){
			board[0]=in[i*5+1].toCharArray();
			board[1]=in[i*5+2].toCharArray();
			board[2]=in[i*5+3].toCharArray();
			board[3]=in[i*5+4].toCharArray();
			
			int outcase = checkBoard(board);
			System.out.println(String.format("Case #%d: %s", i+1, resultstr[outcase]));
		}
		
		
		
	}
	
	private static int checkBoard(char[][] board){

		int res=-1;
		if((res=checkRow(board,0)) >0 ||(res=checkRow(board,1)) >0 ||(res=checkRow(board,2)) >0 ||(res=checkRow(board,3)) >0 
				||(res=checkCol(board,0)) >0 ||(res=checkCol(board,1)) >0 ||(res=checkCol(board,2)) >0 ||(res=checkCol(board,3)) >0 
				||(res=checkD1(board)) >0 ||(res=checkD2(board)) >0 ){
			return res-1;
		}		
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(board[i][j]=='.')
					return 3;
			}
		}
		
		return 2;
		
	}
	private static int checkRow(char[][] board, int i){
		if(board[i][0]=='.'||board[i][1]=='.'||board[i][2]=='.'||board[i][3]=='.')
			return 0;
		
		char chk=board[i][0];
		if(chk=='T') chk=board[i][1];
		
		int sret=0;
		if(chk=='X') sret=1; else sret=2;
		
		if((board[i][0]=='T'||board[i][0]==chk)
				&&(board[i][1]=='T'||board[i][1]==chk)
				&&(board[i][2]=='T'||board[i][2]==chk)
				&&(board[i][3]=='T'||board[i][3]==chk)){
			return sret;
		}else{
			return 0;
		}
		
	}
	private static int checkCol(char[][] board, int i){
		if(board[0][i]=='.'||board[1][i]=='.'||board[2][i]=='.'||board[3][i]=='.')
			return 0;
		
		char chk=board[0][i];
		if(chk=='T') chk=board[1][i];
		int sret=0;
		if(chk=='X') sret=1; else sret=2;
		
		if((board[0][i]=='T'||board[0][i]==chk)
				&&(board[1][i]=='T'||board[1][i]==chk)
				&&(board[2][i]=='T'||board[2][i]==chk)
				&&(board[3][i]=='T'||board[3][i]==chk)){
			return sret;
		}else{
			return 0;
		}
	}
	private static int checkD1(char[][] board){
		if(board[0][0]=='.'||board[1][1]=='.'||board[2][2]=='.'||board[3][3]=='.')
			return 0;
		
		char chk=board[0][0];
		if(chk=='T') chk=board[1][1];
		int sret=0;
		if(chk=='X') sret=1; else sret=2;
		
		if((board[0][0]=='T'||board[0][0]==chk)
				&&(board[1][1]=='T'||board[1][1]==chk)
				&&(board[2][2]=='T'||board[2][2]==chk)
				&&(board[3][3]=='T'||board[3][3]==chk)){
			return sret;
		}else{
			return 0;
		}
	}
	private static int checkD2(char[][] board){
		if(board[3][0]=='.'||board[2][1]=='.'||board[1][2]=='.'||board[0][3]=='.')
			return 0;
		
		char chk=board[0][3];
		if(chk=='T') chk=board[1][2];
		int sret=0;
		if(chk=='X') sret=1; else sret=2;
		
		if((board[0][3]=='T'||board[0][3]==chk)
				&&(board[1][2]=='T'||board[1][2]==chk)
				&&(board[2][1]=='T'||board[2][1]==chk)
				&&(board[3][0]=='T'||board[3][0]==chk)){
			return sret;
		}else{
			return 0;
		}
	}
}
