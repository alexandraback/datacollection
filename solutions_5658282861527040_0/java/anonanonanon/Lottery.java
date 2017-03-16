public class Lottery {

   public static void main(String[] args) {
      int T = StdIn.readInt();
      for (int t = 0; t < T; t++) {
         int a = StdIn.readInt();
         int b = StdIn.readInt();
         int k = StdIn.readInt();
         int count = 0;
         for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
               int c = i & j;
               if (c < k) count++; 
            }
         }
         System.out.println("Case #" + (t + 1) + ": " + count);
      }
      
   }

}
