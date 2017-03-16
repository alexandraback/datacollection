import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;


public class one_1 {

	
	public static void main(String args[]) throws FileNotFoundException
	{
		Scanner in=new Scanner(new FileReader("ina.in"));
		PrintWriter pw=new PrintWriter("outA.txt");
		
		int cases=in.nextInt();
		in.nextLine();
		
		for(int counter=1;counter<=cases;counter++)
		{
			int a=in.nextInt();
			int b=in.nextInt();
			
			in.nextLine();
			
			float arr[]=new float[a];
			float corr[]=new float[a];
			float incorr[]=new float[a];
			
			for(int i=0;i<a;i++)
			{
				arr[i]=in.nextFloat();
				corr[i]=(i>0?corr[i-1]:1)*arr[i];
				incorr[i]=1-corr[i];
			}
			
			float minimum=(b-a+1)*corr[a-1]+(b+b-a+2)*(incorr[a-1]);
			
			for(int i=1;i<a;i++)
			{
				int rem=a-i;
				float temp=i+(b-rem+1)*corr[rem-1]+(b+1+b-rem+1)*incorr[rem-1];
				
				if(temp<minimum)
					minimum=temp;
			}
			
			float temp=(a==b?corr[a-1]:0)*1+(b+2);
			if(temp<minimum)
				minimum=temp;
		
			pw.println("Case #"+counter+": "+minimum);
			
		}
		pw.close();
	}
}
