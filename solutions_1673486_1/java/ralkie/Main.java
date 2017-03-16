package lt.kasrud.gcj.r11;

import lt.kasrud.gcj.common.IO;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Main {
  public static void main(String[] args) throws IOException {
    IO.Data data = IO.readFile("A-large.in");
    IO.writeFile("out11.txt", process(data));
  }

  private static List<Double> process(IO.Data data) {
    Integer casesCnt = data.getInt(0, 0);
    List<Double> result = new ArrayList<Double>(casesCnt);
    for (int i = 1; i <= casesCnt; i++) {
      int charsTyped = data.getInt(i * 2 - 1, 0);
      int charsTotal = data.getInt(i * 2 - 1, 1);
      List<Double> probs = data.getRecord(i * 2).getDoubleList(0);
      Double optimal = Double.MAX_VALUE;
      for (int j = 0; j <= charsTyped; j++) {
        Double r = calculate(charsTyped, charsTotal, probs, j);
        optimal = Math.min(optimal, r);
      }
      //enter anew
      Double r = 1D + charsTotal + 1;
      optimal = Math.min(optimal, r);
      result.add(optimal);
    }
    return result;
  }

  private static Double calculate(int charsTyped, int charsTotal, List<Double> probs, int backs) {
    Double right = 1.0;
    for (int i = 0; i < charsTyped - backs; i++) {
      right *= probs.get(i);
    }

    return right * (charsTotal - charsTyped + 2 * backs + 1)
      + (1 - right) * (charsTotal - charsTyped + 2 * backs + 1 + charsTotal + 1);
  }

}
