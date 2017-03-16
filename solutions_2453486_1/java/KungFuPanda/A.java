import java.util.*;
import java.io.*;
import java.util.Collections;


public class A {
  
  public static void main(String[] args) throws IOException {
    BufferedReader  br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    String[] board = new String[4];
    boolean finish;
    char winner;
    for(int i=0; i<n; i++) {
      for(int j=0; j<4; j++) {
        board[j] = br.readLine();
        //System.out.println(board[j]);
      }
      solve(board, i);
      br.readLine();
      if(i!=n-1) System.out.println();
    }
  }
  
  
  private static int solve(String[] board, int n) {
    for(int i=0; i<4; i++) {
      if(checkStr(board[i].toCharArray())) {
        printWinner(board[i].toCharArray(), n+1);
        return 0;
      }
    }
    char[] colm = new char[4];
    for(int i=0;i<4;i++) {
      for(int j=0;j<4;j++) colm[j] = board[j].charAt(i);
      //System.out.println("Checking for "+new String(colm));
      if(checkStr(colm)) {
        printWinner(colm, n+1);
        return 0;
      }
    }
    
    char[] d1 = new char[4];
    char[] d2 = new char[4];
    
    for(int i=0;i<4;i++) {
      d1[i] = board[i].charAt(i);
      d2[i] = board[i].charAt(3-i);
    }
      
     if(checkStr(d1)) {
        printWinner(d1, n+1);
        return 0;
      }
      
      if(checkStr(d2)) {
        printWinner(d2, n+1);
        return 0;
      }
     
      if(countEmpty(board)) {
       System.out.print("Case #"+(n+1)+": Game has not completed");
       return 0;
      }
      System.out.print("Case #"+(n+1)+": Draw");
      return 0;
  }
  
  private static boolean countEmpty(String[] board) {
    for(String str:board) {
      for(char x: str.toCharArray())
        if(x=='.') return true;
    }
    return false;
  }
  
  
  private static boolean checkStr(char[] result) {
    int count1 =0;
    int count2 =0;
    for(char x: result) {
      if(x=='.')
        return false;
      if(x=='T') continue;
      if(x == 'X') count1++;
      else count2++;
    }
    return (count1 ==0 || count2 == 0);
  }
  
  private static void printWinner(char[] result, int n) {
    char c='T';
    for(char x:result) {
      if(x == 'T') continue;
      c = x;
      break;
    }
    System.out.print("Case #"+n+": "+c+" won");
  }
}  