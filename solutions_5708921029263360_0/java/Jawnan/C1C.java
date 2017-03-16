import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by Nejc on 08.05.2016.
 */
public class C1C {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++){
            String input[] = br.readLine().split(" ");
            int J = Integer.parseInt(input[0]);
            int P = Integer.parseInt(input[1]);
            int S = Integer.parseInt(input[2]);
            int K = Integer.parseInt(input[3]);
            int[][] jp = new int[J][P];
            int[][] js = new int[J][S];
            int[][] ps = new int[P][S];
            String out = "";
            int result = 0;
            for(int j = 0; j < J; j++){
                for(int p = 0; p < P; p++){
                    for(int s = 0; s < S; s++){
                        if(jp[j][p] == K) break;
                        if(js[j][s] < K && ps[p][s] < K){
                            out += (j+1) + " " + (p+1) + " " + (s+1) + "\n";
                            result++;
                            jp[j][p]++;
                            js[j][s]++;
                            ps[p][s]++;
                        }
                    }
                }
            }
            System.out.println("Case #"+t+": "+result);
            System.out.print(out);
        }
    }
}
