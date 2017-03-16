package cg.y2012.QualQ2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Q2 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		int[] s = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
		Map<Integer, List<int[]>> G = new HashMap<Integer, List<int[]>>();
		for(int i:s){
			for(int j:s){
				for(int k:s){
					if(Math.abs(i-j)< 2 && Math.abs(k-j)< 2 && Math.abs(i-k)< 2){
						int sum = i+j+k;
						List<int[]> trips = G.get(sum);
						if(trips == null){
						 trips = new ArrayList<int[]>();
						}
						trips.add(new int[]{i,j,k});
						G.put(sum, trips);
					}
				}
			}
		}
		Map<Integer, List<int[]>> ST = new HashMap<Integer, List<int[]>>();
		for(int i:s){
			for(int j:s){
				for(int k:s){
					if((Math.abs(i-j)== 2 && Math.abs(k-j) < 2 && Math.abs(i-k) < 2) ||
							(Math.abs(i-j)< 2 && Math.abs(k-j)== 2 && Math.abs(i-k)<2) ||
							(Math.abs(i-j) < 2 && Math.abs(k-j) < 2 && Math.abs(i-k)== 2)){
						int sum = i+j+k;
						List<int[]> trips = ST.get(sum);
						if(trips == null){
						 trips = new ArrayList<int[]>();
						}
						trips.add(new int[]{i,j,k});
						ST.put(sum, trips);
					}
					if((Math.abs(i-j)== 2 && (Math.abs(k-j) == 0 || Math.abs(i-k) == 0)) ||
							(Math.abs(k-j)== 2 && (Math.abs(k-i) == 0 || Math.abs(i-j) == 0)) ||
							(Math.abs(k-i)== 2 && (Math.abs(k-j) == 0 || Math.abs(i-j) == 0))){
						int sum = i+j+k;
						List<int[]> trips = ST.get(sum);
						if(trips == null){
						 trips = new ArrayList<int[]>();
						}
						trips.add(new int[]{i,j,k});
						ST.put(sum, trips);
					}
				}
			}
		}
		for(Map.Entry<Integer, List<int[]>> k : G.entrySet()){
			System.out.print(k.getKey()+" -- ");
			List<int[]> l = k.getValue();
			for(int[] a : l){
				System.out.print("{");
				for(int x : a){
					System.out.print(" "+x+", ");
				}
				System.out.print("}");
			}
			System.out.println("");
		}
		
		for(Map.Entry<Integer, List<int[]>> k : ST.entrySet()){
			System.out.print(k.getKey()+" -- ");
			List<int[]> l = k.getValue();
			for(int[] a : l){
				System.out.print("{");
				for(int x : a){
					System.out.print(" "+x+", ");
				}
				System.out.print("}");
			}
			System.out.println("");
		}
		BufferedWriter out = null;
		try {
			String newLine = System.getProperty("line.separator");
		    out = new BufferedWriter(new FileWriter(args[0]+".output"));
		    BufferedReader b = new BufferedReader(new FileReader(args[0]));
		    int number_of_test_cases = Integer.parseInt(b.readLine().split(" ")[0]);
		    for( int tc = 0; tc < number_of_test_cases; tc++) {
		    	int[] data = convertToInt(b.readLine());
		    	int N = data[0];
		    	int S = data[1];
		    	int p = data[2];
		    	
		    	int rScores[] = new int[N];
		    	int j=0;
		    	for(int i=0;i < rScores.length;i++){
					rScores[i] = -1;
		    	}
		    	
		    	int count = 0;
		    	for(int i=0;i<N;i++){
			    	List<int[]> scores = G.get(data[3+i]);
			    	boolean found = false;
			    	if(scores != null){
				    	for(int[] score : scores){
			    			if(score[0] >=p ||score[1] >=p  || score[2] >=p  ){
				    			count ++;
				    			found = true;
				    			break;
				    		}
				    	}
				    	if(!found){
				    		rScores[j] =data[3+i];
				    		j++;
				    	}
			    	}
				}
	    		for(int i=0;i < rScores.length && S > 0;i++){
		    		if(rScores[i] == -1)
		    			break;
			    	List<int[]> scores = ST.get(rScores[i]);
			    	if(scores != null){
				    	for(int[] score : scores){
			    			if(score[0] >=p ||score[1] >=p  || score[2] >=p  ){
				    			count ++;
				    			S--;
				    			break;
				    		}
				    	}
			    	}
				}
			    out.write("Case #"+(tc+1)+": "+count+newLine);
				
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
