using System;
using System.IO;

namespace GCJ
{
	class MainClass
	{
		public static void Main ()
		{
			StreamReader SR = new StreamReader("B-large.in");
			StreamWriter SW = new StreamWriter("a.out");
		
			int T = int.Parse(SR.ReadLine());
			for(int tcase = 1; tcase <= T; tcase++)
			{
				int N = int.Parse(SR.ReadLine());
				int[] A = new int[N];
				int[] B = new int[N];
				for(int i = 0; i < N; i++)
				{
					string[] args = SR.ReadLine().Split(' ');
					A[i] = int.Parse(args[0]);
					B[i] = int.Parse(args[1]);
				}
				
				int count = 0, step = 0;
				int[] stat = new int[N];
				Array.Clear(stat, 0, N);

				while(true)
				{
					
					for(int i = 0; i < N; i++) if(stat[i] != 3 && B[i] <= count)
					{
						step++;
						count += (stat[i] == 1 ? 1 : 2);
						stat[i] = 3;
						i = -1;
					}
					
					int id = -1;
					for(int i = 0; i < N; i++) if(stat[i] == 0 && A[i] <= count)
					{
						if(id == -1) id = i;
						else if(B[i] > B[id]) id = i;
					}
					if(id == -1) break;
					count++;
					step++;
					stat[id] = 1;
				}
				
				for(int i = 0; i < N; i++) if(stat[i] != 3)
				{
					step = -1;
					break;
				}
				
				if(step == -1) SW.WriteLine("Case #{0}: Too Bad", tcase);
				else SW.WriteLine("Case #{0}: {1}", tcase, step);
			}
			SW.Close();
		}
	}
}
