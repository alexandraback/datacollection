package r2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;

/**
 * User: temas
 * Date: 12.05.13
 */
public class T2 {
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new FileReader(args[0]));
        BufferedWriter fw = new BufferedWriter(new FileWriter(args[1]));


        String line = br.readLine();
        int numCases = Integer.valueOf(line);
        for (int i=1; i<=numCases; i++) {
            line = br.readLine();
            String[] nums = line.split(" ");
            int x = Integer.valueOf(nums[0]);
            int y = Integer.valueOf(nums[1]);

            boolean found = false;
            for (int sc = 1; sc <= 500; sc++) {
                int xx = x;
                int yy = y;
                ArrayList<Character> path = new ArrayList<Character>();
                for (int j = sc; j > 0; j--) {
                    if (Math.abs(xx) > Math.abs(yy)) {
                        if (xx > 0) {
                            xx -= j;
                            path.add('E');
                        } else {
                            xx += j;
                            path.add('W');
                        }
                    } else {
                        if (yy > 0) {
                            yy -= j;
                            path.add('N');
                        } else {
                            yy += j;
                            path.add('S');
                        }
                    }
                }
                if (xx == 0 && yy == 0) {
                    StringBuilder sb = new StringBuilder();
                    for (int k = path.size() - 1; k >=0; k--) {
                        sb.append(path.get(k));
                    }
                    fw.write(String.format("Case #%d: %s\n", i, sb.toString()));
                    found = true;
                    break;
                }
            }
            if (!found) {
                throw new IllegalStateException();
            }
        }
        fw.flush();
        fw.close();
        br.close();
    }
}
