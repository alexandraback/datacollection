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
		Scanner file = new Scanner(new File("A-small.in"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("out.txt")));
		int zz = file.nextInt();file.nextLine();
		for(int i = 1;i<=zz;i++)
		{
			char[] next = file.nextLine().toCharArray();
			String ans = "";
			for(int j = 0;j<next.length;j++)
			{
				if(ans.isEmpty())
				{
					ans+=next[j];
					continue;
				}
				if(ans.charAt(0)<=next[j])
				{
					ans = next[j]+ans;
				}else
					ans+=next[j];
			}
			out.printf("Case #%d: %s%n",i,ans);
		}
		out.close();
	}
}
