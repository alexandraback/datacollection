
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    static BigInteger Ten = BigInteger.valueOf(10);
    static BigInteger Two = BigInteger.valueOf(2);
    static int maxd;
    static int[] cnt = new int[105];
    static ArrayList<BigInteger> ans = new ArrayList<>();

    static boolean isPalindrome(BigInteger x) {
        String s = x.toString();
        for (int i = 0, j = s.length() - 1; i <= j; i++, j--) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
        }
        return true;
    }

    static BigInteger make(BigInteger x, int type){
        BigInteger ret = x;
        String s = ret.toString();
        if(type == 0){
            for(int i = s.length() - 1; i >= 0; --i){
                ret = ret.multiply(Ten).add(BigInteger.valueOf(s.charAt(i) - '0'));
            }
        }else{
            for(int i = s.length() - 2; i >= 0; --i){
                ret = ret.multiply(Ten).add(BigInteger.valueOf(s.charAt(i) - '0'));
            }
        }
        return ret;
    }
    
    static void dfs(BigInteger now, int depth) {
        if (depth == maxd) {
            BigInteger M = make(now, 0);
            BigInteger M2 = M.multiply(M);
           
            boolean flag = false;
            if (isPalindrome(M2)) {
                ans.add(M2);
                cnt[M2.toString().length()]++;
                flag = true;
            }
            M = make(now, 1);
            M2 = M.multiply(M);
            if (isPalindrome(M2)) {
                ans.add(M2);
                cnt[M2.toString().length()]++;
                flag = true;
            }
//            if(flag){
//                System.out.println(now);
//            }
            return;
        }
        for (int i = 0; i < 3; ++i) {
            if (depth == 0 && i == 0) {
                continue;
            }
            if (depth != maxd - 1 && i == 2){
                continue;
            }
            BigInteger nxt = now.multiply(Ten).add(BigInteger.valueOf(i));
            dfs(nxt, depth + 1);
        }
    }

    static int calc(BigInteger x){
        int l = 0, h = ans.size() - 1;
        while(l < h){
            int mid = (l + h) >> 1;
            if(ans.get(mid).compareTo(x) > 0){
                h = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
    
    public static void main(String[] args) throws java.io.IOException{
//        ans.add(BigInteger.valueOf(9));
//        for(int i = 0; i < 105; ++i){
//            cnt[i] = 0;
//        }
//        cnt[1] = 1;
//        for(maxd = 1; maxd <= 26; ++maxd){
//            dfs(BigInteger.ZERO, 0);
//        }
//        BigInteger now1 = BigInteger.valueOf(20), now = BigInteger.ONE;
//        for(int i = 3; i <= 51; ++i){
//            now1 = now1.multiply(Ten);
//            BigInteger t = now1.add(Two);
//            ans.add(t.multiply(t));
//            if(i % 2 == 1){
//                now = now.multiply(Ten);
//                t = now1.add(now).add(Two);
//                ans.add(t.multiply(t));
//            }
//        }
//        
//        System.out.println(ans.size());
//        Collections.sort(ans);
//        System.out.println(ans.get(ans.size() - 1).toString().length());
        
        Scanner in2 = new Scanner(new FileInputStream("num.out"));
        Scanner in = new Scanner(new FileInputStream("C-small-attempt0.in"));
//        PrintWriter out = new PrintWriter("num.out");
//        out.println(ans.size());
//        for(BigInteger x:ans){
//            out.println(x);
//        }
//        out.close();
        int n = in2.nextInt();
        for(int i = 0; i < n; ++i){
            BigInteger r = in2.nextBigInteger();
            ans.add(r);
        }
        int T, nCase = 0;

        PrintWriter out = new PrintWriter("C-small-attempt0.out");
        T = in.nextInt();
        System.out.println(calc(BigInteger.ZERO));
        while(++nCase <= T){
            out.print("Case #" + nCase + ": ");
            BigInteger A, B;
            A = in.nextBigInteger();
            B = in.nextBigInteger();
            out.println(calc(B) - calc(A.subtract(BigInteger.ONE)));
        }
        in.close();
        out.close();
    }
}
