import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class mainA {

	/**
	 * @param args
	 */
	public static void main(String[] args) {	
		try(Scanner sc = new Scanner(new File("./A-small-attempt0.in"))) {
			System.setOut(new PrintStream(new File("A-small-attempt0.out")));
			
			int T = sc.nextInt();
			
			for (int t = 1; t <= T; t++) {
				int A = sc.nextInt(), B = sc.nextInt();
				double[] p = new double[A];
			
				for (int i = 0; i < A; i++) p[i] = sc.nextDouble();
				
				int mask = 0;
				int size = (int) Math.pow(2, A);
				
				double keepTypingExpected = 0;
				double backOnceExpected = 0;
				double backTwiceExpected = 0;
				double enterExpected = 0;
				
				while(mask<size) {
					boolean[] g = new boolean[A];
					int mask2 = 1;
					for (int i = 0; i < g.length; i++) {
						g[i] = (mask&mask2)!=0;
						mask2 *= 2;
					}
					
					double probability = 1;
					for (int i = 0; i < g.length; i++) {
						if(g[i]) {
							probability *= p[i];							
						} else {
							probability *= (1-p[i]);
						}
					}
					
					int keepTyping = 0;
					if(mask==size-1) {
						keepTyping += B-A+1;								
					} else {
						keepTyping += 2*B-A+2;
					}
					keepTypingExpected += keepTyping * probability; 
					
					int backOnce = 0;
					boolean onlyLastPossiblyWrong = true;
					for (int i = 0; i < g.length-1; i++) {
						if(!g[i]) {
							onlyLastPossiblyWrong = false;
							break;
						}
					}
					if(onlyLastPossiblyWrong) {
						backOnce += 2 + B-A + 1;
					} else {
						backOnce += 2 + B-A + 1 + B + 1;
					}
					backOnceExpected += backOnce * probability; 
					
					
					int backTwice = 0;
					boolean onlyLastTwoPossiblyWrong = true;
					for (int i = 0; i < g.length-2; i++) {
						if(!g[i]) {
							onlyLastTwoPossiblyWrong = false;
							break;
						}
					}
					if(onlyLastTwoPossiblyWrong) {
						backTwice += 4 + B-A + 1;
					} else {
						backTwice += 4 + B-A + 1 + B + 1;
					}
					backTwiceExpected += backTwice * probability;
					
					enterExpected += (B+2) * probability; 
					
					
					mask++;
				}
				
				double best =  Math.min(keepTypingExpected, Math.min(backOnceExpected, Math.min(backTwiceExpected, enterExpected)));
				System.out.format("Case #%d: %f%n", t, best);
			}
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

	}

}
