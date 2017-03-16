import java.io.*;
import java.util.*;
import java.math.*;

public class B
{
  static int max=0;
	public static void main(String[] args) throws Exception
	{
    int T;	
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		T=Integer.parseInt(in.readLine());
		

		for (int i=1; i<=T; i++)
		{
		  String line=in.readLine();
		  String[] temp=line.split("[ ]+");
		  int E=Integer.parseInt(temp[0]);
		  int R=Integer.parseInt(temp[1]);
		  int N=Integer.parseInt(temp[2]);		  		  
		  
		  int[] v=new int[N];
		    line=in.readLine();
		    temp=line.split("[ ]+");		  
		  for (int k=0; k<N; k++) v[k]=Integer.parseInt(temp[k]);
		  
      String ans=solveSmall(E,R,N,v);
      System.out.println("Case #"+i+": "+ans);
    }

		in.close();
	}
	

  //use simulation!!!
	public static String solveSmall(int E, int R, int N, int[] v)
  {
    max=0;
    go(E,E,R,v,0,0);
    return ""+max;
  }
  
  public static void go(int E, int e, int R, int[] v, int cur, int gain)
  {
    if (cur>=v.length)
    {
      //System.out.println(cur+" "+gain);
      max=Math.max(max,gain);
      return;
    }
    
    for (int i=0; i<=E; i++)
    {
      if (i<=e) go(E, Math.min(E,e-i+R), R, v, cur+1, gain+i*v[cur]);
    }
  }
}