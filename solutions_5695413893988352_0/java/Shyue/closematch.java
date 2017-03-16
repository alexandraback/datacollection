package googlecodejam;
import java.io.*;
import java.util.*;

public class closematch {


	  public static void main (String [] args) throws IOException {
	    // Use BufferedReader rather than RandomAccessFile; it's much faster
	    BufferedReader f = new BufferedReader(new FileReader("B-small-attempt2(1).in"));
	                                                  // input file name goes above
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("closematch.out")));
	    // Use StringTokenizer vs. readLine/split -- lots faster
	    StringTokenizer st = new StringTokenizer(f.readLine());
							  // Get line, break into tokens
	    
	   //enter program here
	    int cases = Integer.parseInt(st.nextToken());
	    for (int i = 0; i<cases; i++){
	    	st = new StringTokenizer(f.readLine());
	    	String a = st.nextToken(); String b = st.nextToken();
	    	String answer = "";
	    	String rA = ""; String rB = "";
	    	int flag = 0;
	    	
	    	System.out.println(a+" "+b);
	    	//find the double
	    	int mark = -1;
	    	for (int j = 0; j<a.length();j++){
	    		if (a.charAt(j)!='?' && b.charAt(j)!='?'){
	    			mark = j; break;
	    		}
	    	}
	    	if (mark>0){
	    		String holdA = a.charAt(mark-1)+""+a.charAt(mark);
	    		String holdB = b.charAt(mark-1)+""+b.charAt(mark);
	    		if (holdA.charAt(0)=='?' && holdB.charAt(0)=='?'){
	    			int t1 = Math.abs(Integer.parseInt("0"+holdA.charAt(1))-Integer.parseInt("0"+holdB.charAt(1)));
	    			int t2 = Math.abs(Integer.parseInt("0"+holdA.charAt(1))-Integer.parseInt("1"+holdB.charAt(1)));
	    			int t3 = Math.abs(Integer.parseInt("1"+holdA.charAt(1))-Integer.parseInt("0"+holdB.charAt(1)));
	    			
	    			int min = Math.min(t1, Math.min(t2, t3));
	    			
	    			if (min==t1){
	    				a = a.substring(0, mark-1)+"0"+a.substring(mark);
	    				b = b.substring(0, mark-1)+"0"+b.substring(mark);
	    			}
	    			else if (min==t2){
	    				a = a.substring(0, mark-1)+"0"+a.substring(mark);
	    				b = b.substring(0, mark-1)+"1"+b.substring(mark);
	    			}
	    			else if (min==t3){
	    				a = a.substring(0, mark-1)+"1"+a.substring(mark);
	    				b = b.substring(0, mark-1)+"0"+b.substring(mark);
	    			}
	    		}
	    		else if (holdA.charAt(0)!='?' && holdB.charAt(0)=='?'){
	    			int t1 = Math.abs(Integer.parseInt(holdA)-Integer.parseInt(""+ ((Integer.parseInt(""+holdA.charAt(0))+9)%10)+ holdB.charAt(1)));
	    			int t2 = Math.abs(Integer.parseInt(holdA)-Integer.parseInt(""+ ((Integer.parseInt(""+holdA.charAt(0))+10)%10)+ holdB.charAt(1)));
	    			int t3 = Math.abs(Integer.parseInt(holdA)-Integer.parseInt(""+ ((Integer.parseInt(""+holdA.charAt(0))+11)%10)+ holdB.charAt(1)));
	    			
	    			int min = Math.min(t1, Math.min(t2, t3));
	    			
	    			if (min==t1){
	    				b = b.substring(0, mark-1)+((Integer.parseInt(""+holdA.charAt(0))+9)%10)+b.substring(mark);
	    			}
	    			else if (min==t2){
	    				
	    				b = b.substring(0, mark-1)+((Integer.parseInt(""+holdA.charAt(0))+10)%10)+b.substring(mark);
	    			}
	    			else if (min==t3){
	    				
	    				b = b.substring(0, mark-1)+((Integer.parseInt(""+holdA.charAt(0))+11)%10)+b.substring(mark);
	    			}
	    		}
	    		else if (holdA.charAt(0)=='?' && holdB.charAt(0)!='?'){
	    			int t1 = Math.abs(Integer.parseInt(holdB)-Integer.parseInt(""+ ((Integer.parseInt(""+holdB.charAt(0))+9)%10)+ holdA.charAt(1)));
	    			int t2 = Math.abs(Integer.parseInt(holdB)-Integer.parseInt(""+ ((Integer.parseInt(""+holdB.charAt(0))+10)%10)+ holdA.charAt(1)));
	    			int t3 = Math.abs(Integer.parseInt(holdB)-Integer.parseInt(""+ ((Integer.parseInt(""+holdB.charAt(0))+11)%10)+ holdA.charAt(1)));
	    			
	    			int min = Math.min(t1, Math.min(t2, t3));
	    			
	    			if (min==t1){
	    				a = a.substring(0, mark-1)+((Integer.parseInt(""+holdB.charAt(0))+9)%10)+a.substring(mark);
	    			}
	    			else if (min==t2){
	    				
	    				a = a.substring(0, mark-1)+((Integer.parseInt(""+holdB.charAt(0))+10)%10)+a.substring(mark);
	    			}
	    			else if (min==t3){
	    				
	    				a = a.substring(0, mark-1)+((Integer.parseInt(""+holdB.charAt(0))+11)%10)+a.substring(mark);
	    			}
	    		}
	    		
	    	}
	    	System.out.println(a+" "+b);
	    	
	    	for (int j = 0; j<a.length(); j++){
	    		
	    		if (flag ==0){
	    			if (a.charAt(j)!='?' && b.charAt(j)!='?'){
	    				if (a.charAt(j)>b.charAt(j)) flag = 1; 
	    				else if (a.charAt(j)<b.charAt(j)) flag = 2;
	    				rA+=a.charAt(j);
	    				rB+=b.charAt(j);
	    				
	    			}
	    			if (a.charAt(j)=='?' && b.charAt(j)=='?'){
	    				rA+='0'; rB+='0';
	    			}
	    			if (a.charAt(j)=='?' && b.charAt(j)!='?'){
	    				rA+=b.charAt(j); rB+=b.charAt(j);
	    			}
	    			if (a.charAt(j)!='?' && b.charAt(j)=='?'){
	    				rA+=a.charAt(j); rB+=a.charAt(j);
	    			}
	    			
	    		}
	    		else if (flag ==1){
	    			if (a.charAt(j)=='?'){
	    				rA+='0';
	    			}else{
	    				rA+=a.charAt(j);
	    			}
	    			if (b.charAt(j)=='?'){
	    				rB+='9';
	    			}else{
	    				rB+=b.charAt(j);
	    			}
	    		}
	    		else if (flag ==2){
	    			if (a.charAt(j)=='?'){
	    				rA+='9';
	    			}else{
	    				rA+=a.charAt(j);
	    			}
	    			if (b.charAt(j)=='?'){
	    				rB+='0';
	    			}else{
	    				rB+=b.charAt(j);
	    			}	
	    		}
	    		
	    	}
	    	answer = rA+" "+rB;
	    	System.out.println("Case #"+(i+1)+": "+answer);
	    	out.println("Case #"+(i+1)+": "+answer);
	    }
	
	    
	    // answer output

    	out.close();	    
	    System.exit(0);                               // don't omit this!
	  }

}