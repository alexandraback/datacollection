import java.io.*;
import java.util.*;
public class D
{
  public static int war(ArrayList<Double>[]blocks2)
  {
    ArrayList<Double>[]blocks=new ArrayList[2];
    blocks[0]=(ArrayList<Double>)blocks2[0].clone();
    blocks[1]=(ArrayList<Double>)blocks2[1].clone();
    int temp=0;
    while(blocks[0].size()!=0)
    {
      if(blocks[0].get(blocks[0].size()-1)<blocks[1].get(blocks[1].size()-1))
      {
        blocks[1].remove(blocks[1].size()-1);
      }
      else
      {
        blocks[1].remove(0);
        temp++;
      }
      blocks[0].remove(blocks[0].size()-1);
    }
    return temp;
  }
  public static void main(String[] arg)throws IOException
  {
    BufferedReader in=new BufferedReader(new FileReader("D-large.in"));
    PrintWriter out=new PrintWriter(new FileWriter("D.out"));
    int num=Integer.parseInt(in.readLine());
    for(int asd=1;asd<=num;asd++)
    {
      out.print("Case #"+asd+": ");
      ArrayList<Double>[] blocks=new ArrayList[2];
      int n=Integer.parseInt(in.readLine());
      for(int asdasd=0;asdasd<2;asdasd++)
      {
        blocks[asdasd]=new ArrayList<Double>();
        String[]temp=in.readLine().split(" ");
        for(int x=0;x<n;x++)
        {
          Double temp2=Double.parseDouble(temp[x]);
          for(int y=0;y<blocks[asdasd].size();y++)
          {
            if(blocks[asdasd].get(y)>temp2)
            {
              blocks[asdasd].add(y,temp2);
              break;
            }
            if(y==blocks[asdasd].size()-1)
            {
              blocks[asdasd].add(temp2);
              break;
            }
          }
          if(blocks[asdasd].size()==0)
            blocks[asdasd].add(temp2);
        }
      }
      int war=(war(blocks));
      int dwar=0;
      while(blocks[0].size()!=0)
      {
        if(blocks[0].get(0)<blocks[1].get(0))
        {
          blocks[1].remove(blocks[1].size()-1);
        }
        else
        {
          blocks[1].remove(0);
          dwar++;
        }
        blocks[0].remove(0);
      }
      out.println(dwar+" "+war);
    }
    in.close();
    out.close();
  }
}