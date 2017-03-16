package gcj16.qualification.b;

import java.util.Scanner;

public class RevengeOfThePancakes {

  private static char stack[];
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    for(int i = 1; i <= n ; i++) {
      String s = scanner.next();
      processTestCase(i, s);
    }

  }

  private static void processTestCase(int testCaseNumber, String s) {
    stack = s.toCharArray();
    int swaps = 0;
    while(true) {
      int lastIndexOfMinus = -1;
      for (int i = stack.length - 1; i >= 0; i--) {
        if (stack[i] == '-') {
          lastIndexOfMinus = i;
          break;
        }
      }
      if(lastIndexOfMinus == -1) {
        System.out.println("Case #" + testCaseNumber + ": " + swaps);
        return;
      }
      int firstIndexOfMinus = -1;
      if (stack[0] == '+') {
        for(int i = 0;i<=lastIndexOfMinus; i++) {
          if(stack[i] == '-') {
            firstIndexOfMinus = i;
            break;
          }
        }
        swapStack(firstIndexOfMinus - 1);
        swaps++;
      }
      swapStack(lastIndexOfMinus);
      swaps++;
    }
  }

  private static void swapStack(int lastIndex) {
    int a = 0, b = lastIndex;
    while(a <= b) {
      char temp = stack[a];
      stack[a] = swapSign(stack[b]);
      stack[b] = swapSign(temp);
      a++;
      b--;
    }
  }

  private static char swapSign(char c) {
    if(c == '+') {
      return '-';
    }
    return '+';
  }

}
