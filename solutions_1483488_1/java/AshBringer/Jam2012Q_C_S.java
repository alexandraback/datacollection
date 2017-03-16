
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.TreeSet;

/**
 *
 * @author violetlily
 */
public class Jam2012Q_C_S {

//    private final String ipath = "C-small-attempt0.in";
//    private final String opath = "C-small-attempt0.ou";
    private final String ipath = "C-large.in";
    private final String opath = "C-large.ou";

    public void Handle() throws FileNotFoundException {

        PrintStream out = new PrintStream(   
                new BufferedOutputStream(   
                        new FileOutputStream(opath)));   
        System.setOut(out);

        Scanner sc = new Scanner(new FileInputStream(new File(ipath)));
        int t = sc.nextInt();
        int ii = 1;
        while (t > 0) {

            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = 0;
    
            for (int i = a; i <= b; i++) {
                TreeSet ts = new TreeSet();
                String ta = Integer.toString(i);
                String tb = ta + ta;
                for (int j = 0; j < ta.length(); j++) {
                    int tc = Integer.valueOf(tb.substring(j, j + ta.length()));
                    if (tc > i && tc <= b) {
                        ts.add(tc);
                    }
                }
                c += ts.size();
            }

            System.out.println("Case #" + ii + ": " + c);
            
            ii++;
            t--;
        }
        out.close();
    }

    public static void main(String args[]) throws Exception {
        Jam2012Q_C_S t = new Jam2012Q_C_S();
        t.Handle();
    }
}
