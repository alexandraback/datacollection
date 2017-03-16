package roundTwo;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;

/**
 * Created by rubenverboon on 11/04/15.
 */
public class A {

  public static void main(String[] args) throws FileNotFoundException {
    Scanner sc = new Scanner(new File("/Users/rubenverboon/Documents/workspace/googlecode/src/main/resources/A.in"));
    PrintWriter pw = new PrintWriter(new File("/Users/rubenverboon/Documents/workspace/googlecode/src/main/resources/A.out"));
    A a = new A();
    int c = sc.nextInt();
    for (int i = 0; i < c; i++) {
      pw.println("Case #" + (i + 1) + ": " + a.solve(sc));
    }
    pw.close();
    sc.close();
  }


  private int solve(Scanner sc) {
    return f(sc.nextInt());

  }

  HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

  private int f(int i) {
    if (map.containsKey(i)) return map.get(i);
    int res = Integer.MAX_VALUE;
    if(i<10) return i;

    if(i%10!=0) {
      int b = Integer.parseInt(new StringBuilder(Integer.toString(i)).reverse().toString());
      if(b<i)
      res = 1 + f(b);
    }
    res = Math.min(res, 1+f(i-1));
    map.put(i, res);
    return res;
  }


}
