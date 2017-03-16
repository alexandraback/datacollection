package round3;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class pb2 {

    /**
     * @param args
     * @throws IOException 
     */
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File(args[0]));
        BufferedWriter out = new BufferedWriter(new FileWriter(
                new File("output")));

        int T = sc.nextInt();

        for (int i = 0; i < T; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            solveTest(out, x, y, i + 1);
        }

        out.close();

    }

    private static void solveTest(BufferedWriter out, int x, int y,
            int usecase) throws IOException {

        StringBuilder sb = new StringBuilder();
        int xstart = 0, ystart = 0;

        if (xstart < x) {
            while (xstart != x) {
                xstart++;
                sb.append("WE");
            }
        } else {
            while (xstart != x) {
                xstart--;
                sb.append("EW");
            }
        }
        
        if(ystart < y) {
            while(ystart != y) {
                ystart++;
                sb.append("SN");
            }
        } else {
            while(ystart != y) {
                ystart--;
                sb.append("NS");
            }
        }
        
        out.write("Case #" + usecase + ": " + sb.toString());
        out.newLine();


    }

}
