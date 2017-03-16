import java.util.*;
import java.io.*;
import java.math.*;

public class A {
   static Scanner sc;

   public static void go() {
      int A = sc.nextInt();
      int N = sc.nextInt();
      int[] M = new int[N];
      for (int i=0; i<N; i++)
         M[i] = sc.nextInt();

      Arrays.sort(M);

      if (A == 1) {
         // special case. Can't grow
         System.out.println(N);
         return;
      }

      for (int ops=0; ops<=N; ops++) {
         // check if we can do it in this many ops
         int opCount = 0;
         int size = A;
         for (int i=0; i<N && opCount <= ops; i++) {
            // see if we can just remove the rest
            if (N - i + opCount <= ops) {
               opCount += (N - i);
               break;
            }

            // keep adding one size-1
            while (M[i] >= size) {
               opCount++;
               size += (size-1);
            }
            size += M[i];
         }

         if (opCount == ops) {
            System.out.println(ops);
            return;
         }
      }
   }

   public static void main(String[] args) {
      sc = new Scanner(System.in);
      int T = sc.nextInt();
      for (int i=1; i<=T; i++) {
         System.out.format("Case #%d: ", i);
         go();
      }
   }
}
