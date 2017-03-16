package qualB;

import java.util.*;

public class Dancing {
  
  private static int cases;
  
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    if (input.hasNextInt()) {
      cases = input.nextInt();
    }
    
    for (int i = 0; i < cases; i++) {
      System.out.println("Case #" + (i+1) + ": " + getBest(input));
    }
  }
  
  
  /* If n is 0, 1, 29 or 30 then there is no special case.. otherwise:
   * if (n%3 == 0)
   * normal case:  [(n/3), (n/3), (n/3)]
   * special case: [(n/3)-1, (n/3), (n/3)+1]
   * 
   * if (n%3 == 1)
   * normal case:  [(n/3), (n/3), (n/3)+1]
   * special case: [(n/3)-1, (n/3)+1, (n/3)+1]
   * 
   * if (n%3 == 2) 
   * normal case:  [(n/3), (n/3)+1, (n/3)+1]
   * special case: [(n/3), (n/3), (n/3)+2]
   * 
   */
  public static int getBest(Scanner input) {
    int googlers = 0;
    int surprising = 0;
    int scoreWanted = 0;
    int counter = 0;
    
    if (input.hasNextInt()) {
      googlers = input.nextInt();
    }
    if (input.hasNextInt()) {
      surprising = input.nextInt();
    }
    if (input.hasNextInt()) {
      scoreWanted = input.nextInt();
    }
    
    Integer[] scores = new Integer[googlers];
    for (int i = 0; i < scores.length; i++) {
      if (input.hasNextInt()) {
        scores[i] = input.nextInt();
      }
    }
    
    for (int i = 0; i < scores.length; i++) {
      int n = scores[i];
      
      //0, 1, 29 and 30 don't have special cases..
      if (n == 0) {
        if (0 >= scoreWanted) {
          counter++;
        }
      } else if (n == 1) {
        if (1 >= scoreWanted) {
          counter++;
        }
      } else if (n == 29 || n == 30) {
        if (10 >= scoreWanted) {
          counter++;
        }
      } else {
        
        
        if (n % 3 == 0) {
          //case 1:
          
          if ((n / 3) >= scoreWanted) {
            //normal case
            counter++;
          } else {
            //special case..?
            if (surprising > 0 && ((n / 3)+1 >= scoreWanted)) {
              counter++;
              surprising--;
            }
          }
          
        } else if (scores[i] % 3 == 1) {
          //case 2:
          
          if ((n / 3)+1 >= scoreWanted) {
            //normal case and special case in this case..
            counter++;
          }
          
        } else {
          //case 3:
          
          if ((n / 3)+1 >= scoreWanted) {
            //normal case
            counter++;
          } else {
            //special case..?
            if (surprising > 0 && ((n / 3)+2 >= scoreWanted)) {
              counter++;
              surprising--;
            }
          }
        }
      }
      
    }
    return counter;
  }
}