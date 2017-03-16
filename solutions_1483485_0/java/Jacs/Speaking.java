package qualA;

import java.util.*;

public class Speaking {
  
  private static int cases;
  
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    if (input.hasNextInt()) {
      cases = input.nextInt();
    }
    
    for (int i = 0; i <= cases; i++) {
      StringBuilder sb = new StringBuilder("Case #" + i + ": ");
      translate(input, sb);
    }
  }
  
  public static void translate(Scanner input, StringBuilder sb) {
    String text = "";
    if (input.hasNextLine()) {
      text = input.nextLine();
    }
    if (text.length() > 0) {
      for (int i = 0; i < text.length(); i++) {
        char letter = text.charAt(i);
        sb.append(translate(letter));
      }
      System.out.println(sb.toString());
    }
  }
  
  public static char translate(char letter) {
    switch (letter) {
      case ' ':
        return ' ';
      case 'a': 
        return 'y';
      case 'b':
        return 'h';
      case 'c':
        return 'e';
      case 'd':
        return 's';
      case 'e':
        return 'o';
      case 'f':
        return 'c';
      case 'g':
        return 'v';
      case 'h':
        return 'x';
      case 'i':
        return 'd';
      case 'j':
        return 'u';
      case 'k':
        return 'i';
      case 'l':
        return 'g';
      case 'm':
        return 'l';
      case 'n':
        return 'b';
      case 'o':
        return 'k';
      case 'p':
        return 'r';
      case 'q':
        return 'z';
      case 'r':
        return 't';
      case 's':
        return 'n';
      case 't':
        return 'w';
      case 'u':
        return 'j';
      case 'v':
        return 'p';
      case 'w':
        return 'f';
      case 'x':
        return 'm';
      case 'y':
        return 'a';
      case 'z':
        return 'q';
    }
    return ' ';
  }
}