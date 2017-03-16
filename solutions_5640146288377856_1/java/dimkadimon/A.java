import java.io.*;
import java.util.*;
import java.math.*;

public class A
{  
	public static void main(String[] args) throws Exception
	{
    int T;	
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		T=Integer.parseInt(in.readLine());
		

		for (int i=1; i<=T; i++)
		{
		  String[] temp=in.readLine().split("[ ]+");		  
		  int R=Integer.parseInt(temp[0]);
		  int C=Integer.parseInt(temp[1]);
		  int W=Integer.parseInt(temp[2]);		  		  

      String ans=solve(R,C,W);
      System.out.println("Case #"+i+": "+ans);
    }

		in.close();
	}
	
	
	public static String solve(int R, int C, int W)
  {  
    int ans=(R-1)*(C/W)+(C/W)+(W-1);
    if (C%W>=1) ans++;
    return ""+ans;
  }
}