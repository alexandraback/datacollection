import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Minesweeper {

	public final static String INPUT_FILE_NAME = "C-small-attempt1.in";
	public final static String OUTPUT_FILE_NAME = "MineOut.txt";
	
	public static void main(String[] args) {
		try(Scanner in = new Scanner(new FileReader(INPUT_FILE_NAME));
				PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(OUTPUT_FILE_NAME))))
		{
			int numT = in.nextInt();
			for(int t = 1; t <= numT; t ++)
			{
				
				out.println("Case #" + t + ":");
				int rows = in.nextInt();
				int cols = in.nextInt();
				int mines = in.nextInt();
				System.out.println(t + " " + rows + " " + cols + " " + mines);
				int emptySpaces = rows*cols - mines;
				
				if(emptySpaces == 1)
				{
					for(int i = 0; i < rows; i ++)
					{
						for(int j = 0; j < cols; j ++)
						{
							if(i==0 && j==0)out.print('c');else out.print('*');
						}
						out.println();
					}
				}
				else if(rows == 1)
				{
					for(int i = 0; i < mines; i ++)
					{
						out.print('*');
					}
					for(int i = 0; i < cols-mines-1; i ++)
					{
						out.print('.');
					}
					out.println('c');
				}
				else if(cols == 1)
				{
					for(int i = 0; i < mines; i ++)
					{
						out.println('*');
					}
					for(int i = 0; i < rows-mines-1; i ++)
					{
						out.println('.');
					}
					out.println('c');
				}
				else if(rows == 2 || cols == 2)
				{
					if(emptySpaces == 2 || (emptySpaces >= 3 && emptySpaces%2 !=0))
					{
						out.println("Impossible");
					}
					else
					{
						if(rows == 2)
						{
							for(int i = 0; i < 2; i ++)
							{
								for(int j = 0; j < mines/2; j ++)
								{
									out.print('*');
								}
								for(int j = 0; j < cols-mines/2-1; j ++)
								{
									out.print('.');
								}
								out.println(i==0?'.':'c');
							}
						}
						else
						{
							for(int i = 0; i < mines/2; i ++)
							{
								out.println("**");
							}
							for(int i = 0; i < rows-mines/2-1; i ++)
							{
								out.println("..");
							}
							out.println(".c");
						}
					}
				}
				else
				{
					if(emptySpaces==2||emptySpaces==3||emptySpaces==5||emptySpaces==7)
					{
						out.println("Impossible");
					}
					else
					{
						for(int i = rows - 3; i > 0; i --)
						{
							for(int j = cols-1; j >= 0; j --)
							{
								if(mines > 0)
								{
									if(mines == 1 && j == 1)
									{
										out.print("..");
										j--;
									}
									else
									{
										out.print('*');
										mines--;
									}
								}
								else
								{
									out.print('.');
								}
							}
							out.println();
						}
						for(int j = 0; j < cols-3; j ++)
						{
							if(mines > 0)
							{
								out.print('*');
								mines--;
							}
							else
							{
								out.print('.');
							}
						}
						if(mines %2 != 0)
						{
							out.print('*');
							mines--;
						}
						else
						{
							out.print('.');
						}
						if(emptySpaces==4)
						{
							out.println("**");
							mines -= 2;
						}
						else
						{
							out.println("..");
						}
						for(int i = 0; i <= 1; i ++)
						{
							for(int j = 0; j < mines/2; j ++)
							{
								out.print('*');
							}
							for(int j = 0; j < cols-mines/2-1; j ++)
							{
								out.print('.');
							}
							out.println(i==0?'.':'c');
						}
					}
				}
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
