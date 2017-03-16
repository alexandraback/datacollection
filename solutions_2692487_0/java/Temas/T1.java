package rond1;

import sun.applet.Main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;

/**
 * User: temas
 * Date: 04.05.13
 */
public class T1 {
    private static String outFile = null;
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new FileReader(args[0]));
        BufferedWriter fw = new BufferedWriter(new FileWriter(args[1]));
        outFile = args[1];

        String line = br.readLine();
        int numCases = Integer.valueOf(line);
        for (int i=1; i<=numCases; i++) {
            line = br.readLine();
            String[] nums = line.split(" ");
            int A = Integer.valueOf(nums[0]);
            int N = Integer.valueOf(nums[1]);
            List<Integer> motes = new ArrayList<Integer>(N);

            line = br.readLine();
            nums = line.split(" ");
            for (String num : nums) {
                motes.add(Integer.valueOf(num));
            }

            Collections.sort(motes);

            int currentMote = A;
            int minOperations = Integer.MAX_VALUE;
            int deletion = 0;
            int operations = 0;
            int prevDelitions = 0;

            do
            {
                operations = 0;
                deletion = 0;
                for (int m : motes) {
                    if (currentMote > m) {
                        currentMote += m;
                    }
                    else if (currentMote * 2 - 1 > m) { //add
                        currentMote = (currentMote * 2) - 1;
                        currentMote += m;
                        operations++;
                    }
                    else
                    {
                        while ((currentMote * 2 - 1 <= m) && prevDelitions > 0) {
                            prevDelitions--;
                            currentMote = (currentMote * 2) - 1;
                            operations++;
                        }
                        if (currentMote * 2 - 1 <= m) {
                            deletion++;
                            operations++;
                        }
                        else {
                            currentMote = (currentMote * 2) - 1;
                            currentMote += m;
                            operations++;
                        }

                    }
                }

                if (operations < minOperations) {
                    minOperations = operations;
                } else break;

                prevDelitions = deletion;
                currentMote = A;

            } while (deletion > 0);


            fw.write(String.format("Case #%d: %d\n", i, minOperations));
        }
        fw.flush();
        fw.close();
        br.close();
    }


}
