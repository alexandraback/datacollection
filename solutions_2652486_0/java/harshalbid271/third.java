import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StringReader;
import java.util.Scanner;
import java.util.StringTokenizer;


public class third {

	public static void main(String[] args) throws IOException 
	{

		Scanner sc=new Scanner((new FileReader("a.txt")));
		int cases=sc.nextInt();

		for(int counter=1;counter<=cases;counter++)
		{
			int r=sc.nextInt();
			int n=sc.nextInt();
			int m=sc.nextInt();
			int k=sc.nextInt();
			
			System.out.println("Case #"+counter+":");
			for(int i=0;i<r;i++)
			{
				int arr[]=new int[k];
						
				for(int j=0;j<k;j++)
				{
					arr[j]=sc.nextInt();
				}
				
				int sol[]=new int[3];
				
				sol[0]=2;
				sol[1]=2;
				sol[2]=2;
				
				boolean flag=false;
				outer:
				do
				{
					flag=false;
					for(int j=0;j<k;j++)
					{
						if(!isPossible(arr[j], sol[0], sol[1], sol[2]))
						{
							flag=true;
							sol[2]++;
							if(sol[2]==6)
							{
								sol[2]=2;
								sol[1]++;
							}
							if(sol[1]==6)
							{
								sol[1]=2;
								sol[0]++;
							}
							if(sol[0]==6)
								continue outer;
						}
					}
				}while(flag);
				
				System.out.println(sol[0]+""+sol[1]+""+sol[2]);
			}
		}
	}

	public static boolean isPossible(int num, int a, int b, int c)
	{
		if(num==a ||
				num==b||
				num==c||
				num==a*b||
				num==b*c||
				num==a*c||
				num==a*b*c||
				num==1)
			return true;
		else 
			return false;
	}
}