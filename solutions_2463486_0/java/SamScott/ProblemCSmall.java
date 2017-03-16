package qualificationRound;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemCSmall {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("qualificationRound/C-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("qualificationRound/out.txt"));
		
		int T = sc.nextInt();
		sc.nextLine();
		
		for (int tc = 1; tc <= T; tc++) {
			
			int A = sc.nextInt();
			int B = sc.nextInt();
			int count = 0;
			for (int i=(int)Math.sqrt(A); i<=Math.sqrt(B); i++) {
				int target = i*i;
				if (target >= A && target <= B && isPalindrome(i) && isPalindrome(target)) {
					count++;
					System.out.println(i+": "+i*i);
				}
			}
			printSolution(out, tc, ""+count);
		}
		out.close();
		sc.close();
	}

	public static void printSolution(PrintWriter out, int tc, String soln) {
		out.println("Case #"+tc+": "+soln);
		out.flush();
		System.out.println("Case #"+tc+": "+soln);
		
	}
	
	public static boolean isPalindrome(long n) {
		String s = ""+n;
		for (int i=0; i<s.length()/2; i++)
			if (s.charAt(i) != s.charAt(s.length()-i-1))
				return false;
		return true;
	}
}