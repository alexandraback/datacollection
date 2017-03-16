package code;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Random;
import java.util.StringTokenizer;

public class Direction {
	
	static int[] point = new int[2];
	static Random r = new Random();
	static final int N = 0;
	static final int S = 1;
	static final int E = 2;
	static final int W = 3;
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("B-small-attempt0.in")));
		PrintWriter writer = new PrintWriter(new File("direction.txt"));

		StringTokenizer tokenizer = null;
		int numLines = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= numLines; i++) {

			tokenizer = new StringTokenizer(reader.readLine());

			point[0] = Integer.parseInt(tokenizer.nextToken());
			point[1] = Integer.parseInt(tokenizer.nextToken());

			writer.println("Case #" + i + ": " + goToPoint());
		}
		
		writer.flush();
		writer.close();
	}
	
	private static String goToPoint() {
		String moves = "";
		int pMove = 0;
		int[] pos = {0, 0};
		int dir;
		
		
		do {
		
			dir = r.nextInt(4);
			
			switch(dir) {
			
				case N:
					pos[1] += (++pMove);
					moves += "N";
					break;
				case S:
					pos[1] -= (++pMove);
					moves += "S";
					break;
				case E:
					pos[0] += (++pMove);
					moves += "E";
					break;
				case W:
					pos[0] -= (++pMove);
					moves += "W";
					break;
			}
		
			if (pos[0] == point[0] && pos[1] == point[1]) {
				
				return moves;
			}
			
			if (moves.length() > 500) {
				
				moves = "";
				pos[0] = 0;
				pos[1] = 0;
				pMove = 0;
			}
		
		} while (true);
	}
}