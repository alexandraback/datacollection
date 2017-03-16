import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class FairSquare {
	static PrintStream out;
		
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in;
		out = new PrintStream(new File("out.txt"));
		try {
			in = new Scanner(new File(args[0]));
		} catch (IndexOutOfBoundsException e){
			System.out.println("Was expecting path to input file.");
			return;
		} catch (FileNotFoundException e) {
			System.out.println("Could not find the path specified.");
			return;
		}
		//get number of cases
		int cases = in.nextInt();
		for(int i=1;i<=cases;i++){
			long min = in.nextLong();
			long max = in.nextLong();
			
			long minrt = (long) Math.ceil(Math.sqrt(min));
			long maxrt = (long) Math.sqrt(max);
			
			int worthy = 0;
			for(long j=minrt;j<=maxrt;j++){
				if(palindrome(j)){
					long num = j*j;
					if(palindrome(num)){
						worthy++;
					}
				}
			}
			out.println("Case #" + i + ": " + worthy);
		}
	}

	private static boolean palindrome(long j) {
		long oldn = j;
		long newn = 0;
		while(j != 0){
			newn *= 10;
			newn += j%10;
			j /= 10;
		}
		return newn == oldn;
	}
}
