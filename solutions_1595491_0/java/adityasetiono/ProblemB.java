import java.io.*;
import java.util.*;

public class ProblemB
{
	public static void main(String[] args)
	{
		String txtfile="B-small-attempt1.in";
		try
		{
			Scanner scan = new Scanner(new FileInputStream(txtfile));
			FileWriter fstream = new FileWriter("B-small-attempt1.out");
			BufferedWriter out = new BufferedWriter(fstream);
			int T = scan.nextInt();
			int N,S,p;
			int[] t ;
			int max=0;

			for (int X=1;X<=T;X++)
			{
				max = 0;
				N = scan.nextInt();
				S = scan.nextInt();
				p = scan.nextInt();
				t = new int[N];
				for (int i=0;i<N;i++)
				{
					t[i] = scan.nextInt();
				}

				Arrays.sort(t);
				int a,b;
				for (int i=N-1;i>=0;i--)
				{
					a = t[i] / 3;
					b = t[i] % 3;
					if (a>=p)
						max++;
					else if (p-a<=2)
					{
						if (b>0) a++;
						if (a<p && t[i]>0)
						{
							if (p-a==1 && b==0 && S>0)
							{
								a++;
								S--;
							}
							else if (b==2 && S>0)
							{
								a++;
								S--;
							}
						}
						if (a>=p) max++;

					}
				}
				out.write("Case #" + X + ": " + max + "\n");
			}
			out.close();
		}
		catch (Exception ex)
		{
			System.out.println(ex);
			System.exit(1);
		}

	}
}