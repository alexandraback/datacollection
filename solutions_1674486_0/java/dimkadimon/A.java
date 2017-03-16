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
      int N=Integer.parseInt(in.readLine());       
      int[][] a=new int[N][N];
      for (int k=0; k<N; k++)
      {
        String[] temp=in.readLine().split(" ");
        for (int m=1; m<temp.length; m++)
        {
          int val=Integer.parseInt(temp[m]);
          a[k][val-1]=1;
        }
      }     
      String ans=solve(a);
      System.out.println("Case #"+i+": "+ans);
    }

		in.close();
	}
	
	
	//matrix a multiply by matrix b	//(n by a) x (a by m)	public static int[][] matrixMultiply(int[][] a, int[][] b)	{		int[][] c=new int[a.length][b[0].length];		for (int i=0; i<a.length; i++)			for (int m=0; m<b[0].length; m++)				for (int k=0; k<b.length; k++)					c[i][m]+=a[i][k]*b[k][m];		return c;	}	

	public static String solve(int[][] a)
  {
    int N=a.length;
    int[][] b=new int[N][N];
    int[][] c=new int[N][N];
    for (int i=0; i<N; i++) for (int k=0; k<N; k++){ b[i][k]=a[i][k]; c[i][k]=a[i][k];}
    
    for (int i=2; i<=N; i++)
    {
      b=matrixMultiply(b,a);
      for (int k=0; k<N; k++)
      {
        for (int m=0; m<N; m++)
        {
          c[k][m]+=b[k][m];
          if (c[k][m]>=2) return "Yes";
        }
      }
    }
    //print(a);
    //System.err.println();
    //print(c);
    //for (int i=0; i<N; i++)
     // for (int k=0; k<N; k++)
     //   if (c[i][k]>=2) return "Yes";
    return "No";
  }
  
  public static void print(int[][] a)
  {
    for (int i=0; i<a.length; i++)
    {
      for (int k=0; k<a.length; k++) System.err.print(a[i][k]+" ");
      System.err.println();
    }
  }
}