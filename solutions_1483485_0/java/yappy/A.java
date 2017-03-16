import java.util.Scanner;

/*
3
ejp mysljylc kd kxveddknmc re jsicpdrysi
our language is impossible to understand
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
there are twenty six factorial possibilities
de kr kd eoya kw aej tysr re ujdr lkgc jv
so it is okay if you want to just give up
 */

public class A {

	private static void study() {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();
		char[] map = new char[256];
		for (int i = 0; i < n; i++) {
			char[] org = in.nextLine().toCharArray();
			char[] to = in.nextLine().toCharArray();
			for (int k = 0; k < org.length; k++) {
				map[org[k]] = to[k];
			}
		}
		for (char c = 'a'; c <= 'z'; c++) {
			System.out.printf("map['%c'] = '%c';%n", c, map[c] == 0 ? '?'
					: map[c]);
		}
	}

	private static void solve() {
		char[] map = new char[256];
		map[' '] = ' ';
		map['a'] = 'y';
		map['b'] = 'h';
		map['c'] = 'e';
		map['d'] = 's';
		map['e'] = 'o';
		map['f'] = 'c';
		map['g'] = 'v';
		map['h'] = 'x';
		map['i'] = 'd';
		map['j'] = 'u';
		map['k'] = 'i';
		map['l'] = 'g';
		map['m'] = 'l';
		map['n'] = 'b';
		map['o'] = 'k';
		map['p'] = 'r';
		map['q'] = 'z';
		map['r'] = 't';
		map['s'] = 'n';
		map['t'] = 'w';
		map['u'] = 'j';
		map['v'] = 'p';
		map['w'] = 'f';
		map['x'] = 'm';
		map['y'] = 'a';
		map['z'] = 'q';

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.nextLine();
		for (int i = 0; i < n; i++) {
			char[] org = in.nextLine().toCharArray();
			System.out.printf("Case #%d: ", i + 1);
			for (char c : org) {
				System.out.print(map[c]);
			}
			System.out.println();
		}
	}

	public static void main(String[] args) {
		// study();
		solve();
	}

}
