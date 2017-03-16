import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

/**
 * Created by mohamedelsharnouby on 4/9/2016.
 */
public class Jamcoin {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = in.nextInt();
        for (int i = 1; i <= t; ++i) {
            int N = in.nextInt();
            int J = in.nextInt();
            HashMap<String, List<Long>> jams = new HashMap<>();

            for (long j = 0; j < Math.pow(2, N - 2); j++) {
                StringBuilder binary = new StringBuilder(Long.toBinaryString(j));
                for(int k = binary.length(); k < N - 2; k++) {
                    binary.insert( 0, '0' );
                }
                String jam = "1" + binary + "1";

                bases:
                for (int base = 2; base <= 10; base++) {
                    BigInteger num = new BigInteger(jam, base);

                    if (num.mod(BigInteger.valueOf(2)).equals(BigInteger.ZERO)) {
                        if (! jams.containsKey(jam)) jams.put(jam, new ArrayList<Long>());
                        jams.get(jam).add(2L);
                        continue;
                    }
                    //if not, then just check the odds
//                    long smallest = Math.min(10, num.intValue());
                    for(long k=3;k<1000;k+=2) {
                        if(num.mod(BigInteger.valueOf(k)).equals(BigInteger.ZERO)) {
                            if (! jams.containsKey(jam)) jams.put(jam, new ArrayList<Long>());
                            jams.get(jam).add(k);
                            continue bases;
                        }
                    }

                    if (jams.containsKey(jam)) jams.remove(jam);
                    break bases;
                }

                if (jams.size() == J) break;
            }

            System.out.println("Case #" + i + ":");
            for (String jam: jams.keySet()) {
                System.out.print(jam);
                for (Long divisor: jams.get(jam)) {
                    System.out.print(" " + divisor);
                }
                System.out.println();
            }
        }
    }
}
