import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.LinkedList;
import java.util.Scanner;


public class TreasureSlow {

  public static void main(String[] args) throws Exception {
    new TreasureSlow().run();
  }

  void run() throws Exception {
    //System.setIn(new FileInputStream("D-test.in"));
    System.setIn(new FileInputStream("D-small-attempt0.in"));
    System.setOut(new PrintStream("D-small-attempt0.out"));
    //System.setIn(new FileInputStream("D-large.in"));
    Scanner in = new Scanner(System.in);
    int cases = in.nextInt();
    for (int C = 1; C <=cases; ++C) {
      int K = in.nextInt();
      N = in.nextInt();
      visited = new boolean[1<<N];
      int currkeys[] = new int [200];
      for(int k = 0; k < K; ++k)
        currkeys[in.nextInt()-1]++;
      type = new int[N];
      keys = new int [N][];
      for(int n = 0; n < N; ++n) {
        type[n] = in.nextInt() -1;
        keys[n] = new int[in.nextInt()];
        for(int k =  0 ; k < keys[n].length; ++k)
          keys[n][k] = in.nextInt() -1;
      }
      LinkedList<Integer> order = new LinkedList<Integer>();
      String res = " IMPOSSIBLE";
      if(rec(0,currkeys,order)) {
        res = "";
        for( int c: order)
          res += " " + (c+1);
      }
      System.out.println(String.format("Case #%d:%s", C, res));
    }
  }
  int type[], keys[][], N;
  boolean visited[];


  boolean rec(int opened, int[] currkeys, LinkedList<Integer> res) {
    if(visited[opened]) return false;
    visited[opened] = true;
    if(opened == (1<<N)-1) return true;
    for(int c = 0; c < N; ++c) {
      if((opened & (1<<c))>0) continue;
      if(currkeys[type[c]]==0) continue;
      currkeys[type[c]]--;
      for(int k:keys[c])
        currkeys[k]++;
      res.add(c);
      if(rec(opened | (1<<c), currkeys, res)) return true;
      res.removeLast();
      for(int k:keys[c])
        currkeys[k]--;
      currkeys[type[c]]++;
    }
    return false;
  }
}
