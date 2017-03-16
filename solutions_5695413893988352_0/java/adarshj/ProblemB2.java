
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ProblemB2 {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new FileInputStream(new File("B-small-attempt01b.in")));
		// Scanner sc = new Scanner(System.in);
		int t = Integer.parseInt(sc.nextLine());
		int tindex = 1;
		while (t-- > 0) {
			String s = sc.nextLine();
			String c = s.split(" ")[0];
			String j = s.split(" ")[1];
			int len = c.length();
			String newc = "", newj = "";
			List<Integer> clist = new ArrayList<>();
			List<Integer> jlist = new ArrayList<>();
			String format = "%0" + len + "d";
			for (int i = 0; i <= Math.pow(10, len) - 1; i++) {
				if (matches(c, String.format(format, i))) {
					clist.add(i);
				}
				if (matches(j, String.format(format, i))) {
					jlist.add(i);
				}
			}
			int mindiff = Integer.MAX_VALUE;
			int mindiffindexi = 0, mindiffindexj = 0;
			for (int i = 0; i < clist.size(); i++) {
				for (int j1 = 0; j1 < jlist.size(); j1++) {
					if (Math.abs(clist.get(i) - jlist.get(j1)) < mindiff) {
						mindiff = Math.abs(clist.get(i) - jlist.get(j1));
						mindiffindexi = i;
						mindiffindexj = j1;
					}
				}
			}
			String result = "";

			System.out.println("Case #" + tindex++ + ": " + String.format(format, clist.get(mindiffindexi)) + " "
					+ String.format(format, jlist.get(mindiffindexj)));

		}

	}

	private static boolean matches(String c, String s) {
		for (int i = 0; i < c.length(); i++) {
			if (c.charAt(i) != '?' && c.charAt(i) != s.charAt(i)) {
				return false;
			}
		}
		return true;
	}
}