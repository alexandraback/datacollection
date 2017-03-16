import java.io.PrintStream;
import java.util.Scanner;

public class Main
{
	private static Scanner in = new Scanner(System.in);
	private static PrintStream out = System.out;

	public static void main(String[] args)
	{
		int current = in.nextInt() + 1;
		for (int i = 1; i < current; i++)
		{
			out.println("Case #" + i + ":");
			check(i);
		}
	}

	private static void check(int current)
	{
		int r = in.nextInt();
		int c = in.nextInt();
		int m = in.nextInt();

		if (r == 1)
		{
			String str = "c";
			for (int i = c - m - 1; i > 0; i--)
			{
				str += ".";
			}
			for (int i = m; i > 0; i--)
			{
				str += "*";
			}

			out.println(str);
		}
		else if (c == 1)
		{
			String str = "c\n";
			for (int i = r - m - 1; i > 0; i--)
			{
				str += ".\n";
			}
			for (int i = m; i > 0; i--)
			{
				str += "*\n";
			}

			out.print(str);
		}
		else if (c * r - m == 1)
		{
			out.print("c");
			for (int i = c - 1; i > 0; i--)
			{
				out.print("*");
			}
			out.println();

			for (int i = r - 1; i > 0; i--)
			{
				for (int j = c; j > 0; j--)
				{
					out.print("*");
				}
				out.println();
			}
		}
		else if (c * r - m == 5 || c * r - m == 7)
		{
			out.println("Impossible");
		}
		else if (c * r - m > 3)
		{
			if (r == 2)
			{
				if ((c * r - m) % 2 == 0)
				{
					int t = (c * r - m) / 2;

					out.print("c");
					for (int i = 1; i < t; i++)
					{
						out.print(".");
					}
					for (int i = t; i < c; i++)
					{
						out.print("*");
					}
					out.println();

					for (int i = 0; i < t; i++)
					{
						out.print(".");
					}
					for (int i = t; i < c; i++)
					{
						out.print("*");
					}
					out.println();
				}
				else
				{
					out.println("Impossible");
				}
			}
			else if (c == 2)
			{
				if ((c * r - m) % 2 == 0)
				{
					int t = (c * r - m) / 2;

					out.println("c.");

					for (int i = ((c * r) - m) / 2 - 1; i > 0; i--)
					{
						out.println("..");
					}

					for (int i = m / 2; i > 0; i--)
					{
						out.println("**");
					}
				}
				else
				{
					out.println("Impossible");
				}
			}
			else if ((c * r - m) / c < 2)
			{
				if ((c * r - m) % 2 == 0)
				{
					int t = (c * r - m) / 2;

					out.print("c");
					for (int i = 1; i < t; i++)
					{
						out.print(".");
					}
					for (int i = t; i < c; i++)
					{
						out.print("*");
					}
					out.println();

					for (int i = 0; i < t; i++)
					{
						out.print(".");
					}
					for (int i = t; i < c; i++)
					{
						out.print("*");
					}
					out.println();

					for (int i = 2; i < r; i++)
					{
						for (int j = 0; j < c; j++)
						{
							out.print("*");
						}
						out.println();
					}
				}
				else
				{
					int t = (c * r - m - 3) / 2;

					out.print("c");
					for (int i = 1; i < t; i++)
					{
						out.print(".");
					}
					for (int i = t; i < c; i++)
					{
						out.print("*");
					}
					out.println();

					for (int i = 0; i < t; i++)
					{
						out.print(".");
					}
					for (int i = t; i < c; i++)
					{
						out.print("*");
					}
					out.println();

					out.print("...");
					for (int i = 3; i < c; i++)
					{
						out.print("*");
					}
					out.println();

					for (int i = 3; i < r; i++)
					{
						for (int j = 0; j < c; j++)
						{
							out.print("*");
						}
						out.println();
					}
				}
			}
			else if ((c * r - m) % c == 1)
			{
				if ((c * r - m) / c == 2)
				{
					out.print("c");
					for (int i = 2; i < c; i++)
					{
						out.print(".");
					}
					out.println("*");

					for (int i = 1; i < c; i++)
					{
						out.print(".");
					}
					out.println("*");

					out.print("...");
					for (int i = 3; i < c; i++)
					{
						out.print("*");
					}
					out.println();

					for (int i = 3; i < r; i++)
					{
						for (int j = 0; j < c; j++)
						{
							out.print("*");
						}
						out.println();
					}

				}
				else
				{
					out.print("c");
					for (int i = 1; i < c; i++)
					{
						out.print(".");
					}
					out.println();

					for (int i = ((r * c - m) / c) - 2; i > 0; i--)
					{
						for (int j = 0; j < c; j++)
						{
							out.print(".");
						}
						out.println();
					}

					for (int i = 1; i < c; i++)
					{
						out.print(".");
					}
					out.println("*");

					out.print("..");
					for (int i = 2; i < c; i++)
					{
						out.print("*");
					}
					out.println();

					for (int i = 3; i < r; i++)
					{
						for (int j = 0; j < c; j++)
						{
							out.print("*");
						}
						out.println();
					}
				}
			}
			else
			{
				int space = c * r - m - 1;

				out.print("c");
				for (int i = c - 1; i > 0; i--)
				{
					if (space-- > 0)
						out.print(".");
					else
						out.print("*");
				}
				out.println();

				for (int i = r - 1; i > 0; i--)
				{
					for (int j = c; j > 0; j--)
					{
						if (space-- > 0)
							out.print(".");
						else
							out.print("*");
					}
					out.println();
				}
			}
		}
		else
		{
			out.println("Impossible");
		}
	}
}
