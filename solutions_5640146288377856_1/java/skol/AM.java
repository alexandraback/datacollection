import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
import java.util.regex.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;
import static java.lang.Character.*;


public class AM {
	
	static class Solver extends Thread {

		private int R;

		private int C;

		private int W;
		
		void read(Scanner sc) {
			R = sc.nextInt();
			C = sc.nextInt();
			W = sc.nextInt();
		}
		
		
		Object solve() {
			int res = C/W * (R-1);
			while (C >= 2*W) {
				res++;
				C -= W;
			}
			
			if (C == W)
				res += W;
			else
				res += W+1;
			
			return res;
		}

		Object result;
		
		public void run() {
			result = solve();
			synchronized (sync) {
				remaining--; running--;
				startNextCase();
				System.out.println("Remaining: " + remaining + ", Running: " + running);
				if (finished())
					sync.notifyAll();
			}
		}
	}


	private static final int MAX_THREADS = 32;
	private static Object sync = new Object(); static int running, remaining, next; 
	private static ArrayList<Solver> cases = new ArrayList<Solver>(); 

	public static void main(String[] args) throws Exception {
		Scanner sc; PrintWriter fw; 
		String inFile = "input.txt", outFile = "output.txt";
//		inFile = "A-small-attempt0.in";
//		inFile = "A-large.in";
		if (args.length == 0) {
			sc = new Scanner(System.in);
	//		sc = new Scanner(new FileInputStream(inFile));
		} else {
			inFile = args[0];
			sc = new Scanner(new FileInputStream(inFile));
			if (args.length > 1)
				outFile = args[1];
			else if (inFile.endsWith(".in"))
				outFile = inFile.substring(0, inFile.length() - 2) + "out";
			System.out.println(inFile + " -> " + outFile);
		}
		
		fw = new PrintWriter(new FileWriter(outFile, false));
		
		int N = sc.nextInt();
		sc.nextLine();
		
		for (int cas = 1; cas <= N; cas++) {
			Solver solver = new Solver();
			solver.read(sc);
			remaining++;
			cases.add(solver);
		}
		
		for (int i = 0; i < min(N, MAX_THREADS); i++)
			startNextCase();
		System.out.println("Remaining: " + remaining + ", Running: " + running);
		
		while (!finished()) {
			synchronized (sync) {
				sync.wait(1000);
			}
		}
		
		for (int cas = 1; cas <= N; cas++) {
			fw.print("Case #" + cas + ": ");
			Object res = cases.get(cas-1).result;
			if (res instanceof Double) 
				fw.printf("%.10f\n", res);
			else
				fw.printf("%s\n", res);
			fw.flush();
		}
		fw.close();
		sc.close();
	}

	static boolean finished() {
		synchronized (sync) {
			return remaining == 0;
		}
	}
	
	static void startNextCase() {
		synchronized (sync) {
			if (remaining > running) {
				cases.get(next++).start();
				running++;
			}
		}
	}
}
