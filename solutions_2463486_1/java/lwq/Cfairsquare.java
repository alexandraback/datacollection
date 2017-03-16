import java.io.*;
import java.math.*;
import java.util.*;

public class Cfairsquare
{
	public static String reverse(String str)
	{
		return new StringBuilder(str).reverse().toString();
	}
	public static boolean palin(BigInteger i)
	{
		String str=i.toString();
		return str.equals(reverse(str));
	}
	public static void gen(ArrayList<BigInteger> list,String str,String rev,int digits,int two)
	{
		BigInteger s,s2;
		if( digits<=0 )
		{
			if( digits==0 ) s=new BigInteger(str+rev);
			else s=new BigInteger(str+rev.substring(1));
			s2=s.multiply(s);
			if( palin(s2)==true )
			{
				list.add(s2);
//				System.out.printf("%s\t\t%s\n",s,s2);
			}
			return;
		}
		String str2,rev2,digit;
		if( str.equals("")==false )
		{
			digit="0";
			str2=str+digit;
			rev2=digit+rev;
			gen(list,str2,rev2,digits-2,two);
		}
		digit="1";
		str2=str+digit;
		rev2=digit+rev;
		gen(list,str2,rev2,digits-2,two);
		if( two==0 )
		{
			digit="2";
			str2=str+digit;
			rev2=digit+rev;
			gen(list,str2,rev2,digits-2,1);
		}
	}
	public static <T extends Comparable<T>> int posFloor(ArrayList<T> list,T item)
	{
		int j,k,l;
		j=-1;
		k=list.size();
		while( j+1<k )
		{
			l=(j+k)/2;
			if( list.get(l).compareTo(item)<=0 ) j=l; else k=l;
		}
		return j;
	}
	public static <T extends Comparable<T>> int posCeil(ArrayList<T> list,T item)
	{
		int j,k,l;
		j=-1;
		k=list.size();
		while( j+1<k )
		{
			l=(j+k)/2;
			if( list.get(l).compareTo(item)<0 ) j=l; else k=l;
		}
		return k;
	}
	public static <T extends Comparable<T>> int count(ArrayList<T> list,T start,T end)
	{
		return posFloor(list,end)-posCeil(list,start)+1;
	}
	public static void main(String[] args) throws Exception
	{
		FileInputStream fin=new FileInputStream("c.in");
		FileOutputStream fout=new FileOutputStream("c.out");
		BufferedReader in=new BufferedReader(new InputStreamReader(fin));
		BufferedWriter out=new BufferedWriter(new OutputStreamWriter(fout));
		String i;
		BigInteger m,n;
		BigInteger nine=new BigInteger("9");
		ArrayList<BigInteger> b=new ArrayList<BigInteger>();
		for(int a=1;a<=24;a++) gen(b,"","",a,0);
		i=in.readLine();
		int tc=Integer.valueOf(i);
		for(int test=1;test<=tc;test++)
		{
			i=in.readLine();
			String[] j=i.split(" ");
			m=new BigInteger(j[0]);
			n=new BigInteger(j[1]);
			out.write("Case #"+test+": "+(count(b,m,n)+(m.compareTo(nine)<=0&&nine.compareTo(n)<=0?1:0))+"\n");
		}
		out.flush();
		fin.close();
		fout.close();
	}
}
