/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam;

import java.io.*;
import java.math.*;

/**
 *
 * @author GreenTie
 */
public class GoogleCodeJam {

    /**
     * @param args the command line arguments
     */
    public static double problemAs(String G[]) {
        String temp[] = G[0].split(" ");
        int A = Integer.valueOf(temp[0]);
        int B = Integer.valueOf(temp[1]);
        temp = G[1].split(" ");
        double[] p = new double[temp.length];
        for (int i = 0; i < p.length; i++) {
            p[i] = Double.valueOf(temp[i]);
        }

        double x = B + 2;

        double b = B + 1;
        double y =1;
        for (int n = A - 1; n >= 0; n--) {
            if (2 * n >= A + 1) {
                y = y*(p[A - 1 - n]);
                continue;
            } else {
                y = y*(p[A - 1 - n]);
                double k = (2 * B - A + 2 + 2 * n)+(y*(b)*(-1));
                if (k<=x) {
                    x = k;
                    
                }
            }
    
           
            

        }

        return  x;
    }

    public static String problemAb(String G[]) {
        return null;
    }

    public static String problemBs(String G[]) {
        return null;
    }

    public static String problemBb(String G[]) {
        return null;
    }

    public static String problemCs(String G[]) {
        return null;
    }

    public static String problemCb(String G[]) {
        return null;
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here

        String input = "A-large.in";
        String output = "A-large.out";

        BufferedReader br = new BufferedReader(new FileReader(new File(input)));
        int x = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        System.setOut(new PrintStream(new File(output)));
        for (int i = 1; i <= x; i++) {
            String[] temp = new String[2];
            temp[0] = br.readLine().trim();
            temp[1] = br.readLine().trim();
            double result = problemAs(temp);
            System.out.printf("Case #%d: %6f\n",i,result);
            //sb.append("Case #").append(i).append(": ").append(Result[compute(Integer.parseInt(temp[0]),Integer.parseInt(temp[1]))]).append('\n');
            //System.out.printf("Case #%d: %s\n",i,Result[compute(Integer.parseInt(temp[0]),Integer.parseInt(temp[1]))]);   
        }

        
        br.close();

    }
}
