import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
	int T;
	int t = 1;
	String[] out;
	Lvl[] lvl;

	public B() throws FileNotFoundException {
		Scanner sc = new Scanner(new File("B-small-attempt1.in"));
		T = sc.nextInt();
		out = new String[T];
		sc.nextLine();
		while (sc.hasNext()) {
			int N = sc.nextInt();
			lvl = new Lvl[N];
			for (int i = 0; i < N; i++) {
				int a = sc.nextInt();
				int b = sc.nextInt();
				if (sc.hasNext()) {
					sc.nextLine();
				}
				lvl[i] = new Lvl(a, b);
			}
			calcOut();
			t++;
		}
		PrintWriter pw = new PrintWriter("outB.txt");
		for (String s : out) {
			pw.println(s);
			System.out.println(s);
		}
		pw.close();

	}

	public void calcOut() {
		int stars = 0;
		int ant = 0;
		while (!isAllSolved()) {
			int a = best(stars);
			if (a == -1) {
				out[t - 1] = "Case #" + t + ": Too Bad";
				return;
			}
			stars += a;
			ant++;
		}
		out[t - 1] = "Case #" + t + ": " + ant;
	}

	private boolean isAllSolved() {
		for (Lvl l : lvl) {
			if (l.solved != 2) {
				return false;
			}
		}
		return true;
	}

	public int best(int s) {
		for (Lvl l : lvl) {
			if (l.b <= s && l.solved < 2) {
				int a = l.solved;
				l.solved = 2;
				return 2 - a;
			}
		}
		Lvl a = lvl[0];
		for (Lvl l : lvl) {
			if (l.a <= s){
				a = l;
			}
		}
		for (Lvl l : lvl) {
			if (l.a <= s && l.solved < 2 && l.b >= a.b) {
				a = l;
			}
		}
		if (a.solved > 0) {
			return -1;
		}
		if (a.a <= s) {
			a.solved = 1;
			return 1;
		} else {
			return -1;
		}

	}

	public static void main(String[] args) {
		try {
			new B();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}

class Lvl {
	int a, b;
	int solved = 0;

	public Lvl(int a, int b) {
		this.a = a;
		this.b = b;
	}
}
