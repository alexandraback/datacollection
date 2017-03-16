// Author: Alejandro Sotelo Arevalo
package round1b;

import java.io.*;
import java.util.*;

public class A_GettingTheDigits { // small: , large:
  private static final String FILENAME="src/round1b/A-small-attempt1";
  private static final boolean STANDARD_OUTPUT=false;
  public static void main(String[] args) throws Throwable {
    try (BufferedReader in=new BufferedReader(new FileReader(FILENAME+".in"))) {
      try (PrintStream out=!STANDARD_OUTPUT?new PrintStream(FILENAME+".out"):System.out) {
        for (int test=1,TESTS=Integer.parseInt(in.readLine()); test<=TESTS; test++) {
          String S=in.readLine();
          out.println("Case #"+test+": "+solve(S));
        }
      }
    }
  }
  static int freq[]=new int[26],digits[]=new int[10];
  static String solve(String S) {
    Arrays.fill(freq,0);
    for (char ch:S.toCharArray()) {
      freq[ch-'A']++;
    }
    Arrays.fill(digits,0);
    consume(0,'Z',"ZERO");
    consume(2,'W',"TWO");
    consume(6,'X',"SIX");
    consume(8,'G',"EIGHT");
    consume(3,'H',"THREE");
    consume(4,'R',"FOUR");
    consume(5,'F',"FIVE");
    consume(7,'S',"SEVEN");
    consume(1,'O',"ONE");
    consume(9,'N',"NINE");
    StringBuilder stringBuilder=new StringBuilder();
    for (int digit=0; digit<10; digit++) {
      for (int iteration=0; iteration<digits[digit]; iteration++) {
        stringBuilder.append((char)('0'+digit));
      }
    }
    return stringBuilder.toString();
  }
  @SuppressWarnings("unused")
  static void consume(int digit, char clue, String number) {
    int min=Integer.MAX_VALUE;
    for (char ch:number.toCharArray()) {
      min=Math.min(min,freq[ch-'A']);
    }
    digits[digit]=min;
    for (char ch:number.toCharArray()) {
      freq[ch-'A']-=min;
    }
  }
}
