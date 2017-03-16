import java.io.File;
import java.util.Arrays;
import java.util.Scanner;


public class code {
  public static void main(String[] args) throws Exception {
    Scanner s = new Scanner(new File("A-small-attempt0.in"));// "Asample.in"));
    int input_size = s.nextInt();
    for (int n = 0; n < input_size; n++) {
      int test_size = s.nextInt();
      int[] a = new int[test_size + 1];
      s.findInLine(".").charAt(0);
      for (int x = 0; x <= test_size; x++){
        a[x] = s.findInLine(".").charAt(0) - '0';
      }
      long ret = solve(a);
      System.out.println("Case #" + (n + 1) + ": " + ret);
    }
  }
  private static long solve(int[] a) {
    long ret = 0;
    long sum = 0;
    for(int i = 0; i < a.length ; i++){
      if(sum + ret < i){
        ret = i - sum;
      }
      sum += a[i];
    }
    return ret;
  }
}
