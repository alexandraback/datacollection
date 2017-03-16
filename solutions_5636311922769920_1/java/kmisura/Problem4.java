import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Problem4 {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("data/D-large.in"));
        PrintWriter pw = new PrintWriter(new File("data/D-large.out"));
        int T = sc.nextInt();
        for(int t = 1; t<=T; t++){
            int k = sc.nextInt();
            int c = sc.nextInt();
            int s = sc.nextInt();
            List<Long> res = solve(k, c, s);
            if(res == null){
                pw.println("Case #" + t + ": IMPOSSIBLE");
            } else {
                pw.print("Case #" + t + ": ");
                for(long x : res){
                    pw.print((x+1) + " ");
                }
                pw.println();
            }
        }
        sc.close();
        pw.close();
    }
    
    private static long power(long b, long e){
        long ret = 1;
        while(e-->0){
            ret *= b;
        }
        return ret;
    }

    private static List<Long> solve(int k, int c, int s){
        List<Long> ret = new ArrayList<Long>();
        int pow = c-1;
        long tot = 0;
        for(int i=0;i<k;i++){
            tot += i * power(k, pow);
            if(pow == 0 || i==k-1){
                ret.add(tot);
                tot = 0;
                pow = c-1;
            } else {
                pow--;
            }
        }
        if(ret.size() <= s){
            return ret;
        } else {
            return null;
        }
    }
}
