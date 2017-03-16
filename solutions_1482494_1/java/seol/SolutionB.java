package com.seol.codejam;

import java.io.File;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.SortedMap;
import java.util.SortedSet;
import java.util.TreeMap;
import java.util.TreeSet;

public class SolutionB {

	private static int solveCase(SortedSet<Round> rounds) {
		int res = 0;
		int levelComplete = 0;
		
		boolean played = false;
		HashMap<Round, Integer> rcache = new HashMap<Round, Integer>();
		do {
			played = false;
			Round r1 = null;
			for (Iterator<Round> it = rounds.iterator(); it.hasNext();) {
				Round r = it.next();
				if (res >= r.r2) {
					Integer playedScores = rcache.get(r);
					if(playedScores == null) {
						playedScores = 0;
					}
					
					res += 2*r.num - playedScores;
					levelComplete = levelComplete + r.num;
					it.remove();
					played = true;
					continue;
				}
				
				if(r1 == null && res >= r.r1 ) {
					Integer cached = rcache.get(r);
					if(cached == null) {
						r1 = r;
						rcache.put(r1, 0);
					} else if (cached < r.num) {
						r1 = r;
					}
				}
			}			
			
			if (!played && r1 != null) {
				res += 1;
				levelComplete++;
				Integer val = rcache.get(r1);
				rcache.put(r1, ++val);
				played = true;
			}
			
		} while(played);
		
		if(!rounds.isEmpty()) levelComplete = -1;
		
		return levelComplete;
	}
	
	static class Round implements Comparable<Round>{
		int r1;
		int r2;
		int num;
		
		public Round(int r1, int r2) {
			super();
			this.r1 = r1;
			this.r2 = r2;
			num = 1;
		}

		@Override
		public int compareTo(Round o) {
			if(r2 > o.r2) {
				return -1;
			} else if (r2 < o.r2){
				return 1;
			} else {
				if(r1 > o.r1) {
					return -1;
				} else if(r1 < o.r1){
					return 1;
				} else {
					return 0;
				}
			}
		}

		@Override
		public String toString() {
			return "Round [r1=" + r1 + ", r2=" + r2 + ", num=" + num + "]";
		}
	}

	public static String IN = ".in";
	public static String OUT = ".out";
	public static PrintStream out;

	public static void main(String[] args) throws Exception {
		solveAllCases("D:/worspaces/google_codejam/test_data/B-large");
	}

	public static void solveAllCases(String fileName) throws Exception {
		 out = new PrintStream(new File(fileName + OUT));
//		out = System.out;
		Scanner sc = new Scanner(new File(fileName + IN));
		int cases = sc.nextInt();
		for (int i = 0; i < cases; i++) {
			int N = sc.nextInt();

//			int[] u = new int[N];
			TreeMap<Round, Round> rs = new TreeMap<SolutionB.Round, Round>();
			for(int q = 0; q < N; q++) {
				int r1 = sc.nextInt();
				int r2 = sc.nextInt();
				Round r = new Round(r1, r2);
				Round rr = rs.get(r);
				if(rr == null) {
					rs.put(r, r);
				}
				else {
					rr.num++;
				}
			}
			
			int res = solveCase(new TreeSet<SolutionB.Round>(rs.values()));

			out.println("Case #" + (i + 1) + ": " + ((res == -1) ? "Too Bad": ""+res) );
//			for (Map.Entry<Integer, Integer> it : map.entrySet()) {
//				out.print((it.getValue() + 1) + " ");
//			}
		}
	}
}
