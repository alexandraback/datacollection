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
            int cnt =0;
            while(true)
            {
                BigInteger area = ind.add(r.multiply(new BigInteger("2")));
                total=total.add(area);
                if(t.compareTo(total)>=0)
                   cnt++;
                else
                    break;
                ind=ind.add(new BigInteger("4"));
            }
            pw.write("Case #"+Case+": "+cnt+"\n");
        }
        sc.close();
        pw.close();
    }

}

