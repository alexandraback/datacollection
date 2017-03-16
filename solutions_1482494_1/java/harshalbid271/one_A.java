import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Vector;


public class one_A {


//	static int remaining,earned=0,played=0;
	
	public static void main(String args[]) throws FileNotFoundException
	{
		Scanner in=new Scanner(new FileReader("ina.in"));
		PrintWriter pw=new PrintWriter("outA.txt");
		
		int cases=in.nextInt();
		in.nextLine();
		
		for(int counter=1;counter<=cases;counter++)
		{
			int n=in.nextInt();
			in.nextLine();
			
			int remaining,earned=0,played=0;
			
			remaining=n;
			int arr[][]=new int[n][2];
			
			for(int j=0;j<n;j++)
			{
				arr[j][0]=in.nextInt();
				arr[j][1]=in.nextInt();
			}
			
			while(remaining!=0)
			{
				boolean flag=false;
				for(int i=0;i<n;i++)
				{
					if(arr[i][1]<=earned&&arr[i][1]!=-1)
					{
						arr[i][1]=-1;
						remaining--;
						
						if(arr[i][0]!=-1)
						{
							earned+=2;
						}
						else
							earned++;
						i=-1;
//						flag=true;
						played++;
					}
				}
				
//				if(flag)
//					continue;
				
				flag=false;
				int loc=-1;
				int max=-1;

				for(int i=0;i<n;i++)
				{					
					if(arr[i][0]<=earned&&arr[i][0]!=-1&&arr[i][1]!=-1)
					{
						if(max<arr[i][1])
						{
							max=arr[i][1];
							loc=i;
						}
//						flag=true;
//						earned++;
//						arr[i][0]=-1;
//						played++;
					}
				}
				
				if(loc!=-1)
				{
					flag=true;
					arr[loc][0]=-1;
					earned++;
					played++;
				}
				
				if(!flag&&remaining!=0)
				{
					pw.println("Case #"+(counter)+": Too Bad");
					break;
				}
			}
			if(remaining==0)
			{
				pw.println("Case #"+counter+": "+played);
				if(played<=n)
					System.out.println(counter);

			}
						
		}
		pw.close();
	}
}
