package Qualification2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

import javax.imageio.stream.ImageInputStream;

/**
 * Open an input file called "input.txt", output file "output.txt" The file
 * begins with n,the number of lines, followed by n lines each line of the n
 * lines has two numbers writes all the number separated be a space in the
 * output file
 * 
 */
public class C
{

	public static void main(String[] args) throws IOException
	{
		// For the Input file
		BufferedReader in = new BufferedReader(new FileReader("input.txt"));

		// For the output file
		BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));

		// Read the number from the input file and write them to the output file
		int nCases = Integer.parseInt(in.readLine());
		for (int i = 0; i < nCases; i++)
		{
			System.out.println((i+1));
			String[] strs = in.readLine().split(" ");
			int r = Integer.parseInt(strs[0]);
			int c = Integer.parseInt(strs[1]);
			int nBombs = Integer.parseInt(strs[2]);

			out.write("Case #" + (i + 1) + ": \n");
			out.write(solve(r, c, nBombs));
			out.write("\n");

		}
		out.write("\n");
		out.flush();

		// Close the streams
		in.close();
		out.close();
	}

	private static String solve(int r, int c, int nBombs)
	{
		int nGood = r * c - nBombs;

		// Try filling row row
		if (fillRowRow(r, c, nGood, nBombs).equals("Impossible") == false)
		{
			return fillRowRow(r, c, nGood, nBombs);
		} else if (fillColCol(r, c, nGood, nBombs).equals("Impossible") == false)
		{
			return fillColCol(r, c, nGood, nBombs);
		} else if (fillShape3(r, c, nGood, nBombs).equals("Impossible") == false)
		{
			return fillShape3(r, c, nGood, nBombs);
		} 
		
		else
		{
			for (int width = 1; width <= c; width++)
			{
				int height = (nGood / width);
				if (!(width * height == nGood))
					height += 1;

				if (height <= r)
				{
					String newFill1 = fillShape1(r, c, nGood, nBombs, width, height);
					if (newFill1.equals("Impossible") == false)
					{
						return newFill1;
					}

					String newFill2 = fillShape2(r, c, nGood, nBombs, width, height);
					if (newFill2.equals("Impossible") == false)
					{
						return newFill2;
					}
				}

			}
		}

		return "Impossible";
	}

	private static String fillShape3(int r, int c, int nGood, int nBombs)
	{
		boolean[][] m = new boolean[r][c];
		
		if (r + c - 1 < nBombs)
		{
			return "Impossible";
		}
		else
		{
			// make all good
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					m[i][j] = true;
				}
			}
			
			// Make bombs from the far corner
			int count = 0;
			Queue<Integer> bombR = new LinkedList<>();
			Queue<Integer> bombC = new LinkedList<>();
			bombR.add(r - 1);
			bombC.add(c - 1);
			while (count < r*c - nGood && !bombR.isEmpty())
			{
				// Take the bomb
				int newR = bombR.poll();
				int newC = bombC.poll();
				boolean valid = newR >= 0 && newR < r && newC >= 0 && newC < c;
				if (valid)
				{
					m[newR][newC]  = false;
					count++;
					// Add neighbours
					if (newR == r-1 && newC == c - 1)
					{
						bombR.add(newR - 1); 
						bombC.add(newC);
						
						bombR.add(newR); 
						bombC.add(newC-1);
					}
					else if(newR == r-1)
					{
						bombR.add(newR); 
						bombC.add(newC-1);
					}
					else if (newC == c-1)
					{
						bombR.add(newR - 1); 
						bombC.add(newC);
					}
				}

			}
			if (possible(m, r, c, nGood))
				return boardToString(m);
			
		}
		return "Impossible";
	}

	private static String fillShape2(int r, int c, int nGood, int nBombs, int width, int height)
	{
		boolean[][] m = new boolean[r][c];

		// Find the spaces in the first and last lines
		int totalRemaining = width * height - nGood;
		int lastLineBombs = totalRemaining / 2;
		int firstLineBombs = totalRemaining - lastLineBombs;

		// Fill the first line
		for (int i = 0; i < width - firstLineBombs; i++)
			m[0][i] = true;

		// Fill the lines in the middle
		for (int i = 1; i < height - 1; i++)
		{
			for (int j = 0; j < width; j++)
			{
				m[i][j] = true;
			}
		}

		// Fill the last line
		for (int i = lastLineBombs; i < width; i++)
		{
			m[height - 1][i] = true;
		}

		if (possible(m, r, c, nGood))
			return boardToString(m);
		else
			return "Impossible";
	}

	private static String fillShape1(int r, int c, int nGood, int nBombs, int width, int height)
	{
		boolean[][] m = new boolean[r][c];

		// Find the spaces in the first and last lines
		int totalRemaining = width * height - nGood;
		int firstLineBombs = totalRemaining / 2;
		int lastLineBombs = totalRemaining - firstLineBombs;

		// Fill the first line
		for (int i = 0; i < width - firstLineBombs; i++)
			m[0][i] = true;

		// Fill the lines in the middle
		for (int i = 1; i < height - 1; i++)
		{
			for (int j = 0; j < width; j++)
			{
				m[i][j] = true;
			}
		}

		// Fill the last line
		for (int i = lastLineBombs; i < width; i++)
		{
			m[height - 1][i] = true;
		}

		if (possible(m, r, c, nGood))
			return boardToString(m);
		else
			return "Impossible";
	}

	private static String fillColCol(int r, int c, int nGood, int nBombs)
	{
		boolean[][] m = new boolean[r][c];
		int row = 0;
		int col = 0;
		int count = 0;
		while (count < nGood)
		{
			m[row][col] = true;
			count++;
			if (row + 1 < r)
			{
				row++;
			} else
			{
				row = 0;
				col++;
			}
		}
		if (possible(m, r, c, nGood))
			return boardToString(m);
		else
			return "Impossible";
	}

	private static String fillRowRow(int r, int c, int nGood, int nBombs)
	{
		boolean[][] m = new boolean[r][c];
		int row = 0;
		int col = 0;
		int count = 0;
		while (count < nGood)
		{
			m[row][col] = true;
			count++;
			if (col + 1 < c)
			{
				col++;
			} else
			{
				col = 0;
				row++;
			}
		}
		if (possible(m, r, c, nGood))
			return boardToString(m);
		else
			return "Impossible";

	}

	private static boolean possible(boolean[][] m, int r, int c, int nGood)
	{
		// Search starting from the first node
		Stack<Integer> rStack = new Stack<>();
		Stack<Integer> cStack = new Stack<>();
		HashSet<String> explored = new HashSet<>();

		rStack.push(0);
		cStack.push(0);
		int count = 0;
		while (!rStack.isEmpty())
		{
			// Get the next node
			int newR = rStack.pop();
			int newC = cStack.pop();
			boolean valid = newR >= 0 && newR < r && newC >= 0 && newC < c && m[newR][newC];
			boolean notExplored = !(explored.contains(newR + "," + newC));

			if (valid && notExplored)
			{
				// Mark as explored
				explored.add(newR + "," + newC);

				// count the neighboring
				int counter = 0;
				for (int i = -1; i < 2; i++)
				{
					for (int j = -1; j < 2; j++)
					{
						int reqR = newR + i;
						int reqC = newC + j;
						boolean reqValid = reqR >= 0 && reqR < r && reqC >= 0 && reqC < c;
						if (reqValid && !m[reqR][reqC])
							counter++;
					}
				}
				boolean zeroItem = (counter == 0);

				if (zeroItem)
				{
					for (int i = -1; i < 2; i++)
					{
						for (int j = -1; j < 2; j++)
						{
							if (!(i == 0 && j == 0))
							{
								int reqR = newR + i;
								int reqC = newC + j;
								boolean reqValid = reqR >= 0 && reqR < r && reqC >= 0 && reqC < c;
								if (reqValid)
								{
									rStack.push(reqR);
									cStack.push(reqC);
								}

							}
						}
					}
				}
				count++;
			}

		}

		return count == nGood;
	}

	private static String boardToString(boolean[][] m)
	{
		StringBuilder str = new StringBuilder();
		for (int i = 0; i < m.length; i++)
		{
			for (int j = 0; j < m[0].length; j++)
			{
				if (i == 0 && j == 0)
				{
					str.append("c");

				} else
				{
					if (m[i][j])
						str.append(".");
					else
						str.append("*");
				}
			}
			if (i != m.length - 1)
				str.append("\n");
		}

		return str.toString();
	}

}
