import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;


public class RecycledNumbers {
  public RecycledNumbers() { }

  public int solve(String str) {
    String[] tokens = str.split(" ");
    int length = tokens[0].length();
    int a = Integer.valueOf(tokens[0]);
    int b = Integer.valueOf(tokens[1]);
    return solve(a, b, length);
  }
  public int solve(int a, int b, int length) {
    Set<String> rPairs = new HashSet<String>();
    StringBuffer strBuffer = new StringBuffer();
    for (int n = a; n < b; ++n) {
      int shiftNum = n;
      for (int i = 0; i < length; ++i) {
        shiftNum = calcShiftNum(shiftNum, length);

        if (shiftNum <= b && shiftNum > n) {
          strBuffer.setLength(0);
          strBuffer.append("(").append(n).append(", ").append(shiftNum).append(")");
          String result = strBuffer.toString();
          rPairs.add(result);
        }
      }
    }
    return rPairs.size();
  }

  public int calcShiftNum(int num, int length) {
    int maxUnit = Double.valueOf(Math.pow(10, length - 1)).intValue();
    int remainder = num % 10;
    return (remainder * maxUnit) + (num / 10);
  }

  public static void main(String[] args) throws IOException {
    RecycledNumbers solver = new RecycledNumbers();
    //System.out.println(solver.solve("100 500"));
    File folder = new File(".");
    for (File f : folder.listFiles()) {
      if (!f.getName().endsWith("in") || !f.isFile()) {
        continue;
      }
      System.out.println(f.getName());
      String outFileName = f.getName().replace("in", "out");

      BufferedReader reader = new BufferedReader(new FileReader(f));
      String str;
      int lineNum = 0, caseNum = 1;
      BufferedWriter writer = new BufferedWriter(new FileWriter(outFileName));
      lineNum = Integer.valueOf(reader.readLine());
      while ((str = reader.readLine()) != null) {
        str = str.trim();
        writer.write(String.format("Case #%d: %d\n", caseNum++, solver.solve(str)));
      }
      if (lineNum != caseNum - 1) {
        System.err.println("Case Number is not matched to input file.");
      }
      writer.flush();
      writer.close();
    }

  }

}
