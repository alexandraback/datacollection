import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class C {

  static String inputFile = "C-small-attempt0.in";
  static String outputFile = "C-small-attempt0.out";
  static PrintWriter out;
  
  public static void main(String[] args) throws FileNotFoundException {
    
    Scanner in = new Scanner(new File(inputFile));
//    Scanner in = new Scanner(System.in);
    out = new PrintWriter(new File(outputFile));
    
    int T = in.nextInt();
    
    for (int t = 1; t <= T; t++) {
      n = in.nextInt();
      m = in.nextInt();
      g = new int[n][n];
      zip = new String[n];
      
      for (int i = 0; i < n; i++) {
        zip[i] = in.next();
      }
      for (int i = 0; i < m; i++) {
        int a = in.nextInt() - 1;
        int b = in.nextInt() - 1;
        g[a][b] = g[b][a] = 1;
      }
      
      best = null;
      for (int i = 0; i < n; i++) {
        find(i, 1 << i, zip[i], new ArrayList<Integer>());
      }
      System.out.println(t);
      out.println("Case #" + t + ": " + best);
    }
    out.close();
  }

  static int n;
  static int m;
  static int g[][];
  static String zip[];
  
  static String best;

  private static void find(int v, int mask, String string, ArrayList<Integer> returnFlights) {
    
    if(mask == (1 << n) - 1 && returnFlights.size() == 0) {
//      System.out.println(string);
      if(best == null) best = string;
      else if(best.length() > string.length()) best = string;
      else if(best.length() == string.length() && best.compareTo(string) > 0) best = string;
      return ;
    }
    
    for (int next = 0; next < n; next++) {
      if(g[v][next] == 1 && (mask & (1 << next)) == 0) {
        int nextMask = mask | (1 << next);
        
        returnFlights.add(v);
        returnFlights.add(next);
        find(next, nextMask, string + zip[next], returnFlights);
        returnFlights.remove(returnFlights.size()-1);
        returnFlights.remove(returnFlights.size()-1);
      }
    }
    
    for (int i = 0; i < returnFlights.size(); i += 2) {
      int from = returnFlights.get(i);
      int to = returnFlights.get(i+1);
      
      if(v == to) {
        ArrayList<Integer> list = new ArrayList<Integer>(returnFlights);
        list.remove(i);
        list.remove(i);
        find(from, mask, string, list);
      }
    }
    
  }
  
}
