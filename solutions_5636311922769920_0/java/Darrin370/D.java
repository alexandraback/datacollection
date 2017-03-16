import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class D {
	
	public static void main(String[] args) throws IOException
	{
		Scanner file = new Scanner(new File("d-small.in"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("out.txt")));
		int zz = file.nextInt();
		for(int i = 1;i<=zz;i++)
		{
			int K = file.nextInt();
			int C = file.nextInt();
			int S = file.nextInt();
			long total = pow(K,C);
			long dif = pow(K,C-1);
			out.printf("Case #%d: ",i);
			for(int j = 0;j<K;j++)
			{
				out.print(dif*j+1+" ");
			}
			out.println();
		}
		out.close();
	}
	
	public static long pow(long K, int C)
	{
		if(C%2!=0)
			return K*pow(K*K,C/2);
		if(C==0)
			return 1;
		return pow(K*K,C/2);
	}
	
	public static int find(char ch, char[] str)
	{
		for(int i = 0;i<str.length;i++)
			if(str[i]==ch)
				return i;
		return -1;
	}
	
}
