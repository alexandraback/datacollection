import java.util.Scanner;
import java.util.List;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("Main/input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("Main/output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		B solver = new B();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class B {
	class Level {
		int e, h;
		boolean eSolved;

		Level(int e, int h, boolean eSolved) {
			this.e = e;
			this.h = h;
			this.eSolved = eSolved;
		}
	}

	public void solve(int testNumber, Scanner in, PrintWriter out) {
		int N = in.nextInt();
		List<Level> list = new ArrayList<Level>();
		for (int i = 0; i < N; ++i) {
			list.add(new Level(in.nextInt(), in.nextInt(), false));
		}
		int res = 0;
		int score = 0;
		while (list.size() > 0) {
			int sz = list.size();
			boolean c = false;
			Collections.sort(list, new Comparator<Level>() {
				public int compare(Level o1, Level o2) {
					return o1.h - o2.h;
				}
			});
			if (list.get(0).h <= score) {
				res++;
				if (list.get(0).eSolved)
					score += 1;
				else
					score += 2;
				list.remove(0);
				c = true;
			}
			if (list.size() == sz) {
				Collections.sort(list, new Comparator<Level>() {
					public int compare(Level o1, Level o2) {
						if (o1.e == o2.e)
							return o2.h - o1.h;
						return o1.e - o2.e;
					}
				});
//				Collections.sort(list, new Comparator<Level>() {
//					public int compare(Level o1, Level o2) {
//						if (o2.eSolved)
//							return -1;
//						else {
//							if (o1.e == o2.e)
//								return o2.h - o1.h;
//							return o1.e - o2.e;
//						}
//					}
//				});
				for (int i = 0; i < list.size(); ++i)
					if (list.get(i).eSolved == false) {
						if (list.get(i).e <= score) {
							list.get(i).eSolved = true;
							res++;
							score += 1;
							c = true;
							break;
						}
						else break;
					}
			}
			if (!c) {
				res = Integer.MAX_VALUE;
				break;
			}
		}
		if (res == Integer.MAX_VALUE)
			out.print(String.format("Case #%d: %s\n", testNumber, "Too Bad"));
		else
			out.print(String.format("Case #%d: %d\n", testNumber, res));
	}
}

