import java.util.*;

public class SpeakingInTongues
{
  public static void main(String []args)
  {
    Scanner in = new Scanner(System.in);
    int n = Integer.parseInt(in.nextLine());
    for(int i = 1; i <= n; i++)
    {
      System.out.print("Case #" + i + ": ");
      String s = in.nextLine();
      for(int j = 0; j < s.length(); j++)
        System.out.print(translate(s.charAt(j)));
      if(i < n) System.out.println();
    }
  }
  
  public static char translate(char c)
  {
    switch(c)
    {
      case 'y': return 'a';
      case 'n': return 'b';
      case 'f': return 'c';
      case 'i': return 'd';
      case 'c': return 'e';
      case 'w': return 'f';
      case 'l': return 'g';
      case 'b': return 'h';
      case 'k': return 'i';
      case 'u': return 'j';
      case 'o': return 'k';
      case 'm': return 'l';
      case 'x': return 'm';
      case 's': return 'n';
      case 'e': return 'o';
      case 'v': return 'p';
      case 'z': return 'q';
      case 'p': return 'r';
      case 'd': return 's';
      case 'r': return 't';
      case 'j': return 'u';
      case 'g': return 'v';
      case 't': return 'w';
      case 'h': return 'x';
      case 'a': return 'y';
      case 'q': return 'z';
      default: return ' ';
    }
  }
}