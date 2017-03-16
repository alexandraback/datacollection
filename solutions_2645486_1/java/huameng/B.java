import java.util.*;
import java.math.*;

public class B {
  public static void main(String[] args) {
    long time = System.currentTimeMillis();
    Scanner in = new Scanner(System.in);
    int cases = in.nextInt();
    for(int z=1;z<=cases;++z) {
      int fullEnergy = in.nextInt();
      int regain = Math.min(fullEnergy,in.nextInt());
      int activities = in.nextInt();
      int[] values = new int[activities];
      for(int i=0;i<activities;++i) values[i] = in.nextInt();
      int curEnergy = fullEnergy;
      long ans = 0;
      for(int i=0;i<activities;++i) {
        int canUse = Math.max(0,curEnergy+regain-fullEnergy);
        if (i == activities-1) canUse = curEnergy;
        for(int j=i+1;j<activities;++j) {
          if (values[j] >= values[i]) break;
          canUse += regain;
          if (canUse >= curEnergy) break;
          if (j == activities-1) canUse = curEnergy;
        }
        canUse = Math.min(canUse, curEnergy);
        // System.err.println(canUse);
        ans += (long)canUse * values[i];
        curEnergy = Math.min(fullEnergy, curEnergy-canUse+regain);
      }
      System.out.printf("Case #%d: %d\n", z, ans);
    }
    System.err.println(System.currentTimeMillis()-time);
  }
}