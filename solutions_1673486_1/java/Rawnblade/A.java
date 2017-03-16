import java.util.*;
import java.io.*;
import java.math.BigDecimal;

public class A {
	static double[] p;
	static int A,B;
	public static void main(String[] args) throws Exception{
		Scanner reader = new Scanner(new File("a-large.in"));
		int times = reader.nextInt();
		for(int t = 1; t <= times; t++){
			int a = reader.nextInt(); A = a;
			int b = reader.nextInt(); B = b;
			int c = b-a;
			
			double[] p = new double[a];
			for(int i = 0; i < a; i++)
				p[i] = reader.nextDouble(); //p correct
			
			double pC = 1;
			for(int i = 0; i < a; i++)
				pC *= p[i];
			
			double strat1 = (c+1)*pC + (c+1+B+1)*(1-pC);
			double strat2 = 1e9;
			double backspace = 0;
			for(int i = a-1; i >= 0; i--){
				backspace++;
				pC /= p[i];
				
				strat2 = Math.min(backspace + (B-i+1)*pC + (B-i+1+B+1)*(1-pC), strat2);
			}
			double strat3 = 2 + B;
//			System.out.println(strat1 + " " + strat2 + " " + strat3);
			System.out.println("Case #"+t+": "+ Math.min(Math.min(strat1, strat2), strat3));
		}
	}
	
}

/*
3
2 5
0.6 0.6
1 20
1
3 4
1 0.9 0.1

Case #1: 7.000000
Case #2: 20.000000
Case #3: 4.500000
*/
