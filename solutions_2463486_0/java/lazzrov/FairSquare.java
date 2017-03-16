import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;


public class FairSquare {

	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("C-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("fairsquare.out"));
		
	
		int T = in.nextInt();
		
		long limit = 20102;
		
		for (int t = 1; t <= T; t++) {
			long A = in.nextLong();
			long B = in.nextLong();
			
			int count = 0;
			for (int i = 1; i <= limit; i++) {
				if(palindrome(i) && palindrome(i*i)){
					long value = i*i;
//					System.out.println(i + " " + i*i);
					if(value >= A && value <= B){
						count++;
					}
				}
			}
			out.println("Case #" + t + ": " + count);
			
		}
		
		out.close();
		
	}

	private static boolean palindrome(long i) {
		char c[] = Long.toString(i).toCharArray();
		for (int j = 0; j < c.length; j++) {
			if(c[j] != c[c.length - 1 - j]) {
				return false;
			}
		}
		return true;
	}


}
