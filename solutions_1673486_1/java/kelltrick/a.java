import java.io.*;
import java.util.*;

public class a{
	public static void main(String[] args){
		Scanner sc= new Scanner(System.in);
		int tc = sc.nextInt();
		
		for(int c = 0; c < tc; c++){
			System.out.print("Case #" + (c+1) + ": ");
			new a(sc);
		}
	}
	public a(Scanner sc){
		int a = sc.nextInt();
		int b = sc.nextInt();
		double[] p = new double[a];
		double[] ary = new double[a];
		p[0] = sc.nextDouble();
		ary[0] = p[0];
		for(int i = 1 ; i < a; i++){
			p[i] = sc.nextDouble();
			ary[i] = p[i] * ary[i-1];
		}
		
		double abort = (double)b+2;		
		double best = abort;
		for(int i = a-1; i >= 0; i--){
			int keysIfCorrect = b-i + (a-1-i);
			int keysIfInCorrect = b+1+keysIfCorrect;
			double expected = (ary[i] * keysIfCorrect) + ((1-ary[i])*keysIfInCorrect);
			best = Math.min(best,expected);
		}
		
		System.out.printf("%.6f\n",best);		
	}

}
