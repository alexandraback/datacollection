import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by poly on 5/3/15.
 */
public class HikingDeerSmall {
    public static void main(String argv[]) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            int n = scanner.nextInt();
            List<Integer> ds = new ArrayList<Integer>();
            List<Long> ms = new ArrayList<Long>();
            List<Double> speeds = new ArrayList<Double>();
            for (int i = 0; i < n; i++) {
                int d = scanner.nextInt();
                int h = scanner.nextInt();
                long m = scanner.nextInt();
                for (int j = 0; j < h; j++) {
                    ds.add(d);
                    ms.add(m + j);
                    speeds.add(360.0 / m);
                }
            }
            int total = ds.size();
            long res = Long.MAX_VALUE;
            double[] speedRatio = new double[]{0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0};
            for (int i = 0; i < total; i++) {
                double speed = speeds.get(i);
                for (double sr : speedRatio) {
                    double speed2 = speed * sr;
                    double time = 360.0 / speed2;
                    long tmp = 0;
//                System.out.println("========speed: " + speed);
                    for (int j = 0; j < total; j++) {
                        double diff = speed - speeds.get(j);
//                    System.out.println("diff=" + diff);
                        if (diff <= 0) {
//                        System.out.print(time * Math.abs(diff));
//                        System.out.print("<=>");
//                        System.out.println((360 - ds.get(j)));
                            if (time * Math.abs(diff) < (360 - ds.get(j))) {
//                            System.out.println("*skip1");
                            } else {
                                ++tmp;
                                double first = (360 - ds.get(j)) / Math.abs(diff);
                                int additional = (int) ((time - first) / (360 / Math.abs(diff)));
                                tmp += additional;
                            }
                        } else {
                            if (time * diff < ds.get(j)) {
//                            System.out.println("*skip1");
                            } else {
                                ++tmp;
                                double first = ds.get(j) / diff;
                                int additional = (int) ((time - first) / (360 / diff));
                                tmp += additional;
                            }
                        }
                    }
                    res = Math.min(tmp, res);
                }
            }
            System.out.println("Case #" + (t + 1) + ": " + res);
        }
    }
}
