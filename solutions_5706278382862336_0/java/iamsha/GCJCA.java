import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;
import java.util.Scanner;


public class GCJCA {
	private static Scanner sc;
    private static PrintWriter out;

    public static void main(String[] args) {

        try {
            //sc = new Scanner( new File("/Users/sgururaj/Downloads/A-large.in"));
            sc = new Scanner( new File("/Users/sgururaj/Downloads/A-small-attempt0.in"));
            //sc = new Scanner( new File("/Users/sgururaj/Downloads/test.in"));
            out = new PrintWriter("/Users/sgururaj/Downloads/op-large.txt", "UTF-8");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        int C = sc.nextInt();
        String discard = sc.nextLine();
        //l(C);
        for(int test=1; test<=C; test++) {
            String[] now = sc.nextLine().split("/");

            long P = Long.parseLong(now[0]);
            long Q = Long.parseLong(now[1]);
            long g = gcd(P, Q);
            //l(P, Q);

            P/=g; Q/=g;
            if(Long.bitCount(Q)!=1) {
                String pr = ("Case #"+test+": impossible");
                out.println(pr);
                System.out.println(pr);
                continue;
            }
            for(int i=1; i<40; i++) {
                //if(test==1) l(P, Q);
                Q = Q>>1;
                if(P+1<=2*Q&&Q<=P) {
                    String pr = ("Case #"+test+": "+i);
                    out.println(pr);
                    System.out.println(pr);
                }
            }
        }
        out.close();

    }

    static public long gcd(long a, long b) {
        if(b==0)return a;
        return gcd(b, a%b);
    }

    public static void l(Object ...o) {
        String s = "";
        for(Object oo : o) {
            if(oo instanceof int[]) {
                s+=Arrays.toString((int[])oo)+" ";
                continue;
            }
            if(oo instanceof double[]) {
                s+=Arrays.toString((double[])oo)+" ";
                continue;
            }
            if(oo instanceof boolean[]) {
                s+=Arrays.toString((boolean[])oo)+" ";
                continue;
            }
            if(oo instanceof char[]) {
                s+=Arrays.toString((char[])oo)+" ";
                continue;
            }
            if(oo instanceof long[]) {
                s+=Arrays.toString((long[])oo)+" ";
                continue;
            }
            if(oo instanceof String[]) {
                s+=Arrays.toString((String[])oo)+" ";
                continue;
            }
            if(oo instanceof Object[]) {
                s+=Arrays.deepToString((Object[])oo)+" ";
                continue;
            }
            s += (oo.toString())+" ";
        }
        System.out.println(s);
    }
}
