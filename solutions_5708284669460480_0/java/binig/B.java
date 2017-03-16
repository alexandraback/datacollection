import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by benoi_000 on 4/16/2015.
 */
public class B {

    public static void main(String args[]) throws FileNotFoundException {
        final String defaultFile = B.class.getName()+".in";
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
            Object res = comput(scanner);
            out.println("Case #"+(i+1)+": "+res);
        }

    }

    public static double comput(Scanner scanner) {
        int k = scanner.nextInt();
        int l = scanner.nextInt();
        int s = scanner.nextInt();

       scanner.nextLine();
        char[] keys = scanner.next().toCharArray();
        scanner.nextLine();
        String target  = scanner.next();
        Arrays.sort(keys);
        //Arrays.sort(target);
        int[] occKey= new int[26];
        for (char c:keys) {
            occKey[c-'A']++;
        }
        int[] combi = new int[s];
        long maxBanana =0;
        long sumBananas =0;
        long cmpt =0;
        int idx=0;

        while(true) {
            cmpt++;
            char[] res = new char[s];
            for (int i=0;i<s;i++) res[i] = keys[combi[i]];
            int n =numberOf(res,target);
            if (n>0) {
                sumBananas+=n;
                maxBanana= Math.max(n,maxBanana);
            }

           if(!incr(combi,k-1)) break;
        }
        return  (double)maxBanana - ((double)sumBananas/(double)cmpt);
    }

    private static int numberOf(char[] res, String target) {
        int idx = 0;
        int cmpt =0;
        String r = new String(res);
        do {
            if (r.startsWith(target,idx)) cmpt++;
            idx++;
        }while ((idx+target.length())<=res.length);
        return cmpt;
    }

    private static boolean incr(int[] combi,int max) {
        int i = 0;
        while(i<combi.length) {
            if (combi[i]<max) {
                combi[i]++;
                return true;
            }
            else {
                combi[i]=0;
                i++;
            }
        }
        return false;
    }
}
