import java.util.*;

public class Kingdom {
   public static void main(String[] args) {
      Scanner scan = new Scanner(System.in);
      int T = scan.nextInt();
      for (int i = 1; i <= T; i++) {
         System.out.println("Case #"+i+": "+solve(scan));
      }
   }
   
   public static Object solve(Scanner scan) {
      int N = scan.nextInt();
      int[] s1 = new int[N], s2 = new int[N];
      for ( int i = 0; i < N; i++) {
         s1[i] = scan.nextInt();
         s2[i] = scan.nextInt();
      }
      int stars = 0;
      int o = 0;
      
      out: while (stars < N*2) {
         o++;
         for (int i = 0; i < N; i++) {
            if (s2[i] >= 0 && s2[i] <= stars) {
               stars++;
               s2[i] = -1;
               if (s1[i] != -1) {
                  s1[i] = -1;
                  stars++;
               }
               continue out;
            }
         }
         int max = -1, mi = -1;
         for (int i = 0; i < N; i++) {
            if (s1[i] >= 0 && s1[i] <= stars && s2[i] > max) {
               mi = i;
               max = s2[i];
            }
         }
         if (max != -1) {
            s1[mi] = -1;
            stars++;
            continue out;
         }
         
         return "Too Bad";
      }
      return o+"";
   }
}