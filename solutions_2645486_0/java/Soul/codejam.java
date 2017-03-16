import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;

/**
 * Created with IntelliJ IDEA.
 * User: skhan
 * Date: 2013-04-27
 * Time: 10:40 AM
 * To change this template use File | Settings | File Templates.
 */
public class codejam {
    /*static class EnergyGain {
        long energy;
        long gain;
        EnergyGain(long energy, long gain) {this.energy = energy; this.gain = gain;}
    }*/
    private static long E;
    private static long R;
    private static int N;
    private static ArrayList<Long> v;
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new FileReader(args[0]));

            int cases = Integer.parseInt(br.readLine());
            for (int i = 1; i < cases + 1; ++i) {
                String line = br.readLine();
                String[] split = line.split(" ");
                E = Long.parseLong(split[0]);
                R = Long.parseLong(split[1]);
                N = Integer.parseInt(split[2]);
                line = br.readLine();
                String[] v_string_array = line.split(" ");
                v = new ArrayList<Long>();v.add(0L);
                for (int j = 0; j < N; ++j) v.add(Long.parseLong(v_string_array[j]));
                long y = maxGain(1, E);
                System.out.println("Case #" + i + ": " + y);
            }

            br.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static long maxGain(int iteration, long energy) {
        if (iteration > N) return 0;
        long maxGain = -1;
        for (long i = 0; i <= energy; ++i) {
            long energyLeft = energy - i;
            long nextEnergy = energyLeft + R;
            if (nextEnergy > E) nextEnergy = E;
            long gaining = i * v.get(iteration);
            //System.out.println("Iteration: " + iteration + " Using energy " + i + " we gained " + gaining + " nextEnergy: " + nextEnergy);
            long totalGain = gaining + maxGain(iteration+1, nextEnergy);
            if (totalGain > maxGain) { maxGain = totalGain;}

        }
        return maxGain;
    }
}
