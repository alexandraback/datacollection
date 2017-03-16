package lt.kasrud.gcj.ex2;

import lt.kasrud.gcj.common.io.Reader;
import lt.kasrud.gcj.common.io.Writer;

import java.io.IOException;
import java.util.*;

public class Main {
  public static void main(String[] args) throws IOException {
    List<String> iData = Reader.readFile("B-small-attempt0.in");
    Writer.writeFile("out2.txt", process(iData.subList(1, iData.size())));
  }

  private static List<String> process(List<String> data) {
    List<String> result = new ArrayList<String>(data.size());
    for(String record : data){
      List<String> tokens = Arrays.asList(record.trim().split(" "));
      result.add(calculate(Integer.valueOf(tokens.get(1)), Integer.valueOf(tokens.get(2)), tokens.subList(3, tokens.size())));
    }

    return result;
  }

  private static String calculate(Integer surpCnt, Integer maxValue, List<String> totPoints) {
    int cnt = 0;
    int minDiff = maxValue > 0 ? 1 : maxValue;
    int maxDiff = maxValue > 1 ? 2 : maxValue;
    int maxTotal = maxValue * 3 - 2 * minDiff;
    int surpTotal = maxValue * 3 - 2 * maxDiff;
    for (String t : totPoints) {
      int total = Integer.valueOf(t);
      if (total >= maxTotal){
        cnt++;
      }else if(total >= surpTotal && surpCnt > 0){
        cnt++;
        surpCnt--;
      }
    }

    return String.valueOf(cnt);
  }
}
