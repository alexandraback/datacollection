import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class prob3 {
	public static void main(String args[]) throws IOException {
		
		int cases;
		int flag=1;
		int n;
		int k;
		int t;
		int[] data;
		int maxclr;
		int counter = 0;
		int temp;
		float sum;
		float[] res = null;
		float lam = 0;
		float plus;
		float lam2;
		FileWriter fstream = new FileWriter("out3.txt");
    	BufferedWriter out = new BufferedWriter(fstream);
		
		FileReader isr = new FileReader(args[0]);
		Scanner src = new Scanner(isr);
    
		cases = src.nextInt();
		
		for(int i=0;i<cases;i++)
		{
			plus = 0;
			sum = 0;
			n=src.nextInt();
			data = new int[n];
			res = new float[n];
			for(int j=0;j<n;j++)
			{
				data[j] = src.nextInt();
//				if(data[j]>0)
//					plus++;
			}
			
			for(int j=0;j<n;j++)
			{
				sum = sum + data[j];
			}
			
			lam = (float) ((2.0*sum)/(float)n);
			System.out.println(lam);
			plus = sum;
			counter = n;
			for(int j=0;j<n;j++)
			{
				if(data[j]>lam)
				{	plus = plus - data[j];
					counter--;	}
			}
			
			lam2 = ((sum+plus)/(float)counter);
			System.out.println(lam2);
			for(int j=0;j<n;j++)
			{	
				if(data[j]>lam)
					res[j] = 0;
				else
					res[j] = 100*(lam2-data[j])/sum;
			}	
			try{
				out.write("Case #"+(i+1)+": ");
				for(int j=0;j<n;j++)
				{
					out.write(res[j]+" ");
				}
		    	out.write("\r\n");
		    	}catch (Exception e){
		    	System.err.println("Error: " + e.getMessage());
		    	}	
		}
		out.close();
	}
}
