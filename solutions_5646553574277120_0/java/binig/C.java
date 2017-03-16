import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by benoi_000 on 4/16/2015.
 */
public class C {

    public static void main(String args[]) throws FileNotFoundException {
        final String defaultFile = C.class.getName()+".in";
        final PrintStream out;
        final InputStream in;
        if (args.length==0) {
            in = new FileInputStream("test/"+defaultFile);
            out =System.out;

        } else {
            in = new FileInputStream("resources/"+args[0]);
            out = new PrintStream(new FileOutputStream("result/"+args[0]));
        }
        Scanner scanner = new Scanner(in);
        int nbTest = scanner.nextInt();
        for (int i=0;i<nbTest;i++) {
            scanner.nextLine();
            Object res = comput(i,scanner);

            out.println("Case #"+(i+1)+": "+res);
        }

    }

    public static long comput(int testNb,  Scanner scanner) {
        long denomination =0;
        long c = scanner.nextLong();
        int d = scanner.nextInt();

        // max value
        long v = scanner.nextLong();
        long[] existing = new long[d];
        for(int i=0;i<d;i++) {
            existing[i] = scanner.nextLong();
        }
        long amount =1;
        long currMax =0;
        int idx=0;
        long currD=existing[0];
        int added =0;
        while(amount<=v){

            if (amount%currD<=currMax) {
                idx++;
            } else {
                added++;
                currD = amount;

            }
            currMax+=currD*c;
            while (idx<existing.length&&existing[idx]<=(currMax+1)) {
                currD= existing[idx];
                currMax+=currD*c;
                idx++;

            }
            if (idx<existing.length) {
                currD = existing[idx];
            } else if (currMax+1<=v){

                currD=currMax+1;
                added++;
            }
            amount=currMax+1;

        }
        return added;
    }
}
