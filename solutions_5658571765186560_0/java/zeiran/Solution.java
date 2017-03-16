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
        ArrayList<String> answeres = new ArrayList<>();
        for (int i = 0; i < T; i++) {
            int X = scnr.nextInt();
            int R = scnr.nextInt();
            int C = scnr.nextInt();

            if (X == 1) {
                answeres.add("GABRIEL");
            } else if (R * C % X != 0) {
                answeres.add("RICHARD");
            } else if (R == C && C == X) {
                answeres.add("GABRIEL");
            } else {
                int mul = R * C;
                if (X == 2) {
                    answeres.add("GABRIEL");

                } else if (X == 3) {
                    switch (mul) {
                        case 3:
                            answeres.add("RICHARD");
                            break;
                        case 6:
                            answeres.add("GABRIEL");
                            break;
                        case 12:
                            answeres.add("GABRIEL");
                            break;
                    }
                } else if (X == 4) {
                    switch (mul) {
                        case 4:
                            answeres.add("RICHARD");
                            break;
                        case 8:
                            answeres.add("RICHARD");
                            break;
                        case 12:
                            answeres.add("GABRIEL");
                            break;
                    }
                }
            }

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
