import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by Nejc on 09.04.2016.
 */
public class D {
    public static void main(String[]args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++){
            String[] input = br.readLine().split(" ");
            int K = Integer.parseInt(input[0]);
            int C = Integer.parseInt(input[1]);
            int S = Integer.parseInt(input[2]);
            System.out.print("CASE #" + t + ":");
            for(int i = 1; i <= K; i++){
                System.out.print(" " + i);
            }
            System.out.println();
        }
    }
}
