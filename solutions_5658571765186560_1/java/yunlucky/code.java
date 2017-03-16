import java.io.File;
import java.util.Arrays;
import java.util.Scanner;


public class code {
  public static void main(String[] args) throws Exception {
    Scanner s = new Scanner(new File("D-Large.in"));// "Asample.in"));
    int input_size = s.nextInt();
    for (int n = 0; n < input_size; n++) {
      int x = s.nextInt();
      int r = s.nextInt();
      int c = s.nextInt();
      String ret = solve(x,c,r)?"GABRIEL":"RICHARD";
      System.out.println("Case #" + (n + 1) + ": " + ret);
    }
  }
  private static boolean solve(int x, int c, int r) {
    if(x >= 7){
      return false;
    }if(x > c && x > r){
      return false;
    }if(c * r % x != 0){
      return false;
    }if((x + 1) /2 > Math.min(c,r)){
      return false;
    }if(x == 1 || x == 2|| x == 3){
      return true;
    }if(x == 4){
      return Math.min(c,r) > 2;
    }if(x == 5){
      return !(Math.min(c,r) == 3 && Math.max(c,r) == 5);
    }if(x == 6){
      return Math.min(c,r) > 3;
    }
    return false;
  }
}
