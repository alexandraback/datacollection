// Author: Alejandro Sotelo Arevalo
package round1b;

import java.io.*;
import java.math.*;
import java.util.*;

public class B_CloseMatch { // small: OK, large:
  private static final String FILENAME="src/round1b/B-large";
  private static final boolean STANDARD_OUTPUT=false;
  public static void main(String[] args) throws Throwable {
    try (BufferedReader in=new BufferedReader(new FileReader(FILENAME+".in"))) {
      try (PrintStream out=!STANDARD_OUTPUT?new PrintStream(FILENAME+".out"):System.out) {
        for (int test=1,TESTS=Integer.parseInt(in.readLine()); test<=TESTS; test++) {
          StringTokenizer tokenizer=new StringTokenizer(in.readLine());
          String C=tokenizer.nextToken(),J=tokenizer.nextToken();
          out.println("Case #"+test+": "+solveFast(C,J));
        }
      }
    }
  }
  static String solveFast(String C, String J) {
    return new FastSolver().solveFast(C,J);
  }
  static class FastSolver {
    int n;
    char[] X,Y;
    BigInteger minScore[]=null;
    String answer="";
    String solveFast(String C, String J) {
      n=C.length();
      X=C.toCharArray();
      Y=J.toCharArray();
      minScore=null;
      answer="";
      solveFast(0,0);
      return answer;
    }
    static int[][][] OPTIONS1=new int[][][]{{{'9','0'},{'1','0'}},{{'0','0'},{'1','0'},{'0','1'}},{{'0','9'},{'0','1'}}};
    void solveFast(int i, int state) {
      if (i==n) {
        BigInteger number1=new BigInteger(new String(X));
        BigInteger number2=new BigInteger(new String(Y));
        BigInteger score[]={number1.subtract(number2).abs(),number1,number2};
        if (minScore==null||score[0].compareTo(minScore[0])<0||(score[0]==minScore[0]&&(score[1].compareTo(minScore[1])<0||(score[1]==minScore[1]&&score[2].compareTo(minScore[2])<0)))) {
          minScore=score;
          answer=new String(X)+" "+new String(Y);
        }
      }
      else {
        char x=X[i],y=Y[i];
        if (x=='?'&&y=='?') {
          for (int chs[]:OPTIONS1[state+1]) {
            X[i]=(char)chs[0];
            Y[i]=(char)chs[1];
            solveFast(i+1,state!=0?state:Integer.compare(X[i],Y[i]));
          }
        }
        else if (x=='?'&&y!='?') {
          if (state!=0) {
            X[i]=state==-1?'9':'0';
            solveFast(i+1,state!=0?state:Integer.compare(X[i],Y[i]));
          }
          else {
            for (int d=-1; d<=1; d++) {
              int ch=y+d;
              if (ch>='0'&&ch<='9') {
                X[i]=(char)ch;
                solveFast(i+1,state!=0?state:Integer.compare(X[i],Y[i]));
              }
            }
          }
        }
        else if (x!='?'&&y=='?') {
          if (state!=0) {
            Y[i]=state==-1?'0':'9';
            solveFast(i+1,state!=0?state:Integer.compare(X[i],Y[i]));
          }
          else {
            for (int d=-1; d<=1; d++) {
              int ch=x+d;
              if (ch>='0'&&ch<='9') {
                Y[i]=(char)ch;
                solveFast(i+1,state!=0?state:Integer.compare(X[i],Y[i]));
              }
            }
          }
        }
        else {
          solveFast(i+1,state!=0?state:Integer.compare(X[i],Y[i]));
        }
        X[i]=x;
        Y[i]=y;
      }
    }
  }
  static String solveSlow(String C, String J) {
    return new SlowSolver().solveSlow(C,J);
  }
  static class SlowSolver {
    int n;
    char[] array1,array2;
    int minScore[]=null;
    String answer="";
    String solveSlow(String C, String J) {
      n=C.length();
      array1=C.toCharArray();
      array2=J.toCharArray();
      minScore=null;
      answer="";
      solveSlow(0,0);
      return answer;
    }
    void solveSlow(int i, int j) {
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
}
