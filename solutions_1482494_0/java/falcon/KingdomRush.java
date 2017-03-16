package gcj.r1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class KingdomRush {

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
			int N=Integer.valueOf(br.readLine().trim());
			int[] oneStarReq=new int[N];
			int[] twoStarReq=new int[N];
			for(int i=0;i<N;++i)
			{
				String[] tok=br.readLine().split(" ");
				oneStarReq[i]=Integer.valueOf(tok[0]);
				twoStarReq[i]=Integer.valueOf(tok[1]);
			}
			
			boolean[] oneStardone=new boolean[N];
			boolean[] twoStardone=new boolean[N];
			int ret=0;
			int currentStars=0;
			
			while(true)
			{
				boolean allDone=true;
				for(int i=0;i<N;++i)
					allDone&=twoStardone[i];
				if(allDone)
					break;
				else
				{
					//if two stars are possible and levels not attempted before always do it.
					boolean isPossible=false;
					for(int i=0;i<N;++i)
					{
						if(!twoStardone[i] && !oneStardone[i] && twoStarReq[i]<=currentStars)
						{
							++ret;
							oneStardone[i]=true;
							twoStardone[i]=true;
							currentStars+=2;
							isPossible=true;
							break;
						}
					}
					if(!isPossible)
					{
						//if oneStar is done and twoStar is possible always do it
						for(int i=0;i<N;++i)
						{
							if(oneStardone[i] && !twoStardone[i] && twoStarReq[i]<=currentStars)
							{
								++ret;
								twoStardone[i]=true;
								++currentStars;
								isPossible=true;
								break;
							}
						}
						if(!isPossible)
						{
							//see if oneStar is possible and go for the one with maximum twoStarsReq
							int maxTwoStarReq=0;
							int maxIdx=-1;
							for(int i=0;i<N;++i)
							{
								if(!twoStardone[i] && !oneStardone[i] && oneStarReq[i]<=currentStars)
								{
									if(twoStarReq[i]>maxTwoStarReq)
									{
										maxTwoStarReq=twoStarReq[i];
										maxIdx=i;
										isPossible=true;
									}
									
								}
							}
							
							if(isPossible)
							{
								++ret;
								oneStardone[maxIdx]=true;
								++currentStars;					
							}
							
							if(!isPossible)
							{
								ret=-1;
								break;
							}
						}					
					}					
				}
			}
			if(ret==-1)
				System.out.println("Case #"+t+": Too Bad");
			else
				System.out.println("Case #"+t+": "+ret);
		}
		
		br.close();


	}

}
