import java.util.Scanner;
import java.util.ArrayDeque;

public class Main {
  public static final Integer maxBitsForItems = 4;
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = Integer.parseInt(sc.next());
    for (int i = 1; i <= t; i++) {
      int J = sc.nextInt();
      int P = sc.nextInt();
      int S = sc.nextInt();
      int K = sc.nextInt();
      ArrayDeque<Integer> outfits = new ArrayDeque<>();
      short[][] PScombo = new short[P][S];
      short[][] JScombo = new short[J][S];
      short[][] JPcombo = new short[J][P];
      for (int j = 0; j < J; j++) {
        for (int p = 0; p < P; p++) {
          for (int s = 0; s < S; s++) {
            if (PScombo[p][s] < K &&
                JScombo[j][s] < K &&
                JPcombo[j][p] < K) {
              PScombo[p][s]++;
              JScombo[j][s]++;
              JPcombo[j][p]++;
              outfits.add((j * 10 + p) * 10 + s);
            }
          }
        }
      }
      System.out.println("Case #" + i + ": " + outfits.size());
      while (!outfits.isEmpty()) {
        int outfit = outfits.poll();
        int s = outfit % 10;
        outfit = outfit / 10;
        int p = outfit % 10;
        outfit = outfit / 10;
        int j = outfit % 10;
        System.out.println((j+1) + " " + (p+1) + " " + (s+1));
      }
    }
  }
}
