package y2013r1c;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class A {

	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				System.in));
		int ntests = Integer.parseInt(reader.readLine());
		for (int test = 1; test <= ntests; test++) {
			String f[] = reader.readLine().split(" ");
			String name = f[0];
			int n = Integer.parseInt(f[1]);
			System.out.println("Case #" + test + ": " + nValue(name, n));
		}
	}

	private static long nValue(String name, int n) {
		long nValue = 0;
		int lastPos = -1;
		int lastCount = 0;
		for (int i = 0; i < name.length(); i++) {
			if (isVowel(name.charAt(i)) )
				lastCount = 0;
			else
				lastCount++;
			if(lastCount >= n)
				lastPos = i - n + 1;

			nValue += (lastPos + 1);
		}
		return nValue;
	}

	private static boolean isVowel(char c) {
		return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u';
	}

}
