import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;

public class NicePalyndromesGenerator {
    
    static PrintWriter out;
    static int maxLen = 51;
    static BigInteger res[];
    static ArrayList<BigInteger> nums = new ArrayList<BigInteger>();
    
    static boolean isPalyndrome(BigInteger a) {
        int i;
        String s = a.toString();
        for (i=0;i<s.length();i++) {
            if (s.charAt(i) != s.charAt(s.length()-1-i)) {
                return false;
            }
        }
        return true;
    }
    
    // same result when middle is {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}
    static String middle[] = new String[]{"0", "1", "2"};
    
    static void generate(String prefix, String opPrefix) {
        int i;
        
        if (prefix.length() > maxLen) {
            return;
        }
        
        // we try to make odd-digit number by adding a character in the middle
        
        for (i=0;i<middle.length;i++) {
            BigInteger a = new BigInteger(prefix+middle[i]+opPrefix);
            BigInteger sqa = a.multiply(a);
            boolean ipsqa = isPalyndrome(sqa);
            
            if (ipsqa) {
                nums.add(sqa);
                out.println(sqa);
                if (nums.size()%1000==0) {
                    System.out.println(nums.size());
                }
            }
            
            BigInteger b = new BigInteger(prefix+middle[i]+middle[i]+opPrefix);
            BigInteger sqb = b.multiply(b);
            boolean ipsqb = isPalyndrome(sqb);
            
            if (ipsqb) {
                nums.add(sqb);
                out.println(sqb);
                if (nums.size()%1000==0) {
                    System.out.println(nums.size());
                }
            }
            
            if (ipsqa||ipsqb) {
                generate(prefix+middle[i], middle[i]+opPrefix);
            }
            
        }
        
    }
    
    public static void main(String[] args) throws Exception {
        int i;
        
        out = new PrintWriter(new File("data.txt"));
        
        nums.add(new BigInteger("1"));
        out.println("1");
        nums.add(new BigInteger("4"));
        out.println("4");
        nums.add(new BigInteger("9"));
        out.println("9");
        nums.add(new BigInteger("121"));
        out.println("121");
        nums.add(new BigInteger("484"));
        out.println("484");
        
        for (i=1;i<10;i++) {
            generate(""+(char)('0'+i), ""+(char)('0'+i));
        }
        
        int T = nums.size();
        res = new BigInteger[T];
        Iterator<BigInteger> it = nums.iterator();
        for (i=0;i<T;i++) {
            res[i] = it.next();
        }
        
        Arrays.sort(res);
        
        for (i=0;i<res.length;i++) {
            //System.out.println(sqrt(res[i])+"\t"+res[i]);
        }
        
        System.out.println(res.length);
        out.close();
        
    }
    
    static BigInteger sqrt(BigInteger bi) {
        
        BigInteger low = BigInteger.ONE;
        BigInteger high = bi.add(BigInteger.ZERO);
        BigInteger mid;
        
        while (true) {
            mid = low.add(high).divide(new BigInteger("2"));
            
            int cmp = mid.multiply(mid).compareTo(bi);
            if (cmp == 0) {
                return mid;
            }
            if (cmp < 0) {
                low = mid;
            } else {
                high = mid;
            }
            
        }
        
    }
    
}