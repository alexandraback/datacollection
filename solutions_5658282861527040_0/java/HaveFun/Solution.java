package solution;

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;



class Solution {
	//io start
	 public ArrayList<String> input;
	 public int index;
	 
	 public Solution() {
		 input = new ArrayList<String>();
		 index = 0;
	 }
	 
	 public void readFile(String inputfile) {
		 String str;
		 try{
	    	 try{
	    		 File f = new File(inputfile);
	    		 BufferedReader br = new BufferedReader(new FileReader(f));
	    		 while(( str = br.readLine()) != null)
	    			 input.add(str);
	    		 br.close();
	    	 }
	    	 catch(FileNotFoundException e) {}
	     }
	     catch(IOException e) {}
	 }
	 
	 
	 public void writeFile(String file, String[] ans) {
		 try{
	    	 try{
	    		 File f = new File(file);
	    		 BufferedWriter bw = new BufferedWriter(new FileWriter(f));
	    		 for(int i = 0; i < ans.length; i++) {
	    			 bw.write(ans[i]);
	    		     bw.write("\n");
	    		 }
	    		 bw.close();
	    	 }
	    	 catch(FileNotFoundException e) {}
	     }
	     catch(IOException e) {}
	 }
	 
	 public String inputNext() {
		 return input.get(index++);
	 }
	 
	//io end  
	
	 int findSmall(int A, int B, int K) {
		 int ans = 0;
		 for(int i = 0; i < A; i++)
			 for(int j = 0; j < B; j++) {
				 int a = i & j;
				 if(a < K && a >= 0)
					 ans++;
			 }
		 return ans; 
	 }
	 
	 
     public static void main(String[] args) {
   
    	 String file = "Bsmall.txt", fileOut = "BsamllOut.txt";
    	 Solution sol = new Solution();
    	 sol.readFile(file);
    	 String[] outlet;
    	 String[] device;
    	 int C;
    	 C = Integer.parseInt(sol.inputNext());
    	 String input;
    	 String[] inputS, ans;
    	 ans = new String[C];
    	 int A, B, K;
    	 for(int i = 0; i < C; i++) {
    		 
    		 inputS = sol.inputNext().split(" ");
    		 A = Integer.parseInt(inputS[0]);
    		 B = Integer.parseInt(inputS[1]);
    		 K = Integer.parseInt(inputS[2]);
    		 int t = sol.findSmall(A,B,K);
 
    			 ans[i] = String.format("Case #%d: %d", i+1, t);

    	 }
    	 sol.writeFile(fileOut, ans);
    //	 System.out.println(Long.MAX_VALUE);
    
    	 
    	 
     }
}

