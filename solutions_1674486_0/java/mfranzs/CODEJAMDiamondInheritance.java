

///REMOVE ALL OUTPUT AND USE STRINGTOKENIZER!


/*
ID: mfranzs1
LANG: JAVA
TASK: CODEJAMDiamondInheritance
*/
import java.io.*;
import java.util.*;

public class CODEJAMDiamondInheritance {
	static BufferedReader f;
	static ArrayList<ArrayList<Integer>> inheritance;
	static ArrayList<String> allPaths;
	static boolean end=false;
	static boolean works=false;
	static int paths=0;
	public static void main (String [] args) throws IOException {
		long unixTime = System.currentTimeMillis();
		// Use BufferedReader rather than RandomAccessFile; it's much faster
		f = new BufferedReader(new FileReader("CODEJAMDiamondInheritance.in"));
	                                                  // input file name goes above
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("CODEJAMDiamondInheritance.out")));
	    // Use StringTokenizer vs. readLine/split -- lots faster
	    //StringTokenizer st = new StringTokenizer(f.readLine()," ");	    	
  	//int i = Integer.parseInt(st.nextToken());
	    int Tests=Integer.parseInt(f.readLine());
	    for(int test=0;test<Tests;test++){
	    	int numClasses=Integer.parseInt(f.readLine());
	    	end=false;
	    	works=false;
	    	paths=0;
	    	inheritance=new ArrayList<ArrayList<Integer>>();	    
	    	inheritance.add(new ArrayList<Integer>());
	    	for(int c=0;c<numClasses;c++){
	    		StringTokenizer st = new StringTokenizer(f.readLine()," ");
	    		int inherits = Integer.parseInt(st.nextToken());
	    		ArrayList<Integer> ii= new ArrayList<Integer>();
	    		inheritance.add(ii);
	    		for(int i=0;i<inherits;i++){
	    			int classInherited = Integer.parseInt(st.nextToken());
	    			ii.add(classInherited);
	    		}
	    	}
	    	System.out.println(inheritance.size());
	    	for(int i=1;i<=numClasses&&!end;i++){
	    		allPaths=new ArrayList<String>();
	    		branch(i,new ArrayList<Integer>());
	    	}
	    	System.out.println("Case #"+(test+1)+": "+(works?"Yes":"No")+paths);
	    	out.println("Case #"+(test+1)+": "+(works?"Yes":"No"));
	    }
	    
	    out.close();                                  // close the output file
	    
	    System.out.println("Time elapsed (ms): "+(System.currentTimeMillis()-unixTime));
	    
	    System.exit(0);                               // don't omit this!
	  }
	public static void branch(int position,ArrayList<Integer> parents){
		if(end)return;
	
		for(Integer i: parents){
			if(allPaths.contains(i+" "+position)){
				end=true;
				works = true;
				return;
			}
			allPaths.add(i+" "+position);
		}
		
		ArrayList<Integer> ii= inheritance.get(position);
		for(int i=0;i<ii.size()&&!end;i++){
			System.out.println(position+" -> "+ii.get(i));
			if(parents.contains(ii.get(i)))continue;
			System.out.println("F");
			ArrayList<Integer> n  = (ArrayList<Integer>) parents.clone();
			n.add(position);
			branch(ii.get(i),n);
		}
	}
}