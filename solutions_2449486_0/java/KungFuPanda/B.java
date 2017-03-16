import java.util.*;
import java.io.*;
import java.util.Collections;


public class B {
  
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    
    int T = sc.nextInt();
    
    for(int i=1;i<=T; i++) {
      int row = sc.nextInt();
      int col = sc.nextInt();
      int[][] lawn = new int[row][col];
      
      for(int j=0; j<row; j++)
        for(int k=0; k<col; k++) lawn[j][k] = sc.nextInt();
     
      if(checkLawn(lawn)) {
        System.out.print("Case #"+i+": YES");
      } else {
        System.out.print("Case #"+i+": NO");
      }
      if(i!= T) System.out.println();
    }
  }
  
  
  private static boolean checkLawn(int[][] lawn) {
    int row = lawn.length;
    int col = lawn[0].length;
    
    if(row == 1 || col == 1) return true;
    
    for(int i=0;i<row; i++) {
      for(int j=0;j<col;j++)
        if(!checkVal(lawn, i,j)) return false;
    }
    return true;
  }
  
  private static boolean checkVal(int[][] lawn, int r, int c) {
    int row = lawn.length;
    int col = lawn[0].length;
    boolean flag=false;
    for(int i=0;i<col;i++) {
      if(lawn[r][c] < lawn[r][i])
        flag = true;
    }
    
    if(!flag) return true;
    
    for(int i=0;i<row;i++) {
      if(lawn[r][c] < lawn[i][c])
        return false;
    }
    return true;
  }
}