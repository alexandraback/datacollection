import java.io.*;
import java.util.*;
import java.math.*;

public class C
{
  final static int[] dr={0,-1,0,1};
  final static int[] dc={-1,0,1,0};


	public static void main(String[] args) throws Exception
	{
    int T;	
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		T=Integer.parseInt(in.readLine());
		
		

		for (int i=1; i<=T; i++)
		{
		  String line=in.readLine();
		  String[] temp=line.split("[ ]+");
		  int N=Integer.parseInt(temp[0]);
		  int M=Integer.parseInt(temp[1]);
		  int K=Integer.parseInt(temp[2]);		  		  

      String ans=solve(N,M,K);
      System.out.println("Case #"+i+": "+ans);
    }

		in.close();
	}
	
	
	public static String solve(int N, int M, int K)
  {
    //0: empty
    //1: cross
    //2: stone
    int[][] a=new int[N][M];
        
    int maxCross=(N-2)*(M-2);
    int iters=1000000;
    boolean print=false;
    
    int best=Integer.MAX_VALUE;
    
    if (N<=2 || M<=2) return ""+K;
        
    
    for (int iter=0; iter<iters; iter++)
    {
      generateRandom(a,maxCross);
      
      int total=0;
      int stones=0;
      for (int i=0; i<a.length; i++)
        for (int k=0; k<a[0].length; k++)
        {
          if (a[i][k]!=0) total++;
          if (a[i][k]==2) stones++;
        }
      
      if (total<=K)
      {
        stones=stones+(K-total);
        if (stones<best)
        {
          best=stones;
          if (print)
          {
            System.out.println(best);
            print(a);
          }
        }
      }
    }
    
    return ""+best;
  }
  
  public static void generateRandom(int[][] a, int maxCross)
  {
    for (int i=0; i<a.length; i++) for (int k=0; k<a[0].length; k++) a[i][k]=0;
  
    int cross=(int)(Math.random()*(maxCross+1));
    
    //place crosses    
    for (int i=1; i<=cross;)
    {
      int r=(int)(Math.random()*(a.length-2)+1);
      int c=(int)(Math.random()*(a[0].length-2)+1);
      if (a[r][c]==1) continue;
      
      a[r][c]=1;
      i++;
    }

    
    //print(a);
    
    
    //place stones
    for (int r=0; r<a.length; r++)
      for (int c=0; c<a[0].length; c++)
      {
        if (a[r][c]!=1) continue;
        
        for (int m=0; m<dr.length; m++)
        {
          int r2=r+dr[m];
          int c2=c+dc[m];
          if (r2<0 || r2>=a.length || c2<0 || c2>=a[0].length) continue;
          
          if (a[r2][c2]==0) a[r2][c2]=2;
        }
      }      
  }
  
  public static void print(int[][] a)
  {
    for (int r=0; r<a.length; r++)
    {
      for (int c=0; c<a[0].length; c++)
      {
        char q='q';
        if (a[r][c]==0) q='.';
        else if (a[r][c]==1) q='x';
        else q='o';
        
        System.out.print(q);
      }
      System.out.println();
    }
    System.out.println();
  }
}