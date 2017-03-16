package gcj;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Arrays;

public class RecycledNumbers {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception
	{
		BufferedReader br=null;
		if(args.length>=1)
			br=new BufferedReader(new FileReader(new File(args[0])));
		else
			br=new BufferedReader(new InputStreamReader(System.in));
		if(args.length>=2)
			System.setOut(new PrintStream(new FileOutputStream(args[1])));
		int T=Integer.valueOf(br.readLine().trim());
		for(int t=1;t<=T;++t)
		{
			String[] temp=br.readLine().trim().split(" ");
			int A=Integer.valueOf(temp[0]);
			int B=Integer.valueOf(temp[1]);
			int ret=0;
			int[] seen=new int[8];
			for(int m=A;m<=B;++m)
			{
				String mi=""+m;
				int yes=0;
				Arrays.fill(seen,-1);
				for(int k=0;k<=mi.length();++k)
				{
					String front=mi.substring(k);
					String back=mi.substring(0,k);
					if(front.length()==0 || back.length()==0)
						continue;
					int n=Integer.valueOf(front+back);
					if(A<=m && m<n && n<=B && mi.length()==Integer.toString(n).length())
					{
						boolean go=true;
						for(int p=0;p<k;++p)
						{
							if(seen[p]==n)
							{
								go=false;
								break;
							}
						}
						if(go)
						{
							seen[k]=n;
							++yes;
						}				
					}
				}
				ret+=yes;			
			}
			System.out.println("Case #"+t+": "+ret);		
		}
		br.close();
	}

}
