import java.util.*;

public class Keystroke {
   public static void main(String[] args) {
      Scanner scan = new Scanner(System.in);
      int T = scan.nextInt();
      for (int i = 1; i <= T; i++) {
         System.out.println("Case #"+i+": "+solve(scan));
      }
   }
   
   public static Object solve(Scanner scan) {
      int A = scan.nextInt(), B = scan.nextInt();
      double[] arr = new double[A];
      for (int i = 0; i < A; i++) {
         arr[i] = scan.nextDouble();
      }
      double out = Double.MAX_VALUE;
      
      double[] pRight = new double[A+1];
      double curProd = 1;
      for (int i = 0; i <= A; i++) {
         pRight[i] = curProd;
         if (i != arr.length)
            curProd *= arr[i];
      }
      
      for (int i = 0; i <= A; i++) {
         double pError = 1-pRight[A-i];
         double prob = pError * (B+1) + i*2 + 1 + B - A;
         out = Math.min(prob, out);
      }
      
      return Math.min(out/*+ 1 + B - A*/, B + 2);
   }
   
   public static double prod(double[] arr, int ndx) {
      double out = 1;
      for (int i = 0; i < ndx; i++)
         out *= arr[i];
      return out;
   }
}