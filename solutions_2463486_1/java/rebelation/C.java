import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class C{
    public static void main(String[] args) throws Exception{
        new C().run();
    }

    private static final long MAX = 100000000000000L;
    ArrayList<Long> fairs = new ArrayList<Long>();

    boolean isPalindrome(char[] s){
        int len = s.length;
        for(int i = 0; i < len/2; i++)
            if(s[i] != s[len-1-i])
                return false;
        return true;
    }

    int count(long v){
        int index = Collections.binarySearch(fairs, v);
        if(index >= 0)
            return index+1;
        else
            return -(index+1);
    }

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available

        long lim = (long)sqrt(Long.MAX_VALUE);
        for(int i = 1; i < 18;i++){
            int figure = (i+1) / 2;
            long start = (long)pow(10, figure-1);
            long end = (long)pow(10, figure);
            for(long j = start; j < end; j++){
                String s = "" + j;
                StringBuilder sb = new StringBuilder(s.substring(0, s.length()-(i%2==1?1:0)));
                s = s + sb.reverse().toString();
                long val = Long.parseLong(s);
                if(lim < val)
                    break;
                val = val * val;
                if(val > MAX)
                    break;
                if(isPalindrome((""+val).toCharArray()))
                    fairs.add(val);
            }
        }

        /*
        for(int i = 0; i < 100 && i < fairs.size(); i++)
            System.out.print(fairs.get(i) + " ");
        System.out.println();
        */

        int T = sc.nextInt();
        for(int o = 1; o <= T; o++){
            System.out.printf("Case #%d: ", o);
            long A = sc.nextLong();
            long B = sc.nextLong();
            System.out.println(count(B) - count(A-1));
        }
    }
}
