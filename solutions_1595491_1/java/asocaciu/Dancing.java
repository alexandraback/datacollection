package ch.socaciu.andrei.codejam;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * @author Andrei Socaciu
 */
public class Dancing {

    public static void main(String[] args) throws Exception {
        String in = "data/Dancing-large.in.txt";
        String out = "data/Dancing-large.out.txt";
        String line = null;
        BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(in)));
        List<String> lines = new ArrayList<String>();
        while ((line = reader.readLine()) != null) {
            lines.add(line);
        }
        reader.close();
        int tests = Integer.parseInt(lines.get(0));
        List<String> res = new ArrayList<String>();
        int k = 1;
        for (int i = 1; i <= tests; i++) {
            line = lines.get(k++);
            String[] parts = line.split(" ");
            int n = Integer.parseInt(parts[0]);
            int[] scores = new int[n];
            int s = Integer.parseInt(parts[1]);
            int p = Integer.parseInt(parts[2]);
            for (int j = 0; j < n; j++) {
                scores[j] = Integer.parseInt(parts[3+j]);
            }
            int result = solve(scores, s, p);
            res.add("Case #" + i + ": " + result);
        }
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(out)));
        for (String re : res) {
            writer.write(re);
            writer.write("\n");
        }
        writer.close();
    }

    private static int solve(int[] scores, int s, int p) {
        int count = 0;
        int special = s;
        for (int score : scores) {
            if (score / 3 >= p) {
                //avg. larger than p, at least one score will be >= p
                count++;
            } else if (score == 3*p - 1 || score == 3*p - 2) {
                //these are covered by the not-special cases
                count++;
            } else if (special > 0) {
                //try to see if a special case matches
                if (score % 3 == 0) { //s-1,s,s+1
                    if (score / 3 + 1 >= p && score / 3 - 1 >= 0)  {
                        count++;
                        special--;
                    }
                } else if (score % 3 == 1) {//s,s,s-2
                    if ((score + 2) / 3 >= p) {
                        count++;
                        special--;
                    }
                } else {//s,s,s+2
                    if ((score - 2) / 3 + 2 >= p) {
                        count++;
                        special--;
                    }
                }
            }
        }
        return count;
    }

}
