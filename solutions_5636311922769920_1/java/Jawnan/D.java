import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by Nejc on 09.04.2016.
 */
public class D {
    public static void main(String[]args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long T = Integer.parseInt(br.readLine());
        for(long t = 1; t <= T; t++){
            String[] input = br.readLine().split(" ");
            long K = Integer.parseInt(input[0]);
            long C = Integer.parseInt(input[1]);
            long S = Integer.parseInt(input[2]);
            long needed = (long)Math.ceil(1.0*K/C);
            if(S < needed){
                System.out.println("Case #" + t + ": IMPOSSIBLE");
                continue;
            }
            System.out.print("Case #" + t + ":");
            for(long i = 0; i < needed; i++){
                long current = i*C;
                long target = current + 1;
                if(target == K)target--;
                for(long c = 1; c < C; c++){
                    current *= K;
                    current += target;
                    target++;
                    if(target==K)target--;
                }
                System.out.print(" " + (current + 1));
            }
            System.out.println();
        }
    }
}
