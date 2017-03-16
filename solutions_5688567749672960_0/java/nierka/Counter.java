import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Scanner;


public class Counter {
	public static void generateOutput (ArrayList<Long> TestCases) 
	{
		String outFileName = "C:\\dev\\projects\\R2_1Counter\\src\\output.txt";
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

		ArrayList<Long> TestCases;
		
		TestCases = new ArrayList<Long>();
		
		String fileName = "C:\\dev\\projects\\R2_1Counter\\src\\Example.txt";
		
		try 
		{
			InputStream in = new FileInputStream(new File(fileName));
			Scanner reader = new Scanner(in);
	        

	        int cntTests = reader.nextInt();
	        
	        for (int i = 0; i<cntTests; i++) 
	        {
	        	System.out.println("TEST NUMBER " + i);
	        	long N = reader.nextLong();
	        	String Number = "" + N;
	        	long answer = 0;
	        	
	        	long first = Integer.parseInt(""+Number.charAt(0));
	        	long last = Integer.parseInt(""+Number.charAt(Number.length()-1));
	        	long zeros = first;
	        	for (long j=0; j<Number.length()-1; j++) {
	        		zeros = zeros * 10;
	        	}
	        	if ((zeros == N) && (Number.length() > 1)) {
	        		first = first - 1;
	        	}
	        	
	        	long cnt = Number.length();
	        	if (cnt > 2) {
	        		answer = 20 + (cnt - 3) * 19;
	        		//answer = (cnt - 2) * 20;
	        		answer = answer + 19 - (9 - first);
		        	
		        	
	        	} else {
	        		if (cnt == 2) {
	        			answer = answer + 11 + first;
	        			
	        		} else {
	        			answer = answer + first;
	        		}
	        		
	        	}
	        	
	        	if ((first == 1) && (Number.length() > 1)) {
	        		answer = answer - 1;
	        	}
	        	long tmp=first;
	        	for (long j=0; j<cnt-1; j++) {
	        		tmp = tmp * 10;
	        	}
	        	
	        	tmp = tmp + 1;
	        	
	        	if (Number.length() > 1) {
	        	answer = answer + (N-tmp);
	        	}
	        	
	        	
	           
	        
	        	
	        	
	        	
	        	System.out.println(N);
	        	
	        	
		        	
	        	TestCases.add(answer);
	        	System.out.println(answer);
	        
	        }
	        reader.close();
		} catch (Exception ex)	{
			ex.printStackTrace();
		}
		
		generateOutput(TestCases);
		System.out.println("Done");

	}

}
