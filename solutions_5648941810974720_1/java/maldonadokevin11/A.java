package edition2016.round1b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

public class A {

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		for (int caze = 1; caze <= t; caze++) {
			List<Character> chars = new ArrayList<Character>();
			for (char c : br.readLine().toLowerCase().toCharArray()) {
				chars.add(c);
			}
			List<Integer> ret = new ArrayList<Integer>();
			while (chars.contains((Character) 'z')) {
				chars.remove((Character) 'z');
				chars.remove((Character) 'e');
				chars.remove((Character) 'r');
				chars.remove((Character) 'o');
				ret.add(0);
			}
			while (chars.contains((Character) 'w')) {
				chars.remove((Character) 't');
				chars.remove((Character) 'w');
				chars.remove((Character) 'o');
				ret.add(2);
			}
			while (chars.contains((Character) 'x')) {
				chars.remove((Character) 's');
				chars.remove((Character) 'i');
				chars.remove((Character) 'x');
				ret.add(6);
			}
			while (chars.contains((Character) 'x')) {
				chars.remove((Character) 's');
				chars.remove((Character) 'i');
				chars.remove((Character) 'x');
				ret.add(6);
			}
			while (chars.contains((Character) 'g')) {
				chars.remove((Character) 'e');
				chars.remove((Character) 'i');
				chars.remove((Character) 'g');
				chars.remove((Character) 'h');
				chars.remove((Character) 't');
				ret.add(8);
			}
			while (chars.contains((Character) 'h')) {
				chars.remove((Character) 't');
				chars.remove((Character) 'h');
				chars.remove((Character) 'r');
				chars.remove((Character) 'e');
				chars.remove((Character) 'e');
				ret.add(3);
			}
			while (chars.contains((Character) 's')) {
				chars.remove((Character) 's');
				chars.remove((Character) 'e');
				chars.remove((Character) 'v');
				chars.remove((Character) 'e');
				chars.remove((Character) 'n');
				ret.add(7);
			}
			while (chars.contains((Character) 'v')) {
				chars.remove((Character) 'f');
				chars.remove((Character) 'i');
				chars.remove((Character) 'v');
				chars.remove((Character) 'e');
				ret.add(5);
			}
			while (chars.contains((Character) 'f')) {
				chars.remove((Character) 'f');
				chars.remove((Character) 'o');
				chars.remove((Character) 'u');
				chars.remove((Character) 'r');
				ret.add(4);
			}
			while (chars.contains((Character) 'g')) {
				chars.remove((Character) 'e');
				chars.remove((Character) 'i');
				chars.remove((Character) 'g');
				chars.remove((Character) 'h');
				chars.remove((Character) 't');
				ret.add(8);
			}
			while (chars.contains((Character) 'o')) {
				chars.remove((Character) 'o');
				chars.remove((Character) 'n');
				chars.remove((Character) 'e');
				ret.add(1);
			}
			while (chars.contains((Character) 'n')) {
				chars.remove((Character) 'n');
				chars.remove((Character) 'i');
				chars.remove((Character) 'n');
				chars.remove((Character) 'e');
				ret.add(9);
			}
			Collections.sort(ret);
			String nums = ret.stream().map(String::valueOf)
					.collect(Collectors.joining());
			System.out.println(String.format("Case #%d: %s", caze, nums));

		}
	}

}
