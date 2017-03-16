package r2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Set;

/**
 * User: temas
 * Date: 12.05.13
 */
public class T1 {

    private final static Set<Character> SET = new HashSet<Character>();
    static {
        SET.add('a');
        SET.add('e');
        SET.add('i');
        SET.add('o');
        SET.add('u');
    }

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new FileReader(args[0]));
        BufferedWriter fw = new BufferedWriter(new FileWriter(args[1]));


        String line = br.readLine();
        int numCases = Integer.valueOf(line);
        for (int i=1; i<=numCases; i++) {
            line = br.readLine();
            String[] nums = line.split(" ");
            String name = nums[0];
            int n = Integer.valueOf(nums[1]);

            int counter = 0;
            for (int j=n; j<=name.length(); j++) {
                for (int ix = 0; ix < name.length() - j + 1; ix++) {
                    String sub = name.substring(ix, ix + j);
                    if (checkSub(sub, n)) {
                        counter++;
                    }
                }
            }
            fw.write(String.format("Case #%d: %d\n", i, counter));
        }
        fw.flush();
        fw.close();
        br.close();
    }

    private static boolean checkSub(String sub, int n) {
        int counter = 0;
        for (int i=0; i < sub.length(); i++) {
            if (!SET.contains(sub.charAt(i))) {
                counter++;
                if (counter == n) {
                    return true;
                }
            } else {
                counter=0;
            }
        }
        return false;
    }
}
