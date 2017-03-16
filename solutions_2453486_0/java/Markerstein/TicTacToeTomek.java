/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Mark
 */
public class TicTacToeTomek {
  static final String inputFileName = "in.txt";
  static final String outputFileName = "out.txt";
  static int[][] board;
  
  public static void print(String text) {
    System.out.println(text);
  }

  /**
   * @param args the command line arguments
   */
  public static void main(String[] args) {
    try {
      File file = new File(inputFileName);
      Scanner in = new Scanner(file);
      file = new File(outputFileName);
      PrintWriter out = new PrintWriter(file);
      
      
      int num = in.nextInt();
      
      for(int n=1; n<=num; n++) {
        
        board = new int[4][4];
        for(int y=0; y<4; y++) {
          String s = in.next();
          for(int x=0; x<4; x++) {
            char c = s.charAt(x);
            if(c=='X') {
              board[x][y] = 1;
            } else if(c=='O') {
              board[x][y] = 2;
            } else if(c=='T') {
              board[x][y] = 3;
            } else {
              board[x][y] = 0;
            }
          }
        }
        
        int winner = 0;
        
        for(int x=0; x<4; x++) {
          int won = 0;
          boolean ok = true;
          loop:
          for(int y=0; y<4; y++) {
            switch(board[x][y]) {
              case 0: ok = false; break loop;
              case 1: 
                if(won==1||won==0) {
                  won = 1;
                } else {
                  ok = false;
                  break loop;
                }
                break;
              case 2: 
                if(won==2||won==0) {
                  won = 2;
                } else {
                  ok = false;
                  break loop;
                }
                break;
              case 3:
                if(won==1||won==2) {
                  
                } else {
                  ok = false;
                  break loop;
                }
                break;
            }
          }
          
          if(ok) {
            winner = won;
            break;
          }
        }
        if(winner==0) {
          for(int y=0; y<4; y++) {
          int won = 0;
          boolean ok = true;
          loop:
          for(int x=0; x<4; x++) {
            switch(board[x][y]) {
              case 0: ok = false; break loop;
              case 1: 
                if(won==1||won==0) {
                  won = 1;
                } else {
                  ok = false;
                  break loop;
                }
                break;
              case 2: 
                if(won==2||won==0) {
                  won = 2;
                } else {
                  ok = false;
                  break loop;
                }
                break;
              case 3:
                if(won==1||won==2) {
                  
                } else {
                  ok = false;
                  break loop;
                }
                break;
            }
          }
          
          if(ok) {
            winner = won;
            break;
          }
        }
        }
        
        if(winner==0) {
          
          int won = 0;
          boolean ok = true;
          loop:
          for(int y=0; y<4; y++) {
            int x = y;
            switch(board[x][y]) {
              case 0: ok = false; break loop;
              case 1: 
                if(won==1||won==0) {
                  won = 1;
                } else {
                  ok = false;
                  break loop;
                }
                break;
              case 2: 
                if(won==2||won==0) {
                  won = 2;
                } else {
                  ok = false;
                  break loop;
                }
                break;
              case 3:
                if(won==1||won==2) {
                  
                } else {
                  ok = false;
                  break loop;
                }
                break;
            }
          }
          
          if(ok) {
            winner = won;
          }
        }
        
        if(winner==0) {
          
          int won = 0;
          boolean ok = true;
          loop:
          for(int y=0; y<4; y++) {
            int x = 3 - y;
            switch(board[x][y]) {
              case 0: ok = false; break loop;
              case 1: 
                if(won==1||won==0) {
                  won = 1;
                } else {
                  ok = false;
                  break loop;
                }
                break;
              case 2: 
                if(won==2||won==0) {
                  won = 2;
                } else {
                  ok = false;
                  break loop;
                }
                break;
              case 3:
                if(won==1||won==2) {
                  
                } else {
                  ok = false;
                  break loop;
                }
                break;
            }
          }
          
          if(ok) {
            winner = won;
          }
        }
        
        boolean draw = true;
        for(int x=0; x<4; x++) {
          for(int y=0; y<4; y++) {
            if(board[x][y]==0) draw = false;
          }
        }
          
        String str = "Case #"+n+": ";
        
        if(winner == 0) {
          if(draw) {
            str += "Draw";
          } else {
            str += "Game has not completed";
          }
        }
        if(winner == 1) str += "X won";
        if(winner == 2) str += "O won";
        
        out.println(str);
        print(str);
      }
      
      in.close();
      out.close();
    } catch (FileNotFoundException ex) {
      Logger.getLogger(TicTacToeTomek.class.getName()).log(Level.SEVERE, null, ex);
    }
  }
}
