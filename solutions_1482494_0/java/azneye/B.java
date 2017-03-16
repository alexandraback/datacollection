
import java.util.*;

/*
 *	
 *	B.java
 *	Written by Andy Huang: 10:00:19 PM Apr 27, 2012
 */
public class B {
	static Point levels[];
	
	static void solve() {
		int n = in.nInt();
		levels = new Point[n];
		for (int i = 0; i < n; i++)
			levels[i] = new Point(in.nInt(), in.nInt());
		int ans = 0;
		int need = n << 1;
		int stars = 0;
		int last = -1;
		while (stars < need && stars != last){
			last = stars;
			Arrays.sort(levels);
			for (int i = 0; i < n; i++){
				if (levels[i].y <= stars && !levels[i].b){
					levels[i].b = true;
					ans++;
					if (!levels[i].a){
						stars++;
						levels[i].a = true;
					}
					stars++;
					i = -1;
				}
			}
			Arrays.sort(levels,new revcomp());
			for (int i = 0; i < n; i++){
				if (levels[i].x <= stars && !levels[i].a){
					int j = i;
					while (j + 1 < n && levels[i].x == levels[j + 1].x && levels[i].y < levels[j + 1].y && !levels[j + 1].a){
						j++;
					}
					levels[j].a = true;
					ans++;
					stars++;
					break;
				}
			}
		}
		if (stars < need)
			out.appendln("Too Bad");
		else
			out.appendln(ans);
	}

	public static void main(String[] args) {
		in = new Input();
		out = new Output();
		int test = in.nInt();
		int z = 1;
		while(test-- > 0){
			out.append("Case #");
			out.append(z);
			out.append(": ");
			solve();
			z++;
		}
		out.print();
	}

	static Output out;
	static Input in;

	static void pln(Object o) {
		System.out.println(o);
	}

	static void pf(Object o) {
		System.out.print(o);
	}

}

final class revcomp implements Comparator<Point>{

	public int compare(Point a, Point o) {
		if (a.x != o.x)
			return a.x - o.x;
		else if (a.y != o.y)
			return a.y - o.y;
		else
			return 0;
	}
	
}

final class Point extends java.awt.Point implements Comparable<Point> {
	private static final long serialVersionUID = -5276940640259749850L;	
	public boolean a;
	public boolean b;
	
	public Point(int a, int b) {
		super(a, b);
		this.a = false;
		this.b = false;
	}

	public Point(Point p) {
		super(p);
	}

	public Point() {
		super();
	}

	public String toString() {
		return "(" + x + "," + y + ")";
	}

	public int compareTo(Point o) {
		if (y != o.y)
			return y - o.y;
		else if (x != o.x)
			return x - o.x;
		else
			return 0;
	}

}

final class Input {
	private java.io.BufferedReader reader;
	private java.util.StringTokenizer tokenizer;

	public Input() {
		reader = new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new java.util.StringTokenizer(reader.readLine());
			}
			catch (java.io.IOException e) {
				throw new RuntimeException("I/O Error");
			}
		}
		return tokenizer.nextToken();
	}

	public String nLine() {
		try {
			return reader.readLine();
		}
		catch (java.io.IOException e) {
			throw new RuntimeException(e);
		}
	}

	public long nLong() {
		return Long.parseLong(next());
	}

	public int nInt() {
		return Integer.parseInt(next());
	}

	public double nDouble() {
		return Double.parseDouble(next());
	}

}

final class Output {
	public StringBuilder buffer;
	private java.io.PrintWriter out;
	
	Output() {
		buffer = new StringBuilder();
		try {
			out = new java.io.PrintWriter(new java.io.File("output.txt"));
		}
		catch (java.io.IOException e) {
		}
	}

	Output(int size) {
		buffer = new StringBuilder(size);
	}

	void print() {
		out.print(buffer.toString());
		out.close();
	}

	void flush() {
		out.flush();
	}

	<T> void append(T obj) {
		buffer.append(obj);
	}

	<T> void appendln(T obj) {
		append(obj);
		append('\n');
	}

	void delete(int index) {
		buffer.deleteCharAt(index);
	}

}