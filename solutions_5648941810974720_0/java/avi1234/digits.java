import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class digits {
	public static void main(String[] args) throws IOException {
		BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(read.readLine());
		for (int i = 0; i < t; i++) {
			int[] letters = new int[26];
			int[] digits = new int[10];
			String s = read.readLine();
			for (int j = 0; j < s.length(); j++) {
				letters[s.charAt(j) - 65]++;
			}
			//do SIX
			digits[6] = letters[23];
			letters[18] -= digits[6]; letters[23] -= digits[6]; letters[8] -= digits[6];
			//do ZERO
			digits[0] = letters[25];
			letters[25] -= digits[0]; letters[4] -= digits[0]; letters[17] -= digits[0]; letters[14] -= digits[0];
			//do TWO
			digits[2] =  letters[22];
			letters[22] -= digits[2]; letters[19] -= digits[2]; letters[14] -= digits[2];
			//do EIGHT
			digits[8] = letters[6];
			letters[4] -= digits[8]; letters[8] -= digits[8]; letters[6] -= digits[8]; letters[7] -= digits[8]; letters[19] -= digits[8];
			//do FOUR
			digits[4] = letters[20];
			letters[5] -= digits[4]; letters[14] -= digits[4]; letters[20] -= digits[4]; letters[17] -= digits[4];
			//do FIVE
			digits[5] = letters[5];
			letters[5] -= digits[5]; letters[8] -= digits[5]; letters[21] -= digits[5]; letters[4] -= digits[5];
			//do SEVEN
			digits[7] = letters[21];
			letters[18] -= digits[7]; letters[4] -= digits[7]; letters[21] -= digits[7]; letters[4] -= digits[7]; letters[13] -= digits[7];
			//do ONE
			digits[1] = letters[14];
			letters[14] -= digits[1]; letters[13] -= digits[1]; letters[4] -= digits[1];
			//do NINE
			digits[9] = letters[13] / 2;
			letters[13] -= 2 * digits[9]; letters[13] -= digits[8]; letters[13] -= digits[4];
			//do THREE
			digits[3] = letters[19];
			letters[19] -= digits[3]; letters[7] -= digits[3]; letters[17] -= digits[3]; letters[4] -= digits[3] * 2;
			System.out.print("Case #" + (i + 1) + ": ");
			for (int j = 0; j < 10; j++) {
				for (int a = 0; a < digits[j]; a++) {
					System.out.print(j);
				}
			}
			System.out.println();
		}
	}
}
