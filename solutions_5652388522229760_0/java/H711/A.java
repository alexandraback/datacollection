package com.codejam.QualificationRound2016;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;


public class A implements Runnable {
	String file = "A-small-attempt0";
	PrintWriter out;
	static boolean debug = false;

	static class InputData{
		int N;
		InputData(FastReader in) throws IOException{
			N = in.nextInt();
		}
		public String toString(){
			return N+"";
			
		}
		String solve() {
			if(N==0) return "INSOMNIA";
			boolean[] covered = new boolean[10];
			long ans;
			for(long mult=1;mult<Long.MAX_VALUE;mult++){
				ans = N*mult;
				while(ans>0){
					covered[((int)ans)%10] = true;
					ans /= 10;
				}
				for(int i=0;i<10;i++){
					if(!covered[i]) break;
					if(i==9) return N*mult+"";
				}
			}
			return "INSOMNIA";
		}
	}
	public void debug(){
		try {
			FastReader in = new FastReader(new BufferedReader(new FileReader(file+".in")));
			out = new PrintWriter(file + ".out");
			for(int i=0,n = in.nextInt();i<n;i++){
				InputData data = new InputData(in);
				String s = data.solve();
				System.out.println("Case #" + (i+1) + ": "+data.toString());
				System.out.println("Case #" + (i+1) + ": "+s);
				out.println("Case #" + (i + 1) + ": "+s);
			}
			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public void run(){
		try {
			FastReader in = new FastReader(new BufferedReader(new FileReader(file+".in")));
			out = new PrintWriter(file + ".out");
			
			ScheduledThreadPoolExecutor service = new ScheduledThreadPoolExecutor(16);
			
			int tests = in.nextInt();
			Future<String>[] ts = new Future[tests];
			for (int test = 0; test < tests; ++test) {
				ts[test] = service.submit(new Solver(new InputData(in)));
			}
			for (int test = 0; test < tests; ++test) {
				while (!ts[test].isDone()) {
					Thread.sleep(500);
				}
				System.err.println("Test " + test);
				out.print("Case #" + (test + 1) + ": ");
				out.println(ts[test].get());
			}
			service.shutdown();
			
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	static class Solver implements Callable<String>{
		InputData data;
		Solver(InputData data)  throws Exception{
			this.data = data;
		}

		public String call() {
			return data.solve();
		}
	}
	static class FastReader {
		public FastReader(BufferedReader in) {
			this.in = in;
			eat("");
		}
		
		private StringTokenizer st;
		private BufferedReader in;
		
		void eat(String s) {
			st = new StringTokenizer(s);
		}
		
		String next() throws IOException {
			while (!st.hasMoreTokens()) {
				String line = in.readLine();
				if (line == null) {
					return null;
				}
				eat(line);
			}
			return st.nextToken();
		}
		
		int nextInt() throws IOException {
			return Integer.parseInt(next());
		}
		
		long nextLong() throws IOException {
			return Long.parseLong(next());
		}
		
		double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
	}
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		long start = System.currentTimeMillis();
		if(debug) new A().debug();
		else new A().run();
		System.err.println("Time taken : "+(System.currentTimeMillis()-start));
	}
}


