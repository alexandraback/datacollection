import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class B{
    public static void main(String[] args) throws Exception{
        new B().run();
    }

    int A, B, K;

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available
        int T = sc.nextInt();

        for(int o = 1; o <= T; o++){
            System.out.printf("Case #%d: ", o);
            A = sc.nextInt();
            B = sc.nextInt();
            K = sc.nextInt();
            long ans = 0;
            for(int i = 0; i < A; i++)
                for(int j = 0; j < B; j++)
                    if((int)(i&j) < K)
                        ans++;
            System.out.println(ans);
        }
    }
}
