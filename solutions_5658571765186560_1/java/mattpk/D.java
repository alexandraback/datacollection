import java.io.*;
import java.util.*;

public class D
{
  public static void main (String[] args) throws Exception
  {
  Scanner in = new Scanner(new File("D-large.in"));
  // Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
    
    int n = in.nextInt();
    for(int t =0; t<n; t++)
    {
      boolean rWin=false;
      int x = in.nextInt();
      int r = in.nextInt();
      int c = in.nextInt();
      
      if ((r*c)%x != 0) rWin = true;
      else
      {
        // pick a block that doesn't fit
        if (x>r && x>c) rWin=true;
        else if (Math.min(r,c)*2+1<=x) rWin = true;
        else
        {
          // can richard put a hhole in that can't be removed?
          
          if (Math.min(r,c)>1)
          {
          if (Math.min(r,c)%2!=0 && x>=2*Math.min(r,c)-1) rWin=true;
          if (Math.min(r,c)%2==0 && x>=2*Math.min(r,c)) rWin=true;
          }
        }
      }
        String ans = rWin?"RICHARD":"GABRIEL";
      out.println("Case #" + (t+1) + ": " + ans);
      System.out.println("Case #" + (t+1) + ": " + ans);
    }
    in.close();
    out.close();
  }
}