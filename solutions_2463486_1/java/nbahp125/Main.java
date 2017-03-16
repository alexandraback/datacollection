import java.util.*;
import java.math.*;
import java.io.*;
public class Main {

	public static void main(String[] args) 
	{
		try
		{
		Scanner in = new Scanner(System.in);
		BigInteger[] a=new BigInteger[100];
		BufferedWriter bw = new BufferedWriter(new FileWriter(new File("d:\\aa.txt")));
		a[0] = new BigInteger("0");
		int c = 1;
		for(int i=1;i<10000000;i++)
			if(isHuiwen(String.valueOf(i)))
			{
				BigInteger bi = BigInteger.valueOf(i);
				bi = bi.pow(2);
				if(isHuiwen(bi.toString()))
					a[c++]=bi;
			}
		System.out.println("done");
		int t = in.nextInt();
		for(int tt=1;tt<=t;tt++){
			String m = in.next();
			String n = in.next();
			BigInteger b = new BigInteger(m);
			
			int s=0;
			for(;s<c;s++)
				if(b.compareTo(a[s])<=0)
					break;
			b = new BigInteger(n).add(new BigInteger("1"));
			int e=s;
			for(;e<c;e++)
				if(b.compareTo(a[e])<=0)
					break;
			bw.write(("Case #"+tt+": "+(e-s)));
			bw.newLine();
		}
		bw.flush();
		bw.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
			
	}
	public static boolean isHuiwen(String s)
	{
		StringBuilder sb = new StringBuilder();
		for(int i=s.length()-1;i>=0;i--)
			sb.append(s.charAt(i));
		return s.equals(sb.toString());
			
	}

}
