import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


/**
 * for the  challenge.
 * Google code jam 2013 round 1c.
 * @author Jay
 *
 */
public class Consonants {
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc;
		try {
			sc = new Scanner(new File(args[0]));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return;
		}
		String totalProblems = sc.nextLine();
		int total = Integer.parseInt(totalProblems);
		int pos = 1;
		for (;pos <= total;pos++) {
			String size = sc.nextLine();
			String[] sizeArr = size.split(" ");
			String r = (sizeArr[0]);
			double n = Double.parseDouble(sizeArr[1]);
			int result = processString(r,n);
			
			System.out.println("Case #"+pos+": "+result);
		}
	}
	
	private static int processString(String r,double n) {
		if (r.length() < n) {
			return 0;
		}
		int count = 0;
		for (int i = 0; i < r.length();i++) {
			count += aConsecutive(r.substring(i), n);
		}
		return count + processString(r.substring(0, r.length()-1), n);
	}
	
	private static int aConsecutive(String substring, double n) {
		if (hasConsecutive(substring, n)) {
			return 1;
		}
		return 0;
	}
	
	private static boolean hasConsecutive(String substring, double n) {
		int tally = 0;
		for (int i = 0; i < substring.length(); i++) {
			if (isConsonant(substring.charAt(i))) {
				tally++;
				if (tally >= n) {
					return true;
				}
			} else {
				tally = 0;
			}
		}
		return false;
	}

	private static boolean isConsonant(char charAt) {
		return (charAt != 'a' && charAt != 'e' && charAt != 'i' && charAt != 'o' && charAt != 'u');
	}
}
