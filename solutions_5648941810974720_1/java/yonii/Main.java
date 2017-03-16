import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		in = new Scanner(new File("A-large.in"));
		
		int T = in.nextInt();
		for (int i=1; i<=T; i++) {
			String s = in.next();
			int[] cnt = new int[26];
			for (int j=0; j<s.length(); j++) {
				cnt[s.charAt(j)-'A']++;
			}
			int[] digit = new int[10];
			
			while (cnt['Z'-'A'] > 0) { // ZERO
				cnt['Z'-'A']--;
				cnt['E'-'A']--;
				cnt['R'-'A']--;
				cnt['O'-'A']--;
				digit[0]++;
			}
			while (cnt['W'-'A'] > 0) { // TWO
				cnt['T'-'A']--;
				cnt['W'-'A']--;
				cnt['O'-'A']--;
				digit[2]++;
			}
			while (cnt['U'-'A'] > 0) { // FOUR
				cnt['F'-'A']--;
				cnt['O'-'A']--;
				cnt['U'-'A']--;
				cnt['R'-'A']--;
				digit[4]++;
			}
			while (cnt['X'-'A'] > 0) { // SIX
				cnt['S'-'A']--;
				cnt['I'-'A']--;
				cnt['X'-'A']--;
				digit[6]++;
			}
			while (cnt['G'-'A'] > 0) { // EIGHT
				cnt['E'-'A']--;
				cnt['I'-'A']--;
				cnt['G'-'A']--;
				cnt['H'-'A']--;
				cnt['T'-'A']--;
				digit[8]++;
			}
			while (cnt['O'-'A'] > 0) { // ONE
				cnt['O'-'A']--;
				cnt['N'-'A']--;
				cnt['E'-'A']--;
				digit[1]++;
			}
			while (cnt['R'-'A'] > 0) { // THREE
				cnt['T'-'A']--;
				cnt['H'-'A']--;
				cnt['R'-'A']--;
				cnt['E'-'A']--;
				cnt['E'-'A']--;
				digit[3]++;
			}
			while (cnt['F'-'A'] > 0) { // FIVE
				cnt['F'-'A']--;
				cnt['I'-'A']--;
				cnt['V'-'A']--;
				cnt['E'-'A']--;
				digit[5]++;
			}
			while (cnt['S'-'A'] > 0) { // SEVEN
				cnt['S'-'A']--;
				cnt['E'-'A']--;
				cnt['V'-'A']--;
				cnt['E'-'A']--;
				cnt['N'-'A']--;
				digit[7]++;
			}
			while (cnt['N'-'A'] > 0) { // NINE
				cnt['N'-'A']--;
				cnt['I'-'A']--;
				cnt['N'-'A']--;
				cnt['E'-'A']--;
				digit[9]++;
			}
			
			StringBuilder sb = new StringBuilder();
			for (int j=0; j<10; j++) {
				for (int k=0; k<digit[j]; k++) {
					sb.append(j);
				}
			}
			
			System.out.printf("Case #%d: %s\n", i, sb.toString());
		}
	}
}