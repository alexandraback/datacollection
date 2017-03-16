import java.io.*;

/**
 * Created by vivek on 12/04/14.
 */
public class CookieClicker {
   public static void main(String[] args) throws IOException {
      BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
      PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

      int tests = Integer.parseInt(reader.readLine().trim());
      for (int test = 1; test <= tests; test++) {
         String[] inputs = reader.readLine().trim().split(" ");
         double c = Double.parseDouble(inputs[0]);
         double f = Double.parseDouble(inputs[1]);
         double x = Double.parseDouble(inputs[2]);

         out.println("Case #" + test + ": " + String.format( "%.7f", getMinTime(c, f, x)));
      }
      out.flush();
      out.close();
   }

   private static double getMinTime(double c, double f, double x) {
      double t = 0;
      int n = 0;

      while ((t + x / (n * f + 2)) > (t + c / (n * f + 2) + x / ((n + 1) * f + 2))) {
         t += c / (n * f + 2);
         n += 1;
      }
      return t + x / (n * f + 2);
   }
}
