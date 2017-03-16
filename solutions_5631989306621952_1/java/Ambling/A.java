package round1A;

import java.util.LinkedList;
import java.util.Scanner;

class A {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int T = scanner.nextInt();
    scanner.nextLine();
    for (int t = 1; t <= T; t++) {

      String S = scanner.nextLine();
      LinkedList<Character> output = new LinkedList<Character>();

      for (int i = 0; i < S.length(); i ++) {
        char letter = S.charAt(i);
        if (output.isEmpty() || output.getFirst() > letter) {
          output.add(letter);
        } else {
          output.add(0, letter);
        }
      }

      System.out.printf("Case #%d: ", t);
      while (!output.isEmpty()) {
        System.out.print(output.pollFirst());
      }
      System.out.print("\n");
    }
  }
}