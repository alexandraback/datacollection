package Year2013.round1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Manageyourenergy {
	
	public static void main(String[] args) throws IOException{
		
		Worker2 worker = new Worker2();
		worker.work();
		
	}
}


class Worker2{
	
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
	        	
	        	int e = Integer.parseInt(array[0]);
	        	int r = Integer.parseInt(array[1]);
	        	int n = Integer.parseInt(array[2]);
	        	int a[] = new int[n];	
	        	array = inputStream.readLine().split(" ");
	        	for(int j=0;j<n;j++){
	        		a[j] = Integer.parseInt(array[j]);
	        	}
	        	int result = test(e,r,n,a);
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
		
		
		
	int test(int e,int r,int n,int[] a){
		
		int result = 0;
		int maxA = 0;
		int maxIndex = 0;
		int totalA = 0;
		for(int i=0;i<n;i++){
			if(a[i]>maxA){
				maxA = a[i];
				maxIndex = i;
			}
			totalA += a[i];
		}
		
		if (e==r){
			result = totalA*r;
		}
		
		else{
			
			return gain(0, 0, e,  e, r, n, a);
		}
		
		return result;
	}
	
	int gain(int i, int g, int ce, int e,int r,int n,int[] a){
		
		
		if(i<n){
			
			
			int max = 0;
			
			for(int k=0;k<=ce;k++){
				
				
				
				int t = gain(i+1, g+k*a[i], (ce+r-k)>e?e:(ce+r-k), e,r,n,a);
				if(t>max){
					max = t;
				}
			}
			
			return max;
			
		}
		return g;
	}
	
	
}