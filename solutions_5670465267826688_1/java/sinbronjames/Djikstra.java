import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Djikstra
{

	public static void main(String[] args) throws FileNotFoundException
	{
		String digits = "  ijk";
		int[][] product = { { 1, 2, 3, 4 }, { 2, -1, 4, -3 }, { 3, -4, -1, 2 },
				{ 4, 3, -2, -1 } };

		Scanner in = new Scanner(new File ("C-large.in"));
		PrintWriter out = new PrintWriter ("djikstraoutput");
		int T = in.nextInt();
		for (int test = 1; test <= T; test++)
		{
			int L = in.nextInt();
			long X = in.nextLong();
			String quat = in.next();
			int[] partialProd = new int[L];
			int[] prodReverse = new int[L];
			int[] powers = new int[4];
			prodReverse[0] = 1;
			partialProd[0] = digits.indexOf(quat.charAt(0));
			for (int x = 1; x <= L - 1; x++)
			{
				int next = digits.indexOf(quat.charAt(x));
				if (partialProd[x - 1] < 0)
				{
					partialProd[x] = -product[-partialProd[x - 1] - 1][next - 1];
				}
				else
				{
					partialProd[x] = product[partialProd[x - 1] - 1][next - 1];
				}

			}
			for (int y = L - 1; y >= 1; y--)
			{
				int next = digits.indexOf(quat.charAt(y));
				int x = L - y;
				if (prodReverse[x - 1] < 0)
				{
					prodReverse[x] = -product[next - 1][-prodReverse[x - 1] - 1];
				}
				else
				{
					prodReverse[x] = product[next - 1][prodReverse[x - 1] - 1];
				}
			}
			powers[0] = 1;
			for (int i = 1; i <= 3; i++)
			{
				if (powers[i - 1] < 0 && partialProd[L - 1] < 0)
				{
					powers[i] = product[-powers[i - 1] - 1][-partialProd[L - 1] - 1];
				}
				else if (powers[i - 1] < 0 && partialProd[L - 1] > 0)
				{
					powers[i] = -product[-powers[i - 1] - 1][partialProd[L - 1] - 1];
				}
				else if (powers[i - 1] > 0 && partialProd[L - 1] < 0)
				{
					powers[i] = -product[powers[i - 1] - 1][-partialProd[L - 1] - 1];
				}
				else if (powers[i - 1] > 0 && partialProd[L - 1] > 0)
				{
					powers[i] = product[powers[i - 1] - 1][partialProd[L - 1] - 1];
				}
			}
			boolean found = false;
			if (powers[(int)(X % 4)] == -1)
			{
				for (int i = 0; i <= 3 && !found; i++)
				{
					for (int k = 0; k <= 3 && !found; k++)
					{

						for (int a = 0; a <= L - 1 && !found; a++)
						{
							for (int b = 0; b <= L - 1 && !found; b++)
							{
								if (i + k <= X - 2
										|| (i + k <= X - 1 && b >= a))
								{
									int first = 0;
									int third = 0;
									if (powers[i] < 0 && partialProd[a] < 0)
									{
										first = product[-powers[i] - 1][-partialProd[a] - 1];
									}
									else if (powers[i] < 0
											&& partialProd[a] > 0)
									{
										first = -product[-powers[i] - 1][partialProd[a] - 1];
									}
									else if (powers[i] > 0
											&& partialProd[a] < 0)
									{
										first = -product[powers[i] - 1][-partialProd[a] - 1];
									}
									else if (powers[i] > 0
											&& partialProd[a] > 0)
									{
										first = product[powers[i] - 1][partialProd[a] - 1];
									}
									if (powers[k] < 0
											&& prodReverse[L - 1 - b] < 0)
									{
										third = product[-prodReverse[L - 1 - b] - 1][-powers[k] - 1];
									}
									else if (powers[k] < 0
											&& prodReverse[L - 1 - b] > 0)
									{
										third = -product[prodReverse[L - 1 - b] - 1][-powers[k] - 1];
									}
									else if (powers[k] > 0
											&& prodReverse[L - 1 - b] < 0)
									{
										third = -product[-prodReverse[L - 1 - b] - 1][powers[k] - 1];
									}
									else if (powers[k] > 0
											&& prodReverse[L - 1 - b] > 0)
									{
										third = product[prodReverse[L - 1 - b] - 1][powers[k] - 1];
									}

									if (first == 2 && third == 4)
										found = true;
								}
							}
						}

					}

				}
			}

			if (found)
				out.println("Case #" + test + ": " + "YES");
			else
				out.println("Case #" + test + ": " + "NO");

		}
		out.close();
		in.close();

	}

}
