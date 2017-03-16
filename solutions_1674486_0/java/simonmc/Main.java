import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int cases = Integer.parseInt(scan.nextLine());
		for(int c = 0; c < cases; c++) {
			ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
			int nodes = Integer.parseInt(scan.nextLine());
			for(int i = 1; i <= nodes; i++) {
				String line = scan.nextLine();
				Scanner ls = new Scanner(line);
				ArrayList<Integer> nl = new ArrayList<Integer>();
				int links = ls.nextInt();
				for(int l = 0; l < links; l++) {
					nl.add(ls.nextInt());
				}
				list.add(nl);
				
			}
			
			boolean t = process(list);
			if(t) {
				System.out.println("Case #" + (c + 1) + ": " + "Yes");
			} else {
				System.out.println("Case #" + (c + 1) + ": " + "No");				
			}
		}
			
		
	
	}
	
	public static ArrayList<Integer> found;
	
	public static boolean recurse(int i, ArrayList<ArrayList<Integer>> list) {
		//System.err.println("ex: " + i);
		//if(found.contains(i)){
		//	return true;
		//} else {
			if(list.get(i - 1).size() == 0) {
				return false;
			}
			
			for(int k = 0; k < list.get(i - 1).size(); k++) {
				int curr2 = list.get(i-1).get(k);
				if(found.contains(curr2)) {
				//	System.err.println("found  " + curr2);
					return true;
				}
				found.add(curr2);
			}
			found.add(i);
			boolean f = false;
			for(int k = 0; k < list.get(i - 1).size(); k++) {
				f =  f || recurse(list.get(i-1).get(k), list); 
			}
			return f;
		//}		
	
	}
	
	public static boolean process(ArrayList<ArrayList<Integer>> list) {
		for(int i = 1; i <= list.size(); i++) {
			found = new ArrayList<Integer>();
			if(recurse(i, list)) {
				return true;
			}
		}
		return false;
	
		
	}
	
}
