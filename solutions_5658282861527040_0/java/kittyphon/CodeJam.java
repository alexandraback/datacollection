import java.util.Scanner;
import java.io.*;

public class CodeJam {
	
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new File("in.txt"));
		PrintStream out = new PrintStream(new File("out.txt"));
		int t=in.nextInt();
		for(int q=1;q<=t;q++)
		{
			out.print("Case #"+q+": ");
			int a=in.nextInt();
			int b=in.nextInt();
			int k=in.nextInt();
			int ans=0;
			for(int i=0;i<a;i++)
				for(int j=0;j<b;j++)
					if((i&j)<k)
						ans++;
			out.println(ans);
		}
		in.close();
		out.close();
	}
}
