import java.util.*;
import java.io.*;

public class A {
	static double[] p;
	static int A,B;
	public static void main(String[] args) throws Exception{
		Scanner reader = new Scanner(new File("a-small.in"));
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
			for(int i = 1; i <= a; i++){
				double correct = 1;
				for(int j = 0; j < i; j++)
					correct *= p[j];
				strat2 = Math.min(a-i + (b-i+1)*correct + (b-i+1+B+1)*(1-correct), strat2);
			}
			double strat3 = 2 + B;
	
			System.out.println("Case #"+t+": "+ Math.min(Math.min(strat1, strat2), strat3));
		}
	}
	
	//	   2. Hit "backspace" some number of times, deleting the last character(s) I typed, and then complete the password and press "enter" as in option 1. If one of the characters I didn't delete was wrong, I'll have to retype the whole thing and press "enter", knowing I'll get it right the second time.
	
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
