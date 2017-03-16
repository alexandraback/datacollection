package a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

    public void solve() throws IOException {
        Scanner in = new Scanner(new BufferedReader(new FileReader("A-small-attempt0.in")));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("a.out")));
        //PrintWriter out = new PrintWriter(System.out);
        int T = in.nextInt();
        
        for(int ii = 0; ii < T; ii++)
        {
            out.print("Case #" + (ii+1) + ": ");
            int N = in.nextInt();
            long res[] = new long[N+1];
            res[1] = 1;
            for(int i = 2; i <= N; i++)
            {
                res[i] = res[i-1]+1;
                int turn = this.turn(i);
                if(turn < i)
                    res[i] = Math.min(res[turn]+1, res[i]);
            }
            out.println(res[N]);
        }
        
        out.close();
        in.close();
    }

    public static void main(String... args) throws IOException {
        A a = new A();
        a.solve();
    }

    private int turn(int i) {
        if(i % 10 == 0)
            return i;
        int res = 0;
        int rem = i;
        while(0 < rem)
        {
            res *= 10;
            res += rem % 10;
            rem /= 10;            
        }
        if(res == 0)
            return i;
        else
            return res;
    }

}
