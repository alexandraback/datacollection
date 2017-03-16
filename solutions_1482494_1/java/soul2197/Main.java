package round1.p2;

import java.io.File;
import java.util.Scanner;

public class Main
{

  public static void main(final String[] args) throws Exception
  {
    Scanner s = new Scanner(new File("D:\\unsorted\\in"));
    int T = s.nextInt();

    for (int n = 0; n < T; n++)
    {
      int N = s.nextInt();
      int[][] cost = new int[N][2];

      for (int i = 0; i < N; i++)
      {
        cost[i][0] = s.nextInt();
        cost[i][1] = s.nextInt();
      }

      int[] earned = new int[N];

      int stars = 0;
      int attempts = 0;

      while (stars < N * 2) {
        int next = -1;
        int canEarn = 0;
        for (int i = 0; i < N; i++) {
          if (earned[i] < 2 && cost[i][earned[i]] <= stars) {
            int score = (cost[i][1] <= stars && earned[i] == 0) ? 2 : 1;
            if (next == -1 || score > canEarn || (score == canEarn && (earned[i] == 1 || (earned[next] == 0 && cost[i][1] > cost[next][1])))) {
              canEarn = score;
              next = i;
            }
          }
        }
        if (next == -1)
          break;
        earned[next] += canEarn;
        stars += canEarn;
        attempts++;
      }

      System.out.println("Case #"+(n+1)+": "+ ((stars < N*2) ? "Too Bad" : attempts));
    }
  }
}