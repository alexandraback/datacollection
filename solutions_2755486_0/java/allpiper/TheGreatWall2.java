package net.truthcontrol.codejam1t;
import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class TheGreatWall2 {

	private static int cases = 0;

	private static PrintStream ps;

	private static Scanner sc;
	
	class Tribe {
		int d; // first attack
		int n; // number of attacks
		int w, e; // west-/eastmost point of attack
		int s; // strength of first attack
		int nd; // number of days between subsequent attacks
		int v; // distance this tribe travels to the east
		int ns; // change in strength
		int dt; 
	}
	
	class Region {
		int w, e;
		int h;
	}
	
	List<Region> reg = new ArrayList<TheGreatWall2.Region>();
	List<Region> nReg = new ArrayList<TheGreatWall2.Region>();
	
	private int getPoint(final int x) {
		int max=0;
		for (Region r : reg) {
			if (x>= r.w && x<= r.e && r.h> max){
				max = r.h;
			}
		}
		return max;
	}
	
	
	
	private String doIt() {
		List<Tribe> ts = new ArrayList<TheGreatWall2.Tribe>();
		
//		Map<Integer, Integer> wall = new HashMap<Integer, Integer>();
//		Map<Integer, Integer> nWall = new HashMap<Integer, Integer>();
		
		reg = new ArrayList<TheGreatWall2.Region>();
		nReg = new ArrayList<TheGreatWall2.Region>();
		
		
		int nt = sc.nextInt();
		for (int i = 0; i < nt; i++) {
			Tribe t = new Tribe();
			t.d = sc.nextInt();
			t.n = sc.nextInt();
			t.w = sc.nextInt();
			t.e = sc.nextInt();
			t.s = sc.nextInt();
			t.nd = sc.nextInt();
			t.v = sc.nextInt();
			t.ns = sc.nextInt();
			
			t.dt = 0;
			ts.add(t);
		}
		
		int day = 0;
		int nsuc = 0;
		
		while (true) {
//			wall = new HashMap<Integer, Integer>(nWall);
			reg = new ArrayList<TheGreatWall2.Region>(nReg);
			boolean stop = true;
			for (Tribe t : ts) {
				if (day >= t.d) {
					
					if (t.dt <= 0 && t.n > 0 && t.s > 0) {
						t.dt = t.nd;
						t.n--;
						boolean success = false;
						// attack from west to east
						for (int pos = t.w; pos <= t.e; pos++) {
							if (getPoint(pos) < t.s) {
								success = true;
							}
						}
						
						if (success) {
							Region nr = new Region();
							nr.w = t.w;
							nr.e = t.e;
							nr.h = t.s;
							nReg.add(nr);
							nsuc++;
						}
						t.s += t.ns;
					
					}
					t.w += t.v;
					t.e += t.v;
				}
				
				if (t.n > 0) {
					stop = false;
				}
				t.dt--;
			}
			if (stop) {
				break;
			}
			day ++;
		}
		
		
		return Integer.toString(nsuc-1);
	}
	
	
	public static void main(final String[] args) throws NumberFormatException, IOException {
		
		run("sample.in", "output.out");
		
	}
	
	public static void run(final String in, final String out) throws NumberFormatException, IOException {
		TheGreatWall2 s = new TheGreatWall2();
		sc = new Scanner(new File(in));
		ps = new PrintStream(out);

		int numberCases = sc.nextInt();
		long t1, t2, t3 = 0L;

		while (cases < numberCases) {
			cases++;
			
			log("last run: " + t3 + " ms; now calculating test case #" + cases + " ... ");
			
			t1 = System.currentTimeMillis();
			
			print(s.doIt());
			
			t2 = System.currentTimeMillis();
			t3 = t2 - t1;
			
		}
		
		log("last run: " + t3 + " ms");

		sc.close();
	}
	
	
	private static void log(final String string) {
//		System.out.println(string);
	}
	
	private static void print(final String msg) {
		System.out.println("Case #" + cases + ": " + msg);
		ps.println("Case #" + cases + ": " + msg);
	}

}
