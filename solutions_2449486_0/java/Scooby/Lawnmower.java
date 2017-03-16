// Created by Brenton Philp
// 13 April 2013
// Run java Class 
import java.io.*;
import java.util.*;

public class Lawnmower {
	public static void main(String[] args){
		
		String INPUT = args[0];
		int caseNumber = 1;
		int cases = 0;
		
		try {
			Scanner scanner = new Scanner(new File(INPUT));
			cases = scanner.nextInt();
			scanner.nextLine();
			while (caseNumber <= cases){
				String result="YES";

				//save variables
				int n = scanner.nextInt();
				int m = scanner.nextInt();
				scanner.nextLine();
				int[][] lawn = new int[n][m];
				
				for (int i = 0; i < n; i++){
					for (int j = 0; j < m; j++){
						lawn[i][j]=scanner.nextInt();
					}
					scanner.nextLine();
				}
				
				//solve the problem
				// Calculate the maximum height
				int[] rowheights = new int[n];
				int[] colheights = new int[m];
				
				// Calculate row heights
				for (int i = 0; i < n; i++){
					int max = 0;
					for (int j = 0; j < m; j++){
						if (lawn[i][j] > max){
							max =lawn[i][j];
						}
					}
					rowheights[i] = max;
				}
				
				//Calculate column heights
				for (int j = 0; j < m; j++){
					int max = 0;
					for (int i = 0; i < n; i++){
						if (lawn[i][j] > max){
							max =lawn[i][j];
						}
					}
					colheights[j] = max;
					//System.out.println("Column "+j+" height: "+colheights[j]);
				}
				

				// for every square
				for (int i = 0; i < n; i++){
					for (int j = 0; j < m; j++){
						// Check against max row and column heights.
						if (lawn[i][j] < rowheights[i] && lawn[i][j] < colheights[j]){
							result="NO";
							break;
						}
					}
					if (result.equals("NO")){
						break;
					}
				}

				
				//print result
				System.out.println("Case #"+caseNumber+": "+result);
				caseNumber++;
			}
		} catch (Exception e){
			System.out.println(e);
		}
	}
}