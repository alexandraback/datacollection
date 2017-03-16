import java.util.*;

class A{

public static void main(String args[]){
	Scanner sc = new Scanner(System.in);
	int kase = sc.nextInt();
	for(int k = 1; k<=kase; k++){
		int N = sc.nextInt();
		adj = new ArrayList[N];
		for(int i = 0; i<N; i++){
			int M = sc.nextInt();
			adj[i] = new ArrayList<Integer>();
			for(int j = 0; j<M; j++)
				adj[i].add(sc.nextInt()-1);
		}
		boolean ret = false;
		for(int i  = 0; i< N; i++){
			visitted = new boolean[N];
			ret = ret || diamond(i);
		}
		System.out.println("Case #"+k+": "+(ret?"Yes":"No"));
	}
}

static boolean[] visitted;
static ArrayList<Integer>[] adj;


static boolean diamond(int i){
	visitted[i] = true;
	for(int j:adj[i]){
		if(visitted[j]) return true;
		if(diamond(j)) return true;
	}
	return false;
}



}
