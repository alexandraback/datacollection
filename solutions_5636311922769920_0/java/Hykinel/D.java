import java.io.*;
import java.util.*;

public class D {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int keis = sc.nextInt();
		for (int kei = 1; kei <= keis; kei++) {
			int k = sc.nextInt();
			int c = sc.nextInt();
			int s = sc.nextInt();

			String ans = "";
			for (int i = 1; i <= s; i++) {
				ans = ans + " " + i;
			}
			System.out.printf("Case #%d: %s\n", kei, ans.trim());
		}
	}
}