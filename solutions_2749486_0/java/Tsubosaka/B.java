package r1c;

import java.util.Scanner;

public class B {
  static int solveX(int X){
    int x = 0;
    int turn = 0;
    if(X >= 0){
      while(true){
        if(x == X){
          return turn;
        }
        x -= turn + 1;
        x += turn + 2;
        turn += 2;
        System.out.print("WE");              
      }
    }else{
      while(true){
        if(x == X){
          return turn;
        }
        x += turn + 1;
        x -= turn + 2;
        turn += 2;
        System.out.print("EW");                    
      }
    }
  }
  static int solveY(int X , int turn){
    int x = 0;
    if(X >= 0){
      while(true){
        if(x == X){
          return turn;
        }
        x -= turn + 1;
        x += turn + 2;
        turn += 2;
        System.out.print("SN");              
      }
    }else{
      while(true){
        if(x == X){
          return turn;
        }
        x += turn + 1;
        x -= turn + 2;
        turn += 2;
        System.out.print("NS");                    
      }
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int cn = 1 ; cn <= T ; ++cn){
      int X = sc.nextInt();
      int Y = sc.nextInt();
      System.out.printf("Case #%d: ", cn);
      int turn = solveX(X);
      solveY(Y , turn);
      System.out.println();
    }
  }
}
