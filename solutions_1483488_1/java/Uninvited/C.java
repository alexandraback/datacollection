import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;


public class C {
	
	public static void main(String[] args) {
		
		try {
			Scanner in = new Scanner(new File("C.in"));
			BufferedWriter writer = new BufferedWriter(new FileWriter(new File("C.out")));
			
			int T = in.nextInt();
			in.nextLine();
			
			for (int i=0; i<T; i++) {
				
				int A = in.nextInt();
				int B = in.nextInt();
				
				long res = 0;
				
				for (int X=A; X<B; X++) {
					
					int D = digits(X);
					HashSet<Integer> set = new HashSet<Integer>();
					
					for (int j=1; j<D; j++) {
						int C = moveLast(X, j);
						
						if (C > X && C <= B && !(set.contains(C))) {
							set.add(C);
							res++;
							//System.out.println("X="+X + ",     C="+C);
						}
					}
				}
				
				writer.append("Case #" + (i+1) + ": " + res + "\n");
			}
			
			writer.close();
			
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static int moveLast(int X, int digits) {
		
		int last = 0;
		int p = 1;
		int p2 = 1;
		
		for (int i=0; i<digits; i++) p *= 10;
		
		last = X % p;
		
		while ((p2*10)<=X) p2 *= 10;
		
		return last*(p2/p)*10 + (X / p); 
	}
	
	public static int digits(int X) {
		int k = 0;
		
		while (X > 0) {
			X /= 10;
			k++;
		}
		
		return k;
	}
}
