import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;


public class Main {

    public static boolean possible(char[][] grid ,int r ,int c,int m){
    	if(m==0){
    		if(((R>1 && grid[R-2][C-1]=='.')|| R==1) && ((C>1 && grid[R-1][C-2]=='.')|| C==1)&& ((C>1&&R>1 && grid[R-2][C-2]=='.')||C==1||R==1)) {
				grid[R-1][C-1]='c';
    			return true;
			}
    		else if(r==R-1&&c==C-1){
    			grid[R-1][C-1]='c';
    			return true;
			}
    		else {
				return false;
			}
    	}
    	if (R-r<C-c) {
    		if (m>=(R-r)) {
    			for (int i = r; i < R; i++) {
    				grid[i][c]='*';
    			}
    			return possible(grid, r, c+1, m-R+r);
			}
    		else {
				if (R-r==2 || m>(R-r-2)*(C-c-2)) {
					return false;
				}
				else {
					for (int i = c; i < C-2 && m>0; i++) {
						for (int j = r; j < R-2 &&m>0; j++) {
							grid[j][i]='*';
							m--;
						}					
					}
					grid[R-1][C-1]='c';
	    			return true;
				}
			}
		}
    	else{
			if (m>=(C-c)) {
				for (int i = c; i < C; i++) {
    				grid[r][i]='*';
    			}
    			return possible(grid, r+1, c, m-C+c);
			}
			else {
				if (C-c==2 || m>(R-r-2)*(C-c-2)) {
					return false;
				}
				else {
					for (int i = r; i < R-2 && m>0; i++) {
						for (int j = c; j < C-2 && m>0; j++) {
							grid[i][j]='*';
							m--;
						}
					}
					grid[R-1][C-1]='c';
	    			return true;
				}
			}
		}
    }
    static int R;
	static int C;
	static int M;
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner=new Scanner(new File("E:\\C-small-attempt2.in"));
		PrintWriter printWriter=new PrintWriter(new File("E:\\output.txt"));
		int T=scanner.nextInt();
		for (int i = 1; i <= T; i++) {			
			 R=scanner.nextInt();
			 C=scanner.nextInt();
			 M=scanner.nextInt();
			printWriter.println("Case #"+i+":");
			char[][] grid=new char[R][C];
			for (int j = 0; j < R; j++) {
				for (int j2 = 0; j2 < C; j2++) {
					grid[j][j2]='.';
				}
			}
			if (!possible(grid,0,0,M)) {
				printWriter.println("Impossible");
			}
			else {
				for (int j = 0; j < R; j++) {
					for (int j2 = 0; j2 < C; j2++) {
						printWriter.print(grid[j][j2]);
					}
					printWriter.println();
				}
			}
						
		}
		printWriter.close();
	}	 	 
}

