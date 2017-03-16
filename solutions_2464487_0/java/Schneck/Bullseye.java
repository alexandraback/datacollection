
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Bullseye {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    public BigInteger r, t;
    
    static BigInteger TWO = BigInteger.valueOf(2);
    static BigInteger FOUR = BigInteger.valueOf(4);
    static BigInteger EIGHT = BigInteger.valueOf(8);
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        String rstr = scan.next();
        r = new BigInteger(rstr);
        String tstr = scan.next();
        t = new BigInteger(tstr);
        BigInteger tworminusone = r.multiply(TWO).subtract(BigInteger.ONE);
        BigInteger disc = tworminusone.multiply(tworminusone).add(t.multiply(EIGHT));
        System.out.println(BigInteger.ONE.subtract(r.multiply(BigInteger.valueOf(2))).add(sqrt(disc)).divide(FOUR));
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ": ");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new Bullseye().run();
    }
    
    static BigInteger sqrt(BigInteger n) {
        BigInteger a = BigInteger.ONE;
        BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
        while(b.compareTo(a) >= 0) {
          BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
          if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
          else a = mid.add(BigInteger.ONE);
        }
        return a.subtract(BigInteger.ONE);
      }

}
