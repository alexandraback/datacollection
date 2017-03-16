import java.io.*;
import java.util.*;

public class Diamond {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader input = null;
		BufferedWriter output = null;
		try {
			input = new BufferedReader(new FileReader("C:\\Users\\cerberus\\eclipse-workspace\\1C-A\\src\\A-large.in"));
			output = new BufferedWriter(new FileWriter("C:\\Users\\cerberus\\eclipse-workspace\\1C-A\\src\\outp"));
			Deque<Integer> stk = null;
			TreeMap<Integer, Vector<Integer>> inherit = null;
			TreeMap<Integer, Integer> visited = null;
			TreeMap<Integer, Vector<Integer>> parents = null;
			
			int T = Integer.valueOf(input.readLine());
		    for(int i=1; i<=T; i++) {
		    	int N = Integer.valueOf(input.readLine());
		    	inherit = new TreeMap<Integer, Vector<Integer>>();
		    	visited = new TreeMap<Integer, Integer>();
		    	parents = new TreeMap<Integer, Vector<Integer>>();
		    	output.write("Case #"+i+": ");
		    	
		    	for(int j=1; j<=N; j++) {
		    		String nums[] = input.readLine().split(" ");
			    	int n = Integer.valueOf(nums[0]);
			    	Vector<Integer> list = new Vector<Integer>();
			    	for(int k=1; k<=n; k++) {
			    		int m = Integer.parseInt(nums[k]);
			    		list.add(m);
			    		Vector<Integer> pa = parents.get(m);
			    		if(pa == null) {
			    			pa = new Vector<Integer>();
			    		}
			    		pa.add(j);
			    		parents.put(m, pa);
			    	}
			    	inherit.put(j, list);
			    	visited.put(j, 0);
		    	}
		    	Vector<Integer> acpat = new Vector<Integer>();
		    	for(int j=1; j<=N; j++) {
		    		if(parents.get(j) == null) acpat.add(j);
		    	}
		    	Vector<Integer> acp = new Vector<Integer>();
		    	for(int tem: acpat) {
		    		while(inherit.get(tem).size() < 2) {
		    			if(inherit.get(tem).size() == 1)
		    				tem = inherit.get(tem).firstElement();
		    			else
		    				break;
		    		}
		    		if(inherit.get(tem).size() > 1)
		    			acp.add(tem);		    		
		    	}
		    	
		    	boolean hasDiamond = false;
		    	for(int j=0; j<acp.size(); j++) {
			    	stk = new ArrayDeque<Integer>();
			    	stk.push(acp.get(j));
			    	for(int k=1; k<=N; k++)
			    		visited.put(k, 0);
			    	while(!stk.isEmpty()) {
			    		int current = stk.pop();
			    		visited.put(current, visited.get(current)+1);
			    		if(visited.get(current) == 1) {
			    			for(int kk: inherit.get(current))
			    				stk.push(kk);
			    		}
			    	}
			    	hasDiamond = false;
			    	for(int n: visited.values()) {
			    		if(n>1) {
			    			hasDiamond = true;
			    			break;
			    		}
			    	}
			    	if(hasDiamond) break;
		    	}
		    	output.write(hasDiamond ? "Yes" : "No");
		    	if(i<T) output.write("\n");
		    }
		} catch (FileNotFoundException e) {
			System.out.println("input file not found: ");
			e.printStackTrace();
		} catch(IOException e) {
			System.out.println("Error opening files: ");
		    e.printStackTrace();
		    System.exit(1);
		} finally {
			try {
				input.close();
				output.close();
				System.out.println("Done !!");
			} catch (IOException e) {
				System.out.println("Error closing files: ");
				e.printStackTrace();
			}
		}
	}

}
