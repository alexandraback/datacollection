import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Round1A {

	public static void main(String[] args) throws FileNotFoundException {
		// Scanner sc = new Scanner(new File("D:\\Downloads\\small.in"));
		Scanner sc = new Scanner(new File("small.in"));
		
		int T = sc.nextInt();
		sc.nextLine();		// Clear CR;
		
		for (int x = 1; x <= T; ++x) {
			String s = sc.nextLine();
			
			String r = "";
			for (int i = 0; i < s.length(); ++i) {
				if (r.length() == 0) {
					r += s.charAt(i);
				}
				else {
					if (r.charAt(0) <= s.charAt(i)) {
						r = s.charAt(i) + r;
					}
					else {
						r = r + s.charAt(i);
					}
				}
			}
			
			System.out.println("Case #" + x + ": " + r);
		}

		sc.close();
	}
}
