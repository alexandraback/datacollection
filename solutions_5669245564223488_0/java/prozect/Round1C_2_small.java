package codejam2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Round1C_2_small {

	public static String ds[];
	public static int ans = 0;
	
	   static void permute(java.util.List<String> arr, int k){
	        for(int i = k; i < arr.size(); i++){
	            java.util.Collections.swap(arr, i, k);
	            permute(arr, k+1);
	            java.util.Collections.swap(arr, k, i);
	        }
	        if (k == arr.size() -1){
	        	boolean used[] = new boolean[26];
	        	Arrays.fill(used, false);
	        	char last_ch=' ';
	        	boolean result = true;
	        	for(String es : arr) {
	    
	        		for(int j=0; j<es.length(); j++) {
	        			char now_ch = es.charAt(j);
	        			if(last_ch!=now_ch) {
	        				if(used[now_ch-'a']==false) {
	        					used[now_ch-'a']=true;
	        					last_ch=now_ch;
	        				}
	        				else {
	        					result = false; break;
	        				}
	        			}
	        		}
	        		if(result==false) break;
	        	}
	        	
	        	if(result == true) ans++;
	        }
	    }
	   
	public static int process(String[] ds) {
		List<String> l = new ArrayList<String>();
		for(int i=0; i<ds.length; i++) {
			l.add(ds[i]);
		}
		permute(l, 0);
		return 0;
	}
	public static void main(String args[]) {
		try {
			Scanner inputfile = new Scanner(new File("B-small-attempt0.in"));
			int t = inputfile.nextInt();
			String s = inputfile.nextLine();
			for(int i=0; i<t; i++) {
				int n = inputfile.nextInt();
				inputfile.nextLine();
				s = inputfile.nextLine();
				String[] ds = s.split(" ");
				ans=0;
				process(ds);
				System.out.printf("Case #%d: %d\n", i+1, ans);
			}
				
			
			
			inputfile.close();

				
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
		
}
