import java.io.*;
import java.util.*;
import java.math.*;

public class C
{  
	public static void main(String[] args) throws Exception
	{
    int T;	
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		T=Integer.parseInt(in.readLine());
		

		for (int i=1; i<=T; i++)
		{
		  String[] temp=in.readLine().split("[ ]+");		  
		  int C=Integer.parseInt(temp[0]);
		  int D=Integer.parseInt(temp[1]);
		  int V=Integer.parseInt(temp[2]);		  	
		  temp=in.readLine().split("[ ]+");		  		  
		  int[] coins=new int[D];
		  for  (int k=0; k<D; k++) coins[k]=Integer.parseInt(temp[k]);

      String ans=solve(C,V,coins);
      System.out.println("Case #"+i+": "+ans);
    }

		in.close();
	}
	
	public static String solve(int C, int V, int[] coins)
  {  
    boolean[] canMake=new boolean[V+1];
    canMake[0]=true;
    
    for (int i=0; i<coins.length; i++)
      for (int k=V; k>=0; k--)
        if (canMake[k] && k+coins[i]<=V)
          canMake[k+coins[i]]=true;

    //for (int i=0; i<=V; i++) System.out.println(i+" "+canMake[i]);
    
    int count=0;
    while(true)
    {
      //find smallest that we cannot make
      int smallest=-1;
      for (int i=0; i<=V; i++)
        if (!canMake[i])
        {
          smallest=i;
          break;
        }
        
      if (smallest==-1) break;
      
      //System.out.println("adding "+smallest);
      
      for (int k=V; k>=0; k--)
        if (canMake[k] && k+smallest<=V)
          canMake[k+smallest]=true;      
          
      //for (int i=0; i<=V; i++) System.out.println(i+" "+canMake[i]);          
          
      count++;
    }
      
    return ""+count;
  }
}