package test;
import java.io.*;
import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
	
	public static void main( String[] args ) throws IOException {		
		Scanner in = new Scanner(new File("in.txt"));
		//Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new FileWriter("out.txt"));
		int caso = 1; int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			BigDecimal r = new BigDecimal(in.next());
			BigDecimal t = new BigDecimal(in.next());
			BigDecimal pi = new BigDecimal("" + Math.acos(-1));
			
			long ini = 0, mid = 1, fim = 10000000000L;
			long cont = fim - ini;
			long step = 0;
			while( cont > 0 ){	
				step = cont/2;
				mid = ini +  step;
				//System.out.println(mid);				
				//System.out.println(mid);				
				BigDecimal m = new BigDecimal(mid);
				BigDecimal temp = (m.add(new BigDecimal(-1))).multiply(m).multiply(new BigDecimal(2));
				BigDecimal resp = (m.multiply(r).multiply(new BigDecimal(2))).add(m).add(temp);
				//temp = 2 * mid * r + mid + 2 * (mid-1) * mid;
				//System.out.println(resp.toString());
				if ( t.compareTo(resp) >= 0){					
					ini = ++mid;
					cont -= step +1;
				} else {
					cont = step;
				}
			}
			//System.out.println("Case #" + caso++ + ": " + (ini-1));
			out.println("Case #" + caso++ + ": " + (ini-1));
		}
		out.flush();
		out.close();
		
	}	
}
