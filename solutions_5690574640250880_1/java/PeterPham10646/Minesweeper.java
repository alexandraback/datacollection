package Task3;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
 
public class Minesweeper {
	
	public static String explainResult(int result, int matchCard){
		if(result == 0){
			return "Volunteer cheated!";
		}else if (result == 1){
			return "" + matchCard ;
		}else if(result > 1){
			return "Bad magician!";
		}
		
		return "Something is Wrong";
	}
 
	public static void main(String[] args) {
		
		String dir = "/Users/tnpha6/Documents/workspace/CodeJam Preparation/files/Minesweeper/";
		
		int numTestCase;
		int row, column, mines;
		int size, noneMines;
		int noneMineR, noneMineC;
		int addition;
		boolean possible, swap, useSwap;
		char[][] gridConfig;
		
		String result = "";
		String[] splited = null;
		BufferedReader br = null;
		PrintWriter writer = null;
		try {
 
			String sCurrentLine;
 
			br = new BufferedReader(new FileReader(dir + "C-large.in"));
			writer = new PrintWriter(dir + "output", "UTF-8");
			
			// Getting the number of test case
			numTestCase = Integer.parseInt(br.readLine());
			
			// Loop through every test cases
			for(int i = 0; i < numTestCase; i++){
				
				// read C F X
				splited = br.readLine().split(" ");
				row = Integer.parseInt(splited[0]);
				column = Integer.parseInt(splited[1]);
				mines = Integer.parseInt(splited[2]);
				
				gridConfig = new char[row][column];
				size = row * column;
				noneMines = size - mines;
				possible = false;
				swap = false;
				useSwap = true;
				int minesleft = 0;
				noneMineR = 0;
				noneMineC = 0;
				
				
				if (row >= 2 && column >= 2){
					minesleft = 0;
					
					//1: need at least 4 space to construct one click config
					if(noneMines >= 4){
						
						// find the best rectangle
						noneMineR = (int)(Math.sqrt(noneMines));
						noneMineC = noneMineR;
						
						minesleft = noneMines - noneMineR*noneMineC;
						
						//check against grid size
						noneMineR = (noneMineR > row)?row:noneMineR;
						noneMineC = (noneMineC > column)?column:noneMineC;
						
						minesleft = noneMines - noneMineR*noneMineC;
						
						//updateNoneMine row or Column
						if( minesleft > 0){
							if(noneMineR < row){
								addition = minesleft / noneMineC;
								noneMineR = (noneMineR + addition > row)?row:noneMineR + addition;
								minesleft = noneMines - noneMineR*noneMineC;
							}
						}
						
						if( minesleft > 0){
							if(noneMineC < column){
								addition = minesleft / noneMineR;
								noneMineC = (noneMineC + addition > column)?column:noneMineC + addition;
								minesleft = noneMines - noneMineR*noneMineC;
							}
						}
						
						if(minesleft > 1 || minesleft == 0){
							possible = true;
						}else if(noneMineC > 2 && noneMineR > 2){
							possible = true;
							swap = true;
							useSwap = false;
						}
						
					}else if(noneMines == 1){
						possible = true;
						noneMineR = 1;
						noneMineC = 1;
						minesleft = noneMines - noneMineR*noneMineC;
					}
				}else{
					//as long as there is one space, it is possible to win with one click
					if(noneMines >= 1){
						possible = true;
						if(row == 1){
							noneMineR = row;
							noneMineC = mines;
						}else if(column == 1){
							noneMineC = column;
							noneMineR = mines;
						}
						
					}
				}
				minesleft = noneMines - noneMineR*noneMineC;
				
				if(possible){
					
					System.out.println(row + " " + column);
					//Construct grid
					for(int m = 0; m < row; m++ ){
						for(int n = 0; n < column; n++ ){
							
							if(m == 0 && n == 0){
								gridConfig[m][n] = 'c';
							}else if(m < noneMineR && n < noneMineC){
								if (swap && m == noneMineR - 1 && n == noneMineC - 1){
									gridConfig[m][n] = '*';
								}else{
									gridConfig[m][n] = '.';
								}
							}else if(minesleft > 0 && (m == noneMineR || n == noneMineC)){
								if(noneMineR < row && m == noneMineR){
									gridConfig[m][n] = '.';
								}else if( noneMineC < column && n == noneMineC){
									gridConfig[m][n] = '.';
								}else{
									System.out.println("Something Wrong!!");
									return;
								}
								if(swap && !useSwap){
									useSwap= true;
								}else{
									minesleft--;
								}
							}else{
								gridConfig[m][n] = '*';
							}
							
						}
					}
				}
				
				// Print out test case number
				writer.println("Case #" + (i+1) + ":");
				System.out.println("Case #" + (i+1) + ":");
				
				if(possible){
					//Construct grid
					for(int m = 0; m < row ; m++ ){
						for(int n = 0; n < column; n++ ){
							writer.print(gridConfig[m][n] + "");
							System.out.print(gridConfig[m][n] + "");
						}
						writer.println();
						System.out.println();
					}
				}else{
					writer.println("Impossible");
					System.out.println("Impossible");
				}
			}
			
			writer.close();
 
		
		
		
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
 
	}
}


