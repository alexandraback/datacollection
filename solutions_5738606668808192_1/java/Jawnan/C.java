import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.TreeSet;

/**
 * Created by Nejc on 09.04.2016.
 */
public class C {
    public static void main(String[]args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        String[] split = br.readLine().split(" ");
        int N = Integer.parseInt(split[0]);
        int J = Integer.parseInt(split[1]);
        long start = (long)Math.pow(2, N-1)+1;
        long end = (long)Math.pow(2, N);
        int count = 0;
        System.out.println("Case #1:");
        for(long cur = start; cur < end; cur+=2){
            String jamcoin = Long.toString(cur, 2);
            BigInteger base10 = new BigInteger(jamcoin, 10);
            BigInteger base9 = new BigInteger(jamcoin, 9);
            BigInteger base8 = new BigInteger(jamcoin, 8);
            BigInteger base7 = new BigInteger(jamcoin, 7);
            BigInteger base6 = new BigInteger(jamcoin, 6);
            BigInteger base5 = new BigInteger(jamcoin, 5);
            BigInteger base4 = new BigInteger(jamcoin, 4);
            BigInteger base3 = new BigInteger(jamcoin, 3);
            BigInteger base2 = new BigInteger(jamcoin, 2);
            if(isNotPrime(base10)&& isNotPrime(base9)&& isNotPrime(base8)&& isNotPrime(base7)&& isNotPrime(base6)&& isNotPrime(base5)&& isNotPrime(base4)&& isNotPrime(base3)&& isNotPrime(base2)){
                String output = jamcoin + " " + div(base2) + " " + div(base3) + " " + div(base4) + " " + div(base5) + " " + div(base6) + " " + div(base7) + " " + div(base8) + " " + div(base9) + " " + div(base10);
                if(output.contains("-"))continue;
                System.out.println(output);
                count++;
                if(count == J)break;
            }
        }
    }
    
    private static boolean isNotPrime(BigInteger n){
        return !n.isProbablePrime(1);
    }
    
    private static String div(BigInteger n){
        for(BigInteger i = new BigInteger("2"); i.pow(2).compareTo(n) == -1 && i.compareTo(new BigInteger("100")) == -1; i = i.add(BigInteger.ONE)){
            if(n.mod(i).compareTo(new BigInteger("0"))==0){
                return i.toString();
            }
        }
        return "-1";
    }
}
