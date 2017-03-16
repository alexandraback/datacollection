import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

    static BigInteger pow10[] = new BigInteger[200];
    static ArrayList<BigInteger> values;

    public static void search( BigInteger cur, int st, int len, boolean canZero ) {
        if( st * 2 >= len ) {
            return;
        }
        for( int i = canZero ? 0 : 1; i < 10; i++ ) {
            BigInteger next = null;
            if( st != len - st - 1 ) {
                next = cur.add(pow10[st].add(pow10[len-st-1]).multiply(BigInteger.valueOf(i)));
            } else {
                next = cur.add(pow10[len-st-1].multiply(BigInteger.valueOf(i)));
            }
            if( !isPalin(next.multiply(next)) ) {
                continue;
            }
            values.add( next.multiply(next) );
            search( next, st + 1, len, true);
        }
    }

    public static boolean isPalin( BigInteger x ) {
        String s = x.toString(10);
        for( int i = 0; i < s.length(); i++ ) {
            if( s.charAt(i) != s.charAt(s.length() - i - 1 ) ){
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) throws IOException {
        pow10[0] = BigInteger.ONE;
        for( int i = 1; i < pow10.length; i++ ) {
            pow10[i] = pow10[i-1].multiply(BigInteger.TEN);
        }
/*        for( long i = 1; i <= 10000000; i++ ) {
            if( isPalin(BigInteger.valueOf(i)) && isPalin( BigInteger.valueOf(i*i) ) ) {
                System.err.println(i + " " + i*i + "\n");
            }
        }*/
        values = new ArrayList<BigInteger>();
        Collections.sort(values);
        for( int len = 1; len <= 51; len++ ) {
            search(BigInteger.ZERO, 0, len, false);
        }
        ArrayList<BigInteger> tmp = new ArrayList<BigInteger>();
        tmp.add(values.get(0));
        for( int i = 1; i < values.size(); i++ ) {
            if( values.get(i).compareTo(values.get(i-1)) != 0 ) {
                tmp.add(values.get(i));
            }
        }
        values = tmp;
        for( BigInteger a : values ){
            System.err.println(a.toString(10));
        }
        Scanner in = new Scanner(new FileReader("input.txt"));

        PrintWriter out = new PrintWriter(new FileWriter("output.txt"));

        int tn = in.nextInt();
        for( int i = 0; i < tn; i++ ) {
            BigInteger A = new BigInteger(in.next());
            BigInteger B = new BigInteger(in.next());
            int count = 0;
            out.write("Case #" + (i+1) + ": ");
            for( BigInteger a : values ) {
                if( a.compareTo(A) >= 0 && a.compareTo(B) <= 0 ) {
                    count++;
                }
            }
            out.write(Integer.toString(count) + "\n");
        }
        out.flush();
        //System.err.println(checkValue(BigInteger.valueOf(101), 0, 0, 3, true));
    }

}
