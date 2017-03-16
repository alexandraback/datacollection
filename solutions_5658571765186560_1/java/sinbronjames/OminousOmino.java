import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class OminousOmino
{

	public static void main(String[] args) throws FileNotFoundException
	{
		Scanner in = new Scanner(new File("D-large.in"));
		PrintWriter out = new PrintWriter("ominooutput");
		int T = in.nextInt();
		for (int test = 1; test <= T; test++)
		{
			int X = in.nextInt();
			int R = in.nextInt();
			int C = in.nextInt();

			if (X == 1)
			{
				out.println("Case #" + test + ": GABRIEL");
			}
			else if (X == 2)
			{
				if (R % 2 == 0 || C % 2 == 0)
					out.println("Case #" + test + ": GABRIEL");
				else
					out.println("Case #" + test + ": RICHARD");
			}
			else if (X == 3)
			{
				if ((R % 3 == 0 && C >= 2) || (C % 3 == 0 && R >= 2))
					out.println("Case #" + test + ": GABRIEL");
				else
					out.println("Case #" + test + ": RICHARD");
			}
			else if (X == 4)
			{
				if (R % 2 == 0 && C % 2 == 0)
				{
					if (R >= 4 && C >= 4)
					{
						out.println("Case #" + test + ": GABRIEL");
					}
					else
					{
						out.println("Case #" + test + ": RICHARD");
					}
				}
				else if (R % 4 == 0 && C % 2 == 1)
				{
					if (C >= 3)
						out.println("Case #" + test + ": GABRIEL");
					else
						out.println("Case #" + test + ": RICHARD");
				}
				else if (C % 4 == 0 && R % 2 == 1)
				{
					if (R >= 3)
						out.println("Case #" + test + ": GABRIEL");
					else
						out.println("Case #" + test + ": RICHARD");
				}
				else
				{
					out.println("Case #" + test + ": RICHARD");
				}
			}
			else if (X == 5)
			{
				if (R % 5 == 0 && C >= 4)
				{
					out.println("Case #" + test + ": GABRIEL");
				}
				else if (C % 5 == 0 && R >= 4)
				{
					out.println("Case #" + test + ": GABRIEL");
				}
				else
					out.println("Case #" + test + ": RICHARD");
			}
			else if (X == 6)
			{
				if (R % 6 == 0 && C >= 4)
				{
					out.println("Case #" + test + ": GABRIEL");
				}
				else if (C % 6 == 0 && R >= 4)
				{
					out.println("Case #" + test + ": GABRIEL");
				}
				else if ((R % 3 == 0 && R >= 6) && (C % 2 == 0 && C >= 4))
				{
					out.println("Case #" + test + ": GABRIEL");
				}
				else if ((C % 3 == 0 && C >= 6) && (R % 2 == 0 && R >= 4))
				{
					out.println("Case #" + test + ": GABRIEL");
				}
				else
				{
					out.println("Case #" + test + ": RICHARD");
				}

			}
			else if (X >= 7)
			{
				out.println("Case #" + test + ": RICHARD");
			}

		}
		out.close();
		in.close();

	}

}
