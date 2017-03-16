package Year2013.round1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;



public class Bullseye {
	
	public static void main(String[] args) throws IOException{
		
		Worker1 worker = new Worker1();
		worker.work();
		
	}
}



class Worker1{
	
	BufferedReader 	inputStream = null;
    PrintWriter 	outputStream = null;
    String inputFileName = "/Users/baiyuchan0505/Documents/workspace/CodeJam/data/test.data";
	String outFileName   = "/Users/baiyuchan0505/Documents/workspace/CodeJam/data/output.txt";
	
	
	
	public void work() throws IOException{
		
		
		try {
	        inputStream = new BufferedReader(new FileReader(inputFileName));
	        outputStream = new PrintWriter(new FileWriter(outFileName));
	
	        String l;
	        
	        int T = Integer.parseInt(inputStream.readLine());
	        
	        for(int i=0;i<T;i++){
	        	
	        	String[] array = inputStream.readLine().split(" ");
	        	
	        	long r = Long.parseLong(array[0]);
	        	long t = Long.parseLong(array[1]);
	        		
	        	int result = test(r,t);
	        	System.out.println("Case #"+(i+1)+": "+result);
	        	outputStream.println("Case #"+(i+1)+": "+result);
	        	
	        }
		
		}catch(Exception e){
			e.printStackTrace();
		}
		finally{
			 if (inputStream != null) {
	             inputStream.close();
	         }
	         if (outputStream != null) {
	             outputStream.close();
	         }
		}
	}
		
		
		
	int test(long r ,long t){
		
		
		int i=0;
		r++;
		t -= (2*(r-1)+1);
		
		while(t>=0){
			i++;
			r+=2;
			t -= (2*(r-1)+1);
			
		}
			
			
			
		
		
		return i;
	}
	
}