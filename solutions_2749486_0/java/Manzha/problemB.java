
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;

/**
 *
 * @author Manzha
 */
public class problemB {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        BufferedReader leer = new BufferedReader(new InputStreamReader(new FileInputStream("src/B-small-attempt0.in")));
        BufferedWriter salida = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/problemB.out")));
        int t, x, y, cont;
        String sal;
        t = Integer.parseInt(leer.readLine());
        String linea[];
        for (int j = 0; j < t; j++) {
            linea = leer.readLine().trim().split(" ");
            x = Integer.parseInt(linea[0]);
            y = Integer.parseInt(linea[1]);
            int df, dy, ya = 0;
            int c;
            String res = "";
            int vx, vy;
            vx = Math.abs(x);
            vy = Math.abs(y);
            int cox = (int) ((-1 + Math.sqrt(1 + 8 * vy)) / 2);
            df = Math.abs(y) - (cox * (cox + 1) / 2);
            if (y != 0) {
                if (y > 0) {
                    for (int i = 0; i < cox; i++) {
                        res += "N";
                    }
                    for (int i = 0; i < df; i++) {
                        res += "SN";
                    }
                } else {
                    for (int i = 0; i < cox; i++) {
                        res += "S";
                    }
                    for (int i = 0; i < df; i++) {
                        res += "NS";
                    }
                }
            }
            c = cox + 2 * df;
            if (x != 0) {
                if (x > 0) {
                    for (int i = c; i < 501; i = i + 1) {
                        ya++;
                        res += "WE";
                        if (ya == x) {
                            break;
                        }
                    }
                } else {
                    for (int i = c; i < 501; i = i + 1) {
                        ya--;
                        res += "EW";
                        if (ya == x) {
                            break;
                        }
                    }
                }
            }
            salida.write("Case #" + (j + 1) + ": " + res);
            salida.newLine();
        }
        salida.close();
    }

}
