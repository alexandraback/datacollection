import java.util.*;
import java.io.*;

public class MinesweeperMaster {
	public static void main(String[] args) throws Exception
	{
		String inputfile = "D:\\in3-large.txt";
		String outputfile = "D:\\out3-large.txt";
		
		Scanner in = new Scanner(new File(inputfile));
		FileWriter fstream = new FileWriter(outputfile);
		BufferedWriter out = new BufferedWriter(fstream);
		
		int T = in.nextInt();
		for (int t = 1; t <= T; ++t)
		{
			int R, C, M;
			R = in.nextInt();
			C = in.nextInt();
			M = in.nextInt();
			int openSpaces = R*C - M;
			
			System.out.println("iteration " + t);
			out.write(String.format("Case #%d:", t));
			out.newLine();
			
			// boiled down to 3 cases---
			// strip
			if (R == 1 || C == 1)
			{
				boolean first = true;
				for (int r = 0; r < R; ++r)
				{
					for (int c = 0; c < C; ++c)
					{
						if (first)
						{
							first = false;
							out.write('c');
						}
						else if (openSpaces > 1)
						{
							out.write('.');
							--openSpaces;
						}
						else
						{
							out.write('*');
						}
					}
					out.newLine();
				}
			}
			// big strip
			else if (R == 2 || C == 2)
			{
				if (openSpaces == 2 || (openSpaces != 1 && (openSpaces%2 == 1)))
				{
					out.write("Impossible");
					out.newLine();
				}
				else
				{
					boolean first = true;
					for (int r = 0; r < R; ++r)
					{
						for (int c = 0; c < C; ++c)
						{
							if (first)
							{
								first = false;
								out.write('c');
							}
							else if (r >= openSpaces/2 || c >= openSpaces/2)
							{
								out.write('*');
							}
							else
							{
								out.write('.');
							}
						}
						out.newLine();
					}
				}
			}
			// anything else can be mapped to this (I hope, I'm kinda reaching on this one)
			else
			{
				if (openSpaces == 2 || openSpaces == 3 || openSpaces == 5 || openSpaces == 7)
				{
					out.write("Impossible");
					out.newLine();
				}
				else
				{
					boolean[][] mines = new boolean[R][C];
					
					// mass fill all but a super fat strip at the end
					for (int c = 0; c < C - 3; ++c)
					{
						for (int r = 0; r < R; ++r)
						{
							if (M > 0)
							{
								mines[r][c] = true;
								--M;
								
								// special case
								if (M == 0 && r == R-2)
								{
									mines[r][c] = false;
									mines[0][c+1] = true;
								}
							}
						}
					}
					
					// handle the rest of the cases
					for (int r = 0; r < R; ++r)
					{
						for (int c = C - 3; c < C; ++c)
						{
							if (M > 0)
							{
								mines[r][c] = true;
								--M;
								
								// special case
								if (M == 0 && c == C-2 && r+1 < R)
								{
									mines[r][c] = false;
									mines[r+1][C-3] = true;
								}
							}
						}
					}
					
					for (int r = 0; r < R; ++r)
					{
						for (int c = 0; c < C; ++c)
						{
							if (r == R-1 && c == C-1)
							{
								out.write('c');
							}
							else
							{
								out.write(mines[r][c] ? '*' : '.');
							}
						}
						out.newLine();
					}
				}
			}
		}
		
		System.out.println("done...");
		out.close();
	}
}
