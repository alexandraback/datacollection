import java.util.*;
import java.io.*;

public class cja {
	
	public static void main(String[] args) throws Exception {
		
		Scanner qwe = new Scanner(System.in);
		BufferedWriter out = new BufferedWriter(new FileWriter("a.out"));
		
		int T = qwe.nextInt();
		
		for(int z = 1; z <= T; z++)
		{
			int A = qwe.nextInt();
			int N = qwe.nextInt();
			
			int[] ms = new int[N];
			
			for(int i =0; i < N; i++)
				ms[i]=  qwe.nextInt();
			
			int ans = N;
			
			if(A != 1)
			{
				Arrays.sort(ms);
				int cur = N;
				
				for(int i =0; i < N; i++)
				{
					
					
					cur--;
					while(A <= ms[i])
					{
						A = 2*A -1;
						cur++;
					}
					
					A += ms[i];
						
					ans = Math.min(ans,cur);
				}
				
			}
			
			out.write("Case #" + z + ": " + ans +"\n");
		}
		
		
		out.close();
	}
	
	
	

}
