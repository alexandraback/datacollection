import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;


public class ProblemB {
	static int count;
	
	static void shorten(String[] s) {
		for (int j = 0; j < s.length; j++) {
			String str = s[j];
			String n = str.substring(0, 1);
			for (int i = 1; i < str.length(); i++) {
				if (n.charAt(n.length() - 1) == str.charAt(i)) {
					continue;
				}
				n += Character.toString(str.charAt(i));
			}
			s[j] = n;
		}
	}
	
	static boolean valid(String s) {
		HashSet<Character> hs = new HashSet<Character>();
		char prev = s.charAt(0);
		hs.add(prev);
		//System.out.print(s);
		for (int i = 1; i < s.length(); i++) {
			if (prev == s.charAt(i)) {
				continue;
			}
			if (hs.contains(s.charAt(i))) {
				//System.out.println(" false " + i);
				return false;
			}
			hs.add(s.charAt(i));
			prev = s.charAt(i);
//			boolean y = true;
//			char c = s.charAt(i);
//			for (int j = i + 1; j < s.length(); j++) {
//				if (s.charAt(j) != c) {
//					y = false;
//					continue;
//				}
//				if (!y && s.charAt(j) == c) {
//					return false;
//				}
//			}
		}
		//System.out.println(" true");
		return true;
		
	}
	
	static void rec(String[] a, boolean[] b, String s) {
		boolean change = false;
		for(int i = 0; i < b.length; i++) {
			if (!b[i]) {
				change = true;
				b[i] = true;
				String tmp = s + a[i];
				rec(a,b,tmp);
				b[i] = false;
			}
		}
		if (!change) {
			if (valid(s)) {
				count++;
			}
		}
	}
	
	public static void main(String[] args) throws FileNotFoundException{
		Scanner sc = new Scanner(System.in);
		String filename = sc.nextLine();
		sc.close();
		
		PrintWriter pw =
				//new PrintWriter(System.out);
				new PrintWriter(new File(filename + ".out"));
		Scanner scanner = new Scanner(new File(filename));
		int testCases = Integer.parseInt(scanner.nextLine());
		for(int currTest=1; currTest<=testCases; currTest++){
			System.out.println(currTest);
			int n = Integer.parseInt(scanner.nextLine());
			String[] a = scanner.nextLine().split(" ");
			shorten(a);
			boolean b[] = new boolean[n];
			count = 0;
			rec(a, b, "");
			
			
			pw.println(String.format("Case #%d: %d", currTest, count));
			
		}
		scanner.close();
		pw.close();
	}
}
