
import java.io.*;
import java.math.*;
import java.util.*;

/**
 *
 * @author Daniel Sheng (dsheng)
 */
public class Safety {

    private static Scanner in;
    private static PrintStream fout;
    private static int caseNum = 1;
    
    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(System.in);
        fout = new PrintStream("Safety.out");
        
        int nln = Integer.parseInt(in.nextLine());
        for (int ln = 0; ln < nln; ln++) {
            int[] vals = intsplit();
            int total = 0;
            int min = Integer.MAX_VALUE, min2 = Integer.MAX_VALUE, first = 0, second = 1;
            for(int val = 1; val < vals.length; val++) {
                total += vals[val];
                if(vals[val] < min) {
                    min2 = min;
                    min = vals[val];
                    second = first;
                    first = val;
                }
                else if(vals[val] < min2) {
                    min2 = vals[val];
                    second = val;
                }
            }
            String s = "";
            double cutoff = total * 2 / vals[0];
            int rev = vals[0], sum = 0;
            for(int val = 1; val < vals.length; val++) {
                if(vals[val] > cutoff)
                    rev--;
                else
                    sum += vals[val];
            }
            double target = ((double) sum + total) / rev;
            for(int val = 1; val < vals.length; val++) {
                if(vals[val] > cutoff)
                    s += 0.;
                else {
                    s += 100 * (target - vals[val]) / total;
                }
                s += " ";
                /*
                int lowest = first;
                if(val == first) {
                    lowest = second;
                }
                println(val + " " + lowest);
                double diff = Math.abs(((double) vals[val] - vals[lowest]) / total);
                println(diff);
                if(vals[val] < vals[lowest]) {
                    s += (1 - diff) / 2 + diff;
                }
                else {
                    s += (1 - diff) / 2;
                }
                s += " ";
                 */
            }
            println(s.substring(0, s.length() - 1));
            result(s.substring(0, s.length() - 1));
        }
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
