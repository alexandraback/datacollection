import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws IOException
	{
		Scanner file = new Scanner(new File("in.txt"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("out.txt")));
		int zz = file.nextInt();
		for(int i = 1;i<=zz;i++)
		{
			int N = file.nextInt();
			if(N==0)
			{
				out.printf("Case #%d: INSOMNIA%n",i);
				continue;
			}
			HashSet<Integer> set = new HashSet<Integer>();
			boolean[] vis = new boolean[10];
			int V = 0;
			int X = 0;
			while(V!=10)
			{
				X++;
				int Y = N*X;
				while(Y!=0)
				{
					if(!vis[Y%10])
					{
						vis[Y%10] = true;
						V++;
					}
					Y/=10;
				}
			}
			out.printf("Case #%d: %d%n",i,X*N);
		}
		out.close();
	}
}
