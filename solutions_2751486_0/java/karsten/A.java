import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class A {
  public static void main(String[] args) throws Exception {
    if (args.length != 2) {
      System.err.println("Usage: java A <input> <output>");
      System.exit(1);
    }
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    new File(args[1]).getParentFile().mkdirs();
    BufferedWriter bw = new BufferedWriter(new FileWriter(args[1]));
    String line;
    line = br.readLine();
    int num = 1;
    while ((line = br.readLine()) != null) {
      if (line.length() == 0) {
        continue;
      }
      String[] parts = line.split(" ");
      //String name = parts[0];
      int n = Integer.parseInt(parts[1]);
      char[] name = parts[0].toCharArray();
      boolean[] boolName = new boolean[name.length];
      for (int i = 0; i < name.length; i++) {
        if (name[i] == 'a' ||
            name[i] == 'e' ||
            name[i] == 'i' ||
            name[i] == 'o' ||
            name[i] == 'u') {
          boolName[i] = false;
        } else {
          boolName[i] = true;
        }
      }
      int nValue = count(boolName, n, 0, name.length);
      bw.write("Case #" + num++ + ": " + nValue + "\n");
    }
    br.close();
    bw.close();
  }
  private static int count(boolean[] boolName, int n, int from, int to) {
    int matches = 0;
    for (int pos = from; pos < to; pos++) {
      if (boolName[pos]) {
        matches++;
      } else {
        matches = 0;
      }
      if (matches == n) {
        int charsBefore = pos - n - from + 1;
        int charsAfter = to - pos - 1;
        int names = 0;
        names = ((charsBefore + 1) * (charsAfter + 1));
        names += count(boolName, n, pos - n + 2, to);
        return names;
      }
    }
    return 0;
  }
}

