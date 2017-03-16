import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
 



public class  TicTacTOE {
	
	private static char[][] matrix = new char[4][4];
	private static int T;
	
	public static void main(String[] args) {
		
		int i, j, n=4, m=4;
		
		try {
			
			File fileOut = new File("C:/Users/Robi/Desktop/CodeJam/tico.txt");
			File fileIn = new File("C:/Users/Robi/Desktop/CodeJam/tici.txt");
			
			
			BufferedReader br = new BufferedReader(new FileReader(fileIn.getAbsoluteFile()));
			BufferedWriter bw = new BufferedWriter(new FileWriter(fileOut.getAbsoluteFile()));
 
			// if file doesn't exists, then create it
			if (!fileOut.exists()) {
				fileOut.createNewFile();
			}
			
			
			
			T = Integer.parseInt(br.readLine());
			
			for(i = 0; i < T; i++){
				getMatrix(matrix, br, n, m);
				
				switch(checkMatrix(matrix,n,m)){
					case 0: bw.write("Case #"+Integer.toString(i+1)+":"+" Game has not completed");
							bw.newLine();
							break;
					case 1: 
							bw.write("Case #"+Integer.toString(i+1)+":"+" X won");
							bw.newLine();
							break;
					case 2: 
							bw.write("Case #"+Integer.toString(i+1)+":"+" O won");
							bw.newLine();
							break;
					case 3: 
							bw.write("Case #"+Integer.toString(i+1)+":"+" Draw");
							bw.newLine();
							break;
					default: System.out.println("ERROR");
				}
				
			}
			
			
			bw.close();
			br.close();
 
			System.out.println("Done");
 
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private static void getMatrix(char[][] matrix, BufferedReader in, int n, int m) throws IOException{
		int i,j;
		String s;
		
		for(i = 0; i < n; i++){
			s = in.readLine();
			for(j = 0; j < m; j++){
				matrix[i][j] = s.charAt(j);	
			}
		}
		s = in.readLine();
	}
	
	private static void printMatrix(char[][] matrix, int n,int m){
		int i, j;
		
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++)
				System.out.print(matrix[i][j]);
			System.out.println();
		}
	}
	
	private static int checkMatrix(char[][] matrix, int n, int m){
		int xCounter = 0, oCounter = 0, i, j, miss = 0;
		int state = 0; // 0-GNF ; 1-X; 2-O; 3-DRAW
		
		//check main diagonal
		
		for(i=0; i<n; i++){
			if(matrix[i][i] == 'X' || matrix[i][i] == 'T')
				xCounter++;
			if(matrix[i][i] == 'O' || matrix[i][i] == 'T')
				oCounter++;
		}
		if(xCounter == 4) 
			return 1;
		if(oCounter == 4)
			return 2;
		
		//check secondary diagonal
		
		xCounter = 0; oCounter = 0; //reset counter
		for(i=0; i<n; i++){
			if(matrix[i][n-i-1] == 'X' || matrix[i][n-i-1] == 'T')
				xCounter++;
			if(matrix[i][n-i-1] == 'O' || matrix[i][n-i-1] == 'T')
				oCounter++;
		}
		
		if(xCounter == 4) 
			return 1;
		if(oCounter == 4)
				return 2;
		
		
		//check row wise
		for(i = 0; i < n; i++){
			xCounter = 0; oCounter = 0;// reset counter for each row
			
			for(j = 0; j < m; j++){
				if(matrix[i][j] == 'X' || matrix[i][j] == 'T')
					xCounter++;
				if(matrix[i][j] == 'O' || matrix[i][j] == 'T')
					oCounter++;
				if(matrix[i][j] == '.')
					miss++;
			}
			if(xCounter == 4) 
				return 1;
			if(oCounter == 4)
				return 2;
					
		}
		
		//check column wise
		
		for(i = 0; i < m; i++){
			xCounter = 0; oCounter = 0;// reset counter for each column
			
			for(j = 0; j < n; j++){
				if(matrix[j][i] == 'X' || matrix[j][i] == 'T')
					xCounter++;
				if(matrix[j][i] == 'O' || matrix[j][i] == 'T')
					oCounter++;
				if(matrix[j][i] == '.')
					miss++;
			}
			if(xCounter == 4) 
				return 1;
			if(oCounter == 4)
				return 2;
		}
		// check if draw
		if(miss == 0)
			return 3;
					
		
		
		return 0; 
	}
}