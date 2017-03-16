import java.io.*;
import java.util.*;
import java.math.*;

public class B
{

	public static void main(String[] args) throws Exception
	{
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		int T=Integer.parseInt(in.readLine());
		

		for (int i=1; i<=T; i++)
		{
      String line=in.readLine();
      String[] temp=line.split("[ ]+");
      int N=Integer.parseInt(temp[0]);
      int M=Integer.parseInt(temp[1]);
      int[][] grid=new int[N][M];
      for (int r=0; r<N; r++)
      {
        line=in.readLine();
        temp=line.split("[ ]+");
        for (int c=0; c<M; c++) grid[r][c]=Integer.parseInt(temp[c]);
      }
      String ans=solve(grid);
      System.out.println("Case #"+i+": "+ans);
    }

		in.close();
	}
	

	public static String solve(int[][] grid)
  {
    boolean[][] used=new boolean[grid.length][grid[0].length];
    int usedCount=0;
    
    for (int num=1; num<=100; num++)
    {
      for (int r=0; r<grid.length; r++)
      {
        boolean ok=true;
        for (int c=0; c<grid[0].length; c++)
        {
          if (used[r][c]) continue;
          if (grid[r][c]!=num)
          {
            ok=false;
            break;
          }
        }
        
        if (ok)
        {
          for (int c=0; c<grid[0].length; c++)
          {
            if (used[r][c]) continue;
            used[r][c]=true;
            usedCount++;
          }        
        }
      }
      
      for (int c=0; c<grid[0].length; c++)
      {
        boolean ok=true;
        for (int r=0; r<grid.length; r++)
        {
          if (used[r][c]) continue;
          if (grid[r][c]!=num)
          {
            ok=false;
            break;
          }
        }
        
        if (ok)
        {
          for (int r=0; r<grid.length; r++)
          {
            if (used[r][c]) continue;
            used[r][c]=true;
            usedCount++;
          }        
        }
      }      
    }
    
    if (usedCount==grid.length*grid[0].length) return "YES";
    return "NO";
  }
}