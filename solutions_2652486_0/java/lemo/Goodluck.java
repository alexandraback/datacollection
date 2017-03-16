package Year2013.round1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Goodluck {
public static void main(String[] args) throws IOException{
		
		Worker3 worker = new Worker3();
		worker.work();
		
	}
}


class Worker3{
	
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
	        String[] array = inputStream.readLine().split(" ");
        	
        	int r = Integer.parseInt(array[0]);
        	int n = Integer.parseInt(array[1]);
        	int m = Integer.parseInt(array[2]);
        	int k = Integer.parseInt(array[2]);
	        
	        for(int i=0;i<r;i++){
	        	
	        	
	        	
	        	
	        	int a[] = new int[k];	
	        	array = inputStream.readLine().split(" ");
	        	for(int j=0;j<k;j++){
	        		a[j] = Integer.parseInt(array[j]);
	        	}
	        	int result = test(r,n,m,k,a);
	        	System.out.println(""+result);
	        	outputStream.println(""+result);
	        	
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
		
		
		
	int test(int r,int n,int m,int k,int[] a){
		
		
		int[] rate = new int[6];
		
		for(int i=0;i<k;i++){
			
			if(a[i]%2==0&&a[i]%4>0){
				rate[2] = 1;
			}
			if(a[i]%3==0){
				if(rate[3]==0)
					rate[3] = 1;
			}
			if(a[i]%9==0){
				if(rate[3]<2)
					rate[3] = 2;
			}
			if(a[i]%27==0){
				return 333;
			}
			if(a[i]%4==0){
				if(rate[4]<1)
				rate[4] = 1;
			}
			if(a[i]%16==0){
				if(rate[4]<2)
				rate[4] = 2;
			}
			if(a[i]%64==0){
				return 444;
			}
			if(a[i]%5==0){
				if(rate[5]<1)
				rate[5] = 1;
			}
			if(a[i]%25==0){
				if(rate[5]<2)
				rate[5] = 2;
			}
			if(a[i]%125==0){
				return 555;
			}
		}
		
		
		int result = 0;
		int tmp = 0;
		for(int i=0;i<6;i++){
			if(rate[i]==1){
				result = result*10+i;
				tmp++;
			}
			else if(rate[i]==2){
				result = result*100+(i*10+i);
				tmp+=2;
			}
		}
		
		
		if(tmp==2&&rate[4]==1){
			
			result = 0;
			for(int i=0;i<6;i++){
				if(rate[i]==1&&i!=4){
					result = i;
				}
			}
			result += 220;
		}
		else if(tmp==1){
			
			for(int i=0;i<6;i++){
				if(rate[i]==1){
					return i*100+i*10+i;
				}
			}
		}
		else if(tmp==0) {
			return 222;
		}
		
		
		return result;
	}
	
	
	
	
}
