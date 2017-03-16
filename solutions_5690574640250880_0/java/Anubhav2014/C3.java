package qualification2014;

import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class C3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int R,C,M;
		long start = System.currentTimeMillis();
		for (int i = 1; i <=T ; i++) {
			R = sc.nextInt();
			C = sc.nextInt();
			M = sc.nextInt();
			int[][] grid;
			System.out.print("Case #"+i+": ");
			if((R*C)==9 && (M==2)){
				System.out.println();
				System.out.println("Impossible");
			
			}
			else
			if((R*C)==25 && (M==22||M==23)){
				System.out.println();
				System.out.println("Impossible");
			
			}
			else
			if((R*C)==M){

				System.out.println();
				System.out.println("Impossible");
			
			}
			else
			if(!(((R*C)-M==5)||((R*C)-M==7)) ||(R==1 ||C==1))
			{
				if(M!=0)
					grid= getAllCombinations(R, C, M);
				else
					grid=new int[R][C];
				if(grid!=null){
					int count = 0;
					System.out.println();
					for (int j = 0; j < R; j++) {
						for (int k = 0; k < C; k++) {
							if(grid[j][k]==9)
								System.out.print("*");
							else
								if(grid[j][k]==0&&count==0)
									{System.out.print("c");
									count++;
									}
								else
									System.out.print(".");
						}
						System.out.println();
					}
				}
				else{
					System.out.println();
					System.out.println("Impossible");
				}
			}
			else{
				System.out.println();
				System.out.println("Impossible");
			}
				
		}
		
	}
/**
 * 
 *  "smiles".substring(1, 5) returns "mile"

 * @param R
 * @param C
 * @param M
 */
	public static int[][] getAllCombinations(int R,int C,int M){
		int maxBinary = (int)Math.pow(2, R*C);
		String ones = new String("111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
		ones = ones.substring(ones.length()-M, ones.length());
		int start = Integer.parseInt(ones, 2);
		maxBinary = Integer.parseInt((ones+"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000").substring(0, R*C),2);
		ones = ones.replace("1", "1\\d*[0]");
		Pattern p = Pattern.compile(ones);
		Matcher m;
		int[][] grid = new int[R][C];
		for (int i = start; i <= maxBinary; i++) {
			grid = new int[R][C];
			String binary = Integer.toBinaryString(i);
			binary = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"+binary;
			binary = binary.substring(binary.length()-R*C, binary.length());
			m = p.matcher(binary);
			if(true){
				int count = binary.length() - binary.replace("1", "").length();
				if(count==M){
				int l = 0;
				for (int j = 0; j < R; j++) {
					
					
					for (int k = 0; k < C; k++) {
						grid[j][k] = binary.charAt(l)=='1'?9:0;
						l++;
					}
				}
				
				grid = noTheGrid(grid, R, C);
				if(((grid[0][0]== 0)||(grid[R-1][C-1]== 0)||(grid[R-1][0]== 0)||(grid[0][C-1]== 0))
						&&((R*C)-M)==4)
					{
						return grid;
					}
				if((R*C)-M==1){
					for (int j = 0; j < R; j++) {
						for (int k = 0; k < C; k++) {
							if(grid[j][k]!=9)
								grid[j][k]=0;
						}
						
					}
					return grid;
				}
				if(checkIfAllNoHas0AsNeighbour(grid, R, C)){
					
					/*System.out.println();
					for (int j = 0; j < R; j++) {
						for (int k = 0; k < C; k++) {
							System.out.print(grid[j][k]);
						}
						System.out.println();
					}*/
					
					return grid;
				}
				/*System.out.println();
				for (int j = 0; j < R; j++) {
					for (int k = 0; k < C; k++) {
						System.out.print(grid[j][k]);
					}
					System.out.println();
				}*/
				}
			}
		}
		return null;
	}
	
	
	public static int[][] noTheGrid(int[][] grid,int R,int C){
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if(grid[i][j]!=9){
				if(i!=0){
					if(j!=0)
						if(grid[i-1][j-1]==9)
							grid[i][j]++;
					if(grid[i-1][j]==9)
						grid[i][j]++;
					
					if(j!=C-1)
						if(grid[i-1][j+1]==9)
							grid[i][j]++;
					}
				
				if(j!=0)
					if(grid[i][j-1]==9)
						grid[i][j]++;
				if(grid[i][j]==9)
					grid[i][j]++;
				if(j!=C-1)
					if(grid[i][j+1]==9)
						grid[i][j]++;
				
				if(i!=R-1)
				{
					if(j!=0)
					if(grid[i+1][j-1]==9)
						grid[i][j]++;
					if(grid[i+1][j]==9)
						grid[i][j]++;
					if(j!=C-1)
						if(grid[i+1][j+1]==9)
							grid[i][j]++;
				}
				
			}
			
			
		}
	}	
		
	return grid;
	}
	public static boolean checkIfAllNoHas0AsNeighbour(int[][]grid,int R,int C){
		boolean hasZero = true,inside = false;
		if(R==1){
			if(grid[0][0] == 0 || grid[0][C-1]==0){
				return true;
			}
		}
		else
			if(C==1){
				if(grid[0][0] ==0 || grid[R-1][0]==0)
					return true;
			}
			else
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				inside = true;
				if(grid[i][j]!=9){
					if(i!=0){
						if(j!=0)
							if(grid[i-1][j-1]==0)
								continue;
						if(grid[i-1][j]==0)
							continue;
						
						if(j!=C-1)
							if(grid[i-1][j+1]==0)
								continue;
						}
					
					if(j!=0)
						if(grid[i][j-1]==0)
							continue;
					/*if(grid[i][j]==0)
						continue;*/
					if(j!=C-1)
						if(grid[i][j+1]==0)
							continue;
					
					if(i!=R-1)
					{
						if(j!=0)
						if(grid[i+1][j-1]==0)
							continue;
						if(grid[i+1][j]==0)
							continue;
						if(j!=C-1)
							if(grid[i+1][j+1]==0)
								continue;
					}
					
					hasZero=false;
					i=R;
					break;
				}
				
			}
		}
		return hasZero&inside;
	}

}
