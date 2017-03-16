import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/*
ID: arshdee1
LANG: JAVA
PROB: ManageEnergy 
*/

public class ManageEnergy {
    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new FileReader("ManageEnergy.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ManageEnergy.out")));
        int T = Integer.parseInt(f.readLine());
        for (int t = 1; t <= T; t++) {
            //Handling Input.
            StringTokenizer st = new StringTokenizer(f.readLine());
            final int max = Integer.parseInt(st.nextToken());
            final int regain = Integer.parseInt(st.nextToken());
            final int activities = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(f.readLine());
            int[] value = new int[activities];
            for (int i = 0; i < activities; i++) {
                value[i] = Integer.parseInt(st.nextToken());
            }

            //Solve ?
            long maxGain = 0;
            int curr = max;

            System.out.println("---- " + t + " Max: " + max + " Regain: " + regain);
            for (int i = 0; i < value.length; i++) {
                boolean higher = false;
                int indexOfHigher = -1;
                for (int j = i + 1; j < value.length; j++) {
                    if (value[j] > value[i]) {
                        higher = true;
                        indexOfHigher = j;
                        break;
                    }
                }
                System.out.println("Found Next Highest At: " + indexOfHigher);
                if (!higher) {
                    System.out.println("Depleting all " + curr + " Joules");
                    maxGain += curr * value[i];
                    curr = 0;
                } else {
                    int dist = indexOfHigher - i;
                    if (dist * regain >= max) {
                        System.out.println("Depleting all " + curr + " Joules");
                        maxGain += curr * value[i];
                        curr = 0;
                    } else {
                        int totGain = regain * dist;
                        int toSpend;
                        if (max - totGain >= curr)
                            toSpend = 0;
                        else
                            toSpend = curr - (max - totGain);
                        System.out.println("Depleting " + toSpend + " out of " + curr + " Joules");
                        curr -= toSpend;
                        maxGain += toSpend * value[i];
                    }
                }
                curr += regain;
                //Search for next highest ..
                //if this is the highest or the highest is out of range
                    //just use up the tank
                //otherwise
                    //find the distance to the highest
                    //if the distance is regained
                        //spend your tank
                    //otherwise
                        //spend your current amount - (regain * distance)

            }


            //Output data

            out.println("Case #" + t + ": " + maxGain);
        }
        out.close();
        System.exit(0);
    }
}
