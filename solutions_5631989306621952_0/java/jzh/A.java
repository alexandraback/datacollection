/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
  public static void main (String[] args) throws java.lang.Exception
  {
    Scanner in = new Scanner(System.in);
    int t = in.nextInt();
    in.nextLine();
    for(int i = 1; i <= t; i++) {
      System.out.printf("Case #%d: ", i);
      String s = in.nextLine();
      String cur = "";
      for(int j = 0; j < s.length(); j++) {
        String choice1 = s.charAt(j) + cur;
        String choice2 = cur + s.charAt(j);
        if(choice1.compareTo(choice2) >= 0) {
          cur = choice1;
        } else {
          cur = choice2;
        }
      }
      System.out.println(cur);
    }
    
  }
}