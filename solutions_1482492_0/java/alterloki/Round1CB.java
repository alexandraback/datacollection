package jam.jam2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.*;

/**
 *
 * Created by IntelliJ IDEA.
 * User: ashevenkov
 * Date: 29.04.12
 * Time: 22:15
 */
public class Round1CB {

    private DecimalFormat decimalFormat = new DecimalFormat("#.########");

    public static void main(String[] args) throws Exception {
        new Round1CB().run();
    }

    private void run() throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("input/B-small-attempt1.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("output/B-small-attempt1.out"));
        String line = br.readLine();
        int cases = Integer.parseInt(line);
        for (int i = 0; i < cases; i++) {
            line = br.readLine();
            String[] parts = line.split(" ");
            double d = Double.parseDouble(parts[0]);
            int n = Integer.parseInt(parts[1]);
            int a = Integer.parseInt(parts[2]);
            double[] t = new double[n];
            double[] x = new double[n];
            for (int j = 0; j < n; j++) {
                line = br.readLine();
                String[] parts1 = line.split(" ");
                t[j] = Double.parseDouble(parts1[0]);
                x[j] = Double.parseDouble(parts1[1]);
            }
            double[] as = new double[a];
            line = br.readLine();
            parts = line.split(" ");
            for (int j = 0; j < a; j++) {
                as[j] = Double.parseDouble(parts[j]);

            }
            String[] result = calculate(d, t, x, as);
            System.out.println("Case #" + (i + 1) + ": ");
            for (String s : result) {
                System.out.println(s);
            }
            bw.write("Case #" + (i + 1) + ": " + "\n");
            for (String s : result) {
                bw.write(s + "\n");
            }
        }
        bw.flush();
        bw.close();
    }

    private String[] calculate(double d, double[] t, double[] x, double[] as) {
        List<CarPoints> cps = new ArrayList<CarPoints>();
        cps.add(new CarPoints(t[0], 0, x[0]));
        for (int i = 1; i < t.length; i++) {
            double time0 = t[i - 1];
            double time1 = t[i];
            double x0 = x[i - 1];
            double x1 = x[i];
            double speed = (x1 - x0) / (time1 - time0);
            if(x1 <= d) {
                cps.add(new CarPoints(time1, speed, x1));
            } else {
                double timed = (x1 - d) / speed;
                cps.add(new CarPoints(time0 + timed, speed, d));
                break;
            }
        }
        String[] result = new String[as.length];
        for (int i = 0; i < result.length; i++) {
            result[i] = count(d, cps, as[i]);
        }
        return result;
    }

    private String count(double d, List<CarPoints> cps, double a) {
        double time = 0;
        double carx = 0;
        double speed0 = 0;
        for (CarPoints cp : cps) {
            double delta = cp.meters - carx;
            double deltaTime = cp.time - time;
            double maxDist = speed0 * deltaTime + 0.5 * a * deltaTime * deltaTime;
            if(maxDist > delta) {
                time += deltaTime;
                double anew;
                if(deltaTime > 0) {
                    anew = 2 * (delta - speed0 * deltaTime) / (deltaTime * deltaTime);
                } else {
                    anew = 0;
                }
                double speed01 = speed0 + anew * deltaTime;
                double speed02 = a * (Math.sqrt(2 * delta / a));
                speed0 = Math.max(speed01, speed02);
                carx = cp.meters;
            } else {
                time += deltaTime;
                speed0 = speed0 + a * deltaTime;
                carx += maxDist;
            }
        }
        if(carx >= d) {
            return decimalFormat.format(time);
        } else {
            double au = a / 2;
            double b = speed0;
            double c = -(d - carx);
            double t1  = (-b + Math.sqrt(b*b - 4 * au * c))/(2*au);
            double t2  = (-b - Math.sqrt(b*b - 4 * au * c))/(2*au);
            double t;
            if(t1 < 0) {
                t = t2;
            } else if(t2 < 0) {
                t = t1;
            } else {
                t = Math.min(t1, t2);
            }
            return decimalFormat.format(t + time);
        }
    }

    private class CarPoints {
        double time;
        double speed;
        double meters;

        private CarPoints(double time, double speed, double meters) {
            this.time = time;
            this.speed = speed;
            this.meters = meters;
        }
    }

}
