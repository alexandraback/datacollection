package j2014.qual;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

@SuppressWarnings("all")
public class D {

	private static final String FILE_NAME = "D-large";	
	
	private static final String RELATIVE_PATH;
	static {
		String p = D.class.getPackage().getName();
		p = p.replace('.', '\\');
		RELATIVE_PATH = "src\\" + p + "\\" + FILE_NAME;
	}
	
	private Scanner in;
	private PrintStream out;
	
	public D () throws FileNotFoundException {
		in = new Scanner(new File(RELATIVE_PATH + ".in"));	
		out = new PrintStream(RELATIVE_PATH + ".out"); 
			
		int cases = nextInt();	
		for (int i = 1; i <= cases; i++) {
			print("Case #" + i + ": ");
			solve();
			println();
		}	

		out.close();
		System.out.println("\nDONE!");
	}
	
	private void solve() {
		int N = nextInt();
		
		Double[] n = new Double[N];
		for (int i = 0; i < N; i++) {
			n[i] = nextDouble();
		}
		
		Double[] k = new Double[N];
		for (int i = 0; i < N; i++) {
			k[i] = nextDouble();
		}
		
		Arrays.sort(k);
		Arrays.sort(n);
		
		ArrayList<Double> ken = new ArrayList<Double>(N);
		Collections.addAll(ken, k);
		
		ArrayList<Double> naomi = new ArrayList<Double>(N);
		Collections.addAll(naomi, n);
		
		// War
		int naomiPointsWar = 0;
		while (!ken.isEmpty()) {
			double naomiChosen = naomiWarStrategy(naomi);
			double kenChosen = kenWarStrategy(naomiChosen, ken);
			
			if (naomiChosen > kenChosen) naomiPointsWar++;
		}
		
		Collections.addAll(ken, k);
		Collections.addAll(naomi, n);
		
		int naomiPointsDWar = 0;
		while (!ken.isEmpty()) {
			double[] naomiChosen = naomiDWarStrategy(naomi, ken);
			double kenChosen = kenWarStrategy(naomiChosen[1], ken);
			
			if (naomiChosen[0] > kenChosen) naomiPointsDWar++;
		}
		
		print(String.format("%d %d", naomiPointsDWar, naomiPointsWar));
	}
	
	double naomiWarStrategy(ArrayList<Double> blocks) {
		return blocks.remove(blocks.size() - 1);
	}
	
	// return: 0 -> chose; 1 -> told
	double[] naomiDWarStrategy(ArrayList<Double> naomi, ArrayList<Double> ken) {
		double naomiChosen = naomi.remove(0);
		if (naomi.size() == 0) {
			return new double[]{naomiChosen, naomiChosen};
		}
		
		double kenSmallest = ken.get(0);
		
		double naomiTold;
		if (kenSmallest > naomiChosen) {
			double kenLargest	 = ken.get(ken.size() - 1);
			double kenSndLargest = ken.get(ken.size() - 2);
			
			naomiTold = (kenLargest + kenSndLargest) / 2;
		} else {
			double kenLargest	 = ken.get(ken.size() - 1);
			naomiTold = kenLargest + 0.0001;
		}

		return new double[]{naomiChosen, naomiTold};
	}
	
	double kenWarStrategy(double naomiChosen, ArrayList<Double> blocks) {
		if (naomiChosen > blocks.get(blocks.size() - 1)) {
			return blocks.remove(0);
		}
		
		int useBlock = -1;
		for (int i = 0; i < blocks.size(); i++) {
			if (naomiChosen < blocks.get(i)) {
				useBlock = i;
				break;
			}
		}
		
		return blocks.remove(useBlock);
	}
	
	/*
	 * Manage input
	 */
	private String next() {
		return in.next();
	}
	private int nextInt() {
		return in.nextInt();
	}
	private long nextLong() {
		return in.nextLong();
	}
	private double nextDouble() {
		return Double.parseDouble(in.next());
	}

	/*
	 * Manage output
	 */
	private void print(String s) { 
		System.out.print(s);
		out.print(s); 
	}	
	private void print(int i) { 
		System.out.print(i);
		out.print(i); 
	}	
	private void print(Object o) {
		System.out.print(o);
		print(o);
	}
	private void println() { 
		System.out.println();
		out.println(); 
	}
	
	public static void main(String[] args) {
		try {
			new D();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
