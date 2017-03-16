import java.util.Scanner;
import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.*;

public class RankFile {
  public static String solve(Scanner scn) {
    int N = scn.nextInt();
    TreeMap<Integer, Integer> map = new TreeMap<>();

    for(int i = 0; i < N * (2 * N - 1); i++) {
      int next = scn.nextInt();
      if(map.containsKey(next)) {
        map.put(next, map.get(next) + 1);
      } else
        map.put(next, 1);
    }

    List<Integer> res = new LinkedList<>();

    for(Map.Entry<Integer, Integer> entry : map.entrySet()) {
      if(entry.getValue() % 2 == 1) {
        res.add(entry.getKey());
      }
    }

    Collections.sort(res);
    List<String> temp = new LinkedList<>();

    for(Integer p : res) {
      temp.add(p.toString());
    }

    String res1 = String.join(" ", temp);

    return res1;
  }

  public static void main(String[] args) throws Exception {
    Scanner scn;
    PrintStream out;
    if(args.length != 1) {
      scn = new Scanner(System.in);
      out = System.out;
    } else {
      String fileName = args[0];
      int pos = fileName.lastIndexOf(".");
      String outFileName = fileName.substring(0, pos) + ".out";
      scn = new Scanner(new File(args[0]));
      out = new PrintStream(new FileOutputStream(outFileName, false));
    }

    int T = scn.nextInt();

    for(int i = 0; i < T; i++) {
      out.println("Case #" + (i+1) + ": " + solve(scn));
    }

    scn.close();
    out.close();
  }
}