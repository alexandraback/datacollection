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
            Object res = comput(scanner.nextInt(),scanner);

            out.println("Case #"+(i+1)+": "+res);
        }

    }

    public static long comput(int r,  Scanner scanner) {
        int ds[] = new int[r];
        int hs[] = new int[r];
        long ms[] = new long[r];
        List<Long> speeds = new ArrayList<Long>();
        for (int i=0;i<r;i++) {
            ds[i] = scanner.nextInt();
             hs[i] = scanner.nextInt();
             ms[i] = scanner.nextLong();
            for (int j=0;j<hs[i];j++) {
                long t =ms[i]+j;
                long s=((360-ds[i]))*t;
                speeds.add(s);
            }
        }
        int encouter =Integer.MAX_VALUE;
        for (double i:speeds) {
            int e=0;
            for (int j=0;j<r;j++) {
                int d = ds[j];
              for (int k=0;k<hs[j];k++) {
                  long t = ms[j]+k;
                  int f = (int)((double)i/(double)t) +d;
                  if (f <360) {
                      e++;
                  } else if (f>360){
                    int c = (f/360)-1;
                    //  if (f%360==0) c--;
                      e+=c;
                  }

              }
            }
            encouter = Math.min(encouter,e);
            if (encouter==0) break;
        }
        return encouter;
    }
}
