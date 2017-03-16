import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;


public class A {

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));


    String ss = reader.readLine();
    int n = Integer.parseInt(ss);

    for (int i = 0; i < n; i++) {
      Map<String, Integer> map = new HashMap<String, Integer>();
      ss = reader.readLine();

      int N = Integer.parseInt(ss);
      int[][] x = new int[N][N];
      for (int k = 0; k < N; k++) {

        ss = reader.readLine();
        String[] p = ss.split(" ");
        for (int j = 1; j < p.length; j++) {
          int z = Integer.parseInt(p[j]);
          if (z > 0) {
            x[k][z - 1] = 1;
          }
        }
      }
      boolean found = false;
      for (int j = 0; j < N; j++) {

        List<Integer> queue = new LinkedList<Integer>();
        queue.add(j);
        int[] v = new int[N];
        v[j] = 1;
        while (!queue.isEmpty()){
          Integer m = queue.remove(0);
          for (int k = 0; k < N; k++) {
            if (k == m) {
              continue;
            }
            if (x[m][k] == 1) {
              if (v[k] == 1) {
                found = true;
              } else {
                v[k] = 1;
                queue.add(k);
              }
            }
          }
        }
        
      }

      
      String res = "No";
      if (found) {
        res = "Yes";
      }
      String sss = "Case #" + (i + 1) + ": " + res;
      System.out.println(sss);


    }
  }
}
