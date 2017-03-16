package codejam.round1b;

import java.io.*;
import java.util.*;

/**
 *
 * @author Cheng Chen
 * @since Apr 30, 2016
 */

public class CloseMatchII {
	
	public static void main(String[] args) {
		int casetotal = 0;
		int casenumber = 1;
		int totalline = 0;
		String line = "";
		
		try (FileReader fr = new FileReader("data/B-small-attempt6.in");
		            BufferedReader br = new BufferedReader(fr);
		            FileWriter fw = new FileWriter("data/B-small-attempt6.out");
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
				
				/**
				 * processing
				 */
				String result = new CloseMatchII().getCloseMatch(line);
				bw.println("Case #" + casenumber + ": " + result);
				
				casenumber++;
				totalline++;
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
	
	private String getCloseMatch(String s) {
		String first = s.split(" ")[0];
		String second = s.split(" ")[1];
		if (first.length() != second.length())
			throw new IllegalArgumentException(s);
		
		ArrayList<String> list1=new ArrayList<String>();
		StringBuilder sb=new StringBuilder();
		backtrack(first,sb,list1);
		
		ArrayList<String> list2=new ArrayList<String>();
		sb=new StringBuilder();
		backtrack(second,sb,list2);
		
		int difference=Integer.MAX_VALUE;
		String result1="";
		String result2="";
		
		for(String l1:list1){
			for(String l2:list2){
				int n1=Integer.parseInt(l1);
				int n2=Integer.parseInt(l2);
				if(Math.abs(n1-n2)<difference){
					difference=Math.abs(n1-n2);
					result1=l1;
					result2=l2;
				}
				else if(Math.abs(n1-n2)<difference){
					if(n1<Integer.parseInt(result1)){
						result1=l1;
						result2=l2;
					}
					else if(l1.equals(result1) && n2<Integer.parseInt(result2)){
						result1=l1;
						result2=l2;
					}
				}
			}
		}
		return result1+" "+result2;
	}

	private void backtrack(String s, StringBuilder sb, ArrayList<String> list) {
	      if(sb.length()==s.length()){
	      	list.add(sb.toString());
	      	return;
	      }
	      
	      int length=sb.length();
	      if(s.charAt(length)!='?'){
	      	sb.append(s.charAt(length));
	      	backtrack(s,sb,list);
	      }
	      else{
	      	for(int i=0;i<=9;i++){
	      		sb.append(i);
	      		backtrack(s,sb,list);
	      		sb.setLength(length);
	      	}
	      }
	      
      }
	
}
