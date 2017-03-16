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
        scnr.nextLine();
        ArrayList<Integer> answeres = new ArrayList<>();
        for (int i = 0; i < T; i++) {
            String line = scnr.nextLine();
            int sMax = Integer.valueOf(line.charAt(0) + "");
            int stands = 0;
            int intros = 0;
            for (int shyLevel = 0; shyLevel <= sMax; shyLevel++) {
                int people = Integer.parseInt(line.charAt(2 + shyLevel) + "");
                //System.out.println(people);
                if (stands < shyLevel) {
                    int addition = (shyLevel - stands);
                    stands += (shyLevel - stands);
                    intros += addition;
                }
                stands += people;
            }
            answeres.add(intros);
        }

        String out = "";
        for (int i = 0; i < T; i++) {
            out += "Case #" + (i + 1) + ": ";
            out += answeres.get(i);
            out += "\r\n";
        }
        System.out.println(out);
        File outF = new File("out.out");
        FileWriter fw = new FileWriter(outF);
        fw.write(out);
        fw.flush();//*/

    }

}
