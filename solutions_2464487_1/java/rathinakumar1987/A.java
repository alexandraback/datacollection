package A;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: Rathina Kumar - V
 * Date: 26/4/13
 * Time: 10:10 PM
 * To change this template use File | Settings | File Templates.
 */

public class A{
    static final String programName="A";
    static final String WORK_DIR = "E:\\CodeJam\\src\\A\\";
    public static int find(BigInteger x, BigInteger r, BigInteger t)
    {
        BigInteger area1 = (x.multiply(r.add(x))).multiply(new BigInteger("2")).subtract(x);
        BigInteger area2 = ((x.add(BigInteger.ONE)).multiply(r.add(x.add(BigInteger.ONE)))).multiply(new BigInteger("2")).subtract(x.add(BigInteger.ONE));
        if(area1.compareTo(t)>0)return 1;
        if(area1.compareTo(t)<=0 && area2.compareTo(t)>0)return 0;
        return -1;
    }
    public static void main(String[] args) throws FileNotFoundException
    {
        Scanner sc = new Scanner(new File(WORK_DIR+programName+".input"));
        PrintWriter pw = new PrintWriter(new FileOutputStream(new File(WORK_DIR+programName+".output")));
        int testCase = sc.nextInt();
        for(int Case=1; Case<=testCase; Case++)
        {
            BigInteger r = sc.nextBigInteger();
            BigInteger t = sc.nextBigInteger();
            BigInteger total = BigInteger.ZERO;
            BigInteger ind = BigInteger.ONE;
            BigInteger cnt =BigInteger.ZERO;
            BigInteger a = BigInteger.ONE;
            BigInteger b = t;
            BigInteger c = (a.add(b).divide(new BigInteger("2")));
            while(true)
            {
                int aa = find(a,r,t);
                if(aa==0) {cnt=a;break;}
                int bb = find(b, r, t);
                if(bb ==0) {cnt=b;break;}
                int cc = find(c,r,t);
                if(cc==0) {cnt=c;break;}
                if(cc==1)
                {
                    b=c;
                    c=(a.add(b)).divide(new BigInteger("2"));
                }
                else {
                    a=c;
                    c=(a.add(b)).divide(new BigInteger("2"));
                }
            }

            pw.write("Case #" + Case + ": " + cnt + "\n");
        }
        sc.close();
        pw.close();
    }

}

