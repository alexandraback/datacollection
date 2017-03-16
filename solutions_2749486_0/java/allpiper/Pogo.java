package net.truthcontrol.codejam1t;
import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Pogo {

	private static int cases = 0;

	private static PrintStream ps;

	private static Scanner sc;
	
	Map<String, Boolean> al = new HashMap<String, Boolean>();
	
	int tx;
	int ty;
	
	String goal = null;
	
	class Pos {
		String s;
		int i;
		int x;
		int y;
		public Pos(final String s, final int i, final int x, final int y) {
			super();
			this.s = s;
			this.i = i;
			this.x = x;
			this.y = y;
		}
		
		
		
	}
	
	private String doIt() {
		al = new HashMap<String, Boolean>();
		goal = null;
		tx = sc.nextInt();
		ty = sc.nextInt();
//		System.out.println("TX:"+ tx + ", TY:" + ty);
		
		List<Pos> rr = new ArrayList<Pogo.Pos>();
		
		Pos r = new Pos("", 1, 0, 0);
		rr.add(r);
		
		while (goal == null) {
			List<Pos> mr = new ArrayList<Pogo.Pos>(rr);
			for (Pos rn : mr) {
				if (goal != null) break;
				if (rn.x == tx && rn.y == ty) {
//					System.out.println("GOAL:  " + rn.x + "," + rn.y + "," + rn.i + ", " + rn.s);
					goal = rn.s;
					break;
				}
				if (rn.i >= 500) continue;
				String cacheKey = rn.x + "," + rn.y + "," + rn.i;
				if (al.containsKey(cacheKey)) continue;
				al.put(cacheKey, true);
				
//				System.out.println(cacheKey);
				
				rr.add(new Pos(rn.s + "N", rn.i + 1, rn.x, rn.y + rn.i));
				rr.add(new Pos(rn.s + "S", rn.i + 1, rn.x, rn.y - rn.i));
				rr.add(new Pos(rn.s + "E", rn.i + 1, rn.x + rn.i, rn.y));
				rr.add(new Pos(rn.s + "W", rn.i + 1, rn.x - rn.i, rn.y));
			}
		}
		
		return goal;
	}
	
	
	
	
	public static void main(final String[] args) throws NumberFormatException, IOException {
		
		run("sample.in", "output.out");
		
	}
	
	public static void run(final String in, final String out) throws NumberFormatException, IOException {
		Pogo s = new Pogo();
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
