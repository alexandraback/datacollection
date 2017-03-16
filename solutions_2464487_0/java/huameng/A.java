import java.util.*;

public class A {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int cases = in.nextInt();
    for(int z=1;z<=cases;++z) {
      int startRadius = in.nextInt();
      int mls = in.nextInt();
      int ringsDrawn = 0;
      // System.err.println(mls + " " + (2*startRadius+1));
      while(mls >= (2*startRadius+1)) {
        ++ringsDrawn;
        mls -= (2*startRadius+1);
        startRadius += 2;
      }
      System.out.printf("Case #%d: %d\n", z, ringsDrawn);
    }
  } 
}