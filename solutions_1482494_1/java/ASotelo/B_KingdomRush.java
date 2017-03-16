// Author: Alejandro Sotelo Arevalo
package round1a;

import java.io.*;
import java.util.*;

public class B_KingdomRush {
  //--------------------------------------------------------------------------------
  private static String ID="B";
  private static String NAME="large";
  private static boolean STANDARD_OUTPUT=false;
  //--------------------------------------------------------------------------------
  public static void main(String[] args) throws Throwable {
    BufferedReader reader=new BufferedReader(new FileReader(new File("data/"+ID+"-"+NAME+".in")));
    if (!STANDARD_OUTPUT) System.setOut(new PrintStream(new File("data/"+ID+"-"+NAME+".out")));
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      int N=Integer.parseInt(reader.readLine().trim()),a[]=new int[N],b[]=new int[N];
      PriorityQueue<Item> queue1=new PriorityQueue<Item>(),queue2=new PriorityQueue<Item>();
      for (int i=0; i<N; i++) {
        String w[]=reader.readLine().trim().split(" +");
        a[i]=Integer.parseInt(w[0]);
        b[i]=Integer.parseInt(w[1]);
        queue1.offer(new Item(i,a[i],b[i]));
        queue2.offer(new Item(i,b[i],0));
      }
      int stars=0,trials=0,finished=0;
      int completed[]=new int[N];
      Set<Item> rejected=new HashSet<Item>(1024);
      while (true) {
        while (!queue2.isEmpty()&&stars>=queue2.peek().stars) {
          Item item=queue2.poll();
          stars+=completed[item.index]==1?1:2;
          completed[item.index]=2;
          trials++;
          finished++;
        }
        if (queue1.isEmpty()) break;
        Item best=null;
        while (!queue1.isEmpty()&&stars>=queue1.peek().stars) {
          Item item=queue1.poll();
          if (completed[item.index]!=2) {
            if (best==null||item.other>best.other) best=item;
            rejected.add(item);
          }
        }
        if (best==null) break;
        rejected.remove(best);
        queue1.addAll(rejected);
        rejected.clear();
        stars+=1;
        completed[best.index]=1;
        trials++;
      }
      System.out.println("Case #"+c+": "+(finished==N?trials:"Too Bad"));
    }
    if (!STANDARD_OUTPUT) System.out.close();
    reader.close();
  }
  private static class Item implements Comparable<Item> {
    int index,stars,other;
    public Item(int index, int stars, int other) {
      this.index=index;
      this.stars=stars;
      this.other=other;
    }
    public boolean equals(Object item) {
      return item==this;
    }
    public int compareTo(Item item) {
      return stars!=item.stars?stars-item.stars:(other!=item.other?-(other-item.other):index-item.index);
    }
  }
}
