
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class problema1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here
        Scanner leer = new Scanner(new File("B-small-attempt2.in"));
        //Scanner leer = new Scanner(System.in);
        FileWriter fw = new FileWriter("SalidaSC.txt");
        BufferedWriter bw = new BufferedWriter(fw);
        int t, x, y, cont;
        String sal;
        t = leer.nextInt();
        for (int i = 0; i < t; i++) {
            x = leer.nextInt();
            y = leer.nextInt();
            bw.write("Case #" + (i + 1) + ": " + Todo(x, y));
            bw.newLine();
        }
        bw.close();
    }

    public static String Todo(int x, int y) {
        int df, dy, ya = 0;
        int c;
        String ret = "";
        int vax, vay;
        vax = Math.abs(x);
        vay = Math.abs(y);
        int cx = (int) ((-1 + Math.sqrt(1 + 8 * vay)) / 2);
        df = Math.abs(y) - (cx * (cx + 1) / 2);
        if (y != 0) {
            if (y > 0) {
                for (int i = 0; i < cx; i++) {
                    ret += "N";
                }
                for (int i = 0; i < df; i++) {
                    ret += "SN";
                }
            } else {
                for (int i = 0; i < cx; i++) {
                    ret += "S";
                }
                for (int i = 0; i < df; i++) {
                    ret += "NS";
                }
            }
        }
        c = cx + 2 * df;
        if (x != 0) {
            if (x > 0) {
                for (int i = c; i < 501; i = i + 1) {
                    ya++;
                    ret += "WE";
                    if (ya == x) {
                        break;
                    }
                }
            } else {
                for (int i = c; i < 501; i = i + 1) {
                    ya--;
                    ret += "EW";
                    if (ya == x) {
                        break;
                    }
                }
            }
        }
        return ret;
    }
}
