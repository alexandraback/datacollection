
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

/**
 *
 * @author violetlily
 */
public class Jam2012R2_A_S {

    private final String ipath = "A-small-attempt1.in";
    private final String opath = "A-small-attempt1.ou";

    public void Handle() throws FileNotFoundException {

        PrintStream out = new PrintStream(
                new BufferedOutputStream(
                new FileOutputStream(opath)));
        System.setOut(out);

        Scanner sc = new Scanner(new FileInputStream(new File(ipath)));
        int n = sc.nextInt();
        int ii = 1;
        while (n > 0) {
            int m = sc.nextInt();
            int data[] = new int[m];
            double rate[] = new double[m];
            int sum = 0;
            for (int i = 0; i < m; i++) {
                data[i] = sc.nextInt();
                sum += data[i];
                rate[i] = -1;
            }

            int sum_2 = sum;
            int m_2 = m;
            for (int i = 0; i < m; i++) {
                float r = (float) sum / m;
                if (data[i] >= 2 * r) {
                    rate[i] = 0;
                    sum_2 = sum_2 - data[i];
                    m_2--;
                }
            }
            for (int i = 0; i < m; i++) {
                if (rate[i] == 0) {
                } else {
                    if (data[i] != 0) {
                        rate[i] = (double) (sum + sum_2 - m_2 * data[i]) / (m_2 * sum);
                    } else {
                        rate[i] = (double) (sum_2 + sum )/( m_2 * sum);
                    }
                }
            }

            System.out.print("Case #" + ii + ":");
            for (int i = 0; i < m; i++) {
                System.out.printf(" %f", rate[i] * 100);
//                System.out.print(" " + data[i]);
            }
            System.out.println("");
            ii++;
            --n;
        }
        out.close();
    }

    public static void main(String args[]) throws Exception {
        Jam2012R2_A_S t = new Jam2012R2_A_S();
        t.Handle();
    }
}
