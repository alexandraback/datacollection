package lt.kasrud.gcj.r21;

import lt.kasrud.gcj.common.IO;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Main {
  public static void main(String[] args) throws IOException {
    IO.Data data = IO.readFile("A-large.in");
    IO.writeFile("out21.txt", process(data));
  }

  private static List<Object> process(IO.Data data) {
    Integer casesCnt = data.getInt(0, 0);
    List<Object> result = new ArrayList<Object>(casesCnt);
    for (int i = 1; i <= casesCnt; i++) {
      IO.Record r = data.getRecord(i);
      List<Double> scores = r.getDoubleList(1);
      String res = calculate(scores);
      result.add(res);
    }
    return result;
  }

  private static String calculate(List<Double> scores) {
    Double t = 0D;
    for(Double score : scores){
      t+= score;
    }
    Double pool = 2*t;
    Double min = 2*t/scores.size();
    int c = 0;
    for(Double score : scores){
      if (score<=min) c++;
        else pool -= score;
    }
    Double min2 = pool/c;
    String s = "";
    for(Double score : scores){
      Double r = ((min2-score)/t)*100;
      s = s + (r<0? "0.0 ":r+" ");
    }
    return s.trim();  //To change body of created methods use File | Settings | File Templates.
  }


}
