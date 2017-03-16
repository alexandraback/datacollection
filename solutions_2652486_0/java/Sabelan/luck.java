import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class luck {
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new File("luck.in"));
    PrintWriter out = new PrintWriter(new File("luck.out"));
    out.printf("Case #1:\n");
    in.nextInt();
    int r = in.nextInt();
    int n = in.nextInt();
    int m = in.nextInt();
    int numNumbers = in.nextInt();
    
    while (r-- != 0) {
      int[] set = new int[numNumbers];
      for (int i = 0; i < numNumbers; i++) {
        set[i] = in.nextInt();
      }
      
      String ret = "";
      for (int i = 2; i <= m && ret.isEmpty(); i++) {
        for (int j = i; j <= m && ret.isEmpty(); j++) {
          for (int k = j; k <= m && ret.isEmpty(); k++) {
            boolean makeAble = true;
            
            int[] arr = {i, j, k};
            
            
            for (int value : set) {
              boolean made = false;
              for (int bitset = 0; bitset < (1 << 3); bitset++) {
                int mult = 1;
                for (int inset = 0; inset < 3; inset++) {
                  if (((1 << inset) & bitset) != 0) {
                    mult *= arr[inset];
                  }
                }
                
                if (mult == value) {
                  made = true;
                  break;
                }
              }
              
              if (!made) {
                makeAble = false;
              }
            }
            
            if (makeAble) {
              ret = i + "" + j + "" + k;
            }
          }
        }
      }
      
      out.println(ret);
    }
    
    out.close();
  }
  // public static int[] factorize1(int... a) {
  // int[] factorSet = new int[6];
  // for(int i : a) {
  // for(int j = 2; j < 6; j++) {
  // while((i%j)==0) {
  // factorSet[j]
  // }
  // }
  // }
  // }
  //
  // public static int[] Minfactorize(int[] arr) {
  // int[] minFactors = new int[6];
  // for (int i = 0; i < arr.length; i++) {
  // int[] factorSet = new int[6];
  // int c = arr[i];
  // for (int j = 2; c != 1; j++) {
  // while ((c % j) == 0) {
  // c /= j;
  // factorSet[j]++;
  // }
  // }
  //
  // for (int j = 0; j < 6; j++) {
  // minFactors[j] = Math.max(minFactors[j], factorSet[j]);
  // }
  // }
  // return minFactors;
  // }
}
