package gcj.round1A_2013;

import java.io.*;

/**
 * Created with IntelliJ IDEA.
 * User: Administrator
 * Date: 4/26/13
 * Time: 7:00 PM
 * To change this template use File | Settings | File Templates.
 */
public class Prob2 {


  public static void main(String[] args) {

    try {

      BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(".\\data\\gcj\\round1A_2013\\B.in")));
      PrintWriter writer = new PrintWriter(new OutputStreamWriter(new FileOutputStream(".\\data\\gcj\\round1A_2013\\B.out")));

      int T = Integer.parseInt(reader.readLine());
      for (int iT = 0; iT < T; iT++) {
        String[] parts = reader.readLine().split(" ");
        int E = Integer.parseInt(parts[0]);
        int R = Integer.parseInt(parts[1]);
        int N = Integer.parseInt(parts[2]);

        parts = reader.readLine().split(" ");
        long[] vals = new long[N];
        for (int iA = 0; iA < N; iA++) {
          vals[iA] = Long.parseLong(parts[iA]);
        }

        long sumVals = 0;
        long remainingEnergy = E;
        for (int iA = 0; iA < N; iA++) {
          int nextIA = 0;
          for (nextIA = iA + 1; nextIA < N; nextIA++) {
            if (vals[nextIA] > vals[iA])
              break;
          }
          long energyToSave = 0;
          if (nextIA < N && R*(nextIA-iA) < E ) {
            energyToSave = Math.min(remainingEnergy, E - R*(nextIA-iA));
          }
          sumVals += (remainingEnergy - energyToSave)*vals[iA];
          remainingEnergy = energyToSave + R;
        }


        writer.print("Case #" + (iT+1) + ": ");
        writer.println(sumVals);
      }

      writer.close();

    } catch (Exception e) {
      e.printStackTrace();
    }
  }

}
