package round1c;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {

	/**
	 * @param args
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws FileNotFoundException {
		PrintWriter out = new PrintWriter(new OutputStreamWriter(
				new FileOutputStream("1c_b.out")));
		 Scanner cin = new Scanner(new FileInputStream("B-small-attempt1.in"));
//		Scanner cin = new Scanner(System.in);

		int T = cin.nextInt();

		for (int i = 1; i <= T; i++) {
			res = 0;
			int n = cin.nextInt();
			String[] str = new String[n];
			for (int j = 0; j < n; j++) {
				str[j] = cin.next();
			}
			solveSmall(str, 0, n);
			out.print("Case #");
			out.print(i);
			out.print(": ");
			out.println(res);
		}
		out.close();

	}

	static int res = 0;

	static void solveSmall(String[] str, int start, int n) {
		if (start == n)
			validate(str);
			
		for (int i = start; i < n; i++) {
			swap(str, start, i);
			solveSmall(str, start + 1, n);
			swap(str, i, start);
		}
	}

	private static void validate(String[] str) {
		int[] charLoc = new int[26];
		Arrays.fill(charLoc, -1);
		int len = 0;
		for (int i = 0; i < str.length; i++) {
			String s = str[i];
			char[] ch = s.toCharArray();
			for (int j = 0; j < ch.length; j++) {
				int chin = ch[j] - 'a';
				if ((charLoc[chin] != -1)&&(charLoc[chin] != len - 1)) {
					return;
				}
				charLoc[chin] = len;
				len++;
			}
		}
		res++;
	}

	private static void swap(String[] str, int start, int i) {
		if (start == i)
			return;
		String temp = str[start];
		str[start] = str[i];
		str[i] = temp;
	}

}
