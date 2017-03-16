

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.LineNumberReader;
import java.io.PrintStream;

/***/
public class TicTacToeTomek {

	/**
	 */
	public static void main(String[] args) {

		try {

			LineNumberReader reader=new LineNumberReader(new FileReader(new File(args[0]))); // InputFile
			PrintStream printer=new PrintStream(new File(args[1])); // OutputFile
			
			Integer nTestCases=Integer.valueOf(reader.readLine().trim());
			for(int i=0;i!=nTestCases;i++){
				char[][] board=new char[4][4];
				for(int r=0;r!=4;r++)
					board[r]=reader.readLine().trim().toCharArray();
					
				int cPoints=0;
				int[][] cGroups=new int[10][4];
						
				for(int r=0;r!=4;r++){
					for(int c=0;c!=4;c++){
						if(board[r][c]=='.'){
							
							cPoints++;
							cGroups[r][0]++; 
							cGroups[c+4][0]++; 
							if(r==c)
								cGroups[8][0]++;
							if((r+c)==3)
								cGroups[9][0]++;
							
						}else if(board[r][c]=='T'){
							
							cGroups[r][1]++;
							cGroups[c+4][1]++;							
							if(r==c)
								cGroups[8][1]++;
							if((r+c)==3)
								cGroups[9][1]++;
							
						}else if(board[r][c]=='X'){
							
							cGroups[r][2]++;
							cGroups[c+4][2]++;							
							if(r==c)
								cGroups[8][2]++;
							if((r+c)==3)
								cGroups[9][2]++;
							
						}else if(board[r][c]=='O'){
							
							cGroups[r][3]++;
							cGroups[c+4][3]++;							
							if(r==c)
								cGroups[8][3]++;
							if((r+c)==3)
								cGroups[9][3]++;
							
						}							
					}
				}
				
				//
				String strWinner=null;
				for(int g=0;g!=cGroups.length;g++){
					if((cGroups[g][1]+cGroups[g][2])==4)
						strWinner="X won";
					else if((cGroups[g][1]+cGroups[g][3])==4)
						strWinner="O won";
				}
				if(strWinner==null)
					strWinner=(cPoints==0)?"Draw":"Game has not completed";
				
				System.out.println("Case #"+(i+1)+": "+strWinner);			
				printer.println("Case #"+(i+1)+": "+strWinner);
				reader.readLine();
			}
			
			reader.close();
			printer.close();			
		} catch (FileNotFoundException e) {
			
			e.printStackTrace();
		} catch (IOException e) {
			
			e.printStackTrace();
		} 
		
	}
	
}
