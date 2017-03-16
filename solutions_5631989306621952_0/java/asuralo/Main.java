import java.util.*;
import java.io.*;
public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
    for (int i = 1; i <= t; ++i) {
      String s = in.next();
      StringBuilder result= new StringBuilder();
      for(int j = 0; j < s.length(); j++){
          if(j==0)
              result.append(s.charAt(0));
          else{
              if(s.charAt(j) >= result.charAt(0)) {
                  result.insert(0, s.charAt(j));
              }else{
                  result.append(s.charAt(j));
              }
          }
      }
      System.out.println("Case #" + i + ": " + result.toString());
    }
  }
}
