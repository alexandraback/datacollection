

import java.io.*;
import java.util.*;
import java.math.*;

public class Pogo {

    static Scanner in;
    static BufferedWriter out;


    public static void main(String[] args) throws IOException {
        
        in = new Scanner(new File("Pogo.in"));
        out = new BufferedWriter(new FileWriter("Pogo.out"));

        int length = in.nextInt();

        for (int test = 0; test < length; test++) {
            int x = in.nextInt();
            int y = in.nextInt();
            String result = "";

            out.write("Case #" + (test + 1) + ": ");

            if (x > 0) {
                for (int i = 0; i < x; i++) {
                    out.write("WE");
                }
            } else {
                for (int i = 0; i < -x; i++) {
                    out.write("EW");
                }
            }


            if (y > 0) {
                for (int i = 0; i < y; i++) {
                    out.write("SN");
                }
            } else {
                for (int i = 0; i < -y; i++) {
                    out.write("NS");
                }
            }


            out.write("\n");
        }

        in.close();
        out.close();
    }

}    