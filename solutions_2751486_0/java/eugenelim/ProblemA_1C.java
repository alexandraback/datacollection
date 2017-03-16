import java.io.*;
import java.util.*;

/*
 * Round 1C Problem A: Consonants
 */
public class ProblemA_1C {
	public static int solve(String name, int n) {
		boolean[] consonants = new boolean[name.length()];
		for (int i=0; i<consonants.length; i++) {
			char cur = name.charAt(i);
			if (cur != 'a' && cur != 'e' && cur != 'i' && cur != 'o' && cur != 'u') {
				consonants[i] = true;
			} else {
				consonants[i] = false;
			}
		}
		int total = 0;
		for (int l=n; l<=consonants.length; l++) {
			for (int start=0; start<=consonants.length-l; start++) {
				int end = start + l;
				if (end > consonants.length) {
					break;
				}
				for (int i=start; i<end; i++) {
					boolean consec = true;
					if (i + n > end) {
						break;
					}
					for (int j=i; j<i+n; j++) {
						if (!consonants[j]) {
							consec = false;
							break;
						}
					}
					if (consec) {
						 total++;
						 break;
					}
				}
			}
		}
		return total;
	}
	
	public static void main(String[] args) {
		try {
			// Init Scanner / Writer
			String filename = "A-small-attempt0";
			Scanner sc = new Scanner(new File(filename + ".in"));
			BufferedWriter out = new BufferedWriter(new FileWriter(filename + ".out"));
			
			// Start reading file
			int T = sc.nextInt();
			for (int i=1; i<=T; i++) {
				sc.nextLine();
				String name = sc.next();
				int n = sc.nextInt();
				out.write("Case #");
				out.write(Integer.toString(i));
				out.write(": ");
				out.write(Integer.toString(solve(name, n)));
				out.write("\n");
			}
			out.close();
			sc.close();
		} catch (Exception e) {
			System.out.println(e);
		}
	}

}
