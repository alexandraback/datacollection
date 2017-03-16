import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class FinalCountdown {

  public static void main(String[] args) throws FileNotFoundException {
    Scanner in = new Scanner(new File("A-small-attempt0 (2).in"));
    PrintWriter out = new PrintWriter(new File("finalCountdownOutS.txt"));
    long numTests = in.nextLong();

    for (long test = 0; test < numTests; test++) {
      in.nextLine();
      String stack = in.next();
      String res = "";
      for(char c : stack.toCharArray()){
        String front = c + res;
        String back = res + c;
        if(front.compareTo(res) > 0){
          res = front;
        }
        else {
          res = back;
        }
      }
      
      out.print("Case #" + (test+1) + ": ");
        out.println(res);
    }
    out.close();
    in.close();
  }
}
