import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class InfiniteHouseofPancakes {
	
	public static void main(String[] args) {
		try {
			Scanner scanner = new Scanner(new FileReader("B-small-attempt3.in"));
	        int T = scanner.nextInt();
	        ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
	        for(int i=0; i<T; i++) {
	        	int num = scanner.nextInt(); 
	        	ArrayList<Integer> subList = new ArrayList<Integer>(); 
	        	for(int j=0; j<num; j++) {
	        		int newNum = scanner.nextInt();
	        		subList.add(newNum);
	        	}
	        	list.add(subList);
	        }
	        PrintWriter out = new PrintWriter(new FileWriter("output2.txt"));        
	        for(int i=0; i<T; i++) {   	
	        	ArrayList<Integer> subList = list.get(i);
	        	Collections.sort(subList);
	        	int last = subList.get(subList.size()-1);
	        	int minute = last;
	        	for(int j=1; j<=last; j++) {
	        		int current = 0;
	        		for(int k : subList) {
	        			if(k % j ==0) {
	        				current += k/j-1;
	        			} else {
	        				current += k/j;
	        			}       			
	        		}
	        		minute = Math.min(minute, current+j);
	        	}
	        	out.println("Case #" + (i+1) + ": " + minute);
	        }
	        out.close();
	       
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
}
