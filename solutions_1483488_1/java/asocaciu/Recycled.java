package ch.socaciu.andrei.codejam;

import java.io.*;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * @author Andrei Socaciu
 */
public class Recycled {

    public static void main(String[] args) throws Exception {
        String in = "data/Recycled-large.in.txt";
        String out = "data/Recycled-large.out.txt";
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
            int a = Integer.parseInt(parts[0]);
            int b = Integer.parseInt(parts[1]);
            int result = solve(a,b);
            res.add("Case #" + i + ": " + result);
        }
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(out)));
        for (String re : res) {
            writer.write(re);
            writer.write("\n");
        }
        writer.close();
    }

    private static int solve(int a, int b) {
        int count = 0;
        Set<String> unique = new HashSet<String>();
        for (int i = a; i < b; i++) {
            StringBuilder sb = new StringBuilder(Integer.toString(i));
            for (int j = 0; j < sb.length() - 1; j++) {
                char last = sb.charAt(sb.length() - 1);
                sb.deleteCharAt(sb.length() - 1);
                sb.insert(0, last);
                if (sb.charAt(0) != '0') {
                    int permutation = Integer.parseInt(sb.toString());
                    if (permutation >= a && permutation <= b && permutation > i) {
                        String stringForm = i + ", " + sb;
                        if (unique.add(stringForm)) {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }

}
