import java.util.*;
import java.io.*;

public class C {
  static int best = 0;
  static int[] bff;
  static ArrayList<ArrayList<Integer>> graph;
  
  private static int longest(int current, int partner) {
    if (current == partner) return 0;
    ArrayList<Integer> neighbours = graph.get(current);
    int n = neighbours.size();
    if (n == 0) return 1;
    int local = 0;
    for (int i = 0; i < n; i++) {
      local = Math.max(local, 1 + longest(neighbours.get(i), partner));
    }
    return local;
  }
  
  private static void full(int current, HashSet<Integer> vs, int home) {
    if (current == home && !vs.isEmpty()) {
      best = Math.max(best, vs.size());
      return;
    }
        if (vs.contains(current)) return;
    vs.add(current);
    full(bff[current], vs, home);  
  }
  
  public static void main(String[] args) throws Exception {
    //Scanner in = new Scanner(System.in);
    Scanner in = new Scanner(new File("C-small-attempt1.in"));
    PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
    int tests = in.nextInt();
    for (int t = 1; t <= tests; t++) {
      best = 0;
      int n = in.nextInt();
      bff = new int[n];
      // we subtracted 1 from every input.
      for (int i = 0; i < n; i++) {
        bff[i] = in.nextInt() - 1;
      }
      // we do biggest full cycle from each person
      for (int i = 0; i < n; i++) {
        HashSet<Integer> set = new HashSet<Integer>();
        full(i,set, i);
      }
      
      // ok
      graph = new ArrayList<ArrayList<Integer>>();
      for (int i = 0 ; i < n; i++) {
        graph.add(new ArrayList<Integer>());
      }
      for (int i = 0; i < n; i++) {
        graph.get(bff[i]).add(i);
      }
      int altbest = 0;
      // okay now we look at both end of each pair and find the longest path
      // first we find the pairs
      HashSet<String> v = new HashSet<String>();
      for (int i = 0; i < n; i++) {
  
        if (bff[bff[i]] != i) continue;
  if (v.contains(bff[i]+""+i) || v.contains(i+""+bff[i])) continue;
  v.add(bff[i]+""+i);
  
        int first = i;
        int second = bff[i];
        int lf = longest(first, second);
        int ls = longest(second, first);
        altbest +=  lf + ls;
      }
      best = Math.max(altbest,best);
System.out.println("Case #" + t + ": " + best);
      out.println("Case #" + t + ": " + best);
    }
    in.close();
    out.close();
  }
  
  
}