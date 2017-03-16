import java.util.*;

public class D {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for (int k = 1; k <= T; k++) {
      int N = in.nextInt();
      List<Double> nBlocks = new ArrayList<Double>(N);
      List<Double> kBlocks = new ArrayList<Double>(N);
      for (int i = 0; i < N; i++) {
        nBlocks.add(in.nextDouble());
      }
      for (int i = 0; i < N; i++) {
        kBlocks.add(in.nextDouble());
      }
      Collections.sort(nBlocks);
      Collections.sort(kBlocks);
      List<Double> nBlocks2 = new ArrayList<Double>(nBlocks);
      List<Double> kBlocks2 = new ArrayList<Double>(kBlocks);
      int dScore = 0, score = 0;
      for (int i = 0; i < N; i++) {
        if (nBlocks.get(0) < kBlocks.get(0)) {
          nBlocks.remove(0);
          kBlocks.remove(kBlocks.size() - 1);
        } else {
          dScore++;
          nBlocks.remove(0);
          kBlocks.remove(0);
        }
      }
      for (int i = 0; i < N; i++) {
        double first = nBlocks2.remove(0);
        boolean kWin = false;
        for (int j = 0; j < kBlocks2.size(); j++) {
          if (kBlocks2.get(j) > first) {
            kBlocks2.remove(j);
            kWin = true;
            break;
          }
        }
        if (!kWin) {
          score += kBlocks2.size();
          break;
        }
      }
      System.out.printf("Case #%d: %d %d\n", k, dScore, score);
    }
    in.close();
  }
}
