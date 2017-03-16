import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;


public class question3CodeJam {
	
	public int MAX=0;
	public int MIN=0;
	public int COUNTERVALS = 0;
	public int findInversions(){
		
		for(int i=MIN;i<=MAX;i++){
			if(i<10){
				continue;
			}
			String finalizeVals = i+"";
			String tmpString1 = i+"";
			String tmpString2 = "";
			//first string
			HashMap<Integer, Integer> valFound = new HashMap<Integer, Integer>();
			for(int j=0;j<finalizeVals.length();j++){
				String part1 = tmpString1.substring(j+1, tmpString1.length());
				String part2 = tmpString1.substring(0,j+1);
				tmpString2 = part1 + part2;
				int val1;
				try{
					val1 = Integer.parseInt(tmpString1);
				} catch (NumberFormatException ex){
					val1 = 0;
				}
				int val2;
				try{
					val2 = Integer.parseInt(tmpString2);
				} catch (NumberFormatException ex){
					val2 = 0;
				}
				//int val1 = Integer.parseInt(tmpString1);
				//int val2 = Integer.parseInt(tmpString2);
				if ((MIN <= val1) && (val1 < val2) && (val2 <= MAX)) {
					if(valFound.containsKey(val2)){
						System.out.println("(" + val1 + " , " + val2 +")");
					} else {
						valFound.put(val2, 1);
						COUNTERVALS++;
						//System.out.println("(" + val1 + " , " + val2 +")");
					}
					
					//System.out.println("(" + val1 + " , " + val2 +")");
				}
			}
			//take good care of 0s for sure
		}
		return COUNTERVALS;
	}
	public static void main(String[] args){
		
	    try{
		    File file = new File(args[0]);
		    
		    FileWriter fstream = new FileWriter(args[1]);
		    BufferedWriter out = new BufferedWriter(fstream);
		    
		    BufferedReader in = new BufferedReader(new FileReader(file));
		    
		    String line = in.readLine();
		    //here line is the number of rounds
		    int counter=0;
		    int testCase = Integer.parseInt(line);
		    
		    while (counter<testCase) {
		    	question3CodeJam tmp = new question3CodeJam();
		    	String inline = in.readLine();
		    	String[] val = inline.split(" ");
		    	
		    	//initializing
		    	tmp.MIN = Integer.parseInt(val[0]);
		    	tmp.MAX = Integer.parseInt(val[1]);
		    	
		    	++counter;
		    	//System.out.println("Case #" + counter + ": " + tmp.computeAtLeastP());
		    	//out.write(inline);
		    	out.write("Case #" + counter + ": " + tmp.findInversions());
		    	out.write("\n");
	    	}
		    out.close();
		    in.close();
	    }
	    catch(IOException e){
	    	
	    	System.out.println("IO Error");
	    }
	    catch (ArrayIndexOutOfBoundsException e){
	    	System.out.println("Array Error");
	    	e.printStackTrace();
	    }
		
	}
}
