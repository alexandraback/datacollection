import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class AO {

	public static void main(String[] args) throws FileNotFoundException {
		
		
		Scanner in = new Scanner(new File("c:\\codejam2015\\a\\A-small-attempt2.in"));
		PrintWriter out = new PrintWriter(new File(
				"c:\\codejam2015\\a\\small.out"));
		int numTests = in.nextInt();
		for (int i = 1; i <= numTests; i++) {
			solve(i, in, out);
		}

		out.close();
	}
	private static void solve(int testNum, Scanner in, PrintWriter out) {

		long start = System.currentTimeMillis();
		
		long max = in.nextLong();
		
		long l = max;
		long count = 0;
		
		while(l != 0) {
			
			int rem = (int)(l % 10);
			
			if(rem > 1) {
				count += (rem - 1);
				l = l - (rem - 1);
				long flip = flip(l);
				if(l > flip) { //11, 101 etc)
					l = flip;
					count++;
				} else {
					l--;
					count++;
				}
			} else {
				l--;
				count++;
			}
			
		}
		
		out.println("Case #" + testNum + ": " + count);
		
		System.out.println("time taken = " + (System.currentTimeMillis() - start));

	}
	
	private static long flip(long l) {
		long reverse = 0;
        long remainder = 0;
        do{
            remainder = l % 10;
            reverse = reverse*10 + remainder;
            l = l/10;
          
        }while(l > 0);
      
        return reverse;
	}
	    
	    
}
