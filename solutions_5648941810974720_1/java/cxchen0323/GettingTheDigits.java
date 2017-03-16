package codejam.round1b;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.TreeSet;

/**
 *
 * @author Cheng Chen
 * @since Apr 30, 2016
 */

public class GettingTheDigits {
	
	public static void main(String[] args) {
		int casetotal = 0;
		int casenumber = 1;
		int totalline = 0;
		String line = "";
		
		try (FileReader fr = new FileReader("data/A-large.in");
		            BufferedReader br = new BufferedReader(fr);
		            FileWriter fw = new FileWriter("data/A-large.out");
		            PrintWriter bw = new PrintWriter(fw);) {
			while ((line = br.readLine()) != null) {
				if (totalline == 0) {
					casetotal = Integer.parseInt(line);
					totalline++;
					continue;
				}
				
				if (casenumber > casetotal) {
					System.out.println("###Error: The casenumber has problem!!!");
					System.out.println("###Error: This error happened in line number"
					            + totalline);
					throw new IOException("###Error: The casenumber has problem!!!");
				}
				
				String phoneNumber=getTheDigits(line);
				bw.println("Case #"+casenumber+": "+phoneNumber);
				
				casenumber++;
				totalline++;
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}

	public static String getTheDigits(String s) {
	      int[] count=new int[26];
	      for(char c:s.toCharArray())
	      	count[c-'A']++;
	      
	      ArrayList<Integer> result=new ArrayList<Integer>();
	      heler(count,'Z',"ZERO",result,0);
	      heler(count,'W',"TWO",result,2);
	      heler(count,'X',"SIX",result,6);
	      heler(count,'U',"FOUR",result,4);
	      heler(count,'R',"THREE",result,3);
	      heler(count,'F',"FIVE",result,5);
	      heler(count,'V',"SEVEN",result,7);
	      heler(count,'T',"EIGHT",result,8);
	      heler(count,'O',"ONE",result,1);
	      heler(count,'I',"NINE",result,9);
	      
	      Collections.sort(result);
	      
	      StringBuilder sb=new StringBuilder();
	      for(int i:result){
	      	sb.append(i);
	      }
	      
	      return sb.toString();
      }

	private static void heler(int[] count, char uniqueChar, String deductString, ArrayList<Integer> result, int number) {
	      while(count[uniqueChar-'A']>0){
	      	result.add(number);
	      	for(char c:deductString.toCharArray())
	      		count[c-'A']--;
	      }
      }
	
}
