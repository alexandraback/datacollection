package cg.y2012.round1c1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Q {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		

		BufferedWriter out = null;
		try {
			String newLine = System.getProperty("line.separator");
		    out = new BufferedWriter(new FileWriter(args[0]+".output"));
		    BufferedReader b = new BufferedReader(new FileReader(args[0]));
		    int number_of_test_cases = Integer.parseInt(b.readLine().split(" ")[0]);
		    for( int tc = 0; tc < number_of_test_cases; tc++) {
		    	int[] data = convertToInt(b.readLine());
		    	int N = data[0];
		    	int[][] sup = new int[N][];
		    	for(int i=0;i < N;i++){
		    		int[] s = convertToInt(b.readLine());// first element is number
		    		sup[i] =s;
		    	}
		    	
		    	String output = "No";
		    	outer: for(int i=0;i < N;i++){
		    		Set<Integer> parents = new HashSet<Integer>();
		    		for(int j=1;j < sup[i].length;j++){
	    				parents.add(sup[i][j]);
		    		}
		    		// for each parent of a class find a different way to get there.
		    		List<Integer> p2 = new ArrayList<Integer>();
		    		p2.addAll(parents);
		    		do{
		    			List<Integer> temp = new ArrayList<Integer>();
			    		for(int x: p2){
			    			for(int j=1;j < sup[x-1].length;j++){
			    				temp.add(sup[x-1][j]);
			    				if(!parents.add(sup[x-1][j])){
			    					output = "Yes";
			        				break outer;
			    				}
				    		}
			    		}
			    		p2 = temp;
		    		}while(!p2.isEmpty());
    			}

			    out.write("Case #"+(tc+1)+": "+output+newLine);
			}
		} catch (IOException e) {
			System.out.println("Exception : "+e);
		}
		finally {
			if(out != null){
				try {
					out.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}
	
	private static int[] convertToInt(String line){
		String data[] = line.split(" ");
		int[] rtn = new int[data.length];
		for(int i=0;i< data.length ;i++){
			rtn[i]=Integer.parseInt(data[i].trim());
		}
		return rtn;
	}
	
}