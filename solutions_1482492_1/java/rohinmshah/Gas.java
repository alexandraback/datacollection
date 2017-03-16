import java.io.*;
import java.util.*;

public class Gas {

    public static void main (String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new FileReader (args[0]));
        FileWriter output = new FileWriter("gasOutput.txt");
        int numTests = Integer.parseInt(input.readLine());

        for (int test = 1; test <= numTests; test++) {
            output.write("Case #" + test + ":\n");
            output.flush();
            String[] params = input.readLine().split(" ");
            double d = Double.parseDouble(params[0]);
            int n = Integer.parseInt(params[1]);
            // Ignore A, taken care of by the for loop

            double[] times = new double[n+1];
            double[] distances = new double[n+1];
            times[0] = 0;
            distances[0] = 0;

            int i;
            for (i = 1; i <= n; i++) {
                String[] timeAndDist = input.readLine().split(" ");
                times[i] = Double.parseDouble(timeAndDist[0]);
                distances[i] = Double.parseDouble(timeAndDist[1]);
                if (distances[i] >= d) {
                    times[i] = times[i-1] + (d - distances[i-1]) * (times[i] - times[i-1]) / (distances[i] - distances[i-1]);
                    distances[i] = d;
                    int temp = i;
                    for (i++; i <= n; i++) {
                        input.readLine();
                    }
                    n = temp;
                }
            }

            String[] accelerations = input.readLine().split(" ");
            for (String a_i : accelerations) {
                double a = Double.parseDouble(a_i);
                double currDistance = 0, currSpeed = 0;
                for (int j = 1; j <= n; j++) {
                    double timeInterval = times[j] - times[j-1];
                    double distanceInterval = distances[j] - distances[j-1];
                    double newDistance = currDistance + (currSpeed * timeInterval) + (0.5 * a * timeInterval * timeInterval);
                    if (newDistance <= distances[j]) {
                        currDistance = newDistance;
                        currSpeed += a * timeInterval;
                    } else {
                        currSpeed = distanceInterval/timeInterval;
                        currDistance = distances[j];
                    }
                }
                double remaining = d - currDistance, extraTime = 0;
                if (remaining > 0) {
                    extraTime = ((- currSpeed) + Math.sqrt(currSpeed * currSpeed + 2*a*remaining))/a;
                }
                output.write((times[n] + extraTime) + "\n");
            }
        }
        output.flush();
    }

}
