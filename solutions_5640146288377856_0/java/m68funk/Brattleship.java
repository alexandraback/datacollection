package jam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * Created by mafulafunk on 13.03.15.
 */
public class Brattleship {
    private static int cases;

    public static void main(String[] args) throws IOException {
        File in = new File("/Users/mafulafunk/Downloads/A-small-attempt0.in");
//        File in = new File("/Users/mafulafunk/Code/jam/StoreCredit/src/main/resources/Brattleship.in");
        PrintWriter out = new PrintWriter("output.txt");
        BufferedReader br = new BufferedReader(new FileReader(in));
        cases = Integer.valueOf(br.readLine());
        for (int i = 1; i <= cases; i++) {


            long[] line = toLongArray(br.readLine().split(" "));

            long rows = line[0];
            long cols = line[1];
            long sizeOfShip = line[2];

            long perLine = cols / sizeOfShip;

            long sinkTheShip = cols % sizeOfShip == 0 ? sizeOfShip -1 : sizeOfShip;

            out.println("Case #" + i + ": " + (rows * perLine + sinkTheShip));
        }
        out.flush();
        out.close();
    }

    private static long[] toLongArray(String[] strArray) {
        long[] out = new long[strArray.length];
        for (int i = 0; i < strArray.length; i++) {
            out[i] = Integer.parseInt(strArray[i]);
        }
        return out;
    }

}
