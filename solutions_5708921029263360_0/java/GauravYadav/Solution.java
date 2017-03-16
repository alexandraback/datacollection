import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
	
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    Scanner scnr=new Scanner(System.in);
   
    int t=scnr.nextInt();
    String ans[]=new String[t];
    for(int i=0;i<t;i++){
    	StringBuilder evac=new StringBuilder();
    int jlimit=scnr.nextInt();
    int klimit=scnr.nextInt();
    int llimit=scnr.nextInt();
    int plimit=scnr.nextInt();
    int count=0;
    for(int j=1;j<=jlimit;j++){
    	for(int k=1;k<=klimit;k++){
    		int p=0;
    		for(int l=1;l<=llimit&&p<plimit;l++){
    			evac.append(j);
    			evac.append(" ");
    			evac.append(k);
    			evac.append(" ");
    			evac.append(l);
    			evac.append("\n");
    			p++;
    			count++;
    		}
    	}
    }
    ans[i]=count+"\n"+evac.toString();
    }
    
    	
   
    for(int i=0;i<t;i++){
    	System.out.println("Case #"+(i+1)+": "+ans[i]);
    }
    } 
    }
