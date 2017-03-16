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
	
	 ArrayList<Integer> order(int[] v, int[][] A) {
		 int n = v.length;
		 int[] k = new int[n];
		 int[] index = new int[n];
		 boolean[] tap = new boolean[n];
		 for(int i = 0; i < v.length; i++) {
			 k[i] = v[i];
			 index[i] = i;
			 tap[i] = false;
		 }
		 int temp;
		 for(int i = 0; i < n-1; i++)
			 for(int j = i+1; j < n; j++)
				 if(k[i] > k[j]) {
					temp = k[i];
					k[i] = k[j];
					k[j] = temp;
					temp = index[i];
					index[i] = index[j];
					index[j] = temp;
				 }
		 
		 
		 Stack<Integer> s = new Stack<Integer>();
		 s.push(index[0]);
		 tap[index[0]] = true;
		 ArrayList<Integer> ans = new ArrayList<Integer>();
		 ans.add(index[0]);
		 while(!s.empty()) {
			 int t = s.peek();
			 boolean flag = false;
			 for(int j = 0; j < n; j++) {
				 if(tap[index[j]] == false && A[t][index[j]] == 1) {
					 tap[index[j]] = true;
					 s.add(index[j]);
					 ans.add(index[j]);
					 flag = true;
					 break;
				 }
			 }
			 if(flag == false) 
				 s.pop();
		 }
		 return ans;
		 
	 }
	 
	 
     public static void main(String[] args) {
   
    	 String file = "C-small-attempt1.in.txt", fileOut = "CsmallOut.txt";
    	 Solution sol = new Solution();
    	 sol.readFile(file);
    	 String[] outlet;
    	 String[] device;
    	 int C;
    	 C = Integer.parseInt(sol.inputNext());
    	 String input;
    	 String[] inputS, ans;
    	 ans = new String[C];
    	 int N,M;
    	 int[][] A;
    	 int m,n;
    	 ArrayList<Integer> ord;
    	 for(int i = 0; i < C; i++) {
    		 
    		 inputS = sol.inputNext().split(" ");
    		 N = Integer.parseInt(inputS[0]);
    		 M = Integer.parseInt(inputS[1]);
    		 A = new int[N][N];
    		 for(int k = 0; k < N; k++)
    			 for(int j = 0; j < N; j++)
    				 A[k][j] = 0;
    		 int[] v = new int[N];
    		 for(int k = 0; k < N; k++)
    			 v[k] = Integer.parseInt(sol.inputNext());
    		 for(int k = 0; k < M; k++) {
    			 inputS = sol.inputNext().split(" ");
        		 m = Integer.parseInt(inputS[0]);
        		 n = Integer.parseInt(inputS[1]);
        		 A[m-1][n-1] = 1;
        		 A[n-1][m-1] = 1;
    		 }
    		ord = sol.order(v,A); 
    		 String s = "";
    		 for(int k = 0; k < N; k++)
    			 s += Integer.toString(v[ord.get(k)]);
    		ans[i] = String.format("Case #%d: ", i+1);
    		ans[i] += s;

    	 }
    	 sol.writeFile(fileOut, ans);
    //	 System.out.println(Long.MAX_VALUE);
    
    	 
    	 
     }
}

