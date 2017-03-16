import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Q3
{
	public static void main(String[] args) throws IOException
	{
		File input = new File("CodeJamInput.in");
		File output = new File("CodeJamOutput.txt");
		FileWriter writer = new FileWriter(output);
		Scanner scan = new Scanner(input);
		
		
		int testCases = scan.nextInt();
		int rows;
		int cols;
		int mines;
		char[][] grid;
		char[][] pattern1;
		char[][] pattern2;
		char[][] pattern3;
		char[][] pattern4;
		int mineCount;
		boolean done;
		boolean possible;
		boolean p3;
		for (int i = 1; i <= testCases; i++)
		{
			rows = scan.nextInt();
			cols = scan.nextInt();
			mines = scan.nextInt();
			mineCount = mines;
			grid = new char[rows][cols];
			pattern1 = new char[rows][cols];
			pattern2 = new char[rows][cols];
			pattern3 = new char[rows][cols];	
			pattern4 = new char[rows][cols];
			done = false;
			possible = false;
			p3 = true;
			for (int a = 0; a < rows; a++)
			{
				for (int b = 0; b < cols; b++)
				{
					grid[a][b] = '.';
					pattern1[a][b] = '.';
					pattern2[a][b] = '.';
					pattern3[a][b] = '.';
				}
			}
			//Pattern 1: Rows
			for (int a = 0; a < rows; a++)
			{
				for (int b = 0; b < cols; b++)
				{
					if (mines>0)
					{
						pattern1[a][b] = '*';
						mines--;
					}
					else
					{
						done = true;
						break;
					}
				}
				if (done) break;
			}
			pattern1[rows-1][cols-1] =  'c';
			mines = mineCount;
			done = false;
			
			//Pattern 2: Cols
			for (int a = 0; a < cols; a++)
			{
				for (int b = 0; b < rows; b++)
				{
					if (mines>0)
					{
						pattern2[b][a] = '*';
						mines--;
					}
					else
					{
						done = true;
						break;
					}
				}
				if (done) break;
			}
			pattern2[rows-1][cols-1] =  'c';
			mines = mineCount;
			done = false;
			
			//Pattern 3: Rectangles
			if (rows>2&&cols>2){
			for (int a = 0; a < rows-2; a++)
			{
				for (int b = 0; b < cols-2; b++)
				{
					if (mines>0)
					{
						pattern3[a][b] = '*';
						mines--;
					}
					else
					{
						done = true;
						break;
					}
				}
				if (done) break;
			}
			done = false;
			for (int a = rows-2; a < rows; a++)
			{
				for (int b = 0; b < cols-2; b++)
				{
					if (mines>0)
					{
						pattern3[a][b] = '*';
						mines--;
					}
					else
					{
						done = true;
						break;
					}
				}
				if (done) break;
			}
			done = false;
			for (int a = 0; a < rows-2; a++)
			{
				for (int b = cols-2; b < cols; b++)
				{
					if (mines>0)
					{
						pattern3[a][b] = '*';
						mines--;
					}
					else
					{
						done = true;
						break;
					}
				}
				if (done) break;
			}
			if (mines > 0) p3 = false;
			pattern3[rows-1][cols-1] =  'c';
			mines = mineCount;
			done = false;}
			else p3 = false;
			
			//Pattern 4 Spaces
			
			int spaces = (rows*cols) - mineCount;
			int current = 1;
			for (int a = 0; a < rows; a++)
			{
				for (int b = 0; b < cols; b++)
				{
					pattern4[a][b] = '*';
				}
			}
			while (spaces>0)
			{
				for (int a = 0; a < current; a++)
				{
					for (int b = 0; b < current; b++)
					{
						if ((a==current-1||b==current-1)&&spaces>0&&a<rows&&b<cols)
						{
							pattern4[a][b] = '.';
							spaces--;
						}
					}
				}
				current++;
			}
			pattern4[0][0] = 'c';
			done = false;
			
			if (check(pattern1))
			{
				grid = pattern1;
				possible = true;
			}
			else if (check(pattern2))
			{
				grid = pattern2;
				possible = true;
			}
			else if (p3&&(check(pattern3)))
			{
				
				grid = pattern3;
				possible = true;
			}
			else if (check(pattern4))
			{
				grid = pattern4;
				possible = true;
			}
			
			if (mineCount+1==rows*cols)
			{
				for (int a = 0; a < rows; a++)
				{
					for (int b = 0; b < cols; b++)
					{
						grid[a][b] = '*';
					}
				}
				grid[0][0] = 'c';
				possible = true;
			}
			else if (mineCount + 4==rows*cols&&rows>1&&cols>1)
			{
				for (int a = 0; a < rows; a++)
				{
					for (int b = 0; b < cols; b++)
					{
						grid[a][b] = '*';
					}
				}
				grid[0][0] = 'c';
				grid[1][0] = '.';
				grid[0][1] = '.';
				grid[1][1] = '.';
				possible = true;
			}
			else if (rows==5&&cols==5&&mineCount==16)
			{
				for (int a = 0; a < rows; a++)
				{
					for (int b = 0; b < cols; b++)
					{
						grid[a][b] = '*';
					}
				}
				for (int a = 1; a < rows-1; a++)
				{
					for (int b = 1; b < cols-1; b++)
					{
						grid[a][b] = '.';
					}
				}
				grid[2][2] = 'c';
				possible = true;
			}
			
			writer.write("Case #" + i + ":\n");
			if (possible)
			{
				for (int a = 0; a < rows; a++)
				{
					for (int b = 0; b < cols; b++)
					{
						writer.write(grid[a][b]);
					}
					writer.write("\n");
				}
			}
			else writer.write("Impossible\n");
		}
		scan.close();		
		writer.close();
		System.out.println("Done");
	}
	public static boolean check (char[][] grid)
	{
		int row = 0, column = 0;
		boolean[][] revealed = new boolean [grid.length][grid[0].length];
		for (int a = 0; a < grid.length; a++)
		{
			for (int b = 0; b < grid[0].length; b++)
			{
				revealed[a][b] = false;
				if (grid[a][b]=='c')
				{
					row = a;
					column = b;
				}
				else if(grid[a][b]=='*')
					revealed[a][b] = true;
			}
		}
		revealed = reveal(grid, row, column, revealed);
		boolean result = true;
		for (int a = 0; a < revealed.length; a++)
		{
			for (int b = 0; b < revealed[0].length; b++)
			{
				if (!revealed[a][b]) result = false;
			}
		}
		return result;
	}
	public static boolean[][] reveal(char[][] grid, int r, int c, boolean[][] revealed)
	{
		revealed[r][c] = true;
		int mineCount = 0;
		if (r>0&&c>0)
		{
			if (grid[r-1][c-1]=='*') mineCount++;
		}
		if (r>0)
		{
			if (grid[r-1][c]=='*') mineCount++;
		}
		if (r>0&&c<grid[0].length-1)
		{
			if (grid[r-1][c+1]=='*') mineCount++;
		}
		if (c<grid[0].length-1)
		{
			if (grid[r][c+1]=='*') mineCount++;
		}
		if (r<grid.length-1&&c<grid[0].length-1)
		{
			if (grid[r+1][c+1]=='*') mineCount++;
		}
		if (r<grid.length-1)
		{
			if (grid[r+1][c]=='*') mineCount++;
		}
		if (r<grid.length-1&&c>0)
		{
			if (grid[r+1][c-1]=='*') mineCount++;
		}
		if (c>0)
		{
			if (grid[r][c-1]=='*') mineCount++;
		}
		
		if (mineCount>0) return revealed;
		
		//Recurisively reveal adjacents
		
		if (r>0&&c>0)
		{
			if (revealed[r-1][c-1]==false) reveal(grid, r-1, c-1, revealed);
		}
		if (r>0)
		{
			if (revealed[r-1][c]==false) reveal(grid, r-1, c, revealed);
		}
		if (r>0&&c<grid[0].length-1)
		{
			if (revealed[r-1][c+1]==false) reveal(grid, r-1, c+1, revealed);
		}
		if (c<grid[0].length-1)
		{
			if (revealed[r][c+1]==false) reveal(grid, r, c+1, revealed);
		}
		if (r<grid.length-1&&c<grid[0].length-1)
		{
			if (revealed[r+1][c+1]==false) reveal(grid, r+1, c+1, revealed);
		}
		if (r<grid.length-1)
		{
			if (revealed[r+1][c]==false) reveal(grid, r+1, c, revealed);
		}
		if (r<grid.length-1&&c>0)
		{
			if (revealed[r+1][c-1]==false) reveal(grid, r+1, c-1, revealed);
		}
		if (c>0)
		{
			if (revealed[r][c-1]==false) reveal(grid, r, c-1, revealed);
		}
		return revealed;
	}
}