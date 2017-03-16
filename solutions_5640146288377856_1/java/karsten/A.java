package round1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class A {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    BufferedWriter bw = new BufferedWriter(new FileWriter(args[1]));
    String line = br.readLine();
    int testCase = 1;
    while ((line = br.readLine()) != null) {
      if (line.length() == 0) {
        break;
      }
      String[] firstStrings = line.split(" ");
      int r = Integer.parseInt(firstStrings[0]);
      int c = Integer.parseInt(firstStrings[1]);
      int w = Integer.parseInt(firstStrings[2]);
      int minScore = 0;
      minScore += (r - 1) * (c / w);
      minScore += Math.min(c, (c - (w + 1)) / w + w + 1);
      bw.write("Case #" + testCase++ + ": " + minScore + "\n");
    }
    br.close();
    bw.close();
  }
}
