import java.util.*;

public class B {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    StringBuilder output = new StringBuilder();
    int t = in.nextInt();
    int maxFarm = 0;
    int testNum = -1;
    for (int test = 1; test <= t; ++test) {
      double c = in.nextDouble();
      double f = in.nextDouble();
      double x = in.nextDouble();
      
      int farmCount = 0;
      double currentRate = 2.0;
      double bestTime = x / currentRate;
      double prevTime = 0f;
      boolean notDone = true;
      while (notDone) {
        notDone = false;
        prevTime += c / currentRate;
        currentRate += f;
        double newTime = prevTime + x / currentRate;
        if (newTime < bestTime) {
          ++farmCount;
          notDone = true;
          bestTime = newTime;
        }
      }
      if (farmCount > maxFarm) {
        maxFarm = farmCount;
        testNum = test;
      }
      output.append(String.format("Case #%d: %.10f\n", test, bestTime));
    }
    System.out.print(output);
    System.err.println(maxFarm);
    System.err.println(testNum);
  }
}