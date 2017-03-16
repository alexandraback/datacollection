import java.io.FileInputStream;
import java.util.ArrayDeque;
import java.io.InputStream;
import java.util.Collection;
import java.util.Scanner;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Queue;
import java.io.IOException;
import java.io.FileOutputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Quy Doan
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int N = in.nextInt();
        boolean[] visited = new boolean[N + 1];
        Queue<Point> queue = new ArrayDeque<Point>();
        queue.add(new Point(1, 1));
        visited[1] = visited[0] = true;
        int answer = 0;
        while (!queue.isEmpty()) {
            Point top = queue.poll();
            if (top.getX() == N) {
                answer = top.getY();
                break;
            }
            int reverse = (int)reverseNumber(top.getX());
            if (reverse <= N && !visited[reverse]) {
                queue.add(new Point(reverse, top.getY() + 1));
                visited[reverse] = true;
            }
            if (!visited[top.getX() + 1]) {
                queue.add(new Point(top.getX() + 1, top.getY() + 1));
                visited[top.getX() + 1] = true;
            }
        }
        out.println("Case #" + testNumber + ": " + answer);
    }
    private long reverseNumber(long x) {
        char[] s = String.valueOf(x).toCharArray();
        StringBuilder builder = new StringBuilder();
        for (int i = s.length - 1; i >= 0; i--) {
            builder.append(s[i]);
        }
        return Long.valueOf(builder.toString());
    }
}

class Point implements Comparable<Point>{
    /** The coordinate of the point **/
    private final int x ,y;

    public Point(int x,int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    public int compareTo(Point that) {
        if ( this.getX() > that.getX() ) return 1;
        if ( this.getX() < that.getX() ) return -1;
        if ( this.getY() > that.getY() ) return 1;
        if ( this.getY() < that.getY() ) return -1;
        return 0;
    }

}

