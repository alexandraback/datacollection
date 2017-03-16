import java.util.Scanner;

public class A {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int numCases = scanner.nextInt();
    for (int i = 1; i <= numCases; ++i)
      System.out.printf("Case #%d: %s\n", i, getResult(scanner.next()));
  }

  private static String getResult(String s) {
    String last = "";
    for (char c : s.toCharArray()) {
      if (last.isEmpty() || c >= last.charAt(0))
        last = c + last;
      else
        last = last + c;
    }
    return last;
  }
}
