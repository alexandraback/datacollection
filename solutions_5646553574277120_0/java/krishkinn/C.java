package codejam.round1c;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * User: RK
 */
public class C {

    public static int rec(int o[], int l, int deep) {
        if (deep>5) {
            return -1;
        }

        for (int i = 0;i<o.length;i++) {
            if (o[i]==0) {
                if (i<l) {
                    return -1;
                }
                break;
            }
            if (i==o.length-1) {
                return 0;
            }
        }
        int ans = -1;
        int current;
        for (int d=l;d<o.length;d++) {
            if (o[d]!=2) {
                int[] onew = Arrays.copyOf(o, o.length);
                for (int j=o.length-1;j-d>=0;j--) {
                    if (onew[j-d]!=0 && onew[j]==0) {
                        onew[j] = 1;
                    }
                }
                current = rec(onew, d+1, deep+1);
                if (current!=-1 && (ans==-1 || current+1<ans)){
                    ans = current+1;
                }
            }
        }
        return ans;
    }

    public static int process(int c, int da[], int v) {
        int[] o = new int[v+1];
        o[0] = 1;
        for (int d: da) {
            for (int i=0;i<c;i++) {
                for (int j=v;j-d>=0;j--) {
                    if (o[j-d]!=0 && o[j]==0) {
                        o[j] = 1;
                    }
                }
            }
            o[d] = 2;
        }
        return rec(o, 1, 0);
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new FileInputStream("test_codejam/c.in"));
        PrintWriter out = new PrintWriter(new FileOutputStream("test_codejam/c.out"));
//        Scanner in = new Scanner(System.in);
        //PrintWriter out = new PrintWriter(System.out);
        int t = in.nextInt();
        int test = 1;
        while (t-->0) {
            int answer = 0;
            int c,d,v;

            c = in.nextInt();
            d = in.nextInt();
            v = in.nextInt();
            int da[] = new int[d];
            for (int i=0;i<d;i++) {
                da[i] = in.nextInt();
            }

            answer = process(c,da,v);

            out.println("Case #" + test + ": " + answer);
            out.flush();
            test++;
        }
        out.close();
    }

}
