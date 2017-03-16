import java.util.*;
import java.io.*;

public class p2
{
  static int ans=1000;
  public static void main (String[]args)throws IOException
  {
    Scanner s=new Scanner (new File("B-small-attempt1.in"));
    PrintWriter out=new PrintWriter(new FileWriter("out.txt"));
    //Scanner s=new Scanner (System.in);
    
    int cases=s.nextInt();
    for (int n=0;n<cases;n++)
    {
      ans=1000;
      int people=s.nextInt();
      ArrayList<Integer>pan=new ArrayList<Integer>();
      for (int x=0;x<people;x++)
      {
        pan.add(s.nextInt());
      }
     // System.out.println (pan);
      recurse(pan,0);
      
      out.println ("Case #"+(n+1)+": "+ans+" ");
      System.out.println ("Case: #"+(n+1)+": "+ans+" ");
    }
    out.close();
  }
  
  public static ArrayList<Integer> move(ArrayList<Integer> arr,int move)
  {
    if (move==0)
    {
      for (int x=0;x<arr.size();x++)
      {
        arr.set(x,arr.get(x)-1);
        if (arr.get(x)==0)
        {
          arr.remove(x);
          x--;
        }
      }
    }
    else
    {
      arr.set(arr.size()-1,arr.get(arr.size()-1)-move);
      arr.add(move);
    }
    return arr;
  }
  
  public static void recurse(ArrayList<Integer>arr, int moves)
  {
    Collections.sort(arr);
    if (arr.size()==0)
    {
      if (moves<ans)
        ans=moves;
      return;
    }
    if (moves>=ans)return;
    recurse(move(copy(arr),0),moves+1);
    int big=arr.get(arr.size()-1);
    for (int x=1;x<=big/2;x++)
    {
      recurse(move(copy(arr),x),moves+1);
    }
  }
  
  public static ArrayList<Integer> copy (ArrayList<Integer> arr)
  {
    ArrayList<Integer>copy=new ArrayList<Integer>();
    for (int x=0;x<arr.size();x++)
    {
      copy.add(arr.get(x));
    }
    return copy;
  }
}