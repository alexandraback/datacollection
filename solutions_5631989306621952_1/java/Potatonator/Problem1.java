import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Problem1 {

  private static String calculate(String line) {

    char c = ' ';
    char[] chars = line.toCharArray();

    c = chars[0];
    String s = c + "";

    for (int i = 1; i < chars.length; i++) {

      if (chars[i] < c) { s = s + chars[i]; }
      else { s = chars[i] + s; c = chars[i]; }

    }

    return s;

  }

  public static void main(String[] args) {

    Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

    int i = 0;
    int cases = Integer.parseInt(sc.nextLine());

    while (i < cases) {

      String line = sc.nextLine();
      String result = calculate(line);
      i++;

      System.out.println("Case #" + i + ": " + result);

    }

  }

}
