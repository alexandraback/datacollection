
import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.Timer;
import java.util.TimerTask;

public class MainClass {
    static Scanner scan;
    static int[] A = new int[80000];
    static int dem = 2;
    static int i;

    static boolean snt(int x) {
        int t = (int)Math.sqrt(x);
        for(int j=0;j<dem;j++) {
            if(x%A[j]==0) return false;
            if(A[j] > t) {
                A[dem] = x;
                dem++;
                return true;
            }
        }
        A[dem] = x;
        x++;
        return true;
    }

    //static int KQ[][] = new int[50][11];
    static int ii = 0;
    static PrintWriter writer;

    public static void main(String[] args) {
        File file = new File("A-small-attempt0.in");
        try {
            writer = new PrintWriter("A-small-attempt0.out");
            scan = new Scanner(file);
            int test = scan.nextInt();
            scan.nextLine();
            for(int i=0;i<test;i++) {
                writer.print("Case #" + (i + 1) + ":");
                xuly();
            }
            writer.close();
        } catch (Exception e1) {
            e1.printStackTrace();
        }
    }

    static void xuly() {
        String s = scan.next();
        String kq = "" + s.charAt(0);
        for(int i=1;i<s.length();i++) {
            if(s.charAt(i) >= kq.charAt(0))
                kq = s.charAt(i) + kq;
            else kq = kq + s.charAt(i);
        }
        writer.println(kq);
    }
}
