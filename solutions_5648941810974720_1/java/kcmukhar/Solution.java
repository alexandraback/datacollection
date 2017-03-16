import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
		try (Scanner in = new Scanner(new FileInputStream(args[0] + ".in"));
				BufferedWriter out = new BufferedWriter(new FileWriter(args[0] + ".out"))) {
			int T = in.nextInt();
			in.nextLine();
			for (int i = 0; i < T; i++) {
				String s = in.nextLine();
				String temp = new String(s);

				int[] result = new int[2000];
				int idx = 0;
				while (temp.indexOf('Z') >= 0) {
					temp = replaceString(temp, "ZERO");
					result[idx++] = 0;
				}
				while (temp.indexOf('W') >= 0) {
					temp = replaceString(temp, "TWO");
					result[idx++] = 2;
				}
				while (temp.indexOf('X') >= 0) {
					temp = replaceString(temp, "SIX");
					result[idx++] = 6;
				}
				while (temp.indexOf('G') >= 0) {
					temp = replaceString(temp, "EIGHT");
					result[idx++] = 8;
				}
				while (temp.indexOf('T') >= 0) {
					temp = replaceString(temp, "THREE");
					result[idx++] = 3;
				}
				while (temp.indexOf('R') >= 0) {
					temp = replaceString(temp, "FOUR");
					result[idx++] = 4;
				}
				while (temp.indexOf('F') >= 0) {
					temp = replaceString(temp, "FIVE");
					result[idx++] = 5;
				}
				while (temp.indexOf('V') >= 0) {
					temp = replaceString(temp, "SEVEN");
					result[idx++] = 7;
				}
				while (temp.indexOf('I') >= 0) {
					temp = replaceString(temp, "NINE");
					result[idx++] = 9;
				}
				while (temp.indexOf('O') >= 0) {
					temp = replaceString(temp, "ONE");
					result[idx++] = 1;
				}

				int[] answer = Arrays.copyOf(result, idx);
				Arrays.sort(answer);
				StringBuilder sb = new StringBuilder(answer.length);
				for (int ii : answer)
					sb.append(ii);
				String str = "Case #%d: %s\n";
				System.out.printf(str, i + 1, sb.toString());
				out.write("Case #" + (i+1) + ": " + sb.toString());
				out.newLine();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static String replaceString(String temp, String string) {
		for (int i = 0; i < string.length(); i++)
			temp = temp.replaceFirst(string.substring(i, i + 1), "");
		return temp;
	}
}
