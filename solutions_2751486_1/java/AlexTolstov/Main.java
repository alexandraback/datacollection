import java.io.*;
import java.util.*;


public class Main extends Thread {
	
	Scanner in;
	PrintWriter out;
	
	static final String path = "C:/gcj2013_r1/";
	static final String problem = "A-large";
	
	static final char[] gla = {'a', 'e', 'i', 'o', 'u' };
	
	int countGood[];
	
	boolean isSogl(char c) {
		for (int i = 0; i < gla.length; i++) {
			if (gla[i] == c) {
				return false;
			}
		}
		return true;
	}
	
	
	void solveOne(int test) {
		String s = in.next();
		countGood = new int[s.length()];
		int n = in.nextInt();
		int count = 0;
		for (int i = 0; i < s.length(); i++) {
			boolean isGood = isSogl(s.charAt(i));
			if (isGood) {
				countGood[i] = count + 1;
				count++;
			} else {
				countGood[i] = 0;
				count = 0;
			}
		}
		
		long ans = 0;
		int startCheckPos = s.length() - 1;
		for (int i = s.length() - 1; i >= 0; i--) {
			while (startCheckPos >= 0) {
				while (startCheckPos > i) {
					startCheckPos--;
				}
				if (countGood[startCheckPos] >= n) {
					long pointsEnd = startCheckPos - n + 2;
					ans = ans + pointsEnd;// * pointsStart;
					break;
				}
				startCheckPos--;
			}
		}
		out.println("Case #" + test + ": " + ans);
	}
	
	void solve() {
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			solveOne(i + 1);
		}
	}
	
	
	static void check(boolean e) {
		if (!e) {
			throw new Error();
		}
	}
	
	
	public void run() {
		try {
			in = new Scanner(new FileReader(path + problem + ".in"));
			out = new PrintWriter(new FileWriter(path + problem + ".out"));
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
		}
		
		try {
			solve();
		} finally {
			out.close();
		}
	}
	
	public static void main(String[] args) {
		new Thread(null, new Main(), "GAVNO", 500000000).start();
	}
}