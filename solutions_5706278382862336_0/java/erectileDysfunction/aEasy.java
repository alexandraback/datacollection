import java.util.Scanner;
/**
 * Write a description of class aEasy here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class aEasy
{
   public static void main(String[] args){
       Scanner sc = new Scanner(System.in);
       int cases = sc.nextInt();
       for(int z = 1; z <= cases; z++){
           String s = sc.next();
           String[] array = s.split("/");
           long a = Long.parseLong(array[0]);
           long b = Long.parseLong(array[1]);
           long at = a;
           long bt = b;
           boolean valid = true;
           while(gcd(a, b) != 1){
               long c = gcd(a, b);
               a /= c;
               b /= c;
            }
        int ans = 0;
        int minCount = -1;
        while (ans < 40 && a != 0){
            a *= 2;
            ans++;
            if (a >= b){
                if (minCount ==-1){
                    minCount = ans;
                }
                a -= b;
            }
        }
           if(ans == 40){
               System.out.println("Case #" + z + ": impossible");
            } else {
           System.out.println("Case #" + z + ": "+ans(at, bt));
        }
    }
    
}
public static int ans(long a, long b){
    double c = (1.0*a)/(1.0*b);
    double base = .5;
    int ans = 1;
    while(base > c){
        base/= 2.0;
        ans++;
    }
    return ans;
}
public static long gcd(long p, long q) {
        if (q == 0) return p;
        else return gcd(q, p % q);
    }
public static int log2(long n){
    if(n <= 0) throw new IllegalArgumentException();
    return 63 - Long.numberOfLeadingZeros(n);
}
public static int log2(int n){
    if(n <= 0) throw new IllegalArgumentException();
    return 31 - Integer.numberOfLeadingZeros(n);
}
}
