package round1C;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {

	public static void main(String[] args) {
		Scanner in;
		PrintWriter out;
		try {
			in = new Scanner(new File("A-small-attempt0.in"));
			out = new PrintWriter("a0.out");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			System.exit(1);
			return;
		}
		
		int numCases = in.nextInt();
		
		for (int t = 1; t <= numCases; t++){
			
			String line=in.next();
			
			String[] parts = line.split("/");
			
			int p = Integer.parseInt(parts[0]);
			int q = Integer.parseInt(parts[1]);
			
			int result = solve(p,q);
			
			if (result==-1){
				out.println("Case #" + t + ": " + "impossible");
			}
			else out.println("Case #" + t + ": " + result);
			
		}
		
		in.close();
		out.close();
		
	}
	
	private static boolean isPowerof2(int a){
		int b = 1;
		while (b<a){
			b*=2;
		}
		return b==a;
	}
	
	private static int solve(int a, int b){
		if (a==0) return -1;
		if (!isPowerof2(b)) return -1;
		if (a==b) return 0;
		int count = 0;
		while (a < b){
			b/=2;
			count++;
		}
		return count;
		
	}

	
}
