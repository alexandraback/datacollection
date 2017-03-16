import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class C {

	PrintWriter out = null;
	int count = 0;
	Scanner in = null;

	void sort() {
		Attack temp;
		Attack[] att = attacks.toArray(new Attack[attacks.size()]);
		for (int i = 0; i < att.length; i++) {
			for (int j = i + 1; j < att.length; j++) {
				if (att[i].day > att[j].day) {
					temp = att[i];
					att[i] = att[j];
					att[j] = temp;
				}
			}
		}
		attacks.clear();
		for (int i = 0; i < att.length; i++) {
			attacks.add(att[i]);
			// System.out.println(att[i]);
		}
	}

	C() {
		try {
			out = new PrintWriter(new OutputStreamWriter(new FileOutputStream(
					new File("out.txt"))));
			in = new Scanner(new FileInputStream(
					new File("C-small-attempt1.in")));
			// in = new Scanner(System.in);
			execute();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void execute() {
		int a = in.nextInt();
		for (int i = 0; i < a; i++) {
			read();
			print("Case #" + (i + 1) + ": ");
			solve();
		}
		out.close();
		in.close();
	}

	int days;
	ArrayList<Attack> attacks = new ArrayList<C.Attack>();

	class Attack {
		int day;
		int e;
		int w;
		int ht;
		boolean s = true;

		public Attack(int d, int ea, int we, int h) {
			day = d;
			e = ea;
			w = we;
			ht = h;
		}

		@Override
		public String toString() {
			return day + " " + e + " " + w + " " + ht;
		}
	}

	void read() {
		int n = in.nextInt();
		int day = 0;
		for (int i = 0; i < n; i++) {
			day = in.nextInt();
			int no = in.nextInt();
			int w = in.nextInt();
			int e = in.nextInt();
			int h = in.nextInt();
			int dd = in.nextInt();
			int dp = in.nextInt();
			int dh = in.nextInt();
			for (int j = 0; j < no; j++) {
				attacks.add(new Attack(day + (j * dd), e + (j * dp), w
						+ (j * dp), h + (j * dh)));
			}
		}
		sort();
	}

	int success = 0;
	
	void solve() {
		int[][] pos = new int[attacks.size()][4];
		for (int i = 0; i < attacks.size(); i++) {
			pos[i] = new int[] { attacks.get(i).w, attacks.get(i).e,
					attacks.get(i).ht, 0 };
		}
		success = 0;
		for (int i = 0; i < attacks.size(); i++) {
			int day = attacks.get(i).day;
			int k = i;
			while (k < attacks.size() && attacks.get(k).day == day) {
				int w = attacks.get(k).w;
				int e = attacks.get(k).e;
				int ht = attacks.get(k).ht;
				for (int j = 0; j < i; j++) {
					if (pos[j][2] >= ht) {
						if (e <= w || (pos[j][0] < w && pos[j][1] > e)) {
							attacks.get(k).s = false;
							break;
						}
						if (pos[j][0] == w && pos[j][1] == e) {
							attacks.get(k).s = false;
							break;
						}
						if (pos[j][1] <= w || pos[j][0] >= e) {
							continue;
						}
						if (pos[j][0] < w) {
							w = pos[j][1];
						}
						if (pos[j][1] > e) {
							e = pos[j][0];
						}
						// if (pos[j][1] < e) {
						// e = pos[j][0];
						// }
					}
				}
				k++;
			}
			i = k - 1;
		}
		for (int i = 0; i < attacks.size(); i++) {
			if (attacks.get(i).s)
				success++;
		}
		print(success + "\n");
		System.out.println(success);
	}

	void print(String a) {
		out.flush();
		out.print(a);
	}

	public static void main(String[] args) throws FileNotFoundException {
		new C();
	}

}
