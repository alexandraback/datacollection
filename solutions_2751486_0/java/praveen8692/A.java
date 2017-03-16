import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class A {

	PrintWriter out = null;
	int count = 0;
	Scanner in = null;

	// void sort() {
	// int temp = 0;
	// for (int i = 0; i < motes.length; i++) {
	// for (int j = i + 1; j < motes.length; j++) {
	// if (motes[i] > motes[j]) {
	// temp = motes[j];
	// motes[j] = motes[i];
	// motes[i] = temp;
	// }
	// }
	// }
	// }

	A() {
		try {
			out = new PrintWriter(new OutputStreamWriter(new FileOutputStream(
					new File("out.txt"))));
			in = new Scanner(new FileInputStream(
					new File("A-small-attempt0.in")));
			// in = new Scanner(System.in);
			execute();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void execute() {
		int a = in.nextInt();
		h.add('a');
		h.add('e');
		h.add('i');
		h.add('o');
		h.add('u');
		for (int i = 0; i < a; i++) {
			read();
			print("Case #" + (i + 1) + ": ");
			solve();
		}
		out.close();
		in.close();
	}

	String inp = null;
	int n = 0;

	void read() {
		inp = in.next();
		n = in.nextInt();
	}

	void solve() {
		int sc = 0;
		int l = inp.length();
		for (int i = 0; i < l - n + 1; i++) {
			for (int j = i + n; j < l + 1; j++) {
				if (getCon(inp.substring(i, j))) {
					sc++;
				}
			}
		}
		print(sc + "\n");
		System.out.println(sc);
	}

	HashSet<Character> h = new HashSet<Character>();

	boolean getCon(String s) {
		int len = 0;
		for (int i = 0; i < s.length(); i++) {
			if (!h.contains(s.charAt(i))) {
				len++;
				if (len >= n)
					break;
			} else {
				len = 0;
				if (s.length() - i < n)
					break;
			}
		}
		return len >= n;
	}

	void print(Object a) {
		out.flush();
		out.print(a);
	}

	public static void main(String[] args) throws FileNotFoundException {
		new A();
	}

}
