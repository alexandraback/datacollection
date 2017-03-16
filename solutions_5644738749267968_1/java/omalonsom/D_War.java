package gcj2014;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

public class D_War {

  public static void main(String[] args) throws Exception {

     Scanner in = new Scanner(new File("/Users/omalonsom/Tmp/D-large.in"));
    //Scanner in = new Scanner(new File("/Users/omalonsom/Tmp/D-test.txt"));
     System.setOut(new PrintStream("/Users/omalonsom/Tmp/D-large.out"));

    int T = in.nextInt();
    for (int t = 1; t <= T; ++t) {

      int N = in.nextInt();
      SortedSet<Double> blocksN = readBlocks(in, N);
      SortedSet<Double> blocksK = readBlocks(in, N);

      int d = solveDeceitfulWar(new TreeSet(blocksN), new TreeSet(blocksK));
      int w = solveWar(new TreeSet(blocksN), new TreeSet(blocksK));
      System.out.printf("Case #%s: %s %s\n", t, d, w);

    }
  }

  static SortedSet<Double> readBlocks(Scanner in, int N) {
    SortedSet<Double> blocks = new TreeSet<>();
    while (N-- > 0)
      blocks.add(in.nextDouble());
    return blocks;
  }

  static int solveWar(SortedSet<Double> N, SortedSet<Double> K) {

    int res = 0;
    while (!N.isEmpty()) {
      Double n = N.last();
      SortedSet<Double> options = K.tailSet(n);
      Double k = options.isEmpty() ?  K.first(): options.first();

      if(n>k) res++;
      
      N.remove(n);
      K.remove(k);
    }

    return res;
  }

  static int solveDeceitfulWar(SortedSet<Double> N, SortedSet<Double> K) {
    
    int res = 0;
    while (!N.isEmpty()) {
      if(N.last() < K.last()) {
        N.remove(N.first());
        K.remove(K.last());
      } else {
        N.remove(N.last());
        K.remove(K.last());
        res ++;
      }
    }
    return res;
  }

}
