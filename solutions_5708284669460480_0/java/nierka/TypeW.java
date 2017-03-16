import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class TypeW {

	public static void generateOutput (ArrayList<Float> TestCases) 
	{
		String outFileName = "C:\\dev\\projects\\R3_2Type\\src\\output.txt";
		try { 
        File file = new File(outFileName);
        BufferedWriter output = new BufferedWriter(new FileWriter(file));
        for (int i =0; i < TestCases.size(); i++) {
        	output.write("Case #" + (i+1) + ": " + TestCases.get(i));
        	output.newLine();
        }
        
        output.close();
		} catch ( Exception e ) {
			e.printStackTrace();
		} 
		
	}
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {

		ArrayList<Float> TestCases;
		ArrayList<Integer> repeats = new ArrayList<Integer>();
 		
		TestCases = new ArrayList<Float>();
		
		String fileName = "C:\\dev\\projects\\R3_2Type\\src\\Example.txt";
		
		try 
		{
			InputStream in = new FileInputStream(new File(fileName));
			Scanner reader = new Scanner(in);
	        

	        int cntTests = reader.nextInt();
	        
	        for (int i = 0; i<cntTests; i++) 
	        {
	        	System.out.println("TEST NUMBER " + i);
	        	long K = reader.nextInt();
	        	long L = reader.nextInt();
	        	long S = reader.nextInt();
	        	String Letters = reader.next();
	        	String Target = reader.next();
	        	
	        	System.out.println(K+" "+L+" "+S+" "+Letters+" "+Target);
	        	
	        	
	        	
	        	float result = 0;
	        	repeats.clear();
	        	
	        	for (int j=0; j<Target.length(); j++) {
	        		String newS = Target.substring(j) + Target.substring(Target.length()-j);
	        		if (newS.compareTo(Target) == 0) {
	        			repeats.add(j);
	        			
	        		}
	        	}
	        	
	        	long wordsIn = 0;
	        	
	        		long left = S;
	        		for (int j=(repeats.size()-1); j>=0; j--) {
	        			long wLength = (repeats.get(j) + Target.length());
	        			long fits = left / wLength;
	        			
	        			left = left - (fits*wLength);
	        			
	        			wordsIn = wordsIn + (j+1) * fits;
	        		}
	        	
	        	float totalP = wordsIn;
	        	long totalFound = 0;
	        	
	        	for (int j=0; j<Target.length(); j++) {
	        		boolean found = false;
	        		
	        	    Pattern p = Pattern.compile(""+Target.charAt(j));
	        	    Matcher m = p.matcher(Letters);
	        	    int count = 0;
	        	    while (m.find()){
	        	    	count +=1;
	        	    	found = true;
	        	    	
	        	    } 
	        	    if (found) {
	        	    	totalFound++;
	        	    }
	        	    
	        	    totalP = totalP * (((float)count)/((float)Letters.length()));
	        	    
	        	}
		        
	        	if (totalFound == Target.length()) {
	        		result = wordsIn - (totalP);
	        	} else {
	        		result = 0;
	        	}
	        	TestCases.add(result);
	        	System.out.println(result);
	        
	        }
	        reader.close();
		} catch (Exception ex)	{
			ex.printStackTrace();
		}
		
		generateOutput(TestCases);
		System.out.println("Done");

	}

}
