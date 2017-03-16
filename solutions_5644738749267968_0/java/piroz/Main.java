package qualificationD;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	public static boolean debug = false;
	public static void main(String[] args) {
		outinit();
		solve();
		outfile();
	}
	
	public static int N;
	public static LinkedList<Double> m1;
	public static LinkedList<Double> m2;
	public static void solve() {
		Scanner sc = new Scanner(System.in);
		double t = sc.nextDouble();
		for(int i=0;i<t;i++) {
			N = sc.nextInt();
			m1 = new LinkedList<>();
			m2 = new LinkedList<>();
			for(int j=0;j<N;j++) {
				m1.add(sc.nextDouble());
			}
			for(int j=0;j<N;j++) {
				m2.add(sc.nextDouble());
			}
			solveTestcase();
		}
	}
	public static void solveTestcase() {
		Collections.sort(m1);
		Collections.sort(m2);
		int unusedright1 = N-1;
		int ans1 = 0;
		for(int i=N-1;i>=0;i--) {
			if (m2.get(i) < m1.get(unusedright1)) {
				ans1++;
				unusedright1--;
			}
		}
		int ans2 = 0;
		for(int i=N-1;i>=0;i--) {
			int index = Collections.binarySearch(m2, m1.get(i));
			if (index < 0) {
				index = -index - 1;
			}
			if (index == m2.size()) {
				ans2++;
				m2.remove(0);
			}else{
				m2.remove(index);
			}
		}
		out(ans1 + " " + ans2);
	}
	
	public static int outnum = 0;
	public static BufferedWriter bw;
	public static void outinit() {
		try {
			bw = new BufferedWriter(new FileWriter("out.txt"));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public static void out(Object o) {
		outnum++;
		try {
			bw.write("Case #" + outnum + ": " + o);
			bw.newLine();
			if (debug) {
				System.out.println("Case #" + outnum + ": " + o);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public static void outfile() {
		try {
			bw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
