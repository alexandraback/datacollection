import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			String S = sc.next();
			int[] map = new int[26];
			for (char c : S.toCharArray()) {
				map[c - 'A']++;
			}

			ArrayList<Integer> list = new ArrayList<>();
			while (map['Z' - 'A'] > 0) {
				list.add(0);
				map['Z' - 'A']--;
				map['E' - 'A']--;
				map['R' - 'A']--;
				map['O' - 'A']--;
			}
			while (map['W' - 'A'] > 0) {
				list.add(2);
				map['T' - 'A']--;
				map['W' - 'A']--;
				map['O' - 'A']--;
			}
			while (map['U' - 'A'] > 0) {
				list.add(4);
				map['F' - 'A']--;
				map['O' - 'A']--;
				map['U' - 'A']--;
				map['R' - 'A']--;
			}
			while (map['F' - 'A'] > 0) {
				list.add(5);
				map['F' - 'A']--;
				map['I' - 'A']--;
				map['V' - 'A']--;
				map['E' - 'A']--;
			}
			while (map['X' - 'A'] > 0) {
				list.add(6);
				map['S' - 'A']--;
				map['I' - 'A']--;
				map['X' - 'A']--;
			}
			while (map['S' - 'A'] > 0) {
				list.add(7);
				map['S' - 'A']--;
				map['E' - 'A']--;
				map['V' - 'A']--;
				map['E' - 'A']--;
				map['N' - 'A']--;
			}
			while (map['G' - 'A'] > 0) {
				list.add(8);
				map['E' - 'A']--;
				map['I' - 'A']--;
				map['G' - 'A']--;
				map['H' - 'A']--;
				map['T' - 'A']--;
			}
			while (map['I' - 'A'] > 0) {
				list.add(9);
				map['N' - 'A']--;
				map['I' - 'A']--;
				map['N' - 'A']--;
				map['E' - 'A']--;
			}
			while (map['O' - 'A'] > 0) {
				list.add(1);
				map['O' - 'A']--;
				map['N' - 'A']--;
				map['E' - 'A']--;
			}
			while (map['T' - 'A'] > 0) {
				list.add(3);
				map['T' - 'A']--;
				map['H' - 'A']--;
				map['R' - 'A']--;
				map['E' - 'A']--;
				map['E' - 'A']--;
			}
			
			Collections.sort(list);
			System.out.print("Case #" + i + ": ");
			for (Integer integer : list) {
				System.out.print(integer);
			}
			System.out.println();
		}
		sc.close();
	}
}