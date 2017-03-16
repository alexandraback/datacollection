package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

public class CodeJam2012R1CpA {

  static final String fileIn = "/Users/jhorwitz/Documents/workspace/project/src/codejam/data/2012/R1C/A-small-attempt1.in";
  static final String fileOut = "/Users/jhorwitz/Documents/workspace/project/src/codejam/data/2012/R1C/2012-1C-A-out.txt";

  public static void main(String[] args) throws Exception {
    BufferedReader r = new BufferedReader(new FileReader(fileIn));
    BufferedWriter w = new BufferedWriter(new FileWriter(fileOut));
    String line = r.readLine();
    int T = Integer.parseInt(line);
    for (int caseNum = 1; caseNum <= T; caseNum++) {
      String str = "Case #" + caseNum + ": " + solve(r);
      w.write(str + "\n");
      System.out.println(str);
    }
    w.close();
    r.close();
  }

  private static String solve(BufferedReader r) throws IOException {
    String line = r.readLine();
    int N = Integer.valueOf(line);
    int[] M = new int[N+1];
    boolean[][] A = new boolean[N+1][N+1];
    for (int i=1; i<=N; ++i) {
      line = r.readLine();
      String[] MAndAs = line.split(" ");
      M[i] = Integer.valueOf(MAndAs[0]);
      for (int j=1; j<=M[i]; ++j) {
        A[i][Integer.valueOf(MAndAs[j])] = true;
      }
    }

    for (int i=1; i<=N; ++i) {
      Set<Integer> seenSet = new HashSet<Integer>(N); // all nodes visited (these will all at least at one time be in BFSFrontier)
      Queue<Integer> BFSFrontier = new LinkedList<Integer>(); // frontier of nodes not yet visited
      seenSet.add(i);
      BFSFrontier.add(i);
      while(!BFSFrontier.isEmpty()) {
        int cur = BFSFrontier.remove();
        for (int j=1; j<=N; ++j) {
          if (A[cur][j]) {
            if (seenSet.contains(j)) {
              return "Yes";
            } else {
              seenSet.add(j);
              BFSFrontier.add(j);
            }
          }
        }
      }
    }

    return "No";
  }
}