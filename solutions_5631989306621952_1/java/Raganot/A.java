import java.math.BigInteger;
import java.util.*;
import java.io.*;
public class A {
  public static void main(String[] args) {
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    int t = in.nextInt();
    for (int i = 1; i <= t; ++i) {
      String str = in.next();

      String result = "" +str.charAt(0);

      for(int l=1; l< str.length(); l++ ){
        if(str.charAt(l) < result.charAt(0)){
          result = result + str.charAt(l);
        } else {
          result = str.charAt(l) + result;
        }

      }
      System.out.println("Case #" + i + ": " + result );
    }
  }

}
