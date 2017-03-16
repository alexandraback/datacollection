import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeMap;

public class Technobabble {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for(int cn=1; cn<=T;cn++){
			int N=sc.nextInt();
			TreeMap<String,Integer> map1=new TreeMap<String,Integer>();
			TreeMap<String,Integer> map2=new TreeMap<String,Integer>();
			int w1[]=new int[N];
			int w2[]=new int[N];
			for(int i=0;i<N;i++){
				String s1=sc.next();
				if(!map1.containsKey(s1))
					map1.put(s1, map1.size());
				w1[i]=map1.get(s1);
				
				String s2=sc.next();
				if(!map2.containsKey(s2))
					map2.put(s2, map2.size());
				w2[i]=map2.get(s2);
			}
			m=map1.size();
			n=map2.size();
			graph=new boolean[m][n];
			seen=new boolean[n];
			matchL=new int[m];
			matchR=new int[n];
			
			for(int i=0;i<N;i++){
				graph[w1[i]][w2[i]]=true;
			}
//			System.out.println(maximumMatching());
			

			int ans=maximumMatching();
			for(int i:matchL){
				if(i==-1)
					ans++;
			}
			for(int i:matchR){
				if(i==-1)
					ans++;
			}
			
			
			
			System.out.print("Case #"+cn+": "+(N-ans)); 
			System.out.println();
		}
	}

    static int m, n;
    static boolean[][] graph;
    static boolean seen[];
    static int matchL[];   //What left vertex i is matched to (or -1 if unmatched)
    static int matchR[];   //What right vertex j is matched to (or -1 if unmatched)

    static int maximumMatching() {
        //Read input and populate graph[][]
        //Set m to be the size of L, n to be the size of R
        Arrays.fill(matchL, -1);
        Arrays.fill(matchR, -1);

        int count = 0;
        for (int i = 0; i < m; i++) {
            Arrays.fill(seen, false);
            if (bpm(i)) count++;
        }
        return count;
    }

    static boolean bpm(int u) {
        //try to match with all vertices on right side
        for (int v = 0; v < n; v++) {
            if (!graph[u][v] || seen[v]) continue;
            seen[v] = true;
            //match u and v, if v is unassigned, or if v's match on the left side can be reassigned to another right vertex
            if (matchR[v] == -1 || bpm(matchR[v])) {
                matchL[u] = v;
                matchR[v] = u;
                return true;
            }
        }
        return false;
    }
	
	
	
	
}
