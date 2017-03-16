package OneC;

import java.util.*;
import java.io.*;

public class A {

    Scanner sc = new Scanner(System.in);
    int T, P, Q, i;
    
    public static void main(String[] args) throws Exception {
        System.setIn(new FileInputStream(new File("A-small-attempt1.in")));
        System.setOut(new PrintStream(new File("A.out")));
        new A().run();
    }
    
    void run(){
        T = sc.nextInt();
        sc.nextLine();
        for (i=1; i<=T; i++){
            String[] spl = sc.nextLine().split("/");
            P = Integer.parseInt(spl[0]);
            Q = Integer.parseInt(spl[1]);
            int d = gcd(P, Q);
            if (d > 1){
                P /= d;
                Q /= d;
            }
            if (!isPowerOfTwo(Q)){
                print(-1);
                continue;
            }
            
            int x = 1;
            while (!checkPoss()){
                Q /= 2;
                x++;
            }
            print(x);
        }
        
    }
    
    void print(int r){
        System.out.println("Case #" + i + ": " + (r == -1 ? "impossible" : r));
    }
    
    boolean isPowerOfTwo(int x){
        return (x & (x-1)) == 0;
    }
    
    boolean checkPoss(){
      //  System.out.println((P*2) + " | " + Q);
        return P*2 >= Q;
    }
    
    int gcd(int a, int b){
        if (b == 0) return a;
        return gcd(b, a % b);
    }

}
