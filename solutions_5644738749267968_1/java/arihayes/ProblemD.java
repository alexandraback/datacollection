import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemD {
    static String in = "src/d.in";
    static String out = "src/d.out";

    public static void main(String[] args) throws FileNotFoundException, IOException {
        double[] naomi = new double[1000];
        double[] ken = new double[1000];

        Scanner scan = new Scanner(new File(in));
        BufferedWriter write = new BufferedWriter(new FileWriter(out));
        int numlines = scan.nextInt();
        for(int x = 0; x < numlines; x++) {
            int numblocks = scan.nextInt();

            for(int y = 0; y < numblocks; y++) {
                naomi[y] = scan.nextDouble();
            }
            for(int y = 0; y < numblocks; y++) {
                ken[y] = scan.nextDouble();
            }

            Arrays.sort(naomi, 0, numblocks);
            Arrays.sort(ken, 0, numblocks);
            int autowins = 0;
            for(int a = numblocks-1; a >= 0; a--) {
                if(naomi[a] > ken[numblocks-1]) {
                    autowins++;
                }
                else {
                    break;
                }
            }

            /*int tricks = 0;
            int dwins = autowins;
            for(int a = 0; a < numblocks - dwins && tricks < numblocks; a++) {
                if(naomi[numblocks - (1+dwins)] > ken[numblocks-(1+tricks)]) {
                    dwins++;
                    a--;
                    continue;
                } else {
                    tricks++;
                }
            }*/
            /*int dwins = 0;
            int amin = 0;
            int amax = numblocks-1;
            int bmin = 0;
            int bmax = numblocks-1;
            while(amin < amax) {
                if(naomi[amin] < ken[bmin]) {
                    amin++;
                    bmax--;
                }
                else if(naomi[amax] > ken[bmax]) {
                    amax--;
                    bmin++;
                    dwins++;
                }
                else {
                    amax--;
                    bmin++;
                }
            }*/
            int a1 = 0;
            int b1 = 0;
            int nqueue = 0;
            int kqueue = 0;
            while(a1 < numblocks || b1 < numblocks) {
                if(b1 < numblocks && (a1 >= numblocks || naomi[numblocks-(a1+1)] < ken[numblocks-(1+b1)])) {
                    //System.out.print("k\t");
                    if(nqueue > 0) {
                        nqueue--;
                    }
                    else {
                        kqueue++;
                    }
                    b1++;
                }
                else {//System.out.print("n\t");
                    nqueue++;
                    a1++;
                }
            }//System.out.println();
            int dwins = numblocks-nqueue;
            if(dwins < 1) {
                if(naomi[numblocks-1] > ken[0]) {
                    dwins = 1;
                }
            }

            int wwins = autowins;
            int b = autowins;
            outer: for(int a = 0; a < numblocks - autowins; a++) {
                boolean kenwin = false;
                inner: for(int z = b; z < numblocks; z++) {
                    if(ken[z] > naomi[a]) {
                        b = z + 1;
                        kenwin = true;
                        break inner;
                    }
                    wwins++;
                }
            }

            /*int a = 0;
            int b = autowins;
            int nqueue = 0;
            while(a < numblocks - autowins && b < numblocks) {
                if(naomi[a] < ken[b]) {

                }
            }*/

            write.write("Case #" + (x+1) + ": " + dwins + " " + wwins);
            write.newLine();
        }
        scan.close();
        write.close();
    }
}
