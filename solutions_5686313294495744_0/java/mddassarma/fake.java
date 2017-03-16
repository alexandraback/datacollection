import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Queue;

public class fake {

	public static void main(String[] args) throws IOException{
		BufferedReader buf=new BufferedReader(new FileReader("fake.in"));
		PrintWriter printer=new PrintWriter("fake.out");
		int T=Integer.parseInt(buf.readLine());
		for(int i=1;i<=T;i++){
			int answer=0;
			int N=Integer.parseInt(buf.readLine());
			int[][] edges=new int[N][2];
			HashMap<String, Integer> firstmap=new HashMap<String,Integer>();
			int atf = 0;
			HashMap<String, Integer> secondmap=new HashMap<String,Integer>();
			int ats = 0;
			for(int j=0;j<N;j++){
				String[] ss=buf.readLine().split(" ");
				if(firstmap.containsKey(ss[0]))
					edges[j][0]=firstmap.get(ss[0]);
				else{
					edges[j][0]=atf;
					firstmap.put(ss[0], atf++);
				}
				if(secondmap.containsKey(ss[1]))
					edges[j][1]=secondmap.get(ss[1]);
				else{
					edges[j][1]=ats;
					secondmap.put(ss[1], ats++);
				}
			}
			boolean[][] graph=new boolean[atf][ats];
			for(int j=0;j<edges.length;j++)
				graph[edges[j][0]][edges[j][1]]=true;
			int[] matchL = new int[atf];
			int[] matchR = new int[ats];
			Arrays.fill(matchL, -1);
	        Arrays.fill(matchR, -1);
	        boolean[] seen=new boolean[Math.max(atf, ats)];
	        
	        int count = 0;
	        for (int j = 0; j < atf; j++) {
	            Arrays.fill(seen, false);
	            if (bpm(j,atf,ats,graph,seen,matchL,matchR)) count++;
	        }
	        for(int j=0;j<matchL.length;j++){
	        	if (matchL[j]==-1)
	        		count++;
	        }
	        for(int j=0;j<matchR.length;j++){
	        	if(matchR[j]==-1)
	        		count++;
	        }
			answer=N-count;
			printer.println("Case #"+i+": "+answer);
		}
		printer.close();
	}
	/**
	 * Code for the dfs adopted from maxbipartitematching.java (irpap github)
	 * @param u
	 * @param m
	 * @param n
	 * @param graph
	 * @param seen
	 * @param matchL
	 * @param matchR
	 * @return
	 */
    static boolean bpm(int u,int m,int n,boolean[][] graph,boolean[] seen,int[] matchL,int[] matchR) {
        //try to match with all vertices on right side
        for (int v = 0; v < n; v++) {
            if (!graph[u][v] || seen[v]) continue;
            seen[v] = true;
            //match u and v, if v is unassigned, or if v's match on the left side can be reassigned to another right vertex
            if (matchR[v] == -1 || bpm(matchR[v],m,n,graph,seen,matchL,matchR)) {
                matchL[u] = v;
                matchR[v] = u;
                return true;
            }
        }
        return false;
    }

}


