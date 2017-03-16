import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class B {
  public static void main(String[] args) throws Exception {
    if (args.length != 2) {
      System.err.println("Usage: java B <input> <output>");
      System.exit(1);
    }
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    new File(args[1]).getParentFile().mkdirs();
    BufferedWriter bw = new BufferedWriter(new FileWriter(args[1]));
    String line;
    line = br.readLine();
    int num = 1;
    int e = -1, r = -1, v[];
    while ((line = br.readLine()) != null) {
      if (line.length() == 0) {
        continue;
      }
      String[] parts = line.split(" ");
      if (e < 0) {
        e = Integer.parseInt(parts[0]);
        r = Integer.parseInt(parts[1]);
      } else {
        v = new int[parts.length];
        for (int i = 0; i < parts.length; i++) {
          v[i] = Integer.parseInt(parts[i]);
        }
        int maxGain = maxGain(e, e, r, v, 0);
        bw.write("Case #" + num++ + ": " + maxGain + "\n");
        e = -1;
      }
    }
    br.close();
    bw.close();
  }
  private static int maxGain(int maxE, int e, int r, int[] v, int pos) {
    if (pos == v.length) {
      return 0;
    }
    if (e > maxE) {
      e = maxE;
    }
    int maxGain = 0;
    for (int i = 0; i <= e; i++) {
      int gain = i * v[pos] + maxGain(maxE, e - i + r, r, v, pos + 1);
      if (gain > maxGain) {
        maxGain = gain;
      }
    }
    return maxGain;
  }
}

