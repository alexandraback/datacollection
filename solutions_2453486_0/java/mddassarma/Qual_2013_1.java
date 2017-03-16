import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class Qual_2013_1 {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException{
		BufferedReader buf=new BufferedReader(new FileReader("problem1_i.txt"));
		PrintWriter printer=new PrintWriter("problem1.txt");
		int[][] board=new int[4][4];
		int[][] board2=new int[4][4];
		int ss=Integer.parseInt(buf.readLine());
		for(int i=1;i<ss+1;i++){
			printer.print("Case #"+i+": ");
			int p=0;
			for(int j=0;j<4;j++){
				String s=buf.readLine();
				for(int k=0;k<4;k++)
					if(s.charAt(k)=='X'){
						board[j][k]=1;
						board2[j][k]=1;
					}	else if(s.charAt(k)=='O'){
						board[j][k]=2;
						board2[j][k]=2;
					}else if(s.charAt(k)=='T'){
						board[j][k]=1;
						board2[j][k]=2;
					}else{ p++;
					board[j][k]=0;
					board2[j][k]=0;
					}
			}
			int winner=0;
			boolean[] a1=new boolean[4];
			boolean[] a2=new boolean[4];
			boolean[] a3=new boolean[4];
			boolean[] a4=new boolean[4];
			for(int j=0;j<4;j++)
				for(int k=0;k<4;k++){
					if(board[j][k]!=1){
						a1[j]=true;
						a2[k]=true;
					}
					if(board2[j][k]!=2){
						a3[j]=true;
						a4[k]=true;
					}
				}
			if(board[0][0]==1&&board[1][1]==1&&board[2][2]==1&&board[3][3]==1)
				winner=1;
			if(board[3][0]==1&&board[2][1]==1&&board[1][2]==1&&board[0][3]==1)
				winner=1;
			if(board2[0][0]==2&&board2[1][1]==2&&board2[2][2]==2&&board2[3][3]==2)
				winner=2;
			if(board2[3][0]==2&&board2[2][1]==2&&board2[1][2]==2&&board2[0][3]==2)
				winner=2;
			for(int j=0;j<4;j++){
				if(!a1[j])
					winner=1;
				if(!a2[j])
					winner=1;
				if(!a3[j])
					winner=2;
				if(!a4[j])
					winner=2;
			}
			if(winner==1)
				printer.println("X won");
			else if(winner==2)
				printer.println("O won");
			else if(p!=0)
				printer.println("Game has not completed");
			else
				printer.println("Draw");
			buf.readLine();
		}
		
		
		
		printer.close();
	}
	public static String won(int i){
		if(i==1)
			return "X";
		else
			return "O";
	}
}
