import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class mainclass {
	
	public static void main(String args[]) throws IOException {
		
		int cases;
		int a;
		int b;
		int flag;
		int counter;
		int[] data;
		int temp = 0;
		int count = 0;
		int mc;

		FileWriter fstream = new FileWriter("out.txt");
    	BufferedWriter out = new BufferedWriter(fstream);
		
		FileReader isr = new FileReader(args[0]);
		Scanner src = new Scanner(isr);
    
		cases = src.nextInt();
		data = new int[2000000];
		for(int i=0;i<2000000;i++)
			data[i] = 0;
		
		for(int j=0;j<cases;j++)
		{
			a=src.nextInt();
			b=src.nextInt();
			counter = 0;
			
			for(int i=0;i<2000000;i++)
				data[i] = 0;
			
			flag = 0;
			
			for(int i=a;i<=b;i++)
			{
				count = 0;
//				System.out.print(i);
				if(data[i]==0)
				{
					count++;
					mc = numdig(i);
					temp = recnum(i,mc);
					data[i] = 1;
					for(int p=0;p<mc;p++)
					{
						if(temp>=a&&temp<=b&&data[temp]==0&&mc==numdig(temp))
						{
//							System.out.print(" "+temp);
							data[temp] = 1;
							count++;
						}
						temp = recnum(temp,mc);
					}	
					flag = flag+count;
				}		
//				System.out.println(" "+count);
				if(count>1)
					counter = counter + (count*(count-1))/2;
			}
			
//			System.out.println(" "+flag);
			
			try{
				out.write("Case #"+(j+1)+": "+counter);
		    		out.write("\r\n");
		    	}catch (Exception e){
		    	System.err.println("Error: " + e.getMessage());
		    }
		}
		
		out.close();		
	}			
	
	static int numdig(int n)
	{
		int count = 1;
		while(n/10>0)
		{
			count++;
			n = n/10;
		}
		return count;
	}
	
	static int recnum(int n,int p)
	{
		int pow = 1;
		int num;
		num = p-1;
		for(int i=0;i<num;i++)
		{
			pow = pow*10;
		}
		return (n/10)+(pow*(n%10));
	}
}
