import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

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
            long base10 = Long.parseLong(jamcoin, 10);
            long base9 = Long.parseLong(jamcoin, 9);
            long base8 = Long.parseLong(jamcoin, 8);
            long base7 = Long.parseLong(jamcoin, 7);
            long base6 = Long.parseLong(jamcoin, 6);
            long base5 = Long.parseLong(jamcoin, 5);
            long base4 = Long.parseLong(jamcoin, 4);
            long base3 = Long.parseLong(jamcoin, 3);
            long base2 = Long.parseLong(jamcoin, 2);
            if(isNotPrime(base10)&& isNotPrime(base9)&& isNotPrime(base8)&& isNotPrime(base7)&& isNotPrime(base6)&& isNotPrime(base5)&& isNotPrime(base4)&& isNotPrime(base3)&& isNotPrime(base2)){
                System.out.println(jamcoin + " " + div(base2) + " " + div(base3) + " " + div(base4) + " " + div(base5) + " " + div(base6) + " " + div(base7) + " " + div(base8) + " " + div(base9) + " " + div(base10));
                count++;
                if(count == J)break;
            }
        }
    }
    
    private static boolean isNotPrime(long n){
        for(long i = 2; i <= Math.sqrt(n); i++){
            if(n % i == 0){
                return true;
            }
        }
        return false;
    }
    
    private static long div(long n){
        for(long i = 2; i <= Math.sqrt(n); i++){
            if(n % i == 0){
                return i;
            }
        }
        return -1;
    }
}
