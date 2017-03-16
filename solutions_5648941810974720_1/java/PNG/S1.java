import java.util.*;

public class S1 {
	
	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			int T = sc.nextInt();
			sc.nextLine();
			for (int i = 1; i <= T; i++) {
				String s = sc.nextLine().trim();
				int[] ch = new int[26];
				for (int j = 0; j < s.length(); j++) {
					ch[s.charAt(j) - 'A']++;
				}
				
				int[] nums = new int[10];
				
				nums[0] = ch['Z' - 'A'];
				ch['Z' - 'A'] -= nums[0];
				ch['E' - 'A'] -= nums[0];
				ch['R' - 'A'] -= nums[0];
				ch['O' - 'A'] -= nums[0];
				
				nums[2] = ch['W' - 'A'];
				ch['T' - 'A'] -= nums[2];
				ch['W' - 'A'] -= nums[2];
				ch['O' - 'A'] -= nums[2];

				nums[4] = ch['U' - 'A'];
				ch['F' - 'A'] -= nums[4];
				ch['O' - 'A'] -= nums[4];
				ch['U' - 'A'] -= nums[4];
				ch['R' - 'A'] -= nums[4];
				
				nums[5] = ch['F' - 'A'];
				ch['F' - 'A'] -= nums[5];
				ch['I' - 'A'] -= nums[5];
				ch['V' - 'A'] -= nums[5];
				ch['E' - 'A'] -= nums[5];
				
				nums[6] = ch['X' - 'A'];
				ch['S' - 'A'] -= nums[6];
				ch['I' - 'A'] -= nums[6];
				ch['X' - 'A'] -= nums[6];
				
				nums[7] = ch['V' - 'A'];
				ch['S' - 'A'] -= nums[7];
				ch['E' - 'A'] -= nums[7] * 2;
				ch['V' - 'A'] -= nums[7];
				ch['N' - 'A'] -= nums[7];
				
				nums[8] = ch['G' - 'A'];
				ch['E' - 'A'] -= nums[8];
				ch['I' - 'A'] -= nums[8];
				ch['G' - 'A'] -= nums[8];
				ch['H' - 'A'] -= nums[8];
				ch['T' - 'A'] -= nums[8];
				
				nums[9] = ch['I' - 'A'];
				ch['N' - 'A'] -= nums[9] * 2;
				ch['I' - 'A'] -= nums[9];
				ch['E' - 'A'] -= nums[9];
				
				nums[1] = ch['O' - 'A'];
				ch['O' - 'A'] -= nums[1];
				ch['N' - 'A'] -= nums[1];
				ch['E' - 'A'] -= nums[1];
				
				nums[3] = ch['T' - 'A'];
				
				System.out.print("Case #");
				System.out.print(i);
				System.out.print(": ");
				
				for (int j = 0; j < nums.length; j++) {
					int hm = nums[j];
					for (int k = 0; k < hm; k++) {
						System.out.print(String.valueOf(j));
					}
				}

				
				System.out.println();
				
			}
		}
	}

}
