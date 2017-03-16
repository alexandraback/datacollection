import java.io.*;
import java.lang.*;
import java.util.*;

public class A {
  public static void main(String[] args) {
    A a = new A();
    a.run(args[0]);
  }

  public void run(String fileName) {
    try {
      String[] keys = new String[4];
      String[] values = new String[4];
      keys[0] = "yeqz";
      values[0] = "aozq";
      keys[1] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
      values[1] = "our language is impossible to understand";
      keys[2] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
      values[2] = "there are twenty six factorial possibilities";
      keys[3] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
      values[3] = "so it is okay if you want to just give up";
      Map<Character, Character> dict = new HashMap<Character, Character>();
      for (int i = 0; i <= 3; ++i) {
        for (int j = 0; j < keys[i].length(); ++j) {
          Character key = keys[i].charAt(j);
          if (!dict.containsKey(key)) {
            Character value = values[i].charAt(j);
            dict.put(key, value);
          }
        }
      }

      Scanner fin = new Scanner(new File(fileName));
      PrintWriter fout = new PrintWriter(new File(fileName + ".out"));

      int T = fin.nextInt();
      fin.nextLine();

      String line;

      for (int t = 1; t <= T; ++t) {
        fout.format("Case #%d: ", t);

        line = fin.nextLine();

        for (int i = 0; i < line.length(); ++i) {
          fout.format("%c", dict.get(line.charAt(i)));
        }

        fout.format("\n");
      }
      fin.close();
      fout.close();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}
