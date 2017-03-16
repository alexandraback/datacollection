import java.io.*;
import java.util.*;
import static java.util.Arrays.*;

public class C {
	static final boolean _PRACTICE = !true;
	static final boolean _SAMPLE = !true;
	static final boolean _SMALL = true;
	static final String _PROBLEM = "C";

	int len;
	long x;
	String str;
	
	int indexX;
	int indexStr;
	
	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		int testCase = sc.nextInt();

		for (int k = 1; k <= testCase; k++) {
			System.out.printf("Case #%d: ", k);
			System.err.printf("Case #%d: ", k);

			len = sc.nextInt();
			String tmp = sc.next();
			x = Long.valueOf(tmp);
			str = sc.next();

			boolean possible = false;

			indexX = 0;
			indexStr = 0;
			boolean foundA = search('i');
			if (foundA) {
				boolean foundB = search('j');
				if (foundB) {
					boolean foundC = search('k');
					if (foundC) {
						boolean checkLast = checkLast();
						if (checkLast) {
							possible = true;
						}
					}
				}
			}


			System.out.println(possible ? "YES" : "NO");
			System.err.println(possible ? "YES" : "NO");
		}
		sc.close();
	}
	
	private boolean search(char expect) {
		int result = '1';
		for (int j = 0; j < 5; j++) {
			int index = 0;
			int end = len;
			if (j == 0) {
				index = indexStr;
			}
			if (j == 4) {
				end = indexStr;
			}
			for (; index < end; index++) {
				char c = str.charAt(index);
				result = multiple(result, c);
				if (result == expect) {
					if (index == len - 1) {
						indexX++;
						indexStr = 0;
					} else {
						indexStr = index + 1;
					}
					return true;
				}
			}
			if (j < 4) {
				indexX++;
				if (indexX > x) {
					return false;
				}
			}
		}
		
		return false;
	}
	
	private boolean checkLast() {
		if (indexX == x) {
			return true;
		}
		int diff = (int)((x - indexX - 1) % 4);
		int result = '1';
		for (int i = indexStr; i < len; i++) {
			char c = str.charAt(i);
			result = multiple(result, c);
		}
		int tmp = '1';
		for (int i = 0; i < len; i++) {
			tmp = multiple(tmp, str.charAt(i));
		}
		for (int i = 0; i < diff; i++) {
			result = multiple(result, tmp);
		}
		return result == '1';
	}
	
	private int multiple(int x, int y) {
		int absX = Math.abs(x);
		int absY = Math.abs(y);
		int returnVal = absX;
				
		if (absX == '1') {
			returnVal = absY;
		} else if (absY == '1') {
			// do nothing
		} else if (absX == absY) {
			returnVal = 0 - '1';
		} else {
			switch (absX) {
			case 'i':
				if (absY == 'j') {
					returnVal = 'k';
				} else if (absY == 'k') {
					returnVal = 0 - 'j';
				}
				break;
			case 'j':
				if (absY == 'i') {
					returnVal = 0 - 'k';
				} else if (absY == 'k') {
					returnVal = 'i';
				}
				break;
			case 'k':
				if (absY == 'i') {
					returnVal = 'j';
				} else if (absY == 'j') {
					returnVal = 0 - 'i';
				}
				break;
			}
		}
		if (x < 0) {
			returnVal *= -1;
		}
		if (y < 0) {
			returnVal *= -1;
		}
		return returnVal;
	}


	public static void main(String... args) throws IOException {
		if (!_SAMPLE) {
			if (_SMALL) {
				int i = 0;
				while (new File(_SMALLNAME(i) + ".in").exists())
					i++;
				i--;
				boolean test = false;
				if (new File(_SMALLNAME(i) + ".out").exists()) {
					System.err.println("overwrite?(y/n)");
					char c = (char) System.in.read();
					test = c != 'y';
				}
				if (test) {
					System.setIn(new FileInputStream(_SMALLNAME(i) + ".in"));
					System.setOut(new PrintStream(_PROBLEM + "-small-test.out"));
					new C().run();
					FileReader f1 = new FileReader(_PROBLEM + "-small-test.out");
					FileReader f2 = new FileReader(_SMALLNAME(i) + ".out");
					BufferedReader br1 = new BufferedReader(f1);
					BufferedReader br2 = new BufferedReader(f2);
					for (int j = 1;; j++) {
						String s1 = br1.readLine();
						String s2 = br2.readLine();
						if (s1 == null && s2 == null) {
							System.err.println("OK!");
							break;
						}
						if (s1 == null || s2 == null || !s1.equals(s2)) {
							System.err.println("failed at line " + j);
							System.err.println("expected " + s2);
							System.err.println("but " + s1);
							break;
						}
					}
					br1.close();
					br2.close();
				} else {
					System.setIn(new FileInputStream(_SMALLNAME(i) + ".in"));
					System.setOut(new PrintStream(_SMALLNAME(i) + ".out"));
					new C().run();
				}
			} else {
				System.setIn(new FileInputStream(_LARGENAME() + ".in"));
				System.setOut(new PrintStream(_LARGENAME() + ".out"));
				new C().run();
			}
		} else
			new C().run();
	}

	private static String _LARGENAME() {
		return _PROBLEM + "-large" + (_PRACTICE ? "-practice" : "");
	}

	private static String _SMALLNAME(int a) {
		return _PROBLEM + "-small"
				+ (_PRACTICE ? a == 0 ? "-practice" : "" : "-attempt" + a);
	}
}
