package gcj2014;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class B_Cookies {

  public static void main(String[] args) throws Exception {

    Scanner in = new Scanner(new File("/Users/omalonsom/Tmp/B-large.in"));
    //Scanner in = new Scanner(new File("/Users/omalonsom/Tmp/B-test.txt"));
    System.setOut(new PrintStream("/Users/omalonsom/Tmp/B-large.out"));

    int T = in.nextInt();
    for (int t = 1; t <= T; ++t) {

      System.out.printf("Case #%s: %s\n", t, minTime(in));

    }
  }

  private static double minTime(Scanner in) {
    double C = in.nextDouble();
    double F = in.nextDouble();
    double X = in.nextDouble();

    double time = 0;
    double speed = 2;
    double best = X/2; 
    while(time < best ) {
      
      double rem = X/speed;
      //System.out.println(best);
      best = Math.min(best,time + rem); 
      
      double deltaT = C/speed;
      if(deltaT < 1e-7) break;
      time += deltaT;
      speed +=F;
      
    }
    return best;
  }
}
