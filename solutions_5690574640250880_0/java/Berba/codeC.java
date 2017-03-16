import java.util.*;

public class codeC{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for(int ca = 1; ca <= T; ca++){
			int r = sc.nextInt();
			int c = sc.nextInt();
			int mines = sc.nextInt();
			int clear =  r*c - mines;
			char grid[][] = new char[r][c];
			for(int i = 0; i < r; i++)
				for(int j = 0; j < c; j++)
					grid[i][j] = '*';

			if(clear == 0){}
			else if(r == 1){
				for(int i = 0; i < clear; i++)
					grid[0][i] = '.';
				grid[0][0] = 'c';
			}else if(c == 1){
				for(int i = 0; i < clear; i++)
					grid[i][0] = '.';
				grid[0][0] = 'c';
			}else if(clear == 1){
				grid[0][0] = 'c';
			}else if(clear < 4){
				grid = null;
			}else if(r == 2){
				if(clear % 2 != 0) grid = null;
				else {
					for(int j = 0; clear > 0; j++){
						grid[1][j] = grid[0][j] = '.';
						clear -= 2;
					}
					grid[0][0] = 'c';
				}
			}else if(c == 2){
				if(clear % 2 != 0) grid = null;
				else {
					for(int i = 0; clear > 0; i++){
						grid[i][0] = grid[i][1] = '.';
						clear -= 2;
					}
					grid[0][0] = 'c';
				}
			}else{
				boolean free[][] = new boolean[r-1][c-1];
				clear -= 4;
				free[0][0] = true;
				if(clear == 0){
					for(int i = 0; i < r; i++)
							for(int j = 0; j < c; j++){
								if(i < r-1 && j < c-1 && free[i][j])
									grid[i][j] = '.';
								else{
									if(i > 0 && j < c - 1 && free[i-1][j]) grid[i][j] = '.';
									if(j > 0 && i < r - 1 && free[i][j-1]) grid[i][j] = '.';
									if(i > 0 && j > 0 && free[i-1][j-1]) grid[i][j] = '.';
								}
							}
						grid[0][0] = 'c';
				}
				else if(clear == 2){
					free[0][1] = true;
					clear -= 2;
					for(int i = 0; i < r; i++)
							for(int j = 0; j < c; j++){
								if(i < r-1 && j < c-1 && free[i][j])
									grid[i][j] = '.';
								else{
									if(i > 0 && j < c - 1 && free[i-1][j]) grid[i][j] = '.';
									if(j > 0 && i < r - 1 && free[i][j-1]) grid[i][j] = '.';
									if(i > 0 && j > 0 && free[i-1][j-1]) grid[i][j] = '.';
								}
							}
						grid[0][0] = 'c';
				}else if(clear < 4){
					grid = null;
				}else{
					free[0][1] = true;
					clear -= 2;
					free[1][0] = true;
					clear -= 2;
					for(int i = 2; i < r-1; i++){
						if(clear < 2) break;
						else{
							clear-=2;
							free[i][0] = true;
						}
					}

					for(int i = 2; i < c-1; i++){
						if(clear < 2) break;
						else{
							clear -= 2;
							free[0][i] = true;
						}
					}

					for(int i = 1; i < r-1; i++)
						for(int j = 1; j < c-1; j++){
							if(clear == 0) break;
							else{
								free[i][j] = true;
								clear--;
							}
						}
							if(clear != 0) grid = null;
					else{
						for(int i = 0; i < r; i++)
							for(int j = 0; j < c; j++){
								if(i < r-1 && j < c-1 && free[i][j])
									grid[i][j] = '.';
								else{
									if(i > 0 && j < c - 1 && free[i-1][j]) grid[i][j] = '.';
									if(j > 0 && i < r - 1 && free[i][j-1]) grid[i][j] = '.';
									if(i > 0 && j > 0 && free[i-1][j-1]) grid[i][j] = '.';
								}
							}
						grid[0][0] = 'c';
					}
				}
			}
			System.out.println("Case #" + ca +":");
			if(grid == null) {
				System.out.println("Impossible");
			}
			else {
				int count = 0;
				

				// int dx[] = {0,0,1,1,1,-1,-1,-1};
				// int dy[] = {1,-1,0,-1,1,0,-1,1};

				// for(int i = 0; i < r; i++)
				// 	for(int j = 0; j < c; j++)
				// 		if(grid[i][j] == '*'){
				// 			count++;
				// 			for(int k = 0; k < 8; k++)
				// 				if(i + dx[k] < 0 || i+dx[k] >= r || j + dy[k] < 0 || j+dy[k] >= c)
				// 					continue;
				// 				else if(grid[i+dx[k]][j+dy[k]] == '.')
				// 					grid[i+dx[k]][j+dy[k]] = '-';
				// 		}
				// System.out.println("-------> " +  mines + " " + count);

				for(int i = 0; i < r; i++){
					for(int j = 0; j < c; j++){
						System.out.print(grid[i][j]);
					}
					System.out.println();
				}

			}

		}
	}
}
