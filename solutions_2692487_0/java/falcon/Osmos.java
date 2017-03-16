package gcj2013;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Hashtable;

public class Osmos 
{
	private int[] inp;
	private int N;
	private Hashtable<Long,Long> memo;
	private long solve(long curSize)
	{
		if(memo.get(curSize)!=null)
			return memo.get(curSize);
		else
		{
			long ret=N;
			int npidx=-1;
			for(int i=0;i<N;++i)
			{
				if(curSize<=inp[i])
				{
					npidx=i;
					break;
				}				
			}
			if(npidx<0)
				ret=0;
			else
			{
				int extraNeeded=0;
				long nextSize=curSize;
				while(nextSize>1 && nextSize<=inp[npidx])
				{
					++extraNeeded;
					nextSize+=(nextSize-1);
				}
				long t1=N,t2=N;
				if(curSize>1)
				{
					for(int idx=npidx;idx<N;++idx)
					{
						if(nextSize>inp[idx])
							nextSize+=inp[idx];
					}
					t1=extraNeeded+solve(nextSize);
				}
				t2=N-npidx;
				ret=Math.min(ret,t1);
				ret=Math.min(ret,t2);				
			}
			memo.put(curSize,ret);
			return ret;
		}
	}
	private long getMinOperations(int[] inp,int A,int N)
	{
		this.N=N;
		this.inp=inp;
		Arrays.sort(this.inp);
		int curSize=A;
		for(int i=0;i<N;++i)
		{
			if(inp[i]<curSize)
			{
				curSize+=inp[i];
			}				
		}
		this.memo=new Hashtable<Long, Long>();
		long ret=solve(curSize);
		return ret;
	}

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException 
	{
		BufferedReader br=null;
		if(args.length>=1)
			br=new BufferedReader(new FileReader(new File(args[0])));
		else
			br=new BufferedReader(new InputStreamReader(System.in));
		if(args.length>=2)
			System.setOut(new PrintStream(new FileOutputStream(args[1])));
		int T=Integer.valueOf(br.readLine().trim());
		Osmos obj=new Osmos();
		for(int t=1;t<=T;++t)
		{
			String[] tok=br.readLine().split(" ");
			int A=Integer.valueOf(tok[0]);
			int N=Integer.valueOf(tok[1]);
			tok=br.readLine().split(" ");
			int[] inp=new int[N];
			for(int i=0;i<N;++i)
				inp[i]=Integer.valueOf(tok[i]);
			long ret=obj.getMinOperations(inp, A, N);
			System.out.println("Case #"+t+": "+ret);		
		}

	}

}