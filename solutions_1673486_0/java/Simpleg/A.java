// this is for GoogleCodeJam  A
import java.util.*;
import java.io.*;

public class A{

	public static void main(String[] args) throws IOException {
	
		//
		Scanner in = new Scanner(new File("A-small-attempt2.in"));
		FileWriter fw = new FileWriter("A-small.out");
		//
		/*
		Scanner in = new Scanner(new File("A-large-attempt0.in"));
		FileWriter fw = new FileWriter("A-small.out");
		*/
		int T = in.nextInt();
		for (int cases = 1; cases <= T; cases++){
			fw.write("Case #" + cases + ": ");
			int A = in.nextInt();
			int B = in.nextInt();
			double AA = (double)A;
			double BB = (double)B;
			double[] pro = new double[A];
			double[] pro1 = new double[A];
			for(int i = 0; i < A; i++){
				pro[i] = in.nextDouble();
				pro1[i] = 1 - pro[i];
			}
			double best = BB + 1 + 1;
			double[] right = new double[A];			
			right[0] = pro[0];
			
			for(int i = 1; i < A; i++){
				right[i] = right[i - 1] * pro[i];
			}
			
			double c = BB - AA + 1;
			for(int i = 0; i < A; i++){				
				double good = c * right[A - 1 - i] + (c + BB + 1) * (1 - right[A - 1 - i]);
				if(good < best) best = good;
				c += 2;			
			}
			
			
			fw.write(best + "\n");			
		}
		fw.flush();
		fw.close();	
	}
	
	public static long gcd(int a, int b){
		while( b % a != 0){
			int temp = b % a;
			b = a;
			a = temp;
		}
		return (long)a;
	}
}