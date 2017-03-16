package googlecodejam;
import java.io.*;
import java.util.*;

public class gettingthedigits {


	  public static void main (String [] args) throws IOException {
	    // Use BufferedReader rather than RandomAccessFile; it's much faster
	    BufferedReader f = new BufferedReader(new FileReader("A-small-attempt0.in"));
	                                                  // input file name goes above
	    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gettingthedigits.out")));
	    // Use StringTokenizer vs. readLine/split -- lots faster
	    StringTokenizer st = new StringTokenizer(f.readLine());
							  // Get line, break into tokens
	    
	   //enter program here
	    int cases = Integer.parseInt(st.nextToken());
	    for (int i = 0; i<cases; i++){
	    	st = new StringTokenizer(f.readLine());
	    	String s = st.nextToken();
	    	String answer = "";
	    	int[] chars = new int[26];
	    	for (int j=0; j<s.length(); j++){
	    		chars[s.charAt(j)-65] +=1;
	    	}
	    	LinkedList<Integer> vals = new LinkedList<Integer>();
	    	
	    	//zeroes
	    	for (int j = 0; j<chars['Z'-65]; j++){
	    		vals.add(0);
	    		chars['E'-65]-=1;
	    		chars['R'-65]-=1;
	    		chars['O'-65]-=1;
	    	}
	    	chars['Z'-65]=0;
	    	
	    	//two
	    	for (int j = 0; j<chars['W'-65]; j++){
	    		vals.add(2);
	    		chars['T'-65]-=1;
	    		chars['O'-65]-=1;
	    	}
	    	chars['W'-65]=0;
	    	
	    	//four
	    	for (int j = 0; j<chars['U'-65]; j++){
	    		vals.add(4);
	    		chars['F'-65]-=1;
	    		chars['R'-65]-=1;
	    		chars['O'-65]-=1;
	    	}
	    	chars['U'-65]=0;
	    	
	    	//six
	    	for (int j = 0; j<chars['X'-65]; j++){
	    		vals.add(6);
	    		chars['S'-65]-=1;
	    		chars['I'-65]-=1;
	    	}
	    	chars['X'-65]=0;
	    	
	    	//eight
	    	for (int j = 0; j<chars['G'-65]; j++){
	    		vals.add(8);
	    		chars['E'-65]-=1;
	    		chars['I'-65]-=1;
	    		chars['H'-65]-=1;
	    		chars['T'-65]-=1;
	    	}
	    	chars['G'-65]=0;
	    	
	    	//five
	    	for (int j = 0; j<chars['F'-65]; j++){
	    		vals.add(5);
	    		chars['I'-65]-=1;
	    		chars['V'-65]-=1;
	    		chars['E'-65]-=1;
	    	}
	    	chars['F'-65]=0;
	    	
	    	//seven
	    	for (int j = 0; j<chars['V'-65]; j++){
	    		vals.add(7);
	    		chars['S'-65]-=1;
	    		chars['E'-65]-=1;
	    		chars['E'-65]-=1;
	    		chars['N'-65]-=1;
	    	}
	    	chars['V'-65]=0;

	    	//three
	    	for (int j = 0; j<chars['T'-65]; j++){
	    		vals.add(3);
	    		chars['H'-65]-=1;
	    		chars['R'-65]-=1;
	    		chars['E'-65]-=1;
	    		chars['E'-65]-=1;
	    	}
	    	chars['T'-65]=0;
	    	
	    	//one
	    	for (int j = 0; j<chars['O'-65]; j++){
	    		vals.add(1);
	    		chars['N'-65]-=1;
	    		chars['E'-65]-=1;
	    	}
	    	chars['O'-65]=0;
	    	
	    	//nine
	    	for (int j = 0; j<chars['E'-65]; j++){
	    		vals.add(9);
	    		chars['N'-65]-=1;
	    		chars['I'-65]-=1;
	    		chars['N'-65]-=1;
	    	}
	    	chars['E'-65]=0;
	    	
	    	Collections.sort(vals);
	    	for (int j: vals){
	    		answer+=j;
	    	}
	    	System.out.println("Case #"+(i+1)+": "+answer);
	    	out.println("Case #"+(i+1)+": "+answer);
	    }
	
	    
	    // answer output

    	out.close();	    
	    System.exit(0);                               // don't omit this!
	  }

}