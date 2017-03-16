import java.util.*;
import java.io.*;

class CircleFound extends Exception {
};

class Clazz {
   int idx;
   boolean wasUsed;

   ArrayList<Clazz> parents = new ArrayList<Clazz>();

   public Clazz(int idx) {
      this.idx = idx;
   }

   void addParent(Clazz parent) {
      parents.add(parent);
   }

   void dfs() throws CircleFound {
      this.wasUsed = true;
      for (Clazz parent : parents) {
         if (parent.wasUsed) {
            throw new CircleFound();
         } else if (!parent.wasUsed) {
            parent.dfs();
         }
      }
   }

}

public class Main {

   Scanner in;
   PrintWriter out;

   int nBox;
   int nToys;
   long boxAmount[];
   long boxType[];
   long toyAmount[];
   long toyType[];
   long ans[][];
   boolean wasCalc[][];

   long go(int boxIdx, int toyIdx) {
      if (!wasCalc[boxIdx][toyIdx]) {
         if (boxType[boxIdx] == toyType[toyIdx]) {
            if (boxIdx == nBox - 1 && toyIdx < nToys - 1) {
               if (boxAmount[boxIdx] > toyAmount[toyIdx]) {
                  boxAmount[boxIdx]-=toyAmount[toyIdx];
                  ans[boxIdx][toyIdx] = toyAmount[toyIdx] + go(boxIdx, toyIdx + 1);
                  boxAmount[boxIdx]+=toyAmount[toyIdx];
               } else {
                  long save = boxAmount[boxIdx];
                  boxAmount[boxIdx] = 0;
                  ans[boxIdx][toyIdx] = save + go(boxIdx, toyIdx + 1);
                  boxAmount[boxIdx] = save;
               }
            } else if (toyIdx == nToys - 1 && boxIdx < nBox - 1) {
               if (boxAmount[boxIdx] > toyAmount[toyIdx]) {
                  long save = toyAmount[boxIdx];
                  toyAmount[boxIdx] = 0;
                  ans[boxIdx][toyIdx] = save + go(boxIdx + 1, toyIdx);
                  toyAmount[boxIdx] =save;
               } else {
                  toyAmount[toyIdx]-=boxAmount[boxIdx];
                  ans[boxIdx][toyIdx] = boxAmount[boxIdx] + go(boxIdx + 1, toyIdx);
                  toyAmount[toyIdx]+=boxAmount[boxIdx];
               }

            } else if (boxIdx == nBox - 1 && toyIdx == nToys - 1) {
               ans[boxIdx][toyIdx] = Math.min(toyAmount[toyIdx], boxAmount[boxIdx]);
            } else {
               if (boxAmount[boxIdx] > toyAmount[toyIdx]) {
                  long ans1 = go(boxIdx + 1, toyIdx + 1) + toyAmount[toyIdx];
                  boxAmount[boxIdx] -= toyAmount[toyIdx];
                  long ans2 = go(boxIdx, toyIdx + 1) + toyAmount[toyIdx];
                  boxAmount[boxIdx] += toyAmount[toyIdx];
                  ans[boxIdx][toyIdx] = Math.max(ans1, ans2);
               } else {
                  long ans1 = go(boxIdx + 1, toyIdx + 1) + boxAmount[boxIdx];
                  toyAmount[toyIdx] -= boxAmount[boxIdx];
                  long ans2 = go(boxIdx + 1, toyIdx) + boxAmount[boxIdx];
                  toyAmount[toyIdx] += boxAmount[boxIdx];
                  ans[boxIdx][toyIdx] = Math.max(ans1, ans2);
               }
            }
         } else {
            if (boxIdx == nBox - 1 && toyIdx < nToys - 1) {
               ans[boxIdx][toyIdx] = go(boxIdx, toyIdx + 1);
            } else if (toyIdx == nToys - 1 && boxIdx < nBox - 1) {
               ans[boxIdx][toyIdx] = go(boxIdx + 1, toyIdx);
            } else if (boxIdx == nBox - 1 && toyIdx == nToys - 1) {
               ans[boxIdx][toyIdx] = 0;
            } else {
               ans[boxIdx][toyIdx] = Math.max(go(boxIdx + 1, toyIdx),
                     Math.max(go(boxIdx, toyIdx + 1), go(boxIdx + 1, toyIdx + 1)));
            }

         }
         wasCalc[boxIdx][toyIdx] = true;
         return ans[boxIdx][toyIdx];
      } else {
         return ans[boxIdx][toyIdx];
      }
   }

   void solveOne() {
      nBox = in.nextInt();
      nToys = in.nextInt();
      boxAmount = new long[nBox];
      boxType = new long[nBox];
      for (int i = 0; i < 2 * nBox; i++) {
         if (i % 2 == 0) {
            boxAmount[i / 2] = in.nextLong();
         } else {
            boxType[i / 2] = in.nextLong();
         }
      }
      toyAmount = new long[nToys];
      toyType = new long[nToys];
      for (int i = 0; i < 2 * nToys; i++) {
         if (i % 2 == 0) {
            toyAmount[i / 2] = in.nextLong();
         } else {
            toyType[i / 2] = in.nextLong();
         }
      }
      ans = new long[nBox][nToys];
      wasCalc = new boolean[nBox][nToys];
      out.print(go(0, 0));
   }

   void solve() {
      int n = in.nextInt();
      for (int i = 1; i <= n; i++) {
         out.print("Case #" + i + ": ");
         solveOne();
         out.println();
      }
   }

   void run() {
      try {

         in = new Scanner(new FileReader("A-small-attempt0.in"));
         out = new PrintWriter("OUTPUT.TXT");
      } catch (Exception e) {
         throw new Error();
      }
      try {
         solve();
      } finally {
         out.close();
      }
   }

   public static void main(String[] a) {

      new Main().run();

   }
}