import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;


public class Zad1 {

	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("A-small-attempt0 (1).in"));
		PrintWriter out = new PrintWriter(new File("A-small-attempt0 (1).out"));
		
		int T = in.nextInt();
		
		for (int t = 1; t <= T; t++) {
			long r = in.nextLong();
			long n = in.nextLong();
			
			long count = 0;
			
			while(true){
				long paint = (r+1)*(r+1) - r*r;
				if(paint <= n){
					n -= paint;
					r += 2;
					count++;
				}
				else break;
			}
			System.out.println("Case #"+t+": " + count);
			out.println("Case #"+t+": " + count);
		}
		
		out.close();
		
	}
	
	

}
