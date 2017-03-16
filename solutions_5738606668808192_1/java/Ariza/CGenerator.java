import java.io.PrintWriter;
import java.lang.Number;
import java.math.BigInteger;
import java.util.*;


public class CGenerator {
    public static final int BIT = 32;
    public static final int LIMIT = 500;
    public static final String FILE_NAME = "C-large.out";
    
    public static Map<String, List<BigInteger> > ans = new TreeMap<String, List<BigInteger> >();
    
    private static String toBit(long x) {
        String ret = "";
        for (int i=0;i<BIT;++i) {
            ret = ((x&(1L<<i))>0L?"1":"0") + ret;
        }
        return ret;
    }
    
    private static void Print() throws Exception {
        PrintWriter writer = new PrintWriter(FILE_NAME);
        writer.println("Case #1:");
        for (Map.Entry<String, List<BigInteger> > entry : ans.entrySet()) {
            writer.print(entry.getKey());
            for (BigInteger bi : entry.getValue()) {
                writer.print(" " + bi);
            }
            writer.println();
        }
        writer.close();
    }
    
    private static BigInteger isJamCoin(String bitnum, int base) {
        BigInteger x = BigInteger.ZERO;
        
        if (bitnum.charAt(0)!='1' || bitnum.charAt(BIT-1)!='1') return x;
        
        BigInteger mul = BigInteger.ONE;
        BigInteger biBase = new BigInteger(Integer.toString(base));
        for (int i=BIT-1;i>=0;--i) {
            if (bitnum.charAt(i)=='1') {
                x = x.add(mul);
            }
            mul = mul.multiply(biBase);
        }
        
        for (BigInteger bi = new BigInteger("2"); 
            bi.compareTo(new BigInteger("100"))<=0; bi = bi.add(BigInteger.ONE)) {
            if ((x.mod(bi)).compareTo(BigInteger.ZERO)==0) {
                return bi;
            }
        }
        return BigInteger.ZERO;
    }
    
    private static boolean JamCoin(long num) {
        List<BigInteger> list = new ArrayList<BigInteger>();
        boolean isOk = true;
        String bitnum = toBit(num);
        
        for (int i=2;i<=10;++i) {
            BigInteger x = isJamCoin(bitnum,i);
            if (x.compareTo(BigInteger.ZERO)==1) {
                list.add(x);
            }
            else
                isOk = false;
        }
        if (isOk) {
            ans.put(bitnum, list);
        }
        return isOk;
    }
    
    public static void main(String[] args) {
        long start = (1L<<(BIT-1));
        long end = (1L<<BIT);
        
        int found = 0;
        for (long i=start;i<end;++i){
            boolean ok = JamCoin(i);
            if (ok){
                found++;
                System.out.println(found);
            }
            if (found>=LIMIT) break;
        }
        try {
            Print();
        } catch (Exception e) {
            
        }
    }
}