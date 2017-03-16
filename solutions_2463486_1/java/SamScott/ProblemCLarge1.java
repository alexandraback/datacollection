package qualificationRound;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;

public class ProblemCLarge1 {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("qualificationRound/C-large-1.in"));
		PrintWriter out = new PrintWriter(new File("qualificationRound/out.txt"));
		
		int T = sc.nextInt();
		sc.nextLine();
		
		for (int tc = 1; tc <= T; tc++) {
			
			BigInteger A = new BigInteger(sc.next());
			BigInteger B = new BigInteger(sc.next());
		//	System.out.println(A+" "+B);
		//	System.out.println((int)Math.round(A.toString().length()/2.0)+" "+(int)Math.round(B.toString().length()/2.0));
			LinkedList<String> l = getPalindromes((int)Math.round(A.toString().length()/2.0),(int)Math.round(B.toString().length()/2.0),false);
			int count = 0;
			Iterator<String> i = l.iterator();
			while (i.hasNext()) {
				BigInteger current = new BigInteger(i.next());
				//System.out.println(current);
				BigInteger square = current.multiply(current);
				if (square.compareTo(A) >= 0 && square.compareTo(B) <= 0 && isPalindrome(square.toString()))
					count++;
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
	
	public static LinkedList<String> getPalindromes(int minLength, int maxLength, boolean noTwos) {
		//System.out.println(minLength+" "+maxLength);
		LinkedList<String> list = new LinkedList<String>();
		LinkedList<String> foundList = new LinkedList<String>();
		list.add(""); list.add("0"); list.add("1"); 
		if (!noTwos)
			list.add("2");
		if (minLength == 1)
			foundList.add("3");
		while (!list.isEmpty()) {
			String current = list.remove();
		//	System.out.println(current+": "+current.length());
			int l = current.length();
			if (l >= minLength)
				foundList.add(current);
			if (l+2 <= maxLength) {
				list.add("0"+current+"0");
				list.add("1"+current+"1");
				if (!noTwos)
					list.add("2"+current+"2");
			}
		}
		// cull the list
		while (!foundList.isEmpty()) {
			String current = foundList.remove();
			//System.out.println(current);
			if (current.charAt(0) != '0')
				list.add(current);
		}
		return list;
	}

	public static boolean isPalindrome(String s) {
		for (int i=0; i<s.length()/2; i++)
			if (s.charAt(i) != s.charAt(s.length()-i-1))
				return false;
		return true;
	}
}