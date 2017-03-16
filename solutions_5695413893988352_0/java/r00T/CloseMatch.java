import java.util.Scanner;

public class CloseMatch {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    for(int i = 1; i <= n ; i++) {
      String str1 = scanner.next();
      String str2 = scanner.next();
      processTestCase(i, str1, str2);
    }

  }

  private static void processTestCase(int t, String str1, String str2) {
    int qm = 0;
    for(int i = 0; i < str1.length(); i++) {
      if(str1.charAt(i) == '?') {
        qm++;
      }
      if(str2.charAt(i) == '?') {
        qm++;
      }
    }
    int num1Final = 0, num2Final = 0, difference = Integer.MAX_VALUE;
    for(int i = 0; i < Math.pow(10, qm); i++) {
      int arr[] = new int[qm];
      for(int j = 0; j < qm;j++) {
        arr[j] = (i/(int)Math.pow(10,j))%10;
      }
      int pointer = 0;
      int num1 = 0, num2 = 0;
      for(int j = 0;j < str1.length();j++) {
        if(str1.charAt(j) == '?') {
          num1 = num1 * 10 + arr[pointer++];
        } else {
          num1 = num1 * 10 + (str1.charAt(j) - '0');
        }
      }
      for(int j = 0;j < str2.length();j++) {
        if(str2.charAt(j) == '?') {
          num2 = num2 * 10 + arr[pointer++];
        } else {
          num2 = num2 * 10 + (str2.charAt(j) - '0');
        }
      }
      if(Math.abs(num1 - num2) < difference) {
        num1Final = num1;
        num2Final = num2;
        difference = Math.abs(num1 - num2);
      } else if (Math.abs(num1 - num2) == difference) {
        if(num1 < num1Final) {
          num1Final = num1;
          num2Final = num2;
          difference = Math.abs(num1 - num2);
        } else if (num1 == num1Final) {
          if(num2 < num2Final) {
            num1Final = num1;
            num2Final = num2;
            difference = Math.abs(num1 - num2);
          }
        }
      }
    }
    System.out.println("Case #" + t + ": " + String.format("%0" + str1.length() +"d", num1Final) + " " + String.format("%0" + str2.length() +"d", num2Final));
  }
}
