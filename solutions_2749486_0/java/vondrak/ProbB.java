package gcj;

import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * Created with IntelliJ IDEA.
 * User: vondrak
 * Date: 5/12/13
 * Time: 2:38 AM
 * To change this template use File | Settings | File Templates.
 */
public class ProbB {

  public static void main(String[] args) {

    try {
      // BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(".\\data\\B.in")));
      BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(".\\data\\B-small-attempt1.in")));
      PrintWriter writer = new PrintWriter(new OutputStreamWriter(new FileOutputStream(".\\data\\B.out")));

      Map<Integer, String> xSignToDirectionMap = new HashMap<Integer, String>();
      Map<Integer, String> ySignToDirectionMap = new HashMap<Integer, String>();
      xSignToDirectionMap.put(1, "E");
      xSignToDirectionMap.put(0, "W");
      ySignToDirectionMap.put(1, "N");
      ySignToDirectionMap.put(0, "S");



      int T = Integer.parseInt(reader.readLine());
      for (int iT = 0; iT < T; iT++) {

        Integer[] dataInfo = parseInt(reader.readLine());
        int X = dataInfo[0];
        int Y = dataInfo[1];

        int xDir = 1;
        if (X < 0)
          xDir = 0;
        int yDir = 1;
        if (Y < 0)
          yDir = 0;
        X = StrictMath.abs(X);
        Y = StrictMath.abs(Y);

        String steps = "";
        for (int i = 0; i < X; i++)
          steps += xSignToDirectionMap.get(1-xDir) + xSignToDirectionMap.get(xDir);
        for (int i = 0; i < Y; i++)
          steps += ySignToDirectionMap.get(1-yDir) + ySignToDirectionMap.get(yDir);


        //System.out.println(ans);
        writer.print("Case #" + (iT + 1) + ": ");
        writer.println(steps);
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
