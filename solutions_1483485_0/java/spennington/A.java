import java.util.Scanner;

public class A {

  public static void output(int T) {
    System.out.print(String.format("Case #%d: ", T));
    System.out.println();
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    in.nextLine();
    
    char[] translation = new char[26];
    translation['y' - 'a'] = 'a';
    translation['n' - 'a'] = 'b';
    translation['f' - 'a'] = 'c';
    translation['i' - 'a'] = 'd';
    translation['c' - 'a'] = 'e';
    translation['w' - 'a'] = 'f';
    translation['l' - 'a'] = 'g';
    translation['b' - 'a'] = 'h';
    translation['k' - 'a'] = 'i';
    translation['u' - 'a'] = 'j';
    translation['o' - 'a'] = 'k';
    translation['m' - 'a'] = 'l';
    translation['x' - 'a'] = 'm';
    translation['s' - 'a'] = 'n';
    translation['e' - 'a'] = 'o';
    translation['v' - 'a'] = 'p';
    translation['z' - 'a'] = 'q';
    translation['p' - 'a'] = 'r';
    translation['d' - 'a'] = 's';
    translation['r' - 'a'] = 't';
    translation['j' - 'a'] = 'u';
    translation['g' - 'a'] = 'v';
    translation['t' - 'a'] = 'w';
    translation['h' - 'a'] = 'x';
    translation['a' - 'a'] = 'y';
    translation['q' - 'a'] = 'z';

    for (int i=0; i<T; i++) {
      String line = in.nextLine();
      System.out.print("Case #" + (i + 1) + ": ");
      for (char c : line.toCharArray()) {
        if (c == ' ') {
          System.out.print(c);
        } else if (c <= 'z' && c >= 'a'){
          System.out.print(translation[c - 'a']);
        }
      }
      System.out.println();
    }
  }
}