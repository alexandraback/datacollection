//The reason my program didn't halt on large input was that I used input stream for taking the input instead of a file.
package R1B;

import java.awt.Point;
import java.util.Scanner;
import java.io.*;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Vector;

/**
 *
 * @author Rohit
 */
public class QC {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        System.out.println("File Path:");
        Scanner f = new Scanner(System.in);
        String inputfile = f.nextLine();
        f.close();
        Scanner s = null;
        try {
            s = new Scanner(new BufferedReader(new FileReader(inputfile)));
        } catch (FileNotFoundException ex) {
            System.out.println("File Not Found");
            return;
        }
        int Tcases = s.nextInt();
        s.nextLine();
        for (int i = 0; i < Tcases; i++) {
            int Nnumbers = s.nextInt();
            int[] num = new int[Nnumbers];
            for (int j = 0; j < Nnumbers; j++) {
                num[j] = s.nextInt();
            }
            int total = (int) Math.pow(2, Nnumbers);
            int[] sum = new int[total];
            int set = 0;

            // iterate over all the subsets
            for (int j = 0; j < (1 << Nnumbers); j++) {
                // generate the j-th subset
                Vector<Integer> subset = new Vector<Integer>();
                for (int k = 0; k < Nnumbers; k++) {
                    if ((j & (1 << k)) > 0) {
                        subset.add(num[k]);
                    }
                }
                // perform an action over the subset                
                for (int k = 0; k < subset.size(); k++) {
                    sum[set] += subset.get(k);
                }
                set++;
            }


            Point[] point = new Point[sum.length];
            for(int j = 0; j < sum.length; j++) {
                point[j] = new Point(sum[j],j);
            }
            //sort the sum array
            Arrays.sort(point, new PointCmp());
            int j;
            boolean found = false;
            for (j = 0; j < total - 1; j++) {
                if (point[j].x == point[j + 1].x) {
                    found = true;
                    break;
                }
            }
            //printing the output
            if (found) {
                System.out.println("Case #" + (i + 1) + ":");
                printSets(num, point[j].y, point[j+1].y);
            } else {
                System.out.println("Case #" + (i + 1) + ":");
                System.out.println("Impossible");
            }

        }
    }

    public static void printSets(int[] num, int a, int b) {
        for (int k = 0; k < num.length; k++) {
            if ((a & (1 << k)) > 0) {
                System.out.print(num[k] +" ");
            }
        }
        System.out.println("");

        for (int k = 0; k < num.length; k++) {
            if ((b & (1 << k)) > 0) {
                System.out.print(num[k] +" ");
            }
        }
        System.out.println("");
    }
}

class PointCmp implements Comparator<Point> {
    public int compare(Point a, Point b) {
        return (a.x < b.x) ? -1 : (a.x > b.x) ? 1 : 0;
    }
}
