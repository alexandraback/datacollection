import java.util.*;
import java.math.*;

public class C {
  public static void main(String[] args) {
    long time = System.currentTimeMillis();
    Scanner in = new Scanner(System.in);
    int cases = in.nextInt(); // always 1
    for(int z=1;z<=cases;++z) {
      System.out.printf("Case #%d:\n", 1);
      int trials = in.nextInt();
      int numbers = in.nextInt();
      int max = in.nextInt();
      // min = 2
      int subsets = in.nextInt();
      for(int t=0;t<trials;++t) {
        int[] subsetData = new int[subsets];
        for(int i=0;i<subsets;++i) {
          subsetData[i] = in.nextInt();
        }
        double bestProb = 0.0;
        int[] bestGuess = new int[3];
        for(int i=2;i<=5;++i) {
          for(int j=2;j<=5;++j) {
            for(int k=2;k<=5;++k) {
              double thisProb = 1.0;
              // these are all the possible cards
              for(int s=0;s<subsets;++s) {
                // compute probability of this subset occuring with these numbers
                thisProb *= subsetProb(subsetData[s], i, j, k);
              }
              if (thisProb > bestProb) {
                bestProb = thisProb;
                bestGuess[0] = i;
                bestGuess[1] = j;
                bestGuess[2] = k;
              }
            }
          }
        }
        System.out.printf("%d%d%d\n", bestGuess[0], bestGuess[1], bestGuess[2]);
      }
    }
  }
  
  public static double subsetProb(int value, int a, int b, int c) {
    int ways = 0;
    int total = 8;
    if (value == 1) ++ways;
    if (a == value) ++ways;
    if (b == value) ++ways;
    if (c == value) ++ways;
    if (a*b == value) ++ways;
    if (a*c == value) ++ways;
    if (b*c == value) ++ways;
    if (a*b*c == value) ++ways;
    return 1.0*ways/total;
  }
  
  public static int lcm(int a, int b) {
    return a*b/gcd(a,b);
  }
  
  public static int gcd(int a, int b) {
    return (b==0?a:gcd(b,a%b));
  }
}