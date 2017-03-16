import java.util.*;

public class GettingTheDigits{
  public static void main(String []args) {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for (int i = 1; i <= T; i++) {
      int []letters = new int[26];
      String S = in.next();
      for (int j = 0; j < S.length(); j++) {
        letters[S.charAt(j) - 'A']++;
      }
      int []digits = new int[10];
      digits[0] = letters['Z' - 'A'];
      for (int j = 0; j < digits[0]; j++) {
        letters['Z' - 'A']--;
        letters['E' - 'A']--;
        letters['R' - 'A']--;
        letters['O' - 'A']--;
      }
      
      digits[2] = letters['W' - 'A'];
      for (int j = 0; j < digits[2]; j++) {
        letters['T' - 'A']--;
        letters['W' - 'A']--;
        letters['O' - 'A']--;
      }
      
      digits[4] = letters['U' - 'A'];
      for (int j = 0; j < digits[4]; j++) {
        letters['F' - 'A']--;
        letters['O' - 'A']--;
        letters['U' - 'A']--;
        letters['R' - 'A']--;
      }
      
      digits[6] = letters['X' - 'A'];
      for (int j = 0; j < digits[6]; j++) {
        letters['S' - 'A']--;
        letters['I' - 'A']--;
        letters['X' - 'A']--;
      }
      
      digits[8] = letters['G' - 'A'];
      for (int j = 0; j < digits[8]; j++) {
        letters['E' - 'A']--;
        letters['I' - 'A']--;
        letters['G' - 'A']--;
        letters['H' - 'A']--;
        letters['T' - 'A']--;
      }
      
      digits[1] = letters['O' - 'A'];
      for (int j = 0; j < digits[1]; j++) {
        letters['O' - 'A']--;
        letters['N' - 'A']--;
        letters['E' - 'A']--;
      }
      
      digits[3] = letters['H' - 'A'];
      for (int j = 0; j < digits[3]; j++) {
        letters['T' - 'A']--;
        letters['H' - 'A']--;
        letters['R' - 'A']--;
        letters['E' - 'A']--;
        letters['E' - 'A']--;
      }
      
      digits[5] = letters['F' - 'A'];
      for (int j = 0; j < digits[5]; j++) {
        letters['F' - 'A']--;
        letters['I' - 'A']--;
        letters['V' - 'A']--;
        letters['E' - 'A']--;
      }
      
      digits[7] = letters['S' - 'A'];
      for (int j = 0; j < digits[7]; j++) {
        letters['S' - 'A']--;
        letters['E' - 'A']--;
        letters['V' - 'A']--;
        letters['E' - 'A']--;
        letters['N' - 'A']--;
      }
      
      digits[9] = letters['I' - 'A'];
      for (int j = 0; j < digits[9]; j++) {
        letters['N' - 'A']--;
        letters['I' - 'A']--;
        letters['N' - 'A']--;
        letters['E' - 'A']--;
      }
      
      System.out.print("Case #" + i + ": ");
      for (int j = 0; j < 10; j++) {
        for (int k = 0; k < digits[j]; k++)
          System.out.print(j);
      }
      System.out.println();
    }
  }
}