package codeJam;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Hubert
 */
public class RoundOne1CP2 {
	
	static int minMoves = 501;
	//static String directions = "";
	public static void run (int x, int y, int tX, int tY, int j, String d) {
		String d1 = "";
		for (int i = 0; i < d.length(); i++) {
			d1 = d1 + "" + d.charAt(i);
		}
		if (x == tX && y == tY) {
			if (j < minMoves) {
				//directions = d1;
			}
		}
		else if (x < tX) {
			run(x+j, y, tX, tY, j+1, d1 + "E");
		}
		else if (x > tX) {
			run(x-j, y, tX, tY, j+1, d1 + "W");
		}
		else if (y < tY) {
			run(x, y+j, tX, tY, j+1, d1 + "N");
		}
		else if (y > tY) {
			run(x, y-j, tX, tY, j+1, d1 + "S");
		}
	}
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//Scanner sc = new Scanner (System.in);
		Scanner sc = new Scanner (new FileReader("B-small-attempt0 (1).in"));
		//PrintWriter pw = new PrintWriter (System.out);
		PrintWriter pw = new PrintWriter (new FileWriter("out2.txt"));
		int numCases = sc.nextInt();
		for (int z = 0; z < numCases; z++) {
			int tX = sc.nextInt();
			int tY = sc.nextInt();
			int x = 0;
			int y = 0;
			int j = 1;
			String direction = "";
			boolean over = true;
			while (x != tX && over) {
				while(x<tX && over) {
					x = x+j;
					j++;
					direction = direction + "E";
					if (x > tX && over) {
						x = x+j;
						j++;
						direction = direction + "E";
						over = false;
					}
				}
				while(x>tX && over) {
					x = x-j;
					j++;
					direction = direction + "W";
					if (x < tX && over) {
						if(x+j+1 > tX) {
							x = x-j;
							j++;
							direction = direction + "W";
							over = false;
						}
					}
				}
			}
			if (x > tX) {
				while (x != tX) {
					if (x > tX) {
						x = x-j;
						j++;
						direction = direction + "W";
					}
					if (x != tX) {
						x = x+j;
						j++;
						direction = direction + "E";
					}
				}
			}
			else {
				while (x != tX) {
					if (x < tX) {
						x = x+j;
						j++;
						direction = direction + "E";
					}
					if (x != tX) {
						x = x-j;
						j++;
						direction = direction + "W";
					}
				}
			}
			over = true;
			while (y != tY && over) {
				while(y<tY && over) {
					y = y+j;
					j++;
					direction = direction + "N";
					if (y>tY && over && y-j != tY) {
						y = y+j;
						j++;
						direction = direction + "N";
						over = false;
					}
				}
				while(y>tY && over) {
					y = y-j;
					j++;
					direction = direction + "S";
					if (y < tY && over && y+j !=tY) {
						y = y-j;
						j++;
						direction = direction + "S";
						over = false;
					}
				}
			}
			if (y > tY) {
				while (y != tY) {
					if (y > tY) {
						y = y-j;
						j++;
						direction = direction + "S";
					}
					if (y != tY) {
						y = y+j;
						j++;
						direction = direction + "N";
					}
				}
			}
			else {
				while (y != tY) {
					if (y < tY) {
						y = y+j;
						j++;
						direction = direction + "N";
					}
					if (y != tY) {
						y = y-j;
						j++;
						direction = direction + "S";
					}
				}
			}
			pw.println("Case #" + (z+1) + ": " + direction);
		}
		pw.flush();
		pw.close();
	}
}
