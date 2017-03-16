import java.util.*;
import java.io.*;
public class lottery
{
   public static void main(String[] args) throws IOException
   {
      Scanner in = new Scanner(new File("B-small-attempt1.in"));
      PrintStream out = new PrintStream(new File("lot.out"));
      int a = Integer.parseInt(in.nextLine());
      Map<Integer, Integer> mm = new HashMap<Integer, Integer>();
      for(int k = 0; k < a; k++)
      {
         int f = in.nextInt();
         int g = in.nextInt();
         int h = in.nextInt();
         int j = Math.max(f, g);
         j = Math.max(j, h);
         for(int l = 0; l < j; l++)
         {
            if(mm.containsKey(l) == false)
            {
               mm.put(l, convert(l));
            }
         }
         ArrayList<Integer> hh = new ArrayList<Integer>();
         for(int l = 0; l < h; l++)
         {
            hh.add(mm.get(l));
           // hh.add(convert(l));
         }
         int tot = 0;
         for(int l = 0; l < f; l++)
         {  
            for(int m = 0; m < g; m++)
            {
               int ff = and(mm.get(l), mm.get(m));
               if(hh.contains(ff))
               {
                  tot++;
               }
            }
         }
         out.println("Case #"+(k+1)+": "+tot);
      }
      //System.out.println(convert(9));
   }
   public static int and(int a, int b)
   {
      String s = ""+a;
      String p = ""+b;
      //int min = Math.min(s.length(), p.length());
      while(s.length()< p.length())
      {
         s = "0"+s;
      }
      while(p.length()< s.length())
      {
         p = "0"+p;
      }
      String f = "";
      for(int k = 0; k < s.length(); k++)
      {
         String c1 = s.substring(k, k+1);
         String c2 = p.substring(k, k+1);
         if(c1.equals("1") && c2.equals("1"))
         {
            f+="1";
         }
         else
         {
            f+="0";
         }
      }
      return Integer.parseInt(f);
   }
   public static int convert(int a)
   {
      int k = 0;
      while(a >= Math.pow(2, k))
      {
         k++;
      }
      k--;
      //System.out.println(k);
      int n = 0;
      for(int w = k; w >= 0; w--)
      {
         int z = (int)Math.pow(2, w);
         int c = a/z;
         a = a%z;
         c*=Math.pow(10, w);
         n+=c;
      }
      return n;
      
   }
}
