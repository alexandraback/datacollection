package com.codejam.QualificationRound2016;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;


public class D implements Runnable {
	String file = "D-large";
	PrintWriter out;
	static boolean debug = false;

	static class InputData{
		int K,C,S;
		InputData(FastReader in) throws IOException{
			K = in.nextInt();
			C = in.nextInt();
			S = in.nextInt();
		}
		public String toString(){
			return K+" "+ C+" "+S;
		}
		String solve() {
			if(K==1){ return "1";}
			StringBuilder sb = new StringBuilder();
			if(C==1 && S==K){
				for(int i=1;i<=K;i++){
					sb.append(" "+i);
				}
				return sb.substring(1);
			}
			if(C*S<K) return "IMPOSSIBLE";
			BigInteger setDistance = pow(K,C-1);
			for(int i=0,j=(K-1)/C;i<=j;i++){
				sb.append(" "+rec(i*C,C,setDistance).toString());
			}
			return sb.substring(1);
		}
		BigInteger rec(int i,int c,BigInteger d){
			if(c==0) return BigInteger.ONE;
			if(i==K) return BigInteger.ZERO;
			BigInteger start = d.multiply(BigInteger.valueOf(i));
			BigInteger pos = rec(i+1,c-1,d.divide(BigInteger.valueOf(K)));
			return start.add(pos);
		}
		BigInteger pow(int v,int p){
			BigInteger r= BigInteger.ONE;
			BigInteger value = BigInteger.valueOf(v);
			while(p-->0) r=r.multiply(value);
			return r;
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
		if(debug) new D().debug();
		else new D().run();
		System.err.println("Time taken : "+(System.currentTimeMillis()-start));
	}
}


