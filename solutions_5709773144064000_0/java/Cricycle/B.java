import java.util.*;

public class B {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    StringBuilder output = new StringBuilder();
    int t = in.nextInt();
    for (int test = 1; test <= t; ++test) {
      double c = in.nextDouble();
      double f = in.nextDouble();
      double x = in.nextDouble();
      
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
          notDone = true;
          bestTime = newTime;
        }
      }
      output.append(String.format("Case #%d: %.10f\n", test, bestTime));
    }
    System.out.print(output);
  }
}