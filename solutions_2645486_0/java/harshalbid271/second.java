import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

import javax.swing.text.html.MinimalHTMLWriter;


public class second {

	public static void main(String[] args) throws FileNotFoundException {

		Scanner sc=new Scanner((new FileReader("a.txt")));
		int cases=sc.nextInt();
		
		for(int counter=0;counter<cases;counter++)
		{
			long e=sc.nextLong();
			long r=sc.nextLong();
			
			long gain=0;
			long currE=e;
			
			int n=sc.nextInt();
			
			long arr[]=new long[n];
			int length[]=new int[n];
			int indexOfnext[]=new int[n];
			
			int lastIndex=0;
			long max=0;
			for(int i=0;i<n;i++)
			{
				arr[i]=sc.nextLong();
//				if(i==0)
//				{
//					max=arr[0];
//				}
//				
//				if(arr[i]>arr[lastIndex])
//				{
//					max=arr[i];
//					length[lastIndex]=i-lastIndex;
//					lastIndex=i;
//				}
			}

			for(int i=0;i<n;i++)
			{
				boolean flag=true;
				for(int j=i;j<n;j++)
				{
					if(arr[j]>arr[i])
					{
						flag=false;
						indexOfnext[i]=j;
						length[i]=j-i;
						break;
					}
				}
				if(flag)
					length[i]=-1;
			}
			
			for(int i=0;i<n;i++)
			{
//				if(length[i]>=(int)(e/r))
//				{
//					gain+=arr[i]*currE;
//					currE=0;
//				}
//				
				if(length[i]==-1)
				{
//					System.out.println("detected");
					gain+=arr[i]*currE;
					currE=r;
					continue;
				}
				if(length[i]*r+currE>=e)
				{
					gain+=arr[i]*Math.min((currE+r*length[i])-e,currE);
					currE-=Math.min((currE+r*length[i])-e,currE);
				}
				
				if(i==n-1)
				{
					gain+=arr[i]*currE;
				}
				currE+=r;
			}
			
			System.out.println("Case #"+(counter+1)+": "+gain);
		}
	}

}
