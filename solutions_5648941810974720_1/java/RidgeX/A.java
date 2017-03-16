import java.util.*;

public class A {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int cases = input.nextInt();
		input.nextLine();
		for (int c = 0; c < cases; c++) {
			char[] line = input.nextLine().toCharArray();
			int[] freq = new int[256];
			for (int i = 0; i < line.length; i++) {
				freq[line[i]]++;
			}
			List<Integer> list = new ArrayList<Integer>();
			while (freq['Z'] > 0 && freq['E'] > 0 && freq['R'] > 0 && freq['O'] > 0) {
				freq['Z']--;
				freq['E']--;
				freq['R']--;
				freq['O']--;
				list.add(0);
			}
			while (freq['T'] > 0 && freq['W'] > 0 && freq['O'] > 0) {
				freq['T']--;
				freq['W']--;
				freq['O']--;
				list.add(2);
			}
			while (freq['F'] > 0 && freq['O'] > 0 && freq['U'] > 0 && freq['R'] > 0) {
				freq['F']--;
				freq['O']--;
				freq['U']--;
				freq['R']--;
				list.add(4);
			}
			while (freq['S'] > 0 && freq['I'] > 0 && freq['X'] > 0) {
				freq['S']--;
				freq['I']--;
				freq['X']--;
				list.add(6);
			}
			while (freq['E'] > 0 && freq['I'] > 0 && freq['G'] > 0 && freq['H'] > 0 && freq['T'] > 0) {
				freq['E']--;
				freq['I']--;
				freq['G']--;
				freq['H']--;
				freq['T']--;
				list.add(8);
			}
			while (freq['O'] > 0 && freq['N'] > 0 && freq['E'] > 0) {
				freq['O']--;
				freq['N']--;
				freq['E']--;
				list.add(1);
			}
			while (freq['T'] > 0 && freq['H'] > 0 && freq['R'] > 0 && freq['E'] > 0 && freq['E'] > 0) {
				freq['T']--;
				freq['H']--;
				freq['R']--;
				freq['E']--;
				freq['E']--;
				list.add(3);
			}
			while (freq['F'] > 0 && freq['I'] > 0 && freq['V'] > 0 && freq['E'] > 0) {
				freq['F']--;
				freq['I']--;
				freq['V']--;
				freq['E']--;
				list.add(5);
			}
			while (freq['S'] > 0 && freq['E'] > 0 && freq['V'] > 0 && freq['E'] > 0 && freq['N'] > 0) {
				freq['S']--;
				freq['E']--;
				freq['V']--;
				freq['E']--;
				freq['N']--;
				list.add(7);
			}
			while (freq['N'] > 0 && freq['I'] > 0 && freq['N'] > 0 && freq['E'] > 0) {
				freq['N']--;
				freq['I']--;
				freq['N']--;
				freq['E']--;
				list.add(9);
			}
			Collections.sort(list);
			StringBuilder sb = new StringBuilder();
			for (int d : list) {
				sb.append(d);
			}
			System.out.println(String.format("Case #%d: %s", c+1, sb.toString()));
		}
	}
}
