import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;


public class MinesweeperMaster2 {
	public static void main(String[] args) {
        String base = "/home/stefan/";
        String input = base + "C-large.in";
        String output = base + "C-large.out";

        try {
			Scanner scan = new Scanner(new FileReader(input));
        	//Scanner scan = new Scanner(System.in);
			PrintWriter write = new PrintWriter(output);
			
			int n = scan.nextInt();
			scan.nextLine();
			
			for (int i = 1; i <= n; i++) {
				write.write("Case #" + i + ":\n");
				test(scan, write);
			}
			
			scan.close();
			write.close();
        } catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
        
	}

	private static void test(Scanner scan, PrintWriter write) {
		int R, C, M;
		R = scan.nextInt();
		C = scan.nextInt();
		M = scan.nextInt();
		
		char matrix[][] = new char[R][C];
		
		for(int i =0;i<R;i++)
			for(int j=0;j<C;j++)
				matrix[i][j] = '.';
		
		solve(R, C, M, 0, 0, matrix, write);
	}

	private static void solve(int R, int C, int M, int r1, int c1, char[][] matrix, PrintWriter write) {
		//System.out.println("R= " + R + " C= " + C + " M= " + M);
		// R or C equals 1
		if(R == 1 || C == 1){
			if(M < R * C){
				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++) {
						if(M > 0){
							matrix[i][j] = '*';
							M--;
						}
					}
				}
				matrix[matrix.length-1][matrix[0].length-1] = 'c';
				printMatrix(matrix, write);
			} else {
				write.write("Impossible\n");
			}
		} // R or C equals 1 ending
		
		// edno prazno mesto
		else if(M+1==R*C){
			for(int i=0;i<R;i++){
				for(int j=0;j<C;j++)
					matrix[i][j] = '*';
			}
			matrix[matrix.length-1][matrix[0].length-1] = 'c';
			printMatrix(matrix, write);
		}
		// edno prazno mesto kraj
		
		// R or C equals 2
		else if(R == 2 || C == 2){
			if(M == 0){
				matrix[matrix.length-1][matrix[0].length-1] = 'c';
				printMatrix(matrix, write);
			}
			else if(M % 2 == 0 && M < R * C - 2){
				if(R == 2){
					for(int j=c1;j<c1+C;j++){
						for(int i=r1;i<r1+R;i++){
							if(M > 0 && i < r1+R && j < c1 + C - 2){
								M--;
								matrix[i][j] = '*';
							}
						}
					}
				} else {
					for(int i=r1;i<r1+R;i++){
						for(int j=c1;j<c1+C;j++){
							if(M > 0 && i < r1+R-2 && j < c1 + C){
								M--;
								matrix[i][j] = '*';
							}
						}
					}
				}
				matrix[matrix.length-1][matrix[0].length-1] = 'c';
				printMatrix(matrix, write);
			} else {
				write.write("Impossible\n");
			}
		} // R or C equals 2 ending
		
		// R > 2 && C > 2
		else {
			if(M == 0){
				matrix[matrix.length-1][matrix[0].length-1] = 'c';
				printMatrix(matrix, write);
			}
				
			else{
				if(C < R){
					for(int i=c1;i<c1+C-2;i++){
						if(M > 0){
							M--;
							matrix[r1][i] = '*';
						}
					}
					if(M >= 2){
						matrix[r1][c1+C-2] = '*';
						matrix[r1][c1+C-1] = '*';
						M-=2;
					}
					//printMatrix(matrix, write);
					solve(R-1, C, M, r1+1, c1, matrix, write);
				} else {
					for(int i=r1;i<r1+R-2;i++){
						if(M > 0){
							M--;
							matrix[i][c1] = '*';
						}
					}
					if(M >= 2){
						matrix[r1+R-2][c1] = '*';
						matrix[r1+R-1][c1] = '*';
						M-=2;
					}
					//printMatrix(matrix, write);
					solve(R, C-1, M, r1, c1+1, matrix, write);
				}
			}
		}
	}

	private static void printMatrix(char[][] matrix, PrintWriter write) {
		for (int i = 0; i < matrix.length; i++) {
			StringBuilder sb = new StringBuilder();
			for (int j = 0; j < matrix[0].length; j++) {
				sb.append(matrix[i][j]);
			}
			write.write(sb.toString() + "\n");
		}		
	}
}
