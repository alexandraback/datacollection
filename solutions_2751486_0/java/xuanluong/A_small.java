import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;


public class A_small {

	static int nTest;
	static String name;
	static int n;
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new File("A-in.txt"));
		PrintStream ps = new PrintStream(new File("A-out.txt"));
		System.setOut(ps);
		nTest = scanner.nextInt();
		for (int test=1;test<=nTest;++test) {
			name = scanner.next();
			n = scanner.nextInt();
			int L = name.length();
			int val = 0;
			for (int i=0;i<L;++i) {
				for (int j=i+n-1;j<L;++j) {
					
					if (check(i,j, n)) {
//						System.out.println(name.substring(i, j+1));
						val++;
					}
				}
			}
			
			
			System.out.println("Case #" + test + ": " + val);
		}

	}
	
	private static boolean check(int from, int to, int n) {
		for (int i=from;i<=to;++i) {
			if (!isconso(name.charAt(i))) {
				continue;
			}
			else {
				boolean flag = true;
				int j;
				for (j=1;j<n&&i+j<=to;++j) {
					if (!isconso(name.charAt(i+j))) {
						flag = false;
						break;
					}
				}
				if (flag) {
					if (j==n) {
						return true;
					}
				}
				i = i + j;
			}
		}
		return false;
	}

	private static boolean isconso(char c) {
		if (c == 'a') return false;
		if (c == 'e') return false;
		if (c == 'i') return false;
		if (c == 'u') return false;
		if (c == 'o') return false;
		return true;
	}

}
