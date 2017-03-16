import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class FS {
	public static void main(String args[]) throws FileNotFoundException
	{
		Scanner fin = new Scanner(new File("in.txt"));
		int T;
		BigInteger thenums[] = new BigInteger[1000];
		int thenum = 0;
		
		int s = 10000000;
		for (int i = 1; i <= s; ++i)
		{
			String ssi = String.valueOf(i);
			boolean flag1 = true;
			for (int j = 0; j < ssi.length()/2; ++j)
			{
				if (ssi.charAt(j) != ssi.charAt(ssi.length() - j - 1))
				{
					flag1 = false;
					break;
				}
			}
			if (!flag1)
				continue;
			
			
			BigInteger ss = BigInteger.valueOf(i);
			ss = ss.multiply(ss);
			String sss = ss.toString();
			boolean flag = true;
			for (int j = 0; j < sss.length()/2; ++j)
			{
				if (sss.charAt(j) != sss.charAt(sss.length() - j - 1))
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				thenums[thenum++] = ss;
			}
		}
		PrintWriter  fout = new PrintWriter("out.txt");

		T = fin.nextInt();
		for (int i = 0; i < T; ++i)
		{
			String sa, sb;
			sa = fin.next();
			sb = fin.next();
			int countit = 0;
			BigInteger a = new BigInteger(sa);
			BigInteger b = new BigInteger(sb);
			for (int j = 0; j < thenum; ++j)
			{
				if (a.compareTo(thenums[j])<=0 && b.compareTo(thenums[j])>=0)
				{
				//	System.out.println(sa +":"+thenums[j] +":" + sb); 
					countit ++;
				}
			}
			fout.println("Case #" + String.valueOf(i + 1) + ": " + String.valueOf(countit));
		}
		fin.close();
		fout.close();
	}
}
