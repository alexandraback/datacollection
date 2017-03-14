import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Scanner;

public class CodeJamD
{
	public static void main(String args[]) throws Exception
	{
		Scanner in = new Scanner(new File("in.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
		int cases = in.nextInt();
		for(int casenum = 1;casenum <= cases;casenum++)
		{
			int H = in.nextInt();
			int W = in.nextInt();
			int D = in.nextInt();
			in.nextLine();
			in.nextLine();

			boolean x[][] = new boolean[2 * (H - 2)][2 * (W - 2)];
			int R = 0,C = 0;

			for(int n = 0;n < H - 2;n++)
			{
				String str = in.nextLine();
				for(int i = 0;i < W - 2;i++)
				{
					boolean b = false;
					if(str.charAt(i + 1) == 'X')
					{
						R = n;
						C = i;
						b = true;
					}
					x[n][i] = b;
					x[x.length - 1 - n][i] = b;
					x[n][x[0].length - 1 - i] = b;
					x[x.length - 1 - n][x[0].length - 1 - i] = b;
				}
			}
			in.nextLine();

			int count = 0;
			HashSet<String> set = new HashSet<String>();
			for(int a = -D;a <= D;a++)
			{
				for(int b = -D;b <= D;b++)
				{
					if(a * a + b * b > D * D)
						continue;
					if(a == 0 && b == 0)
						continue;

					if(x[(R + a + D * (x.length)) % (x.length)][(C + b + D * (x[0].length)) % (x[0].length)])
					{
						int gcf = gcf(a,b);
						int a2 = a/gcf;
						int b2 = b/gcf;
						String s = a2 + " " + b2;
						
						if(!set.contains(s))
						{
							set.add(s);
							count++;
						}
					}
				}
			}
			out.write("Case #" + casenum + ": " + count + "\n");
		}
		in.close();
		out.close();
	}

	public static int gcf(int a,int b)
	{
		if(a<0)
			a = -a;
		if(b<0)
			b = -b;
		if (b == 0) return a;
	    else return (gcf(b, a % b));
	}
}