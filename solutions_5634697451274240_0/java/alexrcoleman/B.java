import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(new FileInputStream(new File("B.in")));
		PrintWriter out = new PrintWriter(new FileOutputStream(new File("B.out")));
		int T = scan.nextInt();
		scan.nextLine();
		for (int t = 1; t <= T; t++) {
			String s = scan.nextLine();
			boolean[] good = new boolean[s.length()];
			for(int i=0;i<s.length();i++)
				good[i] = s.charAt(i) == '+';
			int ans = 0;
			while(!isGood(good)) {
				int idx = good.length-1;
				for(int i=1;i<good.length;i++) {
					if(good[i] && !good[i-1]) {
						idx = i-1;
						break;
					}
				}
				for(int i=0;i<=idx;i++) {
					good[i] = !good[i];
				}
				ans++;
			}
			out.printf("Case #%d: %d%n", t, ans);
		}
		scan.close();
		out.close();
	}
	public static boolean isGood(boolean[] good) {
		for(boolean b : good) {
			if(!b)
				return false;
		}
		return true;
	}
}
