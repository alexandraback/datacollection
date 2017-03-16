import java.io.*;
import java.util.*;

public class P1
{
  public static int[] save = new int[1000001];
  public static void main (String[] args) throws Exception
  {
    Scanner in = new Scanner(new File("A-small-attempt0.in"));
    //Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
    int n = in.nextInt();
    Arrays.fill(save,-1);
    for (int x =0; x<=20;x++)
      save[x] = x;
    for  (int x =0; x< save.length; x++)
      get(x);
    for(int t =0; t<n; t++)
    {
      int num = in.nextInt();
      String ans = ""+get(num);
      out.println("Case #" + (t+1) + ": " + ans);
      System.out.println("Case #" + (t+1) + ": " + ans);
    }
    in.close();
    out.close();
  }
  public static int get(int num)
  {
    //System.out.println("getting " + num);
    if (num == -1) return Integer.MAX_VALUE;
    if (save[num] != -1) return save[num];
    int ans = Math.min(get(num-1),get(flip(num)))+1;
    save[num] = ans;
    return ans;
  }
  
  public static int flip(int num)
  {
    String a = num+"";
    String build = "";
    for (int x =0; x< a.length();x++)
      build=a.charAt(x)+build;
    if (build.charAt(0) == '0') return -1;
    int final1 = Integer.parseInt(build);
    if (final1>=num) return -1;
    return final1;
  }
}