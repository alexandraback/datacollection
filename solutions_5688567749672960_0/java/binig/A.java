import java.io.*;
import java.util.Scanner;

/**
 * Created by benoi_000 on 4/16/2015.
 */
public class A {

    public static void main(String args[]) throws FileNotFoundException {
        final String defaultFile = A.class.getName()+".in";
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
            Object res = comput(scanner.nextLong());
            out.println("Case #"+(i+1)+": "+res);
        }

    }

    public static long comput(long N) {
        long cmpt =0;
        long i=1;
        while (i<=N) {
            long reverse = reverse(i);
            i++;
            if (reverse>i&&reverse<=N) {
                i = reverse;
            }
            cmpt++;
        }
        return  cmpt;
    }

    private static long reverse(long i) {
       return Long.parseLong(new StringBuilder(Long.toString(i)).reverse().toString());
    }
}
