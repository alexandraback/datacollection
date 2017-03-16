package round1C.c;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class C {
	static String inFile = "src/round1C/c/C-small-attempt0.in";
	static String outFile = "src/round1C/c/C.out";
	static int selectedTest = -1;


	static String solve(Prerequisite p) throws Exception {

		
		Arrays.sort(p.tribes, new Comparator<Tribe>(){
			@Override
			public int compare(Tribe t1, Tribe t2) {
				return t1.d - t2.d;
			}
		});
		
//		for(Tribe t : p.tribes)
//			System.err.println(t);
		
//		System.err.println(p.maxDays);
		
		int[] wall = new int[501];
		
		//day to tribes;
		Map<Integer, List<Attack>> attacks = new TreeMap<>();
		
		for(Tribe t : p.tribes)
			for(int i = 0; i < t.n; i++){
				int dayOfAttack = t.d + i * t.delta_d;
				List<Attack> list;
				if(!attacks.containsKey(dayOfAttack)){
					attacks.put(dayOfAttack, list = new LinkedList<>());
				} else
					list = attacks.get(dayOfAttack);
				list.add(new Attack(t, i));
			}
		
//		System.err.println(attacks);
				
		for(Entry<Integer,List<Attack>> e : attacks.entrySet())
			System.err.println(e.getValue());
		int numAttacks = 0;
		for(Entry<Integer,List<Attack>> e : attacks.entrySet()){
			List<Attack> aN = e.getValue();
			att: for(Attack a : aN){
				Tribe t = a.t;
				int[] aoa = t.attackAtDay(a.i);
				for(int i = aoa[0] + 250 - 1; i < aoa[1] + 250 - 1; i++)
					if(aoa[2] > wall[i]){
						numAttacks++;
						continue att;
					}
			}
			
			att: for(Attack a : aN){
				Tribe t = a.t;
				int[] aoa = t.attackAtDay(a.i);
				for(int i = aoa[0] + 250 - 1; i < aoa[1] + 250 - 1; i++)
					if(aoa[2] > wall[i]){
						wall[i] = aoa[2];
					}
			}
		}
		
		
		
		return String.valueOf(numAttacks);
	}
	
	static class Attack {
		Tribe t;
		int i;
		public Attack(Tribe t, int i){
			this.t = t;
			this.i = i;
		}
		
		@Override
		public String toString() {
			return String.format("(%s, %s)", t, i);
		}
	}

	static class Prerequisite {
		Tribe[] tribes;
		int maxDays;

		public Prerequisite() throws IOException {
			int length = Reader.nextInt();
			tribes = new Tribe[length];
			for(int i = 0; i < tribes.length; i++){
				tribes[i] = new Tribe();
				if(tribes[i].lastDay > maxDays)
					maxDays = tribes[i].lastDay;
			}
		}
	}
	
	static class Tribe {
		int d, n, w, e, s, delta_d, delta_p, delta_s;
		
		int lastDay;
		
		public int[] attackAtDay(int i){
			return new int[]{w + i * delta_p, e + i * delta_p, s + i * delta_s};
		}

		public Tribe() throws IOException {
			//day of first attack
			d = Reader.nextInt();
			//number of attacks
			n = Reader.nextInt();
			
			w = Reader.nextInt();
			e = Reader.nextInt();
			//strength
			s = Reader.nextInt();
			delta_d = Reader.nextInt();
			delta_p = Reader.nextInt();
			delta_s = Reader.nextInt();
			
			lastDay = d + (n-1) * delta_d;
			
			
		}

		@Override
		public String toString() {
			return String.format("(%s %s %s %s %s %s %s %s", d, n, w, e, s,
					delta_d, delta_p, delta_s);
		}
	}

	public static void init() {
		try (Reader reader = new Reader(new FileInputStream(inFile));
				PrintWriter out = new PrintWriter(new FileWriter(outFile));) {			String result;
			long time, overallTime;

			int tN = Reader.nextInt();
			overallTime = System.currentTimeMillis();
			for (int ti = 1; ti <= tN; ti++) {
				Prerequisite p = new Prerequisite();

				if (selectedTest > 0)
					if (ti != selectedTest)
						continue;

				time = System.currentTimeMillis();
				result = solve(p);
				out.printf("Case #%d: %s", ti, result);

				if (ti != tN)
					out.println();

				System.err.printf("Case %-5s ", String.format("#%d:", ti));
				System.err.printf("%-8s", result);
				System.err.printf("%6sms\n", String.format(".. %.0f",
								(double) (System.currentTimeMillis() - time)));
			}

			System.err.printf("%.4fs\n",
					(double) (System.currentTimeMillis() - overallTime) / 1000);
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	static class Reader implements AutoCloseable {
		static BufferedReader in;
		static StringTokenizer tok;

		public Reader(InputStream input) {
			in = new BufferedReader(new InputStreamReader(input));
			tok = new StringTokenizer("");
		}

		@Override
		public void close() throws IOException {
			in.close();
		}

		static String next() throws IOException {
			while (!tok.hasMoreTokens())
				tok = new StringTokenizer(in.readLine());
			return tok.nextToken();
		}

		static int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		static long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		static double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		init();
	}
}
