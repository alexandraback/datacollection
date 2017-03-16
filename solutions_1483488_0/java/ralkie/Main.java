package lt.kasrud.gcj.ex3;

import lt.kasrud.gcj.common.IO;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Main {
  public static void main(String[] args) throws IOException {
    IO.Data data = IO.readFile("C-small-attempt0.in");
    IO.writeFile("out3.txt", process(data));
  }

  private static List<Integer> process(IO.Data data) {
    List<Integer> result = new ArrayList<Integer>(data.getInt(0, 0));
    for(IO.Record r : data.getRecords(1)){
      Integer c = calculate(r.getInt(0), r.getInt(1));
      result.add(c);
    }

    return result;
  }

  private static Integer calculate(Integer a, Integer b) {
    int cnt = 0;
    Set<Integer> ms = new HashSet<Integer>();
    for (int n=a; n<=b; n++){
      ms.clear();
      String ns = String.valueOf(n);
      for (int i = 1; i< ns.length(); i++){
        int m = rotate(ns, i);
        if (m > n && m <= b){
          ms.add(m);
        }
      }
      cnt += ms.size();
    }

    return cnt;
  }

  private static int rotate(String ns, int i){
    String ms = ns.substring(i, ns.length()) + ns.substring(0, i);
    return Integer.valueOf(ms);
  }
}
