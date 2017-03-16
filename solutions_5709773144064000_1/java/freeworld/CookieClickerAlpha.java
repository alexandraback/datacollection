import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

/**
 * Created by freeworld on 4/11/14.
 */
public class CookieClickerAlpha {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("B-large.out"));
        int caseNum = Integer.parseInt(br.readLine());
        for (int i = 0; i < caseNum; i++) {
            double[] datas = new double[3];
            String[] strs = br.readLine().split("\\s+");
            for (int j = 0; j < 3; j++) {
                datas[j] = Double.parseDouble(strs[j]);
            }

            double farmCost = datas[0];
            double extraRate = datas[1];
            double target = datas[2];

            double accum = 0;
            double time = 0;
            double rate = 2.0;

            while (true) {
                if (target/rate > farmCost/rate + target/(rate+extraRate)) {
                    time += farmCost/rate;
                    rate += extraRate;
                }
                else {
                    time += target/rate;
                    break;
                }
            }
            time = round(time, 7);
            i++;
            bw.write("Case #" + i-- + ": " + time);
            bw.newLine();
        }
        br.close();
        bw.close();
    }

    public static double round(double value, int places) {
        if (places < 0) throw new IllegalArgumentException();

        long factor = (long) Math.pow(10, places);
        value = value * factor;
        long tmp = Math.round(value);
        return (double) tmp / factor;
    }
}
