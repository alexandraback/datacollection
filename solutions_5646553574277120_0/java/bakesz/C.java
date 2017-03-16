
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;


public class C
{
public static void main(String[] args) throws Exception
    {
        Scanner s=new Scanner(new FileInputStream(args[0]) );
        int t=s.nextInt();
        for (int i=1;i<=t;i++)
        {
             System.out.print("Case #"+i+": ");
             int c=s.nextInt();
             int d=s.nextInt();
             int v=s.nextInt();
             ArrayList<Integer> now=new ArrayList<Integer>();
             for(int i2=0;i2<d;i2++)
             {
                 now.add(s.nextInt() );
             }
             System.out.println(solve(now,c,v) );
        }
    }

static int calc(List<Integer> now, int d, int v)
{
    //System.err.println("d:"+d);
    int[] keszithetok=new int[v+1];
    keszithetok[0]=1;
    int ret=0;
    for (Integer i:now)
    {
         TreeSet<Integer> toadd=new TreeSet<Integer>();
         
      for (int j=1;j<=v;j++) //FIXME <= vagy <
      {
          for (int k=1;k<=d;k++)
          {
              int prevpos=j-i*k;
           //   if (prevpos>=0) System.err.println(i+" "+k+" "+j+" "+prevpos+" "+keszithetok[prevpos]);
          if (prevpos>=0 &&  keszithetok[prevpos]==1 && keszithetok[j]==0 )
          {
              ret++;
              //keszithetok[j]=1;
              toadd.add(j);
          }
              }
      }
                for (Integer r:toadd)
              keszithetok[r]=1;
      //System.err.println(i+"utan:"+Arrays.toString(keszithetok) );
    }
    //System.err.println(Arrays.toString(keszithetok) );
    //System.err.println(ret);
    //System.exit(0);
    return ret;
}

static int solve(List<Integer> now, int c, int v)
{
  //  System.err.println("start:"+now+" "+c+" "+v+" " );
  int[] keszithetok=new int[v];
  int ret=0;
  int akt=calc(now, c, v);
  //System.err.println("aa"+akt+" "+v);
 /* while (akt!=v)
  {
    
      int akti=0;
  for(int i=1;i<=v;i++) //FIXME: csak azokat, amik még nem voltak, list helyett set
  if (now.contains(i)==false) {
      List<Integer> uj=new LinkedList<Integer>(now);
      uj.add(i);
      int ertek=calc(uj, c, v);
      if (ertek>akt)
      {
          akt=ertek;
          akti=i;
      }
  }
  now.add(akti);
  ret++;
      }
  * 
  */
  
  LinkedList<LinkedList<Integer> > q=new LinkedList<LinkedList<Integer>>();
  q.add(new LinkedList<Integer>() );
  while (q.size()!=0)
  {
      
    LinkedList<Integer> uj=q.getFirst();
    //System.err.println(uj);
    q.removeFirst();
    int ujsize=uj.size();
    List<Integer> uj3=new LinkedList<Integer>(uj);
    uj3.addAll(now);
    if (calc(uj3,c,v)==v)
    {
        ret=uj.size();
        now=uj3;
        break;
    }
    for(int i=1;i<=v;i++) //FIXME: csak azokat, amik még nem voltak, list helyett set
  if (now.contains(i)==false && uj.contains(i)==false && (uj.size()==0 || uj.getLast()<i) ) {
      
      LinkedList<Integer> uj2=new LinkedList<Integer>(uj);
      
      uj2.add(i);
      //if (q.contains(uj2)==false)
      q.add(uj2);
      
  }
    
    
    
  }
  
  //System.err.println("megoldas:"+now+" "+c+" "+v+" "+ret );
  return ret;
}


}