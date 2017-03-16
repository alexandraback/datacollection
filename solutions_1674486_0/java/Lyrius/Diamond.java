import java.util.*;
import java.io.*;

class List extends LinkedList<Integer>{}
public class Diamond {
	
	// Variables preprocess
	

    static void preprocess() {
        
    }

    void solve(Scanner sc, PrintWriter pw) {
    	int N = sc.nextInt();
    	List[] voisins = new List[N];
    	boolean[] racines = new boolean[N];
    	List racine = new List();
    	for(int i=0;i<N;i++){
    		voisins[i]=new List();
    		int M = sc.nextInt();
    		while(M-->0){
    			int u = sc.nextInt()-1;
    			voisins[i].add(u);
    			racines[u]=true;
    		}
    	}
    	for(int i=0;i<N;i++){
    		if(!racines[i]){
    			racine.add(i);
    		}
    	}
    	boolean[] vu = new boolean[N];
    	boolean possible = false;
    	for(int i:racine){
    		Arrays.fill(vu, false);
    		possible = dfs(voisins,vu,i);
    		if(possible){break;}
    	}
    	if(possible){
    		pw.println("Yes");
    	}
    	else{
    		pw.println("No");
    	}
    }
    

    private boolean dfs(List[] voisins, boolean[] vu,
			int i) {
		vu[i]=true;
		for(int v:voisins[i]){
			if(vu[v]==true){
				return true;
			}
			if(!vu[v]){
				if(dfs(voisins,vu,v)){return true;}
			}
		}
		return false;
	}

	public static void main(String[] args) throws Exception {
        preprocess();

        Scanner sc = new Scanner(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new Diamond().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
