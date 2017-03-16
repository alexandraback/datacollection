package gcj16;

import java.util.Scanner;

public class CountingSheep {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    for(int i = 1; i <= n ; i++) {
      int number = scanner.nextInt();
      processTestCase(i, number);
    }

  }

  public static void processTestCase(int i, int number) {
    if(number == 0) {
      System.out.printf("Case #%d: INSOMNIA\n", i);
      return;
    }
    boolean digitFlag[] = {false, false, false, false, false, false, false, false, false, false};
    boolean complete = false;
    for(int j = 1; ; j++) {
      int copy = number * j;
      while (copy > 0) {
        digitFlag[copy % 10] = true;
        copy /= 10;
      }
      complete = checkCompleteness(digitFlag);
      if (complete) {
        System.out.printf("Case #%d: %d\n", i, number*j);
        break;
      }
    }
  }

  private static boolean checkCompleteness(boolean[] digitFlag) {
    for(int i = 0; i< 10; i++) {
      if(!digitFlag[i]) {
        return false;
      }
    }
    return true;
  }
}
