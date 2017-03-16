import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;


public class b {

  private static Scanner input;
  private List<String> beginStr = new ArrayList<String>();
  private List<String> endStr = new ArrayList<String>();
  private Integer ans = 0;
  private Stack<Integer> travel = new Stack<Integer>();
  private HashMap<String, List<Integer>> map = new HashMap<String, List<Integer>>();


  public void run() {
    input = new Scanner(System.in);
    int t = input.nextInt();
    for (int i = 0; i < t; i++) {
      int n = input.nextInt();
      map = new HashMap<String, List<Integer>>();
      beginStr = new ArrayList<String>();
      endStr = new ArrayList<String>();
      for (int j = 0; j < n; j++) {
        String tmp = input.next();
        char begin = tmp.charAt(0);
        char end = tmp.charAt(tmp.length() - 1);
        beginStr.add(String.valueOf(begin));
        endStr.add(String.valueOf(end));
        List<Integer> list = map.get("begin_" + begin);
        if (list == null) {
          list = new ArrayList<Integer>();
        }
        list.add(j);
        map.put("begin_" + begin, list);
        list = map.get("end_" + end);
        if (list == null) {
          list = new ArrayList<Integer>();
        }
        list.add(j);
        map.put("end_" + end, list);
      }
      ans = 0;
      if (n != 1) {
        for (int j = 0; j < n; j++) {
          travel = new Stack<Integer>();
          travel(j, n, 0);
        }
      } else {
        ans =1;
      }

      System.out.println("Case #" + (i + 1) + ": " + ans);
    }
  }

  public void printstack() {
    System.out.println("");
    List<Integer> a = new ArrayList<Integer>();
    while (travel.size() > 0) {
      int p = travel.pop();
      System.out.print(p + " => ");
      a.add(p);
    }
    for (Integer q : a) {
      travel.push(q);
    }
    System.out.println("");
  }

  public void travel(int now, int total, int con_size) {
    String constr = endStr.get(now);
    travel.push(now);
    if (travel.size() == total && con_size > 0) {
      ans++;
    } else {
      List<Integer> list = map.get("begin_" + constr);
      if (list != null) {
        for (Integer i : list) {
          if (!travel.contains(i)) {
            travel(i, total, con_size + 1);
          }
        }
      }

      for (int i = 0; i < total; i++) {
        if (!travel.contains(i) && travel.size() < total - 1 && con_size > 0) {
          travel(i, total, 0);
        }
      }

    }
    travel.pop();
  }


  public static void main(String[] args) {
    b main = new b();
    main.run();
  }

}
