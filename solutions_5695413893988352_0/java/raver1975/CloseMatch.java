import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class CloseMatch {
	static PrintWriter writer;

	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		Scanner sc = new Scanner(new File("in.txt"));
		writer = new PrintWriter("out.txt", "UTF-8");
		int n = sc.nextInt();
		sc.nextLine();
		for (int t = 0; t < n; t++) {
			String s = sc.nextLine();
			String[] tem = s.split(" ");
			String c = tem[0];
			String j = tem[1];
			// System.out.println(c+":"+j);

			int counter1 = counter(c, '?');
			int counter2 = counter(j, '?');
			if (counter1 == c.length() && counter2 == j.length()) {
				String zero1 = "";
				String zero2 = "";
				for (int i = 0; i < counter1; i++)
					zero1 += "0";
				for (int i = 0; i < counter2; i++)
					zero2 += "0";
				out(t + 1, zero1 + " " + zero2);
				continue;
			}

			Score best = new Score("0", Integer.MAX_VALUE + "");
			int mindiff = Integer.MAX_VALUE;
			int minval = Integer.MAX_VALUE;
			Queue<Score> pq = new LinkedList<>();
			ArrayList<Score> ooo = new ArrayList<>();

			pq.add(new Score(c, j));
			while (!pq.isEmpty()) {
				Score sx = pq.poll();
				// System.out.println(sx);
				if (mindiff >= sx.diff()) {
					if (mindiff > sx.diff()) {
						mindiff = sx.diff();
						best = sx;
					} else {
						if (sx.vala() < best.vala()) {
							mindiff = sx.diff();
							best = sx;
						} else if (sx.vala() == best.vala() && sx.valb() < best.valb()) {
							mindiff = sx.diff();
							best = sx;
						}
					}

				}

				if (sx.a.contains("?")) {
					for (int i = 0; i < 10; i++) {
						String aa = sx.a;
						String bb = sx.b;
						int f = sx.a.indexOf("?");
						aa = aa.substring(0, f) + i + aa.substring(f + 1);
						pq.add(new Score(aa, bb));
					}
				}

				if (sx.b.contains("?")) {
					for (int i = 0; i < 10; i++) {
						String aa = sx.a;
						String bb = sx.b;
						int f = sx.b.indexOf("?");
						bb = bb.substring(0, f) + i + bb.substring(f + 1);
						pq.add(new Score(aa, bb));
					}
				}
				// System.out.println(best);

			}
			out(t + 1, best.toString());

		}
		writer.close();
	}

	private static void out(int i, String j) {
		String s = "Case #" + i + ": " + j;
		writer.println(s);
		System.out.println(s);

	}

	static int counter(String s, char b) {
		int counter = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == b) {
				counter++;
			}
		}
		return counter;
	}

}

class Score implements Comparable<Score> {
	String a;
	String b;

	Score(String a, String b) {
		this.a = a;
		this.b = b;
	}

	public int diff() {
		try {
			int aa = Integer.parseInt(a);
			int bb = Integer.parseInt(b);
			return Math.abs(aa - bb);
		} catch (Exception e) {
			return Integer.MAX_VALUE;
		}
	}

	public int vala() {
		try {
			int aa = Integer.parseInt(a);
			return aa;
		} catch (Exception e) {
			return Integer.MAX_VALUE;
		}
	}

	public int valb() {
		try {
			int aa = Integer.parseInt(b);
			return aa;
		} catch (Exception e) {
			return Integer.MAX_VALUE;
		}
	}

	@Override
	public int compareTo(Score arg0) {
		return Integer.compare(this.diff(), arg0.diff());
	}

	@Override
	public String toString() {
		return (a + " " + b);
	}

}
