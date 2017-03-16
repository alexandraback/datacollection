// Author: Alejandro Sotelo Arevalo
package round1c;

import java.io.*;
import java.util.*;

public class A_DiamondInheritance {
  // --------------------------------------------------------------------------------
  private static String ID="A";
  private static String NAME="small-attempt0"; // small-attempt0
  private static boolean STANDARD_OUTPUT=false;
  // --------------------------------------------------------------------------------
  public static void main(String[] args) throws Throwable {
    BufferedReader reader=new BufferedReader(new FileReader(new File("data/"+ID+"-"+NAME+".in")));
    if (!STANDARD_OUTPUT) System.setOut(new PrintStream(new File("data/"+ID+"-"+NAME+".out")));
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      String w[]=reader.readLine().trim().split(" +");
      int N=Integer.parseInt(w[0]);
      int[][] lAdy=new int[N][];
      for (int i=0; i<N; i++) {
        w=reader.readLine().trim().split(" +");
        lAdy[i]=new int[Integer.parseInt(w[0])];
        for (int j=0; j<lAdy[i].length; j++)
          lAdy[i][j]=Integer.parseInt(w[j+1])-1;
      }
      int ts[]=topologicalSort(lAdy),array[]=new int[N],max=0;
      // System.out.println(Arrays.toString(ts));
      for (int k=ts.length-1; k>=0; k--) {
        int a=ts[k],count=0;
        count+=lAdy[a].length;
        array[a]=count;
        max=Math.max(max,array[a]);
      }
      // System.out.println(Arrays.toString(array));
      System.out.println("Case #"+c+": "+(max>=2?"Yes":"No"));
    }
    if (!STANDARD_OUTPUT) System.out.close();
    reader.close();
  }
  public static int findPaths(int[][] ady, boolean[] vis, int i, int j, int level) {
    if (i==j&&level>0) return 1;
    if (vis[j]) return 0;
    vis[j]=true;
    int count=0;
    for (int k:ady[i]) {
      count+=findPaths(ady,vis,k,j,level+1);
      if (count>=2) return count;
    }
    vis[j]=false;
    return count;
  }
  public static int[] topologicalSort(int[][] lAdy) { // Retorna null si no recibe un DAG
    int n=lAdy.length,state[]=new int[n];
    List<Integer> r=new ArrayList<Integer>();
    for (int v=0; v<n; v++) {
      if (state[v]==0&&!dfsTS(lAdy,v,state,r)) return null;
    }
    int t=r.size(),a[]=new int[t],i;
    for (i=0; i<t; i++) {
      a[i]=r.get(t-1-i);
    }
    return a;
  }
  public static boolean dfsTS(int[][] lAdy, int v, int[] state, List<Integer> r) {
    state[v]=1;
    for (int w:lAdy[v]) {
      if (state[w]==1||(state[w]==0&&!dfsTS(lAdy,w,state,r))) return false;
    }
    state[v]=2;
    r.add(v);
    return true;
  }
}
