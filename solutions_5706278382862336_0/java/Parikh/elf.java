import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
public class elf {
  static long gcd(long a,long b)
  {
	  if (b==0)
		  return a;
	  return gcd(b,a%b);
  }
public static void main(String args[])throws IOException
{
	BufferedReader obj = new BufferedReader(new FileReader("D:\\A-small-attempt0.in"));
	PrintWriter prt = new PrintWriter(new FileWriter("D:\\output.txt"));
	String line = obj.readLine();
	int t = Integer.parseInt(line);
	for (int i=1;i<=t;i++)
	{
		prt.print("Case #"+ i+": ");
		line = obj.readLine();
		String str[] = line.split("/");
		long p = Long.parseLong(str[0]);
		long q = Long.parseLong(str[1]);
		long g  = gcd(p,q);
		p = p/g;
		q = q/g;
		long q2=q;
		long val = 2,ans=-1;
		for (int j=1;j<=40;j++)
		{
			if (q2%2==0)
				q2=q2/2;
		}
		if (q2!=1)
			{
			prt.println("impossible");
			continue;
			}
		for (int j=1;j<=40;j++)
		{
			if (val *p>=q)
			{
				ans = j;
				break;
			}
			else
				val = val*2;
		}
		prt.println(ans);
		
		
	  
}
	 obj.close();
	   prt.close();
}
}
