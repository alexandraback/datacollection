import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;


public class Zad1 {

	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("A-large (2).in"));
		PrintWriter out = new PrintWriter(new File("result2.out"));
//		Scanner in = new Scanner(System.in);
		
		
		int T = in.nextInt();
		
		for (int t = 1; t <= T; t++) {
			long A = in.nextLong();
			int n = in.nextInt();
			Long m[] = new Long[n];
			for (int i = 0; i < m.length; i++) {
				m[i] = in.nextLong();
			}
			
			Arrays.sort(m);
			
			long best = Integer.MAX_VALUE;
			
			long curr = 0;
			for (int i = 0; i < m.length; i++) {
				
				int remove = m.length - i;
				best = Math.min(best, curr + remove);
				
				int fail = 0;
				
				while(A <= m[i]){
					long next = A - 1;
					if(next <= 0) {
						fail = 1;
						break;
					}
					A += A - 1;
					curr++;
				}
				
				if(fail == 1) break;
				A += m[i];
				best = Math.min(best, curr + remove - 1);
			}
			
			out.println("Case #"+t+": "+best);
		}
		
		
		
		out.close();
		
	}
	
	

}
