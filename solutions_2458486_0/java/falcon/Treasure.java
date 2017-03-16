package gcj2013;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Arrays;

public class Treasure 
{
	private final int totalKeys=201;
	private int N;
	private int[] inputKey;
	private int[][] outputKey;
	private int[] startKeys;
	
	private int[] memo;
	private int solve(int openMask)
	{
		if(Integer.bitCount(openMask)==N)
		{
			return +N;
		}
		else if(memo[openMask]!=-2)
			return memo[openMask];
		else
		{
			int ret=-1;
			int[] keysAval=new int[totalKeys];
			for(int i=0;i<startKeys.length;++i)
				++keysAval[startKeys[i]];
			for(int i=0;i<N;++i)
			{
				int test=1<<i;
				if( (openMask&test)>0)
				{
					--keysAval[inputKey[i]];
					for(int j=0;j<outputKey[i].length;++j)
						++keysAval[outputKey[i][j]];
				}
			}			
			for(int i=0;i<N;++i)
			{
				int test=1<<i;
				if( (openMask&test)==0)
				{
					if(keysAval[inputKey[i]]>0)
					{
						int nextMask=openMask|test;
						int t1=solve(nextMask);
						if(t1>=0)
						{
							ret=i;
							break;
						}						
					}
				}
			}
			memo[openMask]=ret;
			return ret;
		}
	}
	public String getVisOrder(int[] startKeys,int[] inputKey,int[][] outputKey)
	{
		this.N=inputKey.length;
		this.inputKey=inputKey;
		this.outputKey=outputKey;
		this.startKeys=startKeys;
		
		this.memo=new int[1<<N];
		Arrays.fill(memo,-2);
		int ret=solve(0);
		if(ret>=0)
		{
			String out="";
			int chosen=0;
			int curMask=0;
			while(chosen<N)
			{
				int val=memo[curMask];
				out+=(val+1)+" ";
				++chosen;
				curMask|=(1<<val);
			}
			return out.trim();
		}
		return null;
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
		Treasure obj=new Treasure();
		for(int t=1;t<=T;++t)
		{
			String[] tok=br.readLine().split(" ");
			int K=Integer.valueOf(tok[0]);
			int N=Integer.valueOf(tok[1]);
			tok=br.readLine().split(" ");
			int[] startKeys=new int[K];
			for(int i=0;i<K;++i)
				startKeys[i]=Integer.valueOf(tok[i]);
			int[][] outputKey=new int[N][];
			int[] inputKey=new int[N];
			for(int i=0;i<N;++i)
			{
				tok=br.readLine().split(" ");
				int Ti=Integer.valueOf(tok[0]);
				int Ki=Integer.valueOf(tok[1]);
				inputKey[i]=Ti;
				outputKey[i]=new int[Ki];
				for(int j=0;j<Ki;++j)
					outputKey[i][j]=Integer.valueOf(tok[2+j]);
			}
			String ret=obj.getVisOrder(startKeys, inputKey, outputKey);
			if(ret==null)
				ret="IMPOSSIBLE";
			System.out.println("Case #"+t+": "+ret);
		}

	}

}
