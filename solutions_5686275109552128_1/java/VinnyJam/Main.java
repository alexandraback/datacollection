

package problem2;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;



public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        //Scanner in = new Scanner(new File("B-small-atempt0.in"));
        //new testcreator();
        Scanner in = new Scanner(new File("B-large.in"));
        PrintWriter out = new PrintWriter(new File("output.txt"));
        
        int t = in.nextInt();
        int max=0;
        for (int i=0; i<t; i++){
            int d = in.nextInt();
            int[] plates = new int[d];
            for (int j=0; j<d; j++){
                plates[j]=in.nextInt();
                if (plates[j]>max) max = plates[j];
            }
            int minsum=1000000;
            for (int k=1; k<max+1; k++){
                int sum=0;
                for (int j=0; j<d; j++){
                    sum+=(plates[j]-1)/k;
                }
                if ((sum+k)<minsum) {
                    minsum = sum+k;
                }
            }
            out.println("Case #"+(i+1)+": "+minsum);
        }
        out.flush();
        out.close();
    }
    
}
