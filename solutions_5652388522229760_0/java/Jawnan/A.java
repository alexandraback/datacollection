import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by Nejc on 09.04.2016.
 */
public class A {
    public static void main(String[]args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++){
            int N = Integer.parseInt(br.readLine());
            if(N == 0){
                System.out.println("Case #" + t + ": INSOMNIA");
                continue;
            }
            boolean digits[] = new boolean[10];
            boolean check;
            int x = 0;
            do{
                x++;
                int cur = x*N;
                while(cur > 0){
                    digits[cur%10] = true;
                    cur /= 10;
                }
                check = false;
                for(int i = 0; i < 10; i++){
                    if(!digits[i]) check = true;
                }
            }while(check);
            
            System.out.println("Case #" + t + ": " + x*N);
        }
    }
}
