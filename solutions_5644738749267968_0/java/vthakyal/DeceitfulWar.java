import java.io.*;
import java.util.Arrays;

/**
 * Created by vivek on 12/04/14.
 */
public class DeceitfulWar {
   public static void main(String[] args) throws IOException {
      BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
      PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

      int tests = Integer.parseInt(reader.readLine().trim());
      for (int test = 1; test <= tests; test++) {
         int blocks = Integer.parseInt(reader.readLine().trim());
         double[] naoBlocks = getBlocks(reader.readLine().trim().split(" "));
         double[] kenBlocks = getBlocks(reader.readLine().trim().split(" "));

         Arrays.sort(naoBlocks);
         Arrays.sort(kenBlocks);
         int fairPoints = playFair(naoBlocks, kenBlocks);
         int cheatPoints = cheat(naoBlocks, kenBlocks);
         out.println("Case #" + test + ": " + cheatPoints + " " + fairPoints);
      }
      out.flush();
      out.close();
   }

   private static int playFair(double[] naoBlocks, double[] kenBlocks) {
      int points = 0;
      int naoMin = 0;
      boolean[] kenUsed = new boolean[kenBlocks.length];
      for (int i = 0; i < naoBlocks.length; i++) {
         double naoBlock = naoBlocks[naoMin++];
         double kenBlock = getKenBlock(naoBlock, kenBlocks, kenUsed);
         if (naoBlock > kenBlock) {
            points++;
         }
      }
      return points;
   }

   private static double getKenBlock(double naoBlock, double[] kenBlocks, boolean[] kenUsed) {
      int i = kenBlocks.length - 1;
      double kenMax;
      while(kenUsed[i]) i--;

      kenMax = kenBlocks[i];
      if (kenMax < naoBlock) {
         i = 0;
         while(kenUsed[i]) i++;
         kenUsed[i] = true;
         return kenBlocks[i];
      } else {
         //ceil of naoBlock
         int c = ceil(naoBlock, kenBlocks, 0, kenBlocks.length);
         while(kenUsed[c]) c++;
         kenUsed[c] = true;
         return kenBlocks[c];
      }
   }

   private static int ceil(double naoBlock, double[] kenBlocks, int lo, int hi) {
      if (lo >= hi) return -1;
      int mid = (lo + hi) / 2;
      if (kenBlocks[mid] >= naoBlock && (mid - 1 < 0 || kenBlocks[mid - 1] < naoBlock)) {
         return mid;
      } else if (kenBlocks[mid] < naoBlock) {
         return ceil(naoBlock, kenBlocks, mid + 1, hi);
      } else {
         return ceil(naoBlock, kenBlocks, lo, mid);
      }
   }


   private static int cheat(double[] naoBlocks, double[] kenBlocks) {
      int points = 0;

      int naoMin = 0;
      int kenMin = 0;
      int kenMax = kenBlocks.length - 1;

      for (int i = 0; i < naoBlocks.length; i++) {
         if (naoBlocks[naoMin] < kenBlocks[kenMin]) {
            naoMin++;
            kenMax--;
         } else {
            if (naoBlocks[naoMin] > kenBlocks[kenMin]) {
               points++;
            }
            naoMin++;
            kenMin++;
         }
      }
      return points;
   }

   private static double[] getBlocks(String[] arr) {
      double[] blocks = new double[arr.length];
      for (int i = 0; i < arr.length; i++) {
         blocks[i] = Double.parseDouble(arr[i]);
      }
      return blocks;
   }
}
