package codejam;

import java.util.Scanner;

public class digists {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		for (int i = 1; i <= T; i++) {
			String num = s.next();
			int[] letters = new int[26];
			for (int j = 0; j < 26; j++) letters[j] = 0;
			int[] ans = new int[10];
			for(int j = 0 ; j < 10; j++) ans[j] = 0;
			for (int j = 0 ; j < num.length(); j++) {
				letters[num.charAt(j) - 'A'] ++;
			}
			ans[6] = letters['X' - 'A'];
			letters['S' - 'A'] -= letters['X' - 'A'];
			letters['I' - 'A'] -= letters['X' - 'A'];
			letters['X' - 'A'] = 0;
			ans[0] = letters['Z' - 'A'];
			letters['E' - 'A'] -= letters['Z' - 'A'];
			letters['R' - 'A'] -= letters['Z' - 'A'];
			letters['O' - 'A'] -= letters['Z' - 'A'];
			letters['Z' - 'A'] = 0;
			ans[2] = letters['W' - 'A'];
			letters['T' - 'A'] -= letters['W' - 'A'];
			letters['O' - 'A'] -= letters['W' - 'A'];
			letters['W' - 'A'] = 0;
			ans[8] = letters['G' - 'A'];
			letters['E' - 'A'] -= letters['G' - 'A'];
			letters['I' - 'A'] -= letters['G' - 'A'];
			letters['H' - 'A'] -= letters['G' - 'A'];
			letters['T' - 'A'] -= letters['G' - 'A'];
			letters['G' - 'A'] = 0;
			ans[3] = letters['T' - 'A'];
			letters['H' - 'A'] -= letters['T' - 'A'];
			letters['R' - 'A'] -= letters['T' - 'A'];
			letters['E' - 'A'] -= letters['T' - 'A'];
			letters['E' - 'A'] -= letters['T' - 'A'];
			letters['T' - 'A'] = 0;
			ans[4] = letters['U' - 'A'];
			letters['F' - 'A'] -= letters['U' - 'A'];
			letters['O' - 'A'] -= letters['U' - 'A'];
			letters['R' - 'A'] -= letters['U' - 'A'];
			letters['U' - 'A'] = 0;
			ans[1] = letters['O' - 'A'];
			letters['N' - 'A'] -= letters['O' - 'A'];
			letters['E' - 'A'] -= letters['O' - 'A'];
			letters['O' - 'A'] = 0;
			ans[5] = letters['F' - 'A'];
			letters['I' - 'A'] -= letters['F' - 'A'];
			letters['V' - 'A'] -= letters['F' - 'A'];
			letters['E' - 'A'] -= letters['F' - 'A'];
			letters['F' - 'A'] = 0;
			ans[7] = letters['V' - 'A'];
			letters['S' - 'A'] -= letters['V' - 'A'];
			letters['E' - 'A'] -= letters['V' - 'A'];
			letters['E' - 'A'] -= letters['V' - 'A'];
			letters['N' - 'A'] -= letters['V' - 'A'];
			letters['V' - 'A'] = 0;
			ans[9] = letters['I' - 'A'];
			letters['N' - 'A'] -= letters['I' - 'A'];
			letters['N' - 'A'] -= letters['I' - 'A'];
			letters['E' - 'A'] -= letters['I' - 'A'];
			letters['I' - 'A'] = 0;
			
			StringBuilder print = new StringBuilder();
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < ans[j]; k++) {
					print.append(j);
				}
			}
			System.out.println("Case #" + i + ": " + print.toString());
		}
	}
	
}
