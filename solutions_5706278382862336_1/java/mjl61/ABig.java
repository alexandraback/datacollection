package OneC;

import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class ABig {

    Scanner sc = new Scanner(System.in);
    int T, i;
    BigInteger P, Q;
    
    public static void main(String[] args) throws Exception {
        System.setIn(new FileInputStream(new File("A-large.in")));
        System.setOut(new PrintStream(new File("A.out")));
        new ABig().run();
    }
    
    void run(){
        T = sc.nextInt();
        sc.nextLine();
        for (i=1; i<=T; i++){
            String[] spl = sc.nextLine().split("/");
            P = new BigInteger(spl[0]); //Integer.parseInt(spl[0]);
            Q = new BigInteger(spl[1]);
            BigInteger d = gcd(P, Q);
            if (d.compareTo(BigInteger.valueOf(0)) != 0){
                P = P.divide(d);
                Q = Q.divide(d);
            }

            if (!isPowerOfTwo(Q)){
                print(-1);
                continue;
            }
            
            int x = 1;
            while (!checkPoss()){
                Q = Q.divide(BigInteger.valueOf(2));
                x++;
            }
            print(x);
        }
        
    }
    
    void print(int r){
        System.out.println("Case #" + i + ": " + (r == -1 ? "impossible" : r));
    }
    
    boolean isPowerOfTwo(BigInteger x){
        return (x.and(x.subtract(BigInteger.valueOf(1)))).equals(BigInteger.valueOf(0));
    }
    
    boolean checkPoss(){
        return P.multiply(BigInteger.valueOf(2)).compareTo(Q) >= 0;
    }
    
    BigInteger gcd(BigInteger a, BigInteger b){
        if (b == BigInteger.valueOf(0)) return a;
        return gcd(b, a.mod(b));
    }

}
