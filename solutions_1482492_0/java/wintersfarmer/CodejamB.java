import java.io.*;
import java.util.*;

class CodejamB {
    public static char[] map;
    public static void main (String [] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("E:/B-small-attempt3.in"));
        // BufferedReader in = new BufferedReader(new FileReader("E:/B-small-attempt0 (1).in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("E:/outB.txt")));
        int nTest = Integer.parseInt(in.readLine());
        for (int testIndex = 0; testIndex < nTest; testIndex++) {
            out.println("Case #" + (testIndex + 1) + ":");
            /***** start **********/
            StringTokenizer st = new StringTokenizer(in.readLine());
            double distance = Double.parseDouble(st.nextToken());
            int nRoad = Integer.parseInt(st.nextToken());
            int nGravity = Integer.parseInt(st.nextToken());
            double[] pos = new double[nRoad];
            double[] time = new double[nRoad];
            for (int i = 0; i < nRoad; i++) {
                st = new StringTokenizer(in.readLine());
                time[i] = Double.parseDouble(st.nextToken());
                pos[i] = Double.parseDouble(st.nextToken());
            }
            double[] gravity = new double[nGravity];
            st = new StringTokenizer(in.readLine());
            for (int i = 0; i < nGravity; i++) {
                gravity[i] = Double.parseDouble(st.nextToken());
                out.println(calc(nRoad, gravity[i], distance, time, pos));
            }
            /***** end   **********/
        }
        out.close();
    }
    private static double calc(int n, double g, double d, double[] time, double[] pos) {
        double currentSpeed = 0;
        double currentTime = 0;
        double currentPos = 0;
        for (int i = 1; i < n; i++) {
            if (pos[i] >= d) {
                n = 0;
                double fraction = (d - pos[i-1]) / (pos[i] - pos[i-1]);
                pos[i] = d;
                time[i] = currentTime + (time[i] - time[i-1]) * fraction;
            }

            double timeInterval = time[i] - currentTime;
            double distanceInterval = pos[i] - currentPos;
            double maxDistance = (currentSpeed + g * timeInterval / 2) * timeInterval + currentPos;
            if (maxDistance <= pos[i]) {
                currentPos = maxDistance;
                currentSpeed = currentSpeed + g * timeInterval;
            } else {
                currentPos = pos[i];
                double threshold = g / 2 * timeInterval * timeInterval;
                if (distanceInterval < threshold) {
                    currentSpeed = Math.sqrt(2 * distanceInterval * g);
                } else {
                    currentSpeed = (distanceInterval - threshold) / timeInterval + g * timeInterval;
                }
            }
            currentTime = time[i];
        }
        if (currentPos < d) {
            currentTime += ((-currentSpeed + Math.sqrt(currentSpeed * currentSpeed + (d - currentPos) * 2 * g)) / g);
        }
        return currentTime;
    }
}