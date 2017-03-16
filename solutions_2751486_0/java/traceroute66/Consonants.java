import java.util.Scanner;

public class Consonants {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();

    for (int i = 1; i <= n; i++)
      System.out.println("Case #" + i + ": " + new Consonants().solve(sc.next(), sc.nextInt()));
  }

  public long solve(String name, int n) {
    long count = 0;

    for (int i = n; i < name.length() + 1; i++) {
      for (int j = 0; j < name.length() - i + 1; j++) {
        int consecCons = 0;
        for (int k = j; k < j+i; k++) {
          if (isCons(name.charAt(k)))
            consecCons++;
          else
            consecCons = 0;

          if (consecCons >= n) {
            count++;
            break;
          }
        }
      }
    }

    return count;
  }

  private boolean isCons(char c) {
    return c != 'a'
        && c != 'e'
        && c != 'i'
        && c != 'o'
        && c != 'u';
  }
}
