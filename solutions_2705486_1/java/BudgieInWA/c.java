import java.util.*;
import java.io.*;

public class c {
  private static void p(Object p) { System.out.print(p);   }
  private static void pln(Object p) { System.out.println(p); }
  
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    
    List<String> dic = new ArrayList<String>();
    try {
      File f = new File(args[0]);
      BufferedReader br = new BufferedReader(new FileReader(f));
      String l;
      while((l = br.readLine()) != null) dic.add(l);
    } catch (Exception e) {
      //barf
    }
    
    int P = in.nextInt();
    in.nextLine();

    for (int p = 1; p <= P; p++) {
      String msg = in.next();
      int n = msg.length();
      int[][] count = new int[n+1][5]; //[used][letters_that_we_can't_change]
      for (int[] c: count) Arrays.fill(c, -1);
      Arrays.fill(count[0], 0);
      for (int i = 0; i < n; i++) {
        //pln(i);

ord: for (String w: dic) {
          if (i + w.length() > n) continue; // word is too long;
          int so = -1;
          int off = -1;
          int changes = 0;
          for (int ii = 0; ii < w.length(); ii++) {
            off--;
            if (w.charAt(ii) != msg.charAt(i+ii)) {
              if (off >= 0) continue ord; //changes are too close.
              if (so == -1) {
                if (count[i][Math.min(ii, 4)] < 0) continue ord; // first change isn't possible
                so = ii;
              }
              off = 4;
              changes++;
            }
          }
          //pln("   " + w + " " + (i+w.length()) + " " + off);
          if (so == -1) { // no changes,
            for (int j = 0; j < 5; j++) {
              int k = Math.min(w.length()+j, 4);
              if (count[i+w.length()][j] < 0 || (count[i+w.length()][j] > count[i][k] + changes && count[i][k] + changes >= 0))
                count[i+w.length()][j] = count[i][k] + changes;
            }
          } else {
            for (int j = Math.max(off, 0); j < 5; j++) {
              int k = Math.min(so, 4);
              if (count[i+w.length()][j] < 0 || count[i+w.length()][j] > count[i][k] + changes)
                count[i+w.length()][j] = count[i][k] + changes;
            }
          }
        }
     /*
        for (int t = 0; t < n; t++) {
          for (int tt = 0; tt < 5; tt++) p(" " + count[t][tt]);
          pln("");
        }
      */
      }
      
      System.out.printf("Case #%d: %d\n", p, count[n][4]);
    }
    
  }
}
