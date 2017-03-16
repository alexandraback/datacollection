import java.util.Scanner;

public class GettingTheDigits {

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    for(int i = 1; i <= n ; i++) {
      String str = scanner.next();
      processTestCase(i, str);
    }

  }

  private static void processTestCase(int t, String str) {
    int arr[] = new int[26];
    for(int i = 0; i<str.length();i++) {
      arr[str.charAt(i) - 'A']++;
    }
    int digit[] = new int[10];
    digit[2] = arr['W'-'A'];
    digit[4] = arr['U'-'A'];
    digit[6] = arr['X'-'A'];
    digit[8] = arr['G'-'A'];
    digit[0] = arr['Z'-'A'];
    digit[5] = arr['F'-'A'] - digit[4];
    digit[7] = arr['V'-'A'] - digit[5];
    digit[9] = arr['I'-'A'] - digit[8] - digit[6] - digit[5];
    digit[3] = arr['R'-'A']- digit[4] - digit[0];
    digit[1] = arr['O'-'A']- digit[4] - digit[0] - digit[2];
    System.out.print("Case #" + t + ": ");
    for(int i = 0; i < 10 ;i++) {
      for(int j = 0;j < digit[i];j++) {
        System.out.print(i);
      }
    }
    System.out.println();
  }
}
