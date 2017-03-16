import java.io.*;
import java.util.*;
import java.math.*;

public class B
{

	public static void main(String[] args) throws Exception
	{
    int T;	
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		T=Integer.parseInt(in.readLine());
		
		

		for (int i=1; i<=T; i++)
		{
		  String line=in.readLine();
		  int N=Integer.parseInt(line);
		  line=in.readLine();
		  String[] trains=line.split("[ ]+");

      String ans=solve(trains);
      System.out.println("Case #"+i+": "+ans);
    }

		in.close();
	}
	
	
	public static String solve(String[] trains)
	{
	   int n=trains.length;
	   
	   long valid=0;
	   
	   int[] ind=new int[n];
	   for (int i=0; i<n; i++) ind[i]=i;
	   
	   int count=0;
	   
	   do
	   {
	     if (isValid(trains,ind)) count++;
	   }
	   while(nextPermutation(ind));
	   
	   return ""+count;
  }
  
  public static boolean isValid(String[] trains, int[] ind)
  {
    char prev='Q';
    boolean[] seen=new boolean[26];
    for (int i=0; i<ind.length; i++)
    {
      int i2=ind[i];
      for (int k=0; k<trains[i2].length(); k++)
      {
        char cur=trains[i2].charAt(k);
        int val=(int)(cur-'a');
        if (seen[val] && prev!=cur) return false;
        
        seen[val]=true;
        prev=cur;
      }
    }
    
    return true;
  }
  
	//elements in a have to be sorted in ascending order	//changes the elements to achieve the next permutation	//returns false if there are no more permutations	public static boolean nextPermutation(int[] a)	{		int N=a.length;		int i=N-2;		for (; i>=0; i--)			if (a[i]<a[i+1])				break;		if (i<0) return false;				for (int j=N-1; j>=i; j--)		{			if (a[j]>a[i])			{				int temp=a[i];				a[i]=a[j];				a[j]=temp;				break;					}		}		for (int j=i+1; j<(N+i+1)/2; j++)		//reverse from a[i+1] to a[N-1]		{			int temp=a[j];			a[j]=a[N+i-j];			a[N+i-j]=temp;		}		return true;	}  
}