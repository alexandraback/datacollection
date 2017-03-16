import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class MinesweeperMaster {

	/**
	 * @param args
	 */
	
	private static char[][] config;
	
	public static void main(String[] args) throws Exception {
		Scanner scan = new Scanner(new File("minesweeper.in"));
		PrintWriter out = new PrintWriter(new FileWriter("minesweeper.out"));
		int tests = scan.nextInt();
		for(int main = 1; main <= tests; main++) {
			int r = scan.nextInt();
			int c = scan.nextInt();
			int m = scan.nextInt();
			
			char[][] matrix = new char[r][c];
			
			for(int i = 0; i < r; i++)
				for(int j = 0; j < c; j++)
					matrix[i][j] = '*';
			boolean check = false;
			
			outerloop1:
			for(int i = 0; i < r; i++)
				for(int j = 0; j < c; j++) {
					System.out.println("BEGIN NEW CLICK");
					matrix[i][j] = 'c';
					if(recur(clone(matrix), r*c-1, m, i, j)) {
						check = true;
						break outerloop1;
					}
					matrix[i][j] = '*';
				}
			
			
			System.out.println("Case #"+main+": ");
			out.println("Case #"+main+": ");
			
			if(!check) {
				System.out.println("Impossible");
				out.println("Impossible");
			}
			else
				for(int i = 0; i < r; i++) {
					System.out.println(config[i]);
					out.println(config[i]);
				}
		}
		out.close();

	}
	
	private static boolean recur(char[][] matrix, int mi, int m, int x, int y) {
		
		System.out.println("BEGIN NEW RECUR");
		for(int i = 0; i < matrix.length; i++)
			System.out.println(matrix[i]);
		System.out.println("mi: "+mi+"m: "+m+"x: "+x+"y: "+y);
		
		
		
		
		if(mi==m) {
			System.out.println("only needed to open it!! mi: "+mi);
			config = matrix;
			return true;
		}
		else if(mi < m) {
			return false;
		}
		
		char[][] clone = clone(matrix);
		
		for(int i = -1; i <= 1; i++)
			for(int j = -1; j <= 1; j++)
				if(x+i < matrix.length && x+i >= 0 && y+j < matrix[0].length && y+j >=0 && matrix[x+i][y+j]=='*') {
					System.out.println("opening ("+(x+i)+","+(y+j)+")");
					mi--;
					clone[x+i][y+j]='.';
				}
		System.out.println("not sufficient. lets open up! mi: " + mi);
		if(mi < m) {
			return false;
		}
		else if(mi == m) {
			config=clone;
			return true;
		}
		
		boolean check = false;
		
		outerloop2:
		for(int i = -1; i <= 1; i++)
			for(int j = -1; j <= 1; j++)
				if((i!=0 || j!=0) && x+i < matrix.length && x+i >= 0 && y+j < matrix[0].length && y+j >=0 && matrix[x+i][y+j]=='*' && recur(clone(clone), mi, m, x+i, y+j)) {
						check = true;
						break outerloop2;
				}
		return check;
	}
	
	private static char[][] clone(char[][] arg) {
		char [][] out = new char[arg.length][];
		for(int i = 0; i < arg.length; i++)
		    out[i] = arg[i].clone();
		return out;
	}

}
