package codejam14;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.Reader;
import java.util.Scanner;

public class A {

    static BufferedReader r;

    public static void main(String[] args) throws IOException {
	    System.setIn(new FileInputStream("input"));
        System.setOut(new PrintStream("output"));

        r = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(r.readLine());
        for(int i = 1; i <= T; ++i) {
            solve(i);
        }
    }

    private static void solve(int caseNum) throws IOException {
        String line = r.readLine();
        int pos = line.indexOf('/');
        long P = Long.parseLong(line.substring(0, pos));
        long Q = Long.parseLong(line.substring(pos+1));
        long gcd = GCD(P,Q);
        P /= gcd;
        Q /= gcd;
        if(!isPow2(Q)) {
        	System.out.println("Case #" + caseNum + ": impossible");
        	return;
        }
        
        int gen = 0;
        while (P/Q < 1) {
        	Q /= 2;
        	gen += 1;
        }
        
        System.out.println("Case #" + caseNum + ": " + gen);
        
    }

	private static boolean isPow2(long rate) {
		while(rate != 1) {
			if(rate % 2 == 1) {
				return false;
			}
			rate /= 2;
		}
		return true;
	}
	
	public static long GCD(long a, long b) {
		   if (b==0) return a;
		   return GCD(b,a%b);
		}
}
