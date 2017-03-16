import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class Technobabble 
{
	
    static boolean bpm(int M, int N, boolean bpGraph[][], int u, boolean seen[],
                int matchR[])
    {
        for (int v = 0; v < N; v++)
        {
            if (bpGraph[u][v] && !seen[v])
            {
                seen[v] = true; // Mark v as visited
                if (matchR[v] < 0 || bpm(M, N, bpGraph, matchR[v],
                                         seen, matchR))
                {
                    matchR[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
 
    // Returns maximum number of matching from M to N
    static int[] maxBPM(int M, int N, boolean bpGraph[][])
    {
        // An array to keep track of the applicants assigned to
        // jobs. The value of matchR[i] is the applicant number
        // assigned to job i, the value -1 indicates nobody is
        // assigned.
        int matchR[] = new int[N];
 
        // Initially all jobs are available
        for(int i=0; i<N; ++i)
            matchR[i] = -1;
 
        int jobs = 0; // Count of jobs assigned to applicants
        for (int u = 0; u < M; u++)
        {
            // Mark all jobs as not seen for next applicant.
            boolean seen[] =new boolean[N] ;
            for(int i=0; i<N; ++i)
                seen[i] = false;
 
            // Find if the applicant 'u' can get a job
            if (bpm(M, N, bpGraph, u, seen, matchR))
                jobs++;
        }
        return matchR;
    }
 
    
    static int doWork(int M, int N, boolean bpGraph[][], ArrayList<int[]> edges){
    	int count = 0;
    	int[] matchR = maxBPM(M, N, bpGraph);
    	boolean[] left = new boolean[M];
    	boolean[] right = new boolean[N];
    	for (int i=0; i<N; i++){
    		if (matchR[i] > -1){
    			right[i] = true;
    			left[matchR[i]] = true;
    			count++;
    		}
    	}
    	for (int[] E : edges){
    		if (!(left[E[0]] && right[E[1]])){
    			left[E[0]] = true;
    			right[E[1]] = true;
    			count++;
    		}    		
    	}
    	return edges.size() - count;
    	
    }
    
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i=0; i < T; i++)
		{
			int N = sc.nextInt();
			HashMap[] V = {new HashMap<String, Integer>(), new HashMap<String, Integer>()};
			int[] counts = {0, 0};
			ArrayList<int[]> edges = new ArrayList<int[]>();
			for (int j=0; j<N; j++){
				String [] edge = new String[2];
				for (int k = 0; k< 2; k++){
					edge[k] = sc.next();
					if (!V[k].containsKey(edge[k])){						
						V[k].put(edge[k], counts[k]);
						counts[k]++;
					}
				}
				int[] E = {(Integer) V[0].get(edge[0]), (Integer) V[1].get(edge[1])};
				edges.add(E);				
			}			
			int m = counts[0];
			int n = counts[1];
			boolean[][] graph = new boolean[m][];
			for (int j=0; j<m; j++){
				graph[j] = new boolean[n];
			}
			for (int[] E: edges){
				graph[E[0]][E[1]] = true;
			}
			/*
			for (int j =0; j<m; j++){
				for (int k =0; k<n; k++){
					System.out.print(graph[j][k]?'x':'-');
				}
				System.out.println();
			}
			*/
			System.out.println("Case #" + (i+1) +": " + doWork(m, n, graph, edges));
		}
		sc.close();
		
	}
}
 



