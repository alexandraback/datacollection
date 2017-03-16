import java.io.*;
import java.util.*;
import java.math.*;

public class C
{
  static int R,N,M,K;
  static long maxTime;    //per case
	public static void main(String[] args) throws Exception
	{
    int T;	
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		T=Integer.parseInt(in.readLine());
    System.out.println("Case #"+1+":");		
    
		String line=in.readLine();		
		String[] temp=line.split("[ ]+");		
		R=Integer.parseInt(temp[0]);
		N=Integer.parseInt(temp[1]);             //N independent numbers
		M=Integer.parseInt(temp[2]);            //numbers between 2 and M
		K=Integer.parseInt(temp[3]);					 //num products
		
		maxTime=(20*60*1000)/R;
		

		for (int i=1; i<=R; i++)
		{
		  line=in.readLine();
		  temp=line.split("[ ]+");
		  long[] a=new long[K];
		  for (int k=0; k<K; k++) a[k]=Long.parseLong(temp[k]);		  
      String ans=solveSmall2(a);
      System.out.println(ans);
    }

		in.close();
	}
	

  //use simulation!!!
	public static String solveSmall2(long[] a)
  {
    long oldTime=System.currentTimeMillis();
    long iter=0;
    
    while(System.currentTimeMillis() - oldTime < maxTime)
    {
      int[] nums=new int[N];
      for (int k=0; k<N; k++)
      {
        nums[k]=(int)(Math.random()*(M-1)+2); 
        //System.out.print(nums[k]+" ");
      }
      //System.out.println();
      
      
      Set<Long> products=new HashSet<Long>();      
      
      for (int k=0; k<(1<<N); k++)
      {
        long prod=1;
        for (int m=0; m<N; m++)
          if ((k&(1<<m))>0) prod*=nums[m];
          
        products.add(prod);
      }
      
      boolean ok=true;
      for (int k=0; k<a.length; k++)
      {
        if (!products.contains(a[k]))
        {
          ok=false;
          break;
        }
      }
      
      //YAY!
      if (ok)
      {
        String ans="";
        for (int k=0; k<N; k++) ans+=nums[k];
        //System.out.println("iter "+iter);
        return ans;
      }
      iter++;
    }
    
    String empty="";
    for (int i=0; i<N; i++) empty+=2;
    return empty;
  }
  
  public static String makeKey(int[] nums)
  {
    String key="";
    for (int i=0; i<N; i++) key+=nums[i];
    return key;
  }
  
  public static String solveSmall1(int[] a)
  {
    int[] num=new int[N];
    for (num[0]=2; num[0]<=M; num[0]++)
      for (num[1]=2; num[1]<=M; num[1]++)
        for (num[2]=2; num[2]<=M; num[2]++)
        {
          Set<Integer> products=new HashSet<Integer>();
          for (int i=0; i<(1<<N); i++)
          {
            int prod=1;
            for (int k=0; k<N; k++)
            {
              if ((i&(1<<k))>0) prod*=num[k];
            }
            products.add(prod);
          }
          
          boolean ok=true;
          for (int i=0; i<a.length; i++)
          {
            if (!products.contains(a[i]))
            {
              ok=false;
              break;
            }
          }
          
          if (ok)
          {
            //System.out.println(num[0]+" "+num[1]+" "+num[2]);
            return ""+num[0]+""+num[1]+""+num[2];
          }
        }
        
    return "nothing";
  }
}