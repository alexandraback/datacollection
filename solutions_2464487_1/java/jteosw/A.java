import java.util.*;
import java.math.*;
import java.lang.*;

public class A{
    static BigInteger two = BigInteger.valueOf(2L);
    static Scanner s;
    public static void main(String[] args){
        s = new Scanner(System.in);
        int cases = s.nextInt();
        for(int i = 0; i < cases; i++) {
            BigInteger result = solve();
            System.out.printf("Case #%s: %s\n", i+1, result.toString());
        }
    }

    public static BigInteger solve() {
        BigInteger b = (convert(s.next()).multiply(two)).subtract(BigInteger.ONE);
        BigInteger base = convert(s.next());
        base = (b.multiply(b)).add(base.multiply(BigInteger.valueOf(8L)));
        //System.out.println("base : " + base.toString());
        BigInteger result = sqrt(base);
        //System.out.println("result : " + result.toString());
        result =  ((result.subtract(b)).divide(BigInteger.valueOf(4L)));
        //System.out.println("result : " + result.toString());
        return result;

    }


    public static BigInteger convert(String s) {
        BigInteger result = BigInteger.ZERO;
        for(int i = 0; i < s.length(); i++) {
            result = result.multiply(BigInteger.TEN).
                add(BigInteger.valueOf((long) Integer.parseInt(s.substring(i, i+1))));
        }
        //System.out.println("Convert :" + result.toString());
        return result;
    }

    public static BigInteger sqrt(BigInteger x){
        BigInteger y;
        for(y = x.divide(two); y.compareTo(x.divide(y)) > 0; y = ((x.divide(y)).add(y)).divide(two));
        return y;
    }






}
