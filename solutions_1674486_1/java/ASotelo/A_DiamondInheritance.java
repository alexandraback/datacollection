// Author: Alejandro Sotelo Arevalo
package round1c;

import java.io.*;
import java.util.*;

public class A_DiamondInheritance {
  // --------------------------------------------------------------------------------
  private static String ID="A";
  private static String NAME="large"; 
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
        for (int j=0; j<lAdy[i].length; j++) {
          lAdy[i][j]=Integer.parseInt(w[j+1])-1;
        }
      }
      int ts[]=topologicalSort(lAdy),array[]=new int[N],max=0;
      for (int k=ts.length-1; k>=0&&max<2; k--) {
        int a=ts[k];
        Arrays.fill(array,0);
        traverse(lAdy,a,array);
        for (int i=0; i<N; i++) max=Math.max(max,array[i]);
      }
      System.out.println("Case #"+c+": "+(max>=2?"Yes":"No"));
    }
    if (!STANDARD_OUTPUT) System.out.close();
    reader.close();
  }
  public static void traverse(int[][] lAdy, int v, int[] array) {
    if (lAdy[v].length==0) {
      array[v]++;
    }
    else {
      for (int w:lAdy[v]) {
        traverse(lAdy,w,array);
      }
    }
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
