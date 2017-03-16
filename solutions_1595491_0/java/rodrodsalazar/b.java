import java.util.*;

class b
{
	public static void main(String [] args)
	{
	 	Scanner in = new Scanner(System.in);
	 	int T = in.nextInt();
	 	for(int t=1;t<=T;++t)
	 	{
	 		int N = in.nextInt();
	 		int S = in.nextInt();
	 		int p = in.nextInt();
	 		int max = 0;
	 		int trips [] = new int[N];
	 		for(int i=0;i<N;++i)
	 		{
	 			trips[i] = in.nextInt();
	 			int div3 = trips[i] / 3;
	 			int diff = trips[i] - div3*3;
	 			if(diff == 0)
	 			{
	 				if(div3 >= p)
	 				{
	 					max++;
	 				}
	 				else
	 				{
	 					if(S > 0 && div3+1 >= p && div3-1 >= 0)
	 					{
	 						max++;
	 						S--;
	 					}
	 				}
	 			}
	 			else if(diff == 1)
	 			{
	 				//Still need to allocate 1 more
	 				if(div3 >= p)
	 				{
	 					++max;
	 				}
	 				else if(div3+1 >= p)
	 				{
	 					++max;
	 				}
	 			}
	 			else if(diff == 2)
	 			{
	 				//Still need to allocate 2 more
	 				if(div3 >= p)
	 				{
	 					max++;
	 				}
	 				else
	 				{
	 					if(div3+1 >= p)
	 					{
	 						max++;
	 					}
	 					else if(S > 0 && div3+2 >= p)
	 					{
	 						max++;
	 						S--;
	 					}
	 				}
	 			}
	 		}
	 		System.out.println("Case #"+t+": " + max);
	 	}
	}
}
