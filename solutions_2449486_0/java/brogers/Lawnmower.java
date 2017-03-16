
import java.io.*;
import java.util.*;

public class Lawnmower
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader("Lawnmower-small-attempt0.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("Lawnmower-small-attempt0.out", false));

		String line = in.readLine();
		int cases = Integer.parseInt(line); // # of test cases

		for (int i = 1; i <= cases; i++)
		{
			prt("case #" + i);
			line = in.readLine();
			String[] parts = line.split(" ");
			int h = Integer.parseInt(parts[0]);
			int w = Integer.parseInt(parts[1]);

			int[][] lawn = new int[h][w];
			for (int j = 0; j < h; j++)
			{
				line = in.readLine();
				parts = line.split(" ");
				for (int k = 0; k < w; k++)
				{
					lawn[j][k] = Integer.parseInt(parts[k]);
				}
			}

			dump(lawn);
			out.write("Case #" + i + ": " + solve(lawn));
			out.newLine();
		}

		in.close();
		out.close();
	}

	private static final String YES = "YES";
	private static final String NO = "NO";

	private static String solve(int[][] lawn)
	{
		int h = lawn.length;
		int w = lawn[0].length;
		int[][] canvas = new int[h][w];
		Iterator<Integer> it = getNums(lawn).descendingIterator();
		while (it.hasNext())
		{
			int n = it.next();
			prt("painting " + n);
			for (int r = 0; r < h; r++)
			{
				if (isInRow(lawn, r, n) && canPaintRow(lawn, r, n))
					paintRow(canvas, r, n);
			}
			for (int c = 0; c < w; c++)
			{
				if (isInCol(lawn, c, n) && canPaintCol(lawn, c, n))
					paintCol(canvas, c, n);
			}
			dump(canvas);
		}

		return areEqual(lawn, canvas) ? YES : NO;
	}

	private static boolean isInRow(int[][] mat, int r, int n)
	{
		int w = mat[r].length;
		for (int c = 0; c < w; c++)
			if (mat[r][c] == n) return true;
		return false;
	}

	private static boolean isInCol(int[][] mat, int c, int n)
	{
		int h = mat.length;
		for (int r = 0; r < h; r++)
			if (mat[r][c] == n) return true;
		return false;
	}

	private static boolean canPaintRow(int[][] mat, int r, int n)
	{
		int w = mat[r].length;
		for (int c = 0; c < w; c++)
			if (mat[r][c] > n) return false;
		return true;
	}

	private static boolean canPaintCol(int[][] mat, int c, int n)
	{
		int h = mat.length;
		for (int r = 0; r < h; r++)
			if (mat[r][c] > n) return false;
		return true;
	}

	private static void paintRow(int[][] canvas, int r, int n)
	{
		int w = canvas[r].length;
		for (int c = 0; c < w; c++)
			canvas[r][c] = n;
	}

	private static void paintCol(int[][] canvas, int c, int n)
	{
		int h = canvas.length;
		for (int r = 0; r < h; r++)
			canvas[r][c] = n;
	}

	private static void fill(int[][] canvas, int n)
	{
		int h = canvas.length;
		int w = canvas[0].length;
		for (int r = 0; r < h; r++)
			for (int c = 0; c < w; c++)
				canvas[r][c] = n;
	}

	private static boolean areEqual(int[][] a, int[][] b)
	{
		int h = a.length;
		int w = a[0].length;
		for (int r = 0; r < h; r++)
			for (int c = 0; c < w; c++)
				if (a[r][c] != b[r][c]) return false;
		return true;
	}

	private static NavigableSet<Integer> getNums(int[][] mat)
	{
		NavigableSet<Integer> set = new TreeSet<Integer>();
		int h = mat.length;
		int w = mat[0].length;
		for (int r = 0; r < h; r++)
			for (int c = 0; c < w; c++)
				set.add(mat[r][c]);
		return set;
	}

	private static void dump(int[][] mat)
	{
		int h = mat.length;
		int w = mat[0].length;
		for (int r = 0; r < h; r++)
		{
			for (int c = 0; c < w; c++)
			{
				System.out.print(mat[r][c] + " ");
			}
			System.out.println();
		}
	}

	private static void prt(String s)
	{
		System.out.println(s);
	}
}

