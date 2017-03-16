package gcj.round1A_2013;

import java.io.*;

/**
 * Created with IntelliJ IDEA.
 * User: Administrator
 * Date: 4/26/13
 * Time: 6:05 PM
 * To change this template use File | Settings | File Templates.
 */
public class Prob1 {



  public static void main(String[] args) {

    try {

      BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(".\\data\\gcj\\round1A_2013\\A.in")));
      PrintWriter writer = new PrintWriter(new OutputStreamWriter(new FileOutputStream(".\\data\\gcj\\round1A_2013\\A.out")));

      int T = Integer.parseInt(reader.readLine());
      for (int iT = 0; iT < T; iT++) {
        String[] parts = reader.readLine().split(" ");
        double r = Double.parseDouble(parts[0]);
        double t = Double.parseDouble(parts[1]);

        double v = t;
        double ans = Math.floor( ( -(2*r + 3) + Math.sqrt((2*r+3)*(2*r+3) - 4*2*(2*r+1-v))) / (2*2) ) + 1;

        double i = Math.max(1, ans - 2);
        while (i < ans + 2) {
          if ( i*(2*r+1) + 2*(i-1)*i > t ) {
            break;
          }
          i++;
        }

        writer.print("Case #" + (iT+1) + ": ");
        writer.println((long)i-1);
      }

      writer.close();

    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}
