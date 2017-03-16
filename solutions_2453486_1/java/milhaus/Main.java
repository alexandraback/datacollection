import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.math.*;

/**
 * 
 * Google Code Jam 2013
 * @author Miloš Èernilovský - milhaus
 *
 */
public class Main {
	private static final String FILE_NAME = "A-large"; 
	private static boolean TEST = false;

	public static void main(String[] args) throws IOException {
		if(TEST) {
			System.out.println("TEST !!!");
			createTestFile();
		}
		System.setIn(new FileInputStream(FILE_NAME + ".in"));
		System.setOut(new PrintStream(FILE_NAME + ".out"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		
		outer:
		for (int i = 1; i <= t; i++) {
			char[][] game = new char[4][4];
			for(int j = 0; j < 4; j++) {
				game[j] = br.readLine().toCharArray();
			}
			br.readLine();
			
			boolean finished = true;
			
			for(int j = 0; j < 4; j++) {
				int xh = 0, xd = 0, oh = 0, od = 0;
				
				for(int k = 0; k < 4; k++) {
					if(game[j][k] == 'X') {
						xh++;
						oh = 0;
					} else if(game[j][k] == 'O') {
						oh++;
						xh = 0;
					} else if(game[j][k] == 'T') {
						xh++;
						oh++;
					} else {
						finished = false;
						xh = 0;
						oh = 0;
					}
					
					if(game[k][j] == 'X') {
						xd++;
						od = 0;
					} else if(game[k][j] == 'O') {
						od++;
						xd = 0;
					} else if(game[k][j] == 'T') {
						xd++;
						od++;
					} else {
						finished = false;
						xd = 0;
						od = 0;
					}
					
					if(xh == 4 || xd == 4) {
						System.out.println("Case #" + i + ": X won");
						continue outer;
					} else if(od == 4 || oh == 4) {
						System.out.println("Case #" + i + ": O won");
						continue outer;
					}
				}
			}
			int xlr = 0, xrl = 0, olr = 0, orl = 0;
			for(int k = 0; k < 4; k++) {
				if(game[k][k] == 'X') {
					xlr++;
					olr = 0;
				} else if(game[k][k] == 'O') {
					olr++;
					xlr = 0;
				} else if(game[k][k] == 'T') {
					xlr++;
					olr++;
				} else {
					finished = false;
					xlr = 0;
					olr = 0;
				}
				
				if(game[k][3-k] == 'X') {
					xrl++;
					orl = 0;
				} else if(game[k][3-k] == 'O') {
					orl++;
					xrl = 0;
				} else if(game[k][3-k] == 'T') {
					orl++;
					xrl++;
				} else {
					finished = false;
					orl = 0;
					xrl = 0;
				}
				
				
				if(xrl == 4 || xlr == 4) {
					System.out.println("Case #" + i + ": X won");
					continue outer;
				} else if(orl == 4 || olr == 4) {
					System.out.println("Case #" + i + ": O won");
					continue outer;
				}
			}
			
			System.out.println("Case #" + i + ": " + (finished ? "Draw" : "Game has not completed"));
		}
	}
	
	private static void createTestFile() throws FileNotFoundException {
		System.out.println("Creating a test file ...");
		PrintWriter pw = new PrintWriter(FILE_NAME + ".in");
		
		
		
		pw.flush();
		pw.close();
		System.out.println("Done.");
	}

}
