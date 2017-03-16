import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Brattleship {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new File("/Users/seph/Documents/GoogleCodeJam/in_a"));
		
		int testCases = s.nextInt();
		
		for(int i = 1; i<=testCases; i++) {
			int r = s.nextInt();
			int c = s.nextInt();
			int w = s.nextInt();
			 
			int solution = solve(r, c, w);
			
			System.out.println("Case #"+i+": " + solution);
		}
		
		
		
	}
	
	public static int solve(int r, int c, int w) {
		
		if (c == w) {
			return w;
		}
		
		if (c % w == 0) {
			return (c / w) + w - 1;
		}
		
		return (c / w) + w;
		
	}
	
	
}
