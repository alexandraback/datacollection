import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class fair {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub

		int t = 0;
		Scanner sc = new Scanner(new File("input2.in"));
		t = sc.nextInt();
		for(int i = 0; i < t; i++)
			System.out.println("Case #" + (i+1) + ": " + solve(sc.nextLong(), sc.nextLong()));
			
		
	}
	private static long solve(long a, long b){
		long first;
		long count = 0;
		first = (long) Math.sqrt(a);
		if(first * first != a) first = (first+1);
		for(long i = first;;i++)
		{
			if(isPalindrome(i))
				if(i*i <= b && isPalindrome(i*i))
						count++;
			if(i*i > b) break;
			
		}
		return count;
	}
	private static boolean isPalindrome(long x){
		String nr = Long.toString(x);
		int lg = nr.length();
			for(int i = 0; i <= lg/2 - 1; i++)
				if(nr.charAt(i) != nr.charAt(lg-i-1)) return false;
		return true;
	}
}
