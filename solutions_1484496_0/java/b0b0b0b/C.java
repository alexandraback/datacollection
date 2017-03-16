import java.io.File;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class C {
  public static void main(String[]args) throws Exception {
    File f = new File(args[0]);
    File f2 = new File(f.getParentFile(),f.getName()+".out");
    Scanner s = new Scanner(f);
    int T = s.nextInt();
    for (int t = 1; t <= T; t++) {
      int N = s.nextInt();
      int points[] = new int[N];
      for (int i=0;i<N;i++)
        points[i]=s.nextInt();

      println(f2,"Case #"+t+":\n"+solve(points));
    }
    s.close();
  }

  private static String solve(int[] points) {
    Map<Integer,Integer> m = new HashMap<Integer,Integer>();
    for (int i=1; i < 1<<points.length; i++) {
      int sum = 0;
      for (int x=0;x<points.length;x++) {
        if (((1<<x)&i)!=0) {
          sum+=points[x];
        }
      }
      Integer prev = m.put(sum, i);
      if (prev != null) {
        return s(prev,points)+"\n"+s(i,points);
      }
    }
    return "Impossible";
  }
  static String s(int i,int[]points) {
    String str = "";
    for (int x=0;x<32;x++) {
    if (((1<<x)&i)!=0) {
      if (str.length() != 0) str += " ";
      str += points[x];
    }
    }
    return str;
  }

  static void println(File f, String s) throws Exception {
    FileWriter w = new FileWriter(f,true);
    w.write(s+"\n");
    w.close();
    System.out.println(s);
  }
}
/*
 * 177
 * 59 59 1 0 0 0 58
 * 
 * 1 1 1 1 1 5
 * 
 * 10
 * 
 * 3.33333
 * 1 + .2 * 10 = 3
 * (3.333 - 1) * 2 / 10
 * 
 */
