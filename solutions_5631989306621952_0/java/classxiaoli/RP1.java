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


public class RP1 {
public static void main(String[] args)throws IOException{
	
     try {
        
         File newTextFile = new File("/Users/classxiaoli/Downloads/output.txt");
         FileWriter fw = new FileWriter(newTextFile);
        BufferedReader reader = new BufferedReader(new FileReader("/Users/classxiaoli/Downloads/A-small-attempt0.in"));
       //  BufferedReader reader = new BufferedReader(new FileReader("/Users/classxiaoli/Downloads/input.in"));
         int i=0;
        
         String line;
         reader.readLine();
         while ((line= reader.readLine()) != null) {
        	 i++;
        	 StringBuilder str=new StringBuilder(); 
        	 str.append(line.charAt(0));
        	 char current=line.charAt(0);
        	 for(int j=1;j<line.length();j++){
        		 if(line.charAt(j)<current) str.append(line.charAt(j));
        		 else{
        			 current=line.charAt(j);
        			 str.insert(0, line.charAt(j));
        		 }
        	 }
        	 
            fw.write("Case #"+i+": "+str.toString()+"\n"); 
         
         }
         fw.close();
      }finally {
         
      }
}
}
