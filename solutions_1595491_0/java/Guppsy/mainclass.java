import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class mainclass {
	
	public static void main(String args[]) throws IOException {
		
		int cases;
		int n;
		int s;
		int p;
		int t;
		int flag;
		int counter;
		int[] data;
		int[] arr;
		int surp;
		
		FileWriter fstream = new FileWriter("out.txt");
    	BufferedWriter out = new BufferedWriter(fstream);
		
		FileReader isr = new FileReader(args[0]);
		Scanner src = new Scanner(isr);
    
		cases = src.nextInt();
		
		for(int j=0;j<cases;j++)
		{
			counter = 0;
			surp = 0;
			n = src.nextInt();
			s = src.nextInt();
			p = src.nextInt();
			data = new int [n];
			arr = new int[31];
			for(int i=0;i<31;i++)
				arr[i] = 0;
			
			for(int i=0;i<n;i++)
			{
				arr[src.nextInt()]++;
			}
			
			for(int i=0;i<31;i++)
			{
				if(i>=(p*3-2))
					counter = arr[i]+counter;
				if((i==p*3-3||i==p*3-4)&&i>0)
					surp = arr[i]+surp;
			}
			
			if(surp>s)
				counter = s+counter;
			else
				counter = surp+counter;
			
			try{
				out.write("Case #"+(j+1)+": "+counter);
		    	out.write("\r\n");
		    	}catch (Exception e){
		    	System.err.println("Error: " + e.getMessage());
		    }
		}
		
		out.close();
	}
}
