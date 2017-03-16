// Author: Alejandro Sotelo Arevalo
package round1b;

import java.io.*;
import java.util.*;

public class B_CloseMatch { // small: OK, large:
  private static final String FILENAME="src/round1b/B-small-attempt0";
  private static final boolean STANDARD_OUTPUT=false;
  public static void main(String[] args) throws Throwable {
    try (BufferedReader in=new BufferedReader(new FileReader(FILENAME+".in"))) {
      try (PrintStream out=!STANDARD_OUTPUT?new PrintStream(FILENAME+".out"):System.out) {
        for (int test=1,TESTS=Integer.parseInt(in.readLine()); test<=TESTS; test++) {
          StringTokenizer tokenizer=new StringTokenizer(in.readLine());
          out.println("Case #"+test+": "+solveSlow(tokenizer.nextToken(),tokenizer.nextToken()));
        }
      }
    }
  }
  static int n;
  static char[] array1,array2;
  static int minScore[]=null;
  static String answer="";
  static String solveSlow(String C, String J) {
    n=C.length();
    array1=C.toCharArray();
    array2=J.toCharArray();
    minScore=null;
    answer="";
    solveSlow(0,0);
    return answer;
  }
  static void solveSlow(int i, int j) {
    if (i==n&&j==n) {
      int number1=Integer.parseInt(new String(array1));
      int number2=Integer.parseInt(new String(array2));
      int score[]={Math.abs(number1-number2),number1,number2};
      if (minScore==null||score[0]<minScore[0]||(score[0]==minScore[0]&&(score[1]<minScore[1]||(score[1]==minScore[1]&&score[2]<minScore[2])))) {
        minScore=score;
        answer=new String(array1)+" "+new String(array2);
      }
    }
    else if (i==n) {
      if (array2[j]=='?') {
        for (char ch='0'; ch<='9'; ch++) {
          array2[j]=ch;
          solveSlow(i,j+1);
          array2[j]='?';
        }
      }
      else {
        solveSlow(i,j+1);
      }
    }
    else {
      if (array1[i]=='?') {
        for (char ch='0'; ch<='9'; ch++) {
          array1[i]=ch;
          solveSlow(i+1,j);
          array1[i]='?';
        }
      }
      else {
        solveSlow(i+1,j);
      }
    }
  }
}
