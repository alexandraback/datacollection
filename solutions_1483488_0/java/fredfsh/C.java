import java.io.*;
import java.lang.*;
import java.util.*;

public class C {
  public static void main(String[] args) {
    C prob = new C();
    prob.run(args[0]);
  }

  public void run(String fileName) {
    try {
      Scanner fin = new Scanner(new File(fileName));
      PrintWriter fout = new PrintWriter(new File(fileName + ".out"));

      int T = fin.nextInt();
      for (int t = 1; t <= T; ++t) {
        fout.format("Case #%d: ", t);

        int A = fin.nextInt();
        int B = fin.nextInt();
        int result = 0;

        TreeSet<Integer> pairs = new TreeSet<Integer>();
        for (int i = A; i <= B; ++i) {
          String a = Integer.toString(i);
          pairs.clear();
          for (int j = 1; j < a.length(); ++j) {
            String b = a.substring(j) + a.substring(0, j);
            if (b.charAt(0) == '0') continue;
            int m = Integer.valueOf(b);
            if ((m >= A) && (m <= B) && (m != i)) {
              pairs.add(m);
            }
          }
          result += pairs.size();
        }
        result /= 2;

        fout.format("%d\n", result);
      }

      fin.close();
      fout.close();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}
