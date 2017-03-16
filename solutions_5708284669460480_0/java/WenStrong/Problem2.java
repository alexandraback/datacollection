import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;


public class Problem2 {
	public static void main(String[] args) {
		try {
			Scanner scanner = new Scanner(new FileReader("B-small-attempt0.in"));
	        int T = scanner.nextInt();
	        int[] K = new int[T];
	        int[] L = new int[T];
	        int[] S = new int[T];
	        String[] key = new String[T];
	        String[] target = new String[T];
	        for(int i=0; i<T; i++) {
	        	K[i] = scanner.nextInt();
	        	L[i] = scanner.nextInt();
	        	S[i] = scanner.nextInt();
	        	key[i] = scanner.next();
	        	target[i] = scanner.next();
	        }  
	        PrintWriter out = new PrintWriter(new FileWriter("output2.txt"));        
	        for(int i=0; i<T; i++) {        	
	        	ArrayList<String> list = new ArrayList<String>();
	        	getAllString(list, key[i], "", S[i]);
	        	double max = 0;
	        	double sum = 0;
	        	for(String str : list) {
	        		double count = 0;
	        		int index = 0;
	        		while(index + target[i].length() <= str.length()) {
	        			if(str.substring(index, index+target[i].length()).equals(target[i])) {
	        				count++;
	        			}
	        			index++;
	        		}
	        		max = Math.max(max, count);
	        		sum += count; 
	        	}
	        	double expect = sum/(double)list.size();
	        	expect = max - expect;
	        	out.println("Case #" + (i+1) + ": " + expect);
	        }
	        out.close();	       
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void getAllString(ArrayList<String> list, String key, String current, int n) {
		if(n == 0) {
			list.add(current);
			return;
		}
		for(int i=0; i<key.length(); i++) {
			String newStr = current + key.charAt(i);
			getAllString(list, key, newStr, n-1);
		}
	}
}
