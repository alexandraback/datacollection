import java.util.Scanner;

public class Main {
	static String temp;
	static int L;
	static long X;
	static char[][] table = new char[256][256];

	public static void main(String[] args) {
		initTable();
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			L = sc.nextInt();
			X = sc.nextLong();
			sc.nextLine();
			temp = sc.nextLine();
			System.out.print("Case #" + t + ": ");
			if (X > 10000 || L * X > 10000) {
				if (X < 9) {
					if (workForSmall()) {
						System.out.println("YES");
					} else {
						System.out.println("NO");
					}
				} else {
					if (workForBig()) {
						System.out.println("YES");
					} else {
						System.out.println("NO");
					}
				}
			} else {
				if (workForSmall()) {
					System.out.println("YES");
				} else {
					System.out.println("NO");
				}
			}
		}
	}

	private static boolean workForBig() {
		String newS = " ";
		for (int i = 1; i <= 4; i++) {
			newS += temp;
		}
		char[] suffix = new char[4 * L + 1];
		suffix[4 * L] = newS.charAt(4 * L);
		for (int i = 4 * L - 1; i > 0; i--) {
			suffix[i] = get(newS.charAt(i), suffix[i + 1]);
		}
		char[] pre = new char[4 * L + 1];
		pre[0] = '1';
		for (int i = 1; i <= 4 * L; i++) {
			pre[i] = get(pre[i - 1], newS.charAt(i));
		}
		int remain = (int) ((X-4) % 4);
		char allPre = '1';
		for (int i = 0; i < remain; i++) {
			allPre = get(allPre, pre[L]);
		}
		for (int i = 4 * L - 1; i > 0; i--) {
			if (suffix[i + 1] == 'k' && get(allPre, pre[i]) == 'k') {
				for (int j = 1; j < 4 * L; j++) {
					if (pre[j] == 'i') {
						return true;
					}
				}
				return false;
			}
		}
		return false;
	}

	private static void initTable() {
		table['1']['1'] = '1';
		table['1']['i'] = 'i';
		table['1']['j'] = 'j';
		table['1']['k'] = 'k';
		table['i']['1'] = 'i';
		table['i']['i'] = '4';
		table['i']['j'] = 'k';
		table['i']['k'] = 'm';
		table['j']['1'] = 'j';
		table['j']['i'] = 'n';
		table['j']['j'] = '4';
		table['j']['k'] = 'i';
		table['k']['1'] = 'k';
		table['k']['i'] = 'j';
		table['k']['j'] = 'l';
		table['k']['k'] = '4';
	}

	private static boolean workForSmall() {
		char[] pre = new char[(int) (X * L) + 1];
		String newS = " ";
		for (int i = 1; i <= X; i++) {
			newS += temp;
		}
		pre[0] = '1';
		for (int i = 1; i <= X * L; i++) {
			pre[i] = get(pre[i - 1], newS.charAt(i));
		}
		char[] suffix = new char[(int) (X * L) + 1];
		suffix[(int) (L * X)] = newS.charAt((int) (L * X));
		for (int i = (int) (X * L) - 1; i > 0; i--) {
			suffix[i] = get(newS.charAt(i), suffix[i + 1]);
		}
		for (int i = (int) (X * L) - 1; i > 0; i--) {
			if (suffix[i + 1] == 'k' && pre[i] == 'k') {
				for (int j = 1; j < i; j++) {
					if (pre[j] == 'i') {
						return true;
					}
				}
				return false;
			}
		}
		return false;
	}

	private static char get(char c1, char c2) {
		char c1new = c1;
		char c2new = c2;
		boolean reverse = false;
		if (c1 == '4' || c1 > 'k') {
			reverse = !reverse;
			c1new = (char) (c1new - 3);
		}
		if (c2 == '4' || c2 > 'k') {
			reverse = !reverse;
			c2new = (char) (c2new - 3);
		}
		char ans = table[c1new][c2new];
		if (reverse) {
			if (ans == '4' || ans > 'k') {
				ans = (char) (ans - 3);
			} else {
				ans = (char) (ans + 3);
			}
		}
		return ans;
	}
}
