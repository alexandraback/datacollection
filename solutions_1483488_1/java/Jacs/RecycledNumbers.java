package qualC;

import java.util.*;

public class RecycledNumbers {
  
  private static int cases;
  
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    if (input.hasNextInt()) {
      cases = input.nextInt();
    }
    
    for (int i = 0; i < cases; i++) {
      System.out.println("Case #" + (i+1) + ": " + findRecycled(input));
    }
  }
  
  public static int findRecycled(Scanner input) {
    int startingPoint = 0;
    int endingPoint = 0;
    int counter = 0;
    
    if (input.hasNextInt()) {
      startingPoint = input.nextInt();
    }
    
    if (input.hasNextInt()) {
      endingPoint = input.nextInt();
    }
    
   
    //for each item from start->end..
    for (Integer i = startingPoint; i < endingPoint; i++) {
      
      //cast that item to a string..
      String value = i.toString();
      ArrayList<Integer> thisItem = new ArrayList<Integer>();
      //for each character in the string..
      for (int z = 0; z < value.length(); z++) {
        
        //shuffle the characters along one
        String rotate = value.substring(z);
        rotate += value.substring(0, z);
        
        //cast to an int
        int shuffledInt = Integer.parseInt(rotate);
        
        //make sure it is within the boundaries..
        if (shuffledInt <= endingPoint && shuffledInt >= startingPoint) {
          
          //if it is greater than the original then it is a duplicate
          if (Integer.parseInt(value) < shuffledInt) {
            //make sure if we've looked at this item before that it's not a duplicate..
            if (!thisItem.contains(shuffledInt)) {
              counter++;
              thisItem.add(shuffledInt);
            }
          }
        }
       
      }
    }
    
    return counter;
  }
}