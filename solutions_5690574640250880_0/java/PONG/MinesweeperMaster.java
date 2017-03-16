package com.pong;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class MinesweeperMaster {

//	static String inputFileName = "Inputs/sample.in.txt";
	static String inputFileName = "Inputs/C-small-attempt1.in.txt";
//	static String inputFileName = "Inputs/C-large.in.txt";
	static String outputFileName = "output.txt";
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		BufferedReader br = null;		
		int N = 0;
		
		// read the input from a file
		try {
			br = new BufferedReader(new FileReader(inputFileName));
			
			String line = br.readLine();
			N = Integer.parseInt(line);	
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	
		File file = new File(outputFileName);
		if (!file.exists()) {
			try {
				file.createNewFile();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		FileWriter fw = null;
		try {
			fw = new FileWriter(file.getAbsoluteFile());
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		BufferedWriter bw = new BufferedWriter(fw);
		
		// Solve the problem
		int R = 0, C = 0, M = 0;
		for (int n = 1; n <= N; n++) {
			
			String line = null;
			try {
				line = br.readLine();
				String[] values = line.split(" ");
				
				R = Integer.parseInt(values[0]);
				C = Integer.parseInt(values[1]);
				M = Integer.parseInt(values[2]);
				
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}	
			
			// brute force solution
			int[][] map = new int[R][C];
			int distance = 0;
			int rm = 0, cm = 0;
			boolean bombPlaced = false;
			int bombsPlaced = 0;			
					
			
			// check if there is any position for the bomb for the distance from corner
			for (distance = 0; distance <= R + C; distance++) {
				
				if (bombsPlaced == M) {
					break;
				}
				
//				System.out.println("d = " + distance);
				
				
				// bomb placing needs to be strategic, need to check how close the filling is from row/column				
				if (distance + 2 >= R && (M - bombsPlaced) >= 2) {
					// if there are more than one bombs to be filled, fill the row and (row - 1) cell first
					
					rm = R - 2;
					cm = distance - rm;
					
					if (cm < C && rm >= 0) {
//						System.out.println(rm + " : " + cm);
						if (map[rm][cm] >= 0) {							
						map[rm][cm] = -1;
						bombsPlaced++;
						}
						
						if (cm < C && rm >= 0) {
							//						System.out.println((rm + 1) + " : " + rc);
							if (map[rm + 1][cm] >= 0) {							
							map[rm + 1][cm] = -1;
							bombsPlaced++;
							}
							
							
						}
						
						if (bombsPlaced == M) {
							break;
						}					
						
					}
					

				}
				
				if (distance + 2 >= C && (M - bombsPlaced) >= 2) {
					// if there are more than one bombs to be filled, fill the column and (column - 1) cell first
					
					cm = C - 2;
					rm = distance - cm;
					
					if (rm < R && cm >= 0) {
		//						System.out.println(rm + " : " + rc);
						if (map[rm][cm] >= 0) {
						
						map[rm][cm] = -1;
						bombsPlaced++;
						}
						
						if (rm < R && cm >= 0) {
							//						System.out.println((rm) + " : " + (rc + 1));
							if (map[rm][cm + 1] >= 0) {
							
							map[rm][cm + 1] = -1;
							bombsPlaced++;
							}
						}
						

						
						if (bombsPlaced == M) {
							break;
						}
					}
				
				}
				
				
				
				
				
				bombPlaced = true;
				while (bombPlaced) {
					bombPlaced = false;				
					
					rm = distance > (R - 1) ? (R - 1) : distance;
					cm = distance - rm;
					
					if (rm + 2 >= R) {
						rm = R - 3;
						cm = distance - rm;
					}
					
					while (0 <= rm && cm + 2 < C) {			
//								System.out.println(rm + " : " + rc);
						if (map[rm][cm] >= 0) {
							map[rm][cm] = -1;
							bombPlaced = true;
							bombsPlaced++;
							break;
						}	
						
						rm--;
						cm++;
					}				
					
					if (bombsPlaced == M) {
						break;
					}
				}
				
				
				
				// place the  bomb on boundary
//				System.out.println("P? " + bombPlaced);
				if (!bombPlaced) {
					rm = distance > (R - 1) ? (R - 1) : distance;
					cm = distance - rm;
					
//					System.out.println(rm + " :!: " + cm);
					while (0 <= rm && cm < C) {											
						if (map[rm][cm] >= 0) {
							map[rm][cm] = -1;
							bombPlaced = true;
							bombsPlaced++;
							break;
						}	
						
						rm--;
						cm++;
					}
				}
				
				
				
				
				if (bombsPlaced == M) {
					break;
				}
			}
			
				
				
				
				
				
				
				
				
				
				
				
			
			// put the proper values into the map
			for (int r = 0; r < R; r++) {
				for (int c = 0; c < C; c++) {
					if (map[r][c] == -1) {
						// add one to all neighboring cell
						// N
						if (r - 1 >= 0 && map[r - 1][c] >= 0) {
							map[r - 1][c]++;
						}
						// NE
						if (r - 1 >= 0 && c + 1 < C && map[r - 1][c + 1] >= 0) {
							map[r - 1][c + 1]++;
						}
						// E
						if (c + 1 < C && map[r][c + 1] >= 0) {
							map[r][c + 1]++;
						}
						// SE
						if (r + 1 < R && c + 1 < C && map[r + 1][c + 1] >= 0) {
							map[r + 1][c + 1]++;
						}
						// S
						if (r + 1 < R && map[r + 1][c] >= 0) {
							map[r + 1][c]++;
						}
						// SW
						if (r + 1 < R && c - 1 >= 0 && map[r + 1][c - 1] >= 0) {
							map[r + 1][c - 1]++;
						}
						// W
						if (c - 1 >= 0 && map[r][c - 1] >= 0) {
							map[r][c - 1]++;
						}
						// NW
						if (r - 1 >= 0 && c - 1 >= 0 && map[r - 1][c - 1] >= 0) {
							map[r - 1][c - 1]++;
						}
					}
				}
			}
				

			
			// solve the game
			// if the game is not solvable, try to create another game
			
			// Scan for numeric value
			//	game is possible if there is only 1 value
			//	- OR - 
			//	there is zero in the neighbor of all posible values
			int positiveValueCount = 0;
			boolean impossible = false;
			for (int r = 0; r < R; r++) {
				for (int c = 0; c < C; c++) {
					if (map[r][c] > 0) {
						// find a zero
						positiveValueCount++;
						
						if (r - 1 >= 0 && map[r - 1][c] == 0) {
							continue;
						}
						// NE
						if (r - 1 >= 0 && c + 1 < C && map[r - 1][c + 1] == 0) {
							continue;
						}
						// E
						if (c + 1 < C && map[r][c + 1] == 0) {
							continue;
						}
						// SE
						if (r + 1 < R && c + 1 < C && map[r + 1][c + 1] == 0) {
							continue;
						}
						// S
						if (r + 1 < R && map[r + 1][c] == 0) {
							continue;
						}
						// SW
						if (r + 1 < R && c - 1 >= 0 && map[r + 1][c - 1] == 0) {
							continue;
						}
						// W
						if (c - 1 >= 0 && map[r][c - 1] == 0) {
							continue;
						}
						// NW
						if (r - 1 >= 0 && c - 1 >= 0 && map[r - 1][c - 1] == 0) {
							continue;
						}
						
						impossible = true;
					}
				}
			}
			
			
			
			// Put the c character the the bottom-right corner
			map[R-1][C-1] = -2;
			
			try {
				System.out.println("Case #" + n + ": " + impossible + "<>" + positiveValueCount);
				if (impossible && positiveValueCount > 1) {
					System.out.println("Impossible");
				}
				else {
					for (int r = 0; r < R; r++) {
						for (int c = 0; c < C; c++) {
							switch (map[r][c]) {
								case -1:
									System.out.print("*");
									break;
									
								case -2:
									System.out.print("c");
									break;
									
								default:
									System.out.print(map[r][c]);
//									System.out.print(".");
									break;
							}						
						}
						System.out.println();
					}
				}
				
				bw.write("Case #" + n + ": " + "\n");
				if (impossible && positiveValueCount > 1) {
					bw.write("Impossible\n");
				}
				else {
					for (int r = 0; r < R; r++) {
						for (int c = 0; c < C; c++) {
							switch (map[r][c]) {
								case -1:
									bw.write("*");
									break;
									
								case -2:
									bw.write("c");
									break;
									
								default:
									bw.write(".");
									break;
							}						
						}
						bw.write("\n");
					}
				}
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		try {
			br.close();
			bw.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println("done");
	}

}
