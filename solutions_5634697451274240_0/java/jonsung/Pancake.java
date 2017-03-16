import java.util.*;
import java.io.*;

public class Pancake {
  public static void main(String[] args) throws Exception {
    Scanner scan = new Scanner(new File("B-small-attempt0.in"));
    PrintWriter pw = new PrintWriter(new File("B.out"));
    //Scanner scan = new Scanner(System.in);
   // PrintWriter pw = new PrintWriter(System.out);
    
    int t = scan.nextInt();

    for(int i=1; i<=t; i++) {
      String cakes = scan.next();
      char curChar = cakes.charAt(0);
      int signChanges = 0;
      for (int j=1; j<cakes.length(); j++) {
        if (cakes.charAt(j) != curChar) {
          signChanges += 1;
          curChar = cakes.charAt(j);
        } else {
          
        }
      }
      
      // add extra 1 if last pancake is a -
      if (cakes.charAt(cakes.length()-1) == '-') signChanges += 1;
      
      //output
      pw.println("Case #" + i + ": " + signChanges);
    }
    

    pw.close();  
    
  }
}