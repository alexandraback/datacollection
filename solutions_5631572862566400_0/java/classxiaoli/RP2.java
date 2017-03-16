package codejam;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.*;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.HashSet;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Random;
import java.util.Collections;

public class RP2 {
public static void main(String[] args)throws IOException{
	
     try {
        
         File newTextFile = new File("/Users/classxiaoli/Downloads/output.txt");
         FileWriter fw = new FileWriter(newTextFile);
        // BufferedReader reader = new BufferedReader(new FileReader("/Users/classxiaoli/Downloads/B-large.in"));
     //    BufferedReader reader = new BufferedReader(new FileReader("/Users/classxiaoli/Downloads/input.in"));
       BufferedReader reader = new BufferedReader(new FileReader("/Users/classxiaoli/Downloads/C-small-attempt1.in"));
         int i=0;
        
         String line;
         reader.readLine();
         
         while ((line= reader.readLine()) != null) {
        	 i++;
        	 int a =Integer.parseInt(line);
        	 Map<Integer,Integer> map=new HashMap<Integer,Integer>();
        	 int [] bff=new int[a];
        	 
        	 boolean [] visited=new boolean[a];
        	 int [] count=new int[a];
        	 int [] store=new int[a];
        	 Arrays.fill(count, 0);
        	 Arrays.fill(store, 0);
        	 line=reader.readLine();
        	 String[] str=line.split(" ");
        	 for(int j=0;j<a;j++){
        		int k=Integer.parseInt(str[j]);
        		 bff[j]=k-1;
        		 count[k-1]++;
        	 }
        	
        	
        	 int max=0;
        	 Arrays.fill(visited, false);
        	 for(int j=0;j<a;j++){
        		 if(count[j]==0&&visited[j]==false){
        			 int k=j;
        			 int num=1;
        			 visited[j]=true;
        			 while(visited[bff[k]]==false){
        				 num++;
        				 k=bff[k];
        				 visited[k]=true;
        			 }
        			 
        			 if(store[bff[k]]>0){
        				 max=Math.max(max, num+store[bff[k]]);
        			 }
        			 else if(bff[bff[k]]==k){
        				 store[k]=num;
        				 
        				max=Math.max(max,num);	
        				k=j;
        				while(num>1){
        					
        					store[k]=num;
        					k=bff[k];
        					num--;
        				}
        			 } else{
        				 
        				 int t=bff[k];
        				 int minus=0;
        				 int start=j;
        				 
        				 while(start!=t){
        					 minus++;
        					 start=bff[start];
        				 }
        				 max=Math.max(max, num-minus);
        			 }
        		 }
        	 }
        	 for(int j=0;j<a;j++){
        		 
        		 if(visited[j]==false){
        			 int num=1;
        			 int k=j;
        			 visited[j]=true;
        			 while(visited[bff[k]]==false){
        				 num++;
        				 k=bff[k];
        				 visited[k]=true;
        			 }
        			 
        			 max=Math.max(max,num);	
        		 }
        	 }
        	
        	
            fw.write("Case #"+i+": "+max+"\n"); 
         
         }
         fw.close();
      }finally {
         
      }
}
}
