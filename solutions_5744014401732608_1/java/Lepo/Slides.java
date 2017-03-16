import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by juanc on 08-May-16.
 */
public class Slides {
    private static Scanner sn;
    private static PrintWriter writer;
    private final static boolean INLINE = true;
    private final static String INPUT = "B-large.in";
    private final static String OUTPUT = "answer";


    public static void main(String[] args) throws IOException {
        sn = Input.getScanner("resources/" + INPUT);
        writer = new PrintWriter("resources/" + OUTPUT);
        int T = Integer.parseInt(sn.nextLine());
        for (int i = 1; i <= T; i++) {
            if (INLINE)
                writer.print("Case #" + i + ": ");
            else
                writer.println("Case #" + i + ":");
            SlidesMain();
        }
        writer.close();

    }

    private static void SlidesMain() {
        int B = sn.nextInt();
        String M = sn.nextLine();
        BigInteger Mnum = new BigInteger(M.trim()).subtract(BigInteger.ONE);
        if (Mnum.bitLength() > (B - 2)) {
            writer.println("IMPOSSIBLE");
            return;
        }
        int length = Mnum.toString(2).length();
        writer.println("POSSIBLE");
        /*writer.println(B + " " + M.trim() + " bitlength: " + length);
        writer.println("num: " + Mnum.toString(2));*/
        int count;
        for (int i = 0; i < B; i++) {
            if (i == 0) {
                writer.print('0');
                count = 1;
                for (int k = 0; k < B - 2 - length ; k++) {
                    writer.print('0');
                    count++;
                }
                if(count<B-1){
                    writer.print(Mnum.toString(2));
                }
                writer.print('1');
                //System.out.println(B + " " + M.trim() + ": " + Mnum.bitLength() + " " + Mnum.toString(2));
            } else {
                for (int j = 0; j < B; j++) {
                    if (j <= i) {
                        writer.print('0');
                    } else {
                        writer.print('1');
                    }
                }
            }
            writer.println();
        }

    }
}
