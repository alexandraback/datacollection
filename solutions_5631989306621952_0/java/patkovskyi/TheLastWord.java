import java.util.Scanner;

public class TheLastWord {

  public static String lastWord(String s) {
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < s.length(); i++) {

      if (i == 0 || s.charAt(i) >= sb.charAt(0)) {
        sb.insert(0, s.charAt(i));
      } else {
        sb.append(s.charAt(i));
      }
    }

    return sb.toString();
  }

  public static void main(String args[]) {
    Scanner in = new Scanner(System.in);
    long T = Long.parseLong(in.nextLine());

    for (long i = 1; i <= T; i++) {
      String s = in.nextLine();

      String answer = lastWord(s);

      System.out.printf("Case #%d: %s%n", i, answer);
    }

    in.close();
  }
}
