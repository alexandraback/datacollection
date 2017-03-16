import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;


public class Main 
{

	public static void main(String[] args) throws IOException 
	{
		new Main().doIt();
	}

	private void doIt() throws IOException 
	{
		Scanner sc = new Scanner(new File("in.txt"));
		PrintStream ps = new PrintStream(new File("out.txt"));
		
		int T = sc.nextInt();
		int a,b,k;
		for(int c=1;c<=T;c++)
		{
			a = sc.nextInt();
			b = sc.nextInt();
			k = sc.nextInt();
			int cnt = 0;
			for(int i=0;i<a;i++)
				for(int j=0;j<b;j++)
				{
					if((i&j) < k)
						cnt++;
				}
			ps.printf("Case #%d: %d\n",c,cnt);
		}
		
		sc.close();
		ps.close();
		
	}
	
	
}
