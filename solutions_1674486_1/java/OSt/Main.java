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

   void solveOne() {
      int n = in.nextInt();
      Clazz classes[] = new Clazz[1 + n];
      for (int i = 1; i <= n; i++) {
         classes[i] = new Clazz(i);
      }
      for (int idx = 1; idx <= n; idx++) {
         int nParents = in.nextInt();

         for (int i = 1; i <= nParents; i++) {
            int parentIdx = in.nextInt();
            classes[idx].addParent(classes[parentIdx]);
         }
      }

      for (int i = 1; i <= n; i++) {
         try {
            classes[i].dfs();
         } catch (CircleFound e) {
            out.print("Yes");
            return;
         }
         for (int j = 1; j < classes.length; j++) {
            classes[j].wasUsed = false;
         }

      }
      out.print("No");

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