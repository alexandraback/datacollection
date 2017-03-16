import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class Inheritance {
	public static void main (String [] args) throws IOException {
	    BufferedReader f = new BufferedReader(new FileReader("A-small-attempt0.in"));
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-small-attempt.out")));
	    StringTokenizer st = new StringTokenizer(f.readLine());

	    int caseCt = Integer.parseInt(st.nextToken());

	    int nodeCt;
	    for(int i = 0; i < caseCt; i++){
	    	st = new StringTokenizer(f.readLine());
	    	
	    	nodeCt = Integer.parseInt(st.nextToken());
	    	int[][] edges = new int[nodeCt][11];
	    	boolean[] traveled = new boolean[nodeCt];
	    	boolean[] notRoot = new boolean[nodeCt]; //not a root
	    	for(int j = 0; j < nodeCt; j++){
	    		st = new StringTokenizer(f.readLine());
	    		int edgeCt = Integer.parseInt(st.nextToken());
	    		edges[j][0] = edgeCt;
	    		for(int k = 0; k < edgeCt; k++){
	    			edges[j][k+1] = Integer.parseInt(st.nextToken());
	    			notRoot[edges[j][k+1] - 1] = true;
	    		}
	    	}
	    	
			boolean done = false;
			
	    	for(int j = 0; j < nodeCt; j++){
	    		if(!notRoot[j]){
	    			LinkedList<Integer> toTravel = new LinkedList<Integer>();
	    			toTravel.add(j);
	    	    	traveled = new boolean[nodeCt];
	    			while(toTravel.size() > 0){
	    				int current = toTravel.remove();
	    				//System.out.println(current);
	    				traveled[current] = true;
	    				for(int k = 1; k <= edges[current][0]; k++){
	    					if(!traveled[edges[current][k] - 1]){
	    						toTravel.add(edges[current][k] - 1);
	    						traveled[edges[current][k] - 1] = true;
	    					}  else {
	    						out.println("Case #" + (i+1) + ": Yes");
	    						done = true;
	    						break;
	    					}
	    				}
	    				if(done){
	    					break;
	    				}
	    			}
	    			if(done){
	    				break;
	    			}
	    		}
	    	}
	    	
	    	if(!done){
	    		out.println("Case #" + (i+1) + ": No");
	    	}
	    	
	    }
	    
	    out.close();
	    System.exit(0);
	}
}
