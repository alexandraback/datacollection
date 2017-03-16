import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;
import java.util.Set;

import org.w3c.dom.NodeList;


public class Question3A {
	public static List<Node> nodeList = new ArrayList<Node>();
	//final static String FNAME = "C:\\CodeJam\\DiamondInherit";
	final static String FNAME = "C:\\CodeJam\\A-large";
	//final static String FNAME = "C:\\CodeJam\\A-small-attempt0";
    public static Scanner in;
    public static PrintWriter out;

    static void open() throws IOException {
        Locale.setDefault( Locale.US );
        in = new Scanner( new File( FNAME + ".in" ) );
        out = new PrintWriter( new File( FNAME + ".out" ) );
    }

    static void close() throws IOException {
        out.close();
    }
    
    public static class Node{
    	int name;
    	public int getName() {
			return name;
		}
		public void setName(int name) {
			this.name = name;
		}
		List<Integer> parentSet = new ArrayList<Integer>();
    	public List<Integer> getParentSet() {
			return parentSet;
		}
		public void setParentSet(List<Integer> parentSet) {
			this.parentSet = parentSet;
		}
		Node(int name){
    		this.name = name;
    	}
    	
    	
    }
    
   public static boolean findParents(List<Integer> parentSet, Set<Integer> copyParentSet){
	    
	 for(Integer n : parentSet){
		 boolean added = copyParentSet.add(n);
		 if(!added)
			 return false;	
		 if (!(findParents(nodeList.get(n-1).parentSet, copyParentSet)))
			 return false;
		 
	 } 
	 return true;
	  
   }
        
    
	public static void main(String[] args)throws IOException {
		open();
        int T = in.nextInt();
        //int T = Integer.parseInt(in.nextLine());
        /*    -------- Main code ----------  */
        
        for(int i = 0 ; i < T ; i++){
        	int N = in.nextInt();
        	nodeList.clear();
        	for (int j = 0; j < N; j++) {
        		Node node = new Node(j+1);
				int M = in.nextInt();//number of direct parents
				for (int k = 0; k < M; k++) {
					int parentClass = in.nextInt();
					node.getParentSet().add(parentClass);
				}				
				nodeList.add(node);
			}
        	boolean containsDiamond=false;
        	//process
        	for(int j = 0 ; j < nodeList.size(); j++){
        		Node node = nodeList.get(j);
        		Set<Integer> copySet = new HashSet<Integer>();
        		boolean foundNoDups = findParents(node.getParentSet(),copySet);
        		if(!foundNoDups){
        			containsDiamond = true;
        			break;
        		}
        	}
        	
        	if(containsDiamond)
    			out.println( "Case #" + (i+1) + ": " + "Yes");
    		else
    			out.println( "Case #" + (i+1) + ": " + "No");
        }
        	
        
        	close(); 

        }
        

}
