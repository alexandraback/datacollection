import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
	
	public static void main(String[] args) throws IOException
	{
		Scanner file = new Scanner(new File("b-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("out.txt")));
		int zz = file.nextInt();
		for(int i = 1;i<=zz;i++)
		{
			char[] str = file.next().toCharArray();
			int flips = 0;
			while(true)
			{
				int f = find('-',str);
				if(f==-1)
					break;
				else if(f==0)
				{
					int x = 0;
					while(x<str.length&&str[x]=='-')
						str[x++] = '+';
				}
				else
				{
					for(int x = 0;x<f;x++)
						str[x] = '-';
				}
				flips++;
			}
			out.printf("Case #%d: %d%n",i,flips);
		}
		out.close();
	}
	
	public static int find(char ch, char[] str)
	{
		for(int i = 0;i<str.length;i++)
			if(str[i]==ch)
				return i;
		return -1;
	}
	
}
