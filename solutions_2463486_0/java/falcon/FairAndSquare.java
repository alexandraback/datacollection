package gcj2013;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;

public class FairAndSquare
{
	private long ret;
	private int N;
	private char[] digits;
	private BigInteger num;
	private boolean isPalin(BigInteger inp)
	{
		String s1=inp.toString();
		String rev1=new StringBuffer(s1).reverse().toString();
		return s1.equals(rev1);
		
	}
	private void generate(int idx)
	{
		if(idx<0)
		{
			int lim=N/2;
			for(int i=0;i<lim;++i)
				digits[N-1-i]=digits[i];
			BigInteger temp=new BigInteger(new String(digits));
			temp=temp.multiply(temp);
			if(temp.compareTo(num)<=0 && isPalin(temp))
			{
				++ret;
			}
			return;				
		}
		else
		{
			for(int i=0;i<=2;++i)
			{
				if(idx==0 && i==0)
					continue;
				digits[idx]=(char) ('0'+i);
				generate(idx-1);
			}
		}
	}
	private long getCount(long num)
	{
		this.num=new BigInteger(""+num);
		ret=0L;
		if(1<=num)
			++ret;
		if(4<=num)
			++ret;
		if(9<=num)
			++ret;
		for(int len=2;len<=20;++len)
		{
			this.N=len;
			this.digits=new char[N];
			if(len%2==0)
				generate( (len/2)-1);
			else
				generate((len/2));
				
		}
		return ret;
	}
	public static void brute()
	{
		long total=0;
		for(long i=1;i<=100000000;++i)
		{
			long sq=i*i;
			
			String s1=Long.toString(i);
			String s2=Long.toString(sq);
			
			String rev1=new StringBuffer(s1).reverse().toString();
			String rev2=new StringBuffer(s2).reverse().toString();
			
			if(s1.equals(rev1) && s2.equals(rev2))
			{
				System.out.println(i+" "+sq);
				++total;
			}
		}
		System.err.println("Total Found = "+total);

	}

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException 
	{
		//brute();
		BufferedReader br=null;
		if(args.length>=1)
			br=new BufferedReader(new FileReader(new File(args[0])));
		else
			br=new BufferedReader(new InputStreamReader(System.in));
		if(args.length>=2)
			System.setOut(new PrintStream(new FileOutputStream(args[1])));
		int T=Integer.valueOf(br.readLine().trim());
		FairAndSquare obj=new FairAndSquare();
		for(int t=1;t<=T;++t)
		{
			String[] tok=br.readLine().split(" ");
			long A=Long.valueOf(tok[0]);
			long B=Long.valueOf(tok[1]);
			long ret=obj.getCount(B)-obj.getCount(A-1);
			System.out.println("Case #"+t+": "+ret);
					
		}
	}

}
