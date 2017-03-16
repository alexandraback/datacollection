package jam;

public class Sol
	{
		int con[][];
		int cla[];
		
	
		public Sol(int[][] connections) {
			con = connections;
			cla = new int [con.length];
		}

		public String soln()
		{
			int i,j;
			j=0;
			for(i=0;i<cla.length;++i)
			{
				if(cla[i]==0)
				{
					j = solve(i,i+5);
				}
				if(j==-100)
				{
					return "Yes";
				}
			}
			return "No";
			
		}
		
		public int solve(int a,int b)
		{
			//System.out.println("solve "+a);
			int i,j;
			j = 0;
			if(cla[a] == b)
			{
				//System.out.println("return -100 ");
				return -100;
			}
			else
			{
				cla[a]=b;
				for(i=0;i<cla.length;++i)
				{
					if(con[i][a]==1)
					{
						//System.out.println("i " +  i +" a "+ a);
						j = solve(i,b);
						
					}
					if(j==-100)
					{
						return j;
					}
				}
			}
			return 100;
		}
}