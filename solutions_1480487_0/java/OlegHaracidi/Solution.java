import java.util.*;
import java.io.*;

class IO {
	int testNum;
	static volatile int testCounter = 0;
	static volatile Scanner in;
	static volatile PrintWriter out;
	static void setIO(Scanner in, PrintWriter out) {
		IO.in = in;
		IO.out = out;
	}
}

final class SolutionA extends IO implements Runnable {
	
	static double EPS = 1e-15;
	int n, x;
	int[] s;
	
	boolean check(double p) {
		double sum = 0;
		for (int i = 0; i < n; i++)
			if (s[i] < p) sum += (p - s[i]) / x;
		return sum > 1;
	}
	
	@Override
	public void run() {
		synchronized (in) {
			testNum = ++testCounter;
			n = in.nextInt();
			s = new int[n];
			for (int i = 0; i < n; i++)	s[i] = in.nextInt();
		}
		
		x = 0;
		for (int t: s) x += t;

		double[] m = new double[n];

		for (int i = 0; i < n; i++) {
			double l = 0, r = 1;
			while (l + EPS < r) {
				double mid = (l + r) / 2;
				if (check(s[i] + x * mid)) r = mid;
				else l = mid;
			}
			m[i] = (l + r) / 2;
		}
		
		synchronized (out) {
			out.print("Case #" + testNum + ": ");
			//out.print("q = " + q + "| ");
			for (double d: m) out.print(100 * d + " ");
				
			out.println();
			out.flush();
		}
	}
}

public class Solution {
	
	static int threadCount = 4;
	
	static void solveParallel(int testCount) throws InterruptedException {
		Thread thread[] = new Thread[threadCount];
		for (int i = 0; i < testCount; i++) {
			int threadNum = i % threadCount;
			if (thread[threadNum] != null) thread[threadNum].join();
			thread[threadNum] = new Thread(null, new SolutionA(), String.valueOf(i), 1000000);
			thread[threadNum].start();
		}
		for (Thread th: thread) 
			if (th != null) th.join();
	}
	
	static void solve(int testCount) {
		for (int i = 0; i < testCount; i++)	new SolutionA().run();
	}
	
	public static void main(String[] args) throws InterruptedException, FileNotFoundException {
		Scanner in = new Scanner(new FileInputStream("A-small-attempt2.in"));
		PrintWriter out = new PrintWriter(new File("out.txt"));
		//Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		IO.setIO(in, out);
		
		int testCount = in.nextInt();
		solve(testCount);
		
		out.close();
	}

}
