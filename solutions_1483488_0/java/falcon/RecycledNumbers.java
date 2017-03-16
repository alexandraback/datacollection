package gcj;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintStream;

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
			for(int i=A;i<=B;++i)
			{
				for(int j=i+1;j<=B;++j)
				{
					String ai=""+i;
					String bj=""+j;
					if(ai.length()!=bj.length())
						continue;
					boolean yes=false;
					for(int k=0;k<ai.length();++k)
					{
						String front=ai.substring(k);
						String back=ai.substring(0,k);
						if(front.length()==0 ||back.length()==0)
							continue;
						if( (front+back).equals(bj))
						{
							yes=true;
							break;
						}						
					}
					if(yes)
						++ret;
							
				}
			}
			System.out.println("Case #"+t+": "+ret);
			
		}
		br.close();
		

	}

}
