import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class A{
    public static void main(String[] args) throws Exception{
        new A().run();
    }

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available

        int T = sc.nextInt();
        for(int o = 1; o <= T; o++){
            System.out.printf("Case #%d: ", o);
            long r = sc.nextLong();
            long t = sc.nextLong();
            int ans = 0;
            t -= (r+1)*(r+1) - r*r;
            r++;
            //if(t >= r*r){ans++; t -= r*r;}
            while(t >= 0){
                ans++;
                t -= (r+2)*(r+2) - (r+1)*(r+1);
                r += 2;
            }
            System.out.println(ans);
        }
    }
}
