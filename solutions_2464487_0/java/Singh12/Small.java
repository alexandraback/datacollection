package round1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by IntelliJ IDEA.
 * User: amarjeetsingh
 * Date: 27/04/13
 * Time: 8:18 AM
 * To change this template use File | Settings | File Templates.
 */
public class Small {
    static Scanner scanner = null;
        static PrintWriter printWriter = null;

        public static void main(String[] args) throws FileNotFoundException {
            scanner = new Scanner(new File("/Users/amarjeetsingh/Downloads/A-small-attempt0(1).in"));
            printWriter = new PrintWriter("/Users/amarjeetsingh/Desktop/output1A.in");
            int testcases = scanner.nextInt();
            for(int i=1;i<=testcases;i++){
                long count=0;
                long r=scanner.nextLong()+1;
                long remaingPaint=scanner.nextLong();;
                long areaRequired= (long) (Math.pow(r,2)-Math.pow(r - 1, 2));
                while (areaRequired<=remaingPaint){
                     remaingPaint-=areaRequired;
                     r+=2;
                     areaRequired=(long) (Math.pow(r,2)-Math.pow(r - 1, 2));
                     count++;
                }
                String outputString="Case #"+i+": "+count;
                System.out.println(outputString);
                printWriter.write(outputString+"\n");
            }
            printWriter.flush();
            printWriter.close();
        }
}
