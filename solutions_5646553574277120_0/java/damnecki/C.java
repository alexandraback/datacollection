import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.*;

public class C {

  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(new File("data/c/C-small-attempt1.in"));
    BufferedWriter bw = new BufferedWriter(new FileWriter(new File("data/c/out")));
    int t = sc.nextInt();
    for (int i = 1; i <= t; i++) {
      int c = sc.nextInt();
      int d = sc.nextInt();
      long v = sc.nextLong();
      List<Integer> existing = new ArrayList<Integer>();
      for (int j = 0; j < d; j++) {
        existing.add(sc.nextInt());
      }
      int newCnt = 0;
      int idx;
      if (existing.get(0) == 1) {
        idx = 1;
      } else {
        newCnt++;
        idx = 0;
      }
      int curr = c;
      int j = idx;
      while (j < existing.size()) {
        int dd = existing.get(j);
        if (dd > curr + 1) {
          newCnt++;
          curr += (c * (curr + 1));
        } else {
          curr += (c * dd);
          j++;
        }
        if (curr >= v) {
          break;
        }
      }
      while (curr < v) {
        newCnt++;
        curr += (c * (curr + 1));
      }
      System.out.println("Case #" + i + ": " + newCnt);
      bw.write("Case #" + i + ": " + newCnt + "\n");
    }
    sc.close();
    bw.close();
  }
}
