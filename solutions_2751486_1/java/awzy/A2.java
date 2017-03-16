import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class A2 {
	public static void main(String[] args) throws IOException {
		String name = "A-large";
		Scanner sc = new Scanner(new File(name + ".in"));
		//Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new FileWriter(name + "x.out"));
		int t = sc.nextInt();
		sc.nextLine();
		for (int c = 1; c <= t; c++) {
			String[] strs = sc.nextLine().split(" ");
			String str = strs[0];
			int n = Integer.parseInt(strs[1]);
			long x = 0;
			int m = 0;
			int laststart = -1;
			for(int i = 0; i < str.length(); i++) {
				if(!isVowel(str.charAt(i))) {
					m++;
				} else {
					m = 0;
				}
				if(m >= n) {
					long starts = i-n+1-laststart;
					long ends = str.length() - i;
					x += starts*ends;
					laststart = i-n+1;
				}
			}
			String ans = "Case #" + c + ": " + x;
			out.println(ans);
			System.out.println(ans);
		}
		out.close();
		sc.close();
	}

	public static boolean isVowel(char c) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			return true;
		return false;
	}

}
