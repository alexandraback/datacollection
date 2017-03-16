import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class DiamondInheritance {

  static class Clazz {
    @Override
    public String toString() {
      return "Clazz [id=" + id + ", inherit=" + Arrays.toString(inherit) + "]";
    }
    int id;
    int[] inherit;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new FileReader(new File("A-small-attempt0.in")));
//     BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String line = br.readLine();
    int t = Integer.parseInt(line);
    for (int i = 0; i < t; i++) {
      line = br.readLine();
      int n = Integer.parseInt(line);
      List<Clazz> cls = new ArrayList<DiamondInheritance.Clazz>();
      Map<Integer, Clazz> clsMap = new HashMap<Integer, DiamondInheritance.Clazz>();
      for (int j = 0; j < n; j++) {
        Clazz cl = new Clazz();
        cl.id = j;
        line = br.readLine();
        String[] split = line.split(" ");
        int m = Integer.parseInt(split[0]);
        cl.inherit = new int[m];
        for (int k = 0; k < m; k++) {
          cl.inherit[k] = Integer.parseInt(split[k + 1])-1;
        }
        cls.add(cl);
        clsMap.put(cl.id, cl);
      }
      boolean cycle = false;
      for (int j = 0; j < n; j++) {
        boolean visited[] = new boolean[n];
        if (visited[j])
          continue;
        cycle = visit(j, clsMap, visited);
        if(cycle)break;
      }
      System.out.println("Case #" + (i + 1) + ": " + (cycle ? "Yes" : "No"));
    }
  }

  private static boolean visit(int j, Map<Integer, Clazz> clsMap, boolean[] visited) {
    if (visited[j])
      return true;
    visited[j]=true;
    Clazz curCl = clsMap.get(j);
    int[] inherit = curCl.inherit;
    for (int i : inherit) {
      boolean yes = visit(i, clsMap, visited);
      if(yes)return true;
    }
    return false;
  }

}
