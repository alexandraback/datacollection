import java.io.*;
import java.util.*;

public class D{
  public static void main (String[] args) throws IOException{
    Scanner in = new Scanner (new FileReader("D-small-attempt7.in"));
    PrintWriter out = new PrintWriter ("D.out");
    int cases = in.nextInt();
    testLoop:
    for (int casenum = 1; casenum <= cases; casenum++){
      int x = in.nextInt();
      int r = in.nextInt();
      int c = in.nextInt();
      
      if (x >= 7){
        out.println ("Case #" + casenum + ": RICHARD"); //missed the box option the first time around
        continue;
      }
      if ((r*c)%x != 0){
        out.println ("Case #" + casenum + ": RICHARD");
        continue;
      }    
      if (x > r && x > c){
        out.println ("Case #" + casenum + ": RICHARD");
        continue;
      }
      if (x/2 + x%2> r || x/2 + x%2> c){ //missed the %2s for a long time
        out.println ("Case #" + casenum + ": RICHARD");
        continue;
      }
      if (x > Math.min (r, c)){
        int width = Math.min(r, c);
        int remaining = x - width;  //this one is actually tricky, noticed after 2nd fail, took way too many tries to get it right
        int length = Math.max (r, c);
        //System.out.println ("testing cut-off, remaining = " + remaining);
        richardsLoop:
        for (int side = 0; side <= remaining/2 + remaining%2; side++){
          for (int space = side; space < length - remaining + side; space++){
            //System.out.println ("Testing configuration: space = " + space + "width = " + width + "length = " + length + "side = " + side);
            if ((space * width - side)%x == 0 && ((length - 1 - space)*width - remaining + side)%x == 0){
              //System.out.println ("winnable for side value: " + side + " with space of: " + space);
              continue richardsLoop;
            }
          }
           out.println ("Case #" + casenum + ": RICHARD");
           continue testLoop;
        }
      }
      
      out.println ("Case #" + casenum + ": GABRIEL");
     }
    out.close();
    in.close();
  }
}