import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

/**
 * 
 */

/**
 * @author joelmanning
 *
 */
public class CoinJam
{

    /**
     * @param args
     */
    public static void main(String[] args) throws IOException
    {
        //System.out.println("Start");
        BufferedReader br = new BufferedReader(new FileReader("coins.in"));
        PrintWriter pw = new PrintWriter("coins.out");
        long t = Integer.parseInt(br.readLine());
        for(int i = 1; i <= t; i++){
            pw.println("Case #" + i + ":");
            String nj = br.readLine();
            int space = nj.indexOf(' ');
            int n = Integer.parseInt(nj.substring(0, space));
            int j = Integer.parseInt(nj.substring(space + 1));
            boolean[] current = new boolean[n];
            current[0] = true;
            current[n - 1] = true;
            long[] values = new long[9];
            for(int k = 0; k < 9; k++){
                values[k] = (long) Math.pow(k + 2, n - 1) + 1;
            }
            long jamcoins = 0;
            while(jamcoins < j){
                //System.out.println("Examining " + Arrays.toString(current));
                boolean good = true;
                long[] divisors = new long[9];
                for(int k = 0; k < 9; k++){
                    divisors[k] = divisor(values[k]);
                    if(divisors[k] == -1){
                        good = false;
                    }
                }
                //System.out.println("It had divisors " + Arrays.toString(divisors));
                if(good){
                    String out = "";
                    for(int k = n - 1; k >= 0; k--){
                        if(current[k]){
                            out += 1;
                        } else {
                            out += 0;
                        }
                    }
                    for(long div: divisors){
                        out += " " + div;
                    }
                    pw.println(out);
                    jamcoins++;
                }
                for(int k = 1; k < n; k++){
                    if(k == n - 1){
                        pw.close();
                        throw new RuntimeException("Big Red Error");
                    }
                    if(current[k]){
                        current[k] = false;
                        for(int l = 0; l < 9; l++){
                            values[l] -= Math.pow(l + 2, k);
                        }
                    } else {
                        current[k] = true;
                        for(int l = 0; l < 9; l++){
                            values[l] += Math.pow(l + 2, k);
                        }
                        break;
                    }
                }
            }
        }
        pw.close();
        br.close();
        System.exit(0);
    }
    
    private static long divisor(long num){
        for(long i = 2; num/i >= i; i++){
            if(num % i == 0){
                return i;
            }
        }
        return -1;
    }
    
    private static long pow(long base, long power){
        long num = 1;
        for(int i = 0; i < power; i++){
            num *= base;
        }
        return num;
    }
    
}
