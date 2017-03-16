import java.io.*;
import java.util.*;
import java.math.*;

public class A {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/A-large.in"))));

		String output = "";
		int t = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= t; i++) {
			String s = sc.nextLine();
			int[] freqs = new int[26];
			int[] nums = new int[10];
			for (char c : s.toCharArray()) {
				freqs[c-'A']++;
			}
			nums[0] = freqs['Z'-'A'];
			freqs['Z'-'A'] -= nums[0];
			freqs['E'-'A'] -= nums[0];
			freqs['R'-'A'] -= nums[0];
			freqs['O'-'A'] -= nums[0];
			nums[2] = freqs['W'-'A'];
			freqs['T'-'A'] -= nums[2];
			freqs['W'-'A'] -= nums[2];
			freqs['O'-'A'] -= nums[2];
			nums[6] = freqs['X'-'A'];
			freqs['S'-'A'] -= nums[6];
			freqs['I'-'A'] -= nums[6];
			freqs['X'-'A'] -= nums[6];
			nums[7] = freqs['S'-'A'];
			freqs['S'-'A'] -= nums[7];
			freqs['E'-'A'] -= nums[7];
			freqs['V'-'A'] -= nums[7];
			freqs['E'-'A'] -= nums[7];
			freqs['N'-'A'] -= nums[7];
			nums[5] = freqs['V'-'A'];
			freqs['F'-'A'] -= nums[5];
			freqs['I'-'A'] -= nums[5];
			freqs['V'-'A'] -= nums[5];
			freqs['E'-'A'] -= nums[5];
			nums[4] = freqs['F'-'A'];
			freqs['F'-'A'] -= nums[4];
			freqs['O'-'A'] -= nums[4];
			freqs['U'-'A'] -= nums[4];
			freqs['R'-'A'] -= nums[4];
			nums[8] = freqs['G'-'A'];
			freqs['E'-'A'] -= nums[8];
			freqs['I'-'A'] -= nums[8];
			freqs['G'-'A'] -= nums[8];
			freqs['H'-'A'] -= nums[8];
			freqs['T'-'A'] -= nums[8];
			nums[3] = freqs['R'-'A'];
			freqs['T'-'A'] -= nums[3];
			freqs['H'-'A'] -= nums[3];
			freqs['R'-'A'] -= nums[3];
			freqs['E'-'A'] -= nums[3];
			freqs['E'-'A'] -= nums[3];
			nums[9] = freqs['I'-'A'];
			freqs['N'-'A'] -= nums[9];
			freqs['I'-'A'] -= nums[9];
			freqs['N'-'A'] -= nums[9];
			freqs['E'-'A'] -= nums[9];
			nums[1] = freqs['E'-'A'];
			freqs['O'-'A'] -= nums[1];
			freqs['N'-'A'] -= nums[1];
			freqs['E'-'A'] -= nums[1];
			
			String ans = "";
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < nums[j]; k++) {
					ans += j;
				}
			}
			
			output += "Case #" + i + ": " + ans + "\n";
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/A-large.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
}