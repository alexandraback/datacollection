import java.util.ArrayList;
import java.util.Scanner;

public class BFFs {

	
		public static int max_path_to(int v, int exclude, ArrayList<Integer>[] binv)
		{
			int max = 1;
			for (int w: binv[v]){
				//System.out.println(w +" -> "+v);
				if(w != exclude)
				{
					int pathlen = max_path_to(w, exclude, binv) + 1;
					max = max > pathlen ? max : pathlen;
				}
			}
			return max;
		}
	
		public static int BFFs(int[] bffs){
			int n = bffs.length;
			
			//Get length of cycle starting with v, 0 = not in cycle, 1 not allowed
			boolean duplets_found = false;
			int longest_cycle = 0;
			int[] cycle_len = new int[n];
			ArrayList<Integer> duplets = new ArrayList<Integer>(); //store one from a duplet, i.e. mutual BFFs
			boolean[] examined = new boolean[n];
			for (int i=0; i<n; i++){
				if (!examined[i]){
					boolean[] visited = new boolean[n];				
					int v = i;			
					while (!visited[v]) {
						visited[v] = true;
						v = bffs[v];
					}	
					int loop_v = v;
					v = bffs[v];
					int len = 1;
					while (v != loop_v){
						v = bffs[v];
						len++;
					}
					v = bffs[v];
					while (v != loop_v){
						v = bffs[v];
						examined[v] = true;
						cycle_len[v] = len;
					}
					longest_cycle = (longest_cycle < len) ? len : longest_cycle;
				}				
			}
			for (int i=0; i<n; i++){
				//System.out.print(cycle_len[i]+" ");
				if (cycle_len[i] == 2)
				{
					duplets_found = true;
					duplets.add(i);
				}
			}
			//System.out.println("; longest: "+longest_cycle);
			//if (duplets_found){
				//System.out.println("Duplets: ");
				//for (int d : duplets) { System.out.println(d + " ");}
			//}
			
			//get inverse arrows
			ArrayList<Integer>[] binv = new ArrayList[n];
			for(int i=0; i<n; i++){
				binv[i] = new ArrayList<Integer>(); 
				for (int j=0; j<n; j++){
					if(bffs[j]==i){
						binv[i].add(j);
					}
				}
			}
			
			//get maximum by using duplets;
			int dmax = 0;
			for (int d : duplets)
			{
				int lpt = max_path_to(d, bffs[d], binv);
				//System.out.println("Longest path to " + d +" avoiding " + bffs[d]+": "+lpt);
				dmax += lpt;
			}
			//System.out.println("Total using duplets: "+dmax);						
			return Math.max(dmax, longest_cycle);
		}

		public static void main(String[] args)
		{
			Scanner sc = new Scanner(System.in);
			int T = sc.nextInt();
			for (int i=0; i < T; i++)
			{
				int N = sc.nextInt();
				int[] bffs = new int[N];
				for (int j=0; j<N; j++){
					bffs[j] = sc.nextInt()-1;
				}
				System.out.println("Case #" + (i+1) +": " + BFFs(bffs));
			}
			sc.close();
			
		}
		
}
