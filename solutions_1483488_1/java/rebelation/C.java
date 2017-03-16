import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class C{
    public static void main(String[] args) throws Exception{
        new C().run();
    }

    int A, B;

    int calc(int val){
        String s = "" + val;
        int len = s.length();
        HashSet<Integer> hs = new HashSet<Integer>();
        for(int i = 1; i < len; i++){
            int rev = Integer.parseInt(s.substring(i) + s.substring(0, i));
            if(rev > val && rev <= B)
                hs.add(rev);
        }
        return hs.size();
    }

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available
        int T = sc.nextInt();
        for(int o = 1; o <= T; o++){
            A = sc.nextInt();
            B = sc.nextInt();
            long ans = 0;
            for(int i = A; i <= B; i++)
                ans += calc(i);
            System.out.printf("Case #%d: ", o);
            System.out.println(ans);
        }
    }
}
