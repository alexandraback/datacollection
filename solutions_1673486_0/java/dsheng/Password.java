
import java.io.*;
import java.math.*;
import java.util.*;

/**
 *
 * @author Daniel Sheng (dsheng)
 */
public class Password {

    private static Scanner in;
    private static PrintStream fout;
    private static int caseNum = 1;
    
    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(System.in);
        fout = new PrintStream("Password.out");
        
        int nln = Integer.parseInt(in.nextLine());
        for (int ln = 0; ln < nln; ln++) {
            int[] passData = intsplit();    //typed so far      total
            double[] probs = doublesplit();
            
            double strokesRightAway = passData[1] + 2;
            double probCompletelyCorrect = probCompletelyCorrect(probs);
            double strokesCompleteTyping = probCompletelyCorrect * (passData[1] - passData[0] + 1) + (1 - probCompletelyCorrect) * (passData[1] * 2 - passData[0] + 2);
            double strokesWithBackspace = Double.MAX_VALUE;
            for(int i = 1; i <= passData[0]; i++)  //don't need <=
            {
                double acc = 0;
                for(int j = 0; j <= passData[0]; j++)
                {
                    System.out.println("|" + j);
                    if(i >= j)
                        acc += getProb(passData[0] - j, passData[0], probs) * (2 * i + passData[1] - passData[0] + 1);
                    else
                        acc += getProb(passData[0] - j, passData[0], probs) * (2 * i + passData[1] * 2 - passData[0] + 2);
                }
                println("  " + acc);
                if(acc < strokesWithBackspace)
                    strokesWithBackspace = acc;
            }
            println(strokesRightAway);
            println(strokesCompleteTyping);
            println(strokesWithBackspace);
            double res = Math.min(strokesWithBackspace, Math.min(strokesRightAway, strokesCompleteTyping));
            System.out.println(res);
            result(res);
        }
    }
    
    private static double probCompletelyCorrect(double[] d)
    {
        double acc = 1;
        for(double x : d)
            acc *= x;
        return acc;
    }
    
    private static double getProb(int i, int max, double[] probs)  //probability that character >= i is bad
    {
        double acc = 1;
        for(int n = 0; n < max; n++)
            if(n == i)
                acc *= 1 - probs[n];
            else if(n < i)
                acc *= probs[n];
        //println(acc + " " + i + " " + max + " " + probs[0] + " " + probs[1]);
        return acc;
    }
    
    private static String line() {
        return in.nextLine();
    }
    
    private static int integer() {
        return Integer.parseInt(line());
    }
    
    private static double decimal() {
        return Double.parseDouble(line());
    }
    
    private static BigInteger bigint() {
        return new BigInteger(line());
    }
    
    private static BigDecimal bigdec() {
        return new BigDecimal(line());
    }
    
    private static String[] strsplit() {
        return line().split("\\s+");
    }
    
    private static int[] intsplit() {
        String[] strs = strsplit();
        int[] ints = new int[strs.length];
        for (int i = 0; i < ints.length; i++) {
            ints[i] = Integer.parseInt(strs[i]);
        }
        return ints;
    }
    
    private static double[] doublesplit() {
        String[] strs = strsplit();
        double[] dbls = new double[strs.length];
        for (int i = 0; i < dbls.length; i++) {
            dbls[i] = Double.parseDouble(strs[i]);
        }
        return dbls;
    }
    
    private static BigInteger[] bigintsplit() {
        String[] strs = strsplit();
        BigInteger[] ints = new BigInteger[strs.length];
        for (int i = 0; i < ints.length; i++) {
            ints[i] = new BigInteger(strs[i]);
        }
        return ints;
    }
    
    private static BigDecimal[] bigdecsplit() {
        String[] strs = strsplit();
        BigDecimal[] decs = new BigDecimal[strs.length];
        for (int i = 0; i < decs.length; i++) {
            decs[i] = new BigDecimal(strs[i]);
        }
        return decs;
    }
    
    private static void result(Object o) {
        fout.println("Case #" + (caseNum++) + ": " + o);
    }
    
    private static void resultf(String fmt, Object... args) {
        fout.printf("Case #%d: " + fmt, caseNum++, args);
    }
    
    private static void print(Object o) {
        System.out.print(o);
    }
    
    private static void println(Object o) {
        System.out.println(o);
    }
    
    private static void printf(String fmt, Object... args) {
        System.out.printf(fmt, args);
    }
}
