import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
public class elf {
  static long gcd(long a,long b)
  {
	  if (b==0)
		  return a;
	  return gcd(b,a%b);
  }
public static void main(String args[])throws IOException
{
	BufferedReader obj = new BufferedReader(new FileReader("D:\\A-large.in"));
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
		String s1  = ""+p;
		BigInteger p1 = new BigInteger(s1);
		s1 = ""+q;
		BigInteger q1 = new BigInteger(s1);
		s1 = ""+val;
		BigInteger val1 = new BigInteger(s1);
		for (int j=1;j<=40;j++)
		{
			if (val1.multiply(p1).compareTo(q1)>=0)
			{
				ans = j;
				break;
			}
			else
				val1 = val1.multiply(BigInteger.valueOf(2));
		}
		prt.println(ans);
		
		
	  
}
	 obj.close();
	   prt.close();
}
}
