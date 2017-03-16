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
				System.err.println(temp+"L,");
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
	public long getCount(long num)
	{
		this.num=new BigInteger(""+num);
		ret=0L;
		if(1<=num)
			++ret;
		if(4<=num)
			++ret;
		if(9<=num)
			++ret;
		for(int len=2;len<=16;++len)
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
	public int getCached(long A,long B)
	{
		long[] answers=new long[]{1L, 4L, 9L,
		121L,
		484L,
		10201L,
		40804L,
		12321L,
		44944L,
		14641L,
		1002001L,
		4008004L,
		1234321L,
		100020001L,
		400080004L,
		121242121L,
		102030201L,
		404090404L,
		123454321L,
		104060401L,
		125686521L,
		10000200001L,
		40000800004L,
		12102420121L,
		10221412201L,
		12345654321L,
		1000002000001L,
		4000008000004L,
		1210024200121L,
		1020304030201L,
		1232346432321L,
		1002003002001L,
		4004009004004L,
		1212225222121L,
		1022325232201L,
		1234567654321L,
		1004006004001L,
		1214428244121L,
		1024348434201L,
		100000020000001L,
		400000080000004L,
		121000242000121L,
		102012040210201L,
		123212464212321L,
		100220141022001L,
		121242363242121L,
		102234363432201L,
		123456787654321L};
		
		int ret=0;
		for(int i=0;i<answers.length;++i)
		{
			if(A<=answers[i] && answers[i]<=B)
				++ret;
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
			long ret=obj.getCached(A, B);
			System.out.println("Case #"+t+": "+ret);
					
		}
	}

}
