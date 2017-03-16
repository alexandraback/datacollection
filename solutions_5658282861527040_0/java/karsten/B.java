import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class B {
  public static void main(String[] args) throws Exception {
    if (args.length != 2) {
      System.err.println("Usage: java " + B.class.getName()
          + " [input] [output]");
      System.exit(1);
    }
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    BufferedWriter bw = new BufferedWriter(new FileWriter(args[1]));
    int testCases = Integer.parseInt(br.readLine());
    for (int testCase = 1; testCase <= testCases; testCase++) {
      bw.write("Case #" + testCase + ": ");
      String[] parts = br.readLine().split(" ");
      long a = Long.parseLong(parts[0]);
      long b = Long.parseLong(parts[1]);
      long k = Long.parseLong(parts[2]);
      int pairs = 0;
      for (long ai = 0; ai < a; ai++) {
        for (long bi = 0; bi < b; bi++) {
          if ((ai & bi) < k) {
            pairs++;
          }
        }
      }
      bw.write(pairs + "\n");
    }
    br.close();
    bw.close();
  }

}
