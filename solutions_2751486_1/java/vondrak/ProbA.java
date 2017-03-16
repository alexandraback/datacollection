package gcj;

import java.io.*;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * Created with IntelliJ IDEA.
 * User: vondrak
 * Date: 5/12/13
 * Time: 2:09 AM
 * To change this template use File | Settings | File Templates.
 */
public class ProbA {

  public static void main(String[] args) {

    try {

      BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(".\\data\\A-large.in")));
      PrintWriter writer = new PrintWriter(new OutputStreamWriter(new FileOutputStream(".\\data\\A.out")));
      Set<Character> specialChars = new HashSet<Character>();
      specialChars.add('a');
      specialChars.add('e');
      specialChars.add('i');
      specialChars.add('o');
      specialChars.add('u');

      int T = Integer.parseInt(reader.readLine());
      for (int iT = 0; iT < T; iT++) {

        String[] parts = reader.readLine().split(" ");
        String S = parts[0];
        int n = Integer.parseInt(parts[1]);

        int[] startPoints = new int[S.length()];
        Arrays.fill(startPoints, -1);

        int sum = 0;
        int nConsecutive = 0;
        for (int i = 0; i < startPoints.length; i++) {
          if (!specialChars.contains(S.charAt(i)))
            nConsecutive++;
          else
            nConsecutive = 0;

          if (nConsecutive >= n) {
            startPoints[i] = i - n + 1;
          } else {
            if (i > 0)
              startPoints[i] = startPoints[i-1];
          }

          if (startPoints[i] != -1)
            sum += startPoints[i]+1;
        }

        //System.out.println(ans);
        writer.print("Case #" + (iT + 1) + ": ");
        writer.println(sum);
      }

      reader.close();
      writer.close();

    } catch (Exception e) {
      e.printStackTrace();
    }

  }

  public static Integer[] parseInt(String line) {
    String[] parts = line.split(" ");
    Integer[] intParts = new Integer[parts.length];
    for (int i = 0; i < parts.length; i++) {
      intParts[i] = Integer.parseInt(parts[i]);
    }
    return intParts;
  }


}
