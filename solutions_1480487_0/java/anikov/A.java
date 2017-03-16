
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;


public class A {
  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    
    String ss = reader.readLine();
    int n = Integer.parseInt(ss);
    
    for (int i = 0; i < n; i++) {
      Map<String, Integer> map = new HashMap<String, Integer>();
      ss = reader.readLine();

      String[] p = ss.split(" ");
      int[] z = new int[p.length - 1];
      int sum = 0;
      for (int j = 1; j < p.length; j++) {
        z[j - 1] = Integer.parseInt(p[j]);
        sum += z[j - 1];
      }
      
      String[] r = new String[z.length];
      double avg = (sum * 2) / (double) z.length;
      int count = 0;
      double safe = 0;
      for (int j = 0; j < z.length; j++) {
        if (z[j] >= avg) {
          count++;
          safe+=z[j];
        }
      }
      
      String res = "";
      for (int j = 0; j < z.length; j++) {
        if (j > 0) {
          res = res + " ";
        }
        if (z[j] >= avg) {
          res += "0.000000";
        } else {
          double rest = sum * 2 - safe;
          double restavg = rest / (z.length - count);
          res += "" + 100*(restavg - z[j]) / (sum );
        }
      }
      
      String sss = "Case #" + (i + 1) + ": " + res;
      System.out.println(sss);
      
      
    }
  }
}
