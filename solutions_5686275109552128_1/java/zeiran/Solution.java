import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Chathura
 */
public class Solution {

    public static void main(String[] args) throws FileNotFoundException, IOException {

        Scanner scnr = new Scanner(new File("in.in"));
        int T = scnr.nextInt();
        ArrayList<Integer> answeres = new ArrayList<>();
        for (int m = 0; m < T; m++) {
            int n = scnr.nextInt();
            ArrayList<Integer> elements = new ArrayList<>();
            int max = 0;
            for (int i = 0; i < n; i++) {
                int read = scnr.nextInt();
                elements.add(read);
                if (max < read) {
                    max = read;
                }
            }
            int minMinutes = max;
            int sum;
            for (int i = 1; i <= max; i++) {
                sum = i;
                for (int j = 0; j < n; j++) {
                    if (elements.get(j) > i) {
                        if (elements.get(j) % i == 0) {
                            sum += (elements.get(j) / i - 1);
                        } else {
                            sum += (elements.get(j) / i);
                        }
                    }
                }
                if (minMinutes > sum) {
                    minMinutes = sum;
                }
            }
            answeres.add(minMinutes);
        }

        String out = "";
        for (int i = 0; i < T; i++) {
            out += "Case #" + (i + 1) + ": ";
            out += answeres.get(i);
            if (i != T - 1) {
                out += "\r\n";
            }
        }
        System.out.println(out);
        File outF = new File("out.out");
        FileWriter fw = new FileWriter(outF);
        fw.write(out);
        fw.flush();//*/

    }

}
