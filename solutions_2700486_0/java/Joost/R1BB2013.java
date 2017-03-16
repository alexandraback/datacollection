package gcj2013;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class R1BB2013 {

	public static void main(String[] args) throws Exception {
		new R1BB2013();
	}
	
	static final String filename = "R1B/B-small-attempt0";
	int testcases;
	
	public R1BB2013() throws Exception {
		FileReader ifile = new FileReader(filename+".in");
		Scanner scanner = new Scanner(ifile);
		testcases = (scanner.nextInt());
		FileWriter ofile = new FileWriter(filename+".out");
		for (int i = 1; i <= testcases; i++) {
//            System.out.println("Case "+i);
			ofile.write("Case #"+i+": "+solve(scanner)+(i != testcases ? "\n" : ""));
		}
		ofile.close();
		System.out.println("Finished");
	}
	
	private String solve(Scanner scanner) throws Exception {
        int N = scanner.nextInt();
        int X = scanner.nextInt();
        int Y = scanner.nextInt();
        double prob = 0;
        boolean grid[][] = new boolean[4*N][2*N+5];
        if (2*N+X < 0 || 2*N+X >= 4*N || Y >= 2*N+5 || Y < 0)
            return ""+0;
        return ""+solveRec(N, N, X, Y, grid, 0, 2*N-1+5);
    }
    
    private double solveRec(int N, int n, int X, int Y, boolean grid[][], int x0, int y0) {
        if (n == 0) {
            return (grid[2*N+X][Y] ? 1.0 : 0.0);
        }
        else {
            for (int y = y0; y > 0; y--) {
                if (y == 1 || grid[2*N+x0][y-2]) {
                    if (grid[2*N+x0-1][y-1] && grid[2*N+x0+1][y-1]) {
                        grid[2*N+x0][y] = true;
                        return solveRec(N, n-1, X, Y, grid, 0, 2*N-1+5);
                    }
                    else if (grid[2*N+x0-1][y-1]) {
                        return solveRec(N, n, X, Y, grid, x0+1, y-1);
                    }
                    else if (grid[2*N+x0+1][y-1]) {
                        return solveRec(N, n, X, Y, grid, x0-1, y-1);
                    }
                    else {
                        if (y == 1) {
                            grid[2*N+x0][0] = true;
                            return solveRec(N, n-1, X, Y, grid, 0, 2*N-1+5);
                        }
                        else
                            return 0.5*solveRec(N, n, X, Y, cloneGrid(grid,N), x0+1, y-1) + 0.5*solveRec(N, n, X, Y, cloneGrid(grid,N), x0-1, y-1);
                    }
                }
            }
            grid[2*N+x0][0] = true;
            return solveRec(N, n-1, X, Y, grid, 0, 2*N-1+5);
        }
        //System.out.println("Catch!");
        //return 0;
    }
    
    private boolean[][] cloneGrid(boolean[][] grid, int N) {
        boolean[][] g = new boolean[4*N][2*N+5];
        for (int i = 0; i < 4*N; i++) {
            for (int j = 0; j < 2*N+5; j++) {
                g[i][j] = grid[i][j];
            }    
        }
        return g;
    }
	
}
