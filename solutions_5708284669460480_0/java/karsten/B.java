package round1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class B {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    BufferedWriter bw = new BufferedWriter(new FileWriter(args[1]));
    String line = br.readLine();
    int testCase = 1;
    while ((line = br.readLine()) != null) {
      if (line.length() == 0) {
        break;
      }
      /*
       * 5
7 6 6
BANANAS
MONKEY
2 3 4
AA
AAA
2 1 2
AB
B
6 2 2
GOOGLE
GO
26 11 100
ABCDEFGHIJKLMNOPQRSTUVWXYZ
ROSENCRANTZ
       */
      String[] firstStrings = line.split(" ");
      int s = Integer.parseInt(firstStrings[2]);
      //System.out.println("s=" + s);
      String keyboard = br.readLine();
      //System.out.println("Keyboard: " + keyboard);
      Map<Character, Integer> freqs = new HashMap<Character, Integer>();
      for (char key : keyboard.toCharArray()) {
        if (!(freqs.containsKey(key))) {
          freqs.put(key, 0);
        }
        freqs.put(key, freqs.get(key) + 1);
      }
      //System.out.println(freqs);
      String target = br.readLine();
      //System.out.println("Target: " + target);
      int prefixLength = 0;
      for (int i = target.length() - 1; i > 0; i--) {
        if (target.substring(1).endsWith(target.substring(0, i))) {
          //System.out.println("Prefix in " + target + ": "
          //    + target.substring(0, i));
          prefixLength = i;
          break;
        }
      }
      String targetPrefix = target.substring(0, prefixLength);
      String targetSuffix = target.substring(prefixLength);
      List<Double> probs = new ArrayList<Double>();
      boolean impossible = false;
      for (String str : new String[] { targetPrefix, targetSuffix }) {
        double prob = 1.0;
        for (char key : str.toCharArray()) {
          if (freqs.containsKey(key)) {
            prob *= ((double) freqs.get(key)) /
                ((double) keyboard.length());
          } else {
            impossible = true;
            break;
          }
        }
        probs.add(prob);
      }
      //System.out.println(probs);
      double maxInTarget = (double) Math.max(0,
          (s - targetPrefix.length()) / targetSuffix.length());
      //System.out.println(maxInTarget);
      double bananasLeft = maxInTarget - probs.get(0) *
          Math.pow(probs.get(1), maxInTarget) * maxInTarget;
      if (impossible) {
        bananasLeft = 0.0;
      }
      //System.out.println("pre=" + targetPrefix + " suff=" + targetSuffix);
      //System.out.println("Case #" + testCase + ": " + bananasLeft + "\n");
      bw.write("Case #" + testCase++ + ": " + bananasLeft + "\n");
    }
    br.close();
    bw.close();

  }
}
