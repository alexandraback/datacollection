import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by Nejc on 16.04.2016.
 */
public class A1A {
    public static void main(String[]args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++){
            char[] S = br.readLine().toCharArray();
            char left = S[0];
            String result = S[0]+"";
            for(int i = 1; i < S.length; i++){
                if(S[i]>=left){
                    left = S[i];
                    result = S[i] + result;
                }
                else{
                    result += S[i];
                }
            }
            
            System.out.println("CASE #" + t + ": " + result);
        }
    }
}
