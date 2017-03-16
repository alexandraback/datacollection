import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;


public class Problem3 {
	public static void main(String[] args) {
		try {
			Scanner scanner = new Scanner(new FileReader("C-small-attempt0.in"));
	        int T = scanner.nextInt();
	        int[] C = new int[T];
	        int[] D = new int[T];
	        int[] V = new int[T];
	        ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
	        for(int i=0; i<T; i++) {
	        	C[i] = scanner.nextInt();
	        	D[i] = scanner.nextInt();
	        	V[i] = scanner.nextInt();
	        	ArrayList<Integer> subList = new ArrayList<Integer>();
	        	for(int j=0; j< D[i]; j++) {
	        		int current = scanner.nextInt();
	        		subList.add(current);
	        	}
	        	list.add(subList);
	        }  
	        PrintWriter out = new PrintWriter(new FileWriter("output3.txt"));        
	        for(int i=0; i<T; i++) {
	        	int add = 0;
	        	ArrayList<Integer> subList = list.get(i);
	        	HashSet<Integer> set = new HashSet<Integer>();
	        	for(int j : subList) {
	        		set.add(j);
	        	}
	        	while(set.size() < V[i]) {
	        		if(expand(set, V[i])) {
	        			add++;
	        		} else {
	        			break;
	        		}
	        	}
	        	out.println("Case #" + (i+1) + ": " + add);
	        }
	        out.close();	       
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static boolean expand(HashSet<Integer> set, int V) {
		HashSet<Integer> newSet = new HashSet<Integer>();
		getAllPossible(newSet, set, 0, V);
		for(int i=1; i<= V; i++) {
			if(!newSet.contains(i)) {
				set.add(i);
				return true;
			}
		}
		return false;
	}
	
	public static void getAllPossible(HashSet<Integer> newSet, HashSet<Integer> set, int current, int V) {
		if(current > V) {
			return;
		}
		newSet.add(current);
		Iterator<Integer> iter = set.iterator();
		while(iter.hasNext()) {
			int j = iter.next(); 
			HashSet<Integer> temp = new HashSet<Integer>(set);
			temp.remove(j);
			getAllPossible(newSet, temp, current+j, V);
		}
	}
}
