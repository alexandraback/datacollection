package cj.y2015.qr;

import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.*;

/**
 * Created by admin on 4/6/2015.
 */
public class D {

    private Scanner scanner;
    private Writer writer;

    public static void main(String[] args) throws IOException {
        D a = new D();
        a.meat();
    }

    private void meat() throws IOException {
        scanner = new Scanner(new FileInputStream("src/cj/y2015/qr/D-small-attempt2.in"));
        writer = new FileWriter("src/cj/y2015/qr/D-small-attempt2.out", false);


        int t = scanner.nextInt();
        for (int i=0; i<t; i++) {
            int x = scanner.nextInt();
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            String result = "RICHARD";
            if (((r*c) % x)==0) {
                if (x == 1) {
                    result = "GABRIEL";
                } else if (x == 2) {
                    result = "GABRIEL";
                } else if (x == 3) {
                    if (((r>1) && (c==3)) || ((r==3) && (c>1))) {
                        result = "GABRIEL";
                    } else {
                        result = "RICHARD";
                    }
                } else if (x == 4) {
                    if (((r==4) && (c>=3)) || ((r>=3) && (c==4))) {
                        result = "GABRIEL";
                    } else if ((r==2) && (c==2)) {
                        result = "RICHARD";
                    } else if (((r==4) && (c<=2)) || ((r<=2) && (c==4))) {
                        result = "RICHARD";
                    }
                }
            }
            writer.write("Case #" + (i + 1) + ": " + result + "\n");
            System.out.println("Case #" + (i + 1) + ": " + result);
        }
        scanner.close();
        writer.close();
    }
}
