import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		int c = in.nextInt();
		for (int i = 1; i <= c; i++) {
			char[] inputChars = in.next().toCharArray();

			String finalString = "";

			for (int j = 0; j < inputChars.length; j++) {
				if (j == 0) {
					finalString = "" + inputChars[j];
				} else {
					if (finalString.charAt(0) <= inputChars[j]) {
						finalString = inputChars[j] + finalString;
					} else {
						finalString = finalString + inputChars[j];
					}
				}
			}

			System.out.println("Case #" + i + ": " + finalString);
		}
	}

}