package com.codejam.QualificationRound2016;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;


public class C implements Runnable {
	String file = "input";
	PrintWriter out;
	static boolean debug = true;
	static int inputLength = 8;
	static BigInteger[] prime;
	static void buildPrimes(){
		HashSet<BigInteger> primes = new HashSet<BigInteger>();
		long loop = inputLength >> 1;
		long maxValue = 0;
		while(loop-- > 0){
			maxValue = maxValue*10 + 3;
		}
		int builderLength = Integer.MAX_VALUE >> 2;
		if(maxValue < builderLength) builderLength = (int) maxValue;
		boolean[] notPrime = new boolean[builderLength];
		for(int i=2;i<builderLength;i++){
			if(notPrime[i]) continue;
			for(int j=2,k=builderLength/i;j<k;j++){
				notPrime[i*j] = true;
			}
			primes.add(BigInteger.valueOf(i));
		}
		BigInteger zero = BigInteger.ZERO;
		for(long i= builderLength;i<maxValue;i++){
			boolean isPrime = true;
			BigInteger c = BigInteger.valueOf(i);
			for(BigInteger p: primes){
				if(c.remainder(p).equals(zero)){
					isPrime=false;
					break;
				}
			}
			if(isPrime){
				primes.add(BigInteger.valueOf(i));
			}
		}
		prime = new BigInteger[primes.size()];
		primes.toArray(prime);
		Arrays.sort(prime);
	}
	static class InputData{
		int N,J;
		InputData(FastReader in) throws IOException{
			N = in.nextInt();
			J = in.nextInt();
		}
		public String toString(){
			return N+","+J;
		}
		String solve(){
			int a = N >> 1;
			int b = N - a -1;
			long aa = 1;
			long bb = 1;
			while(a-->0) aa*=10;
			while(b-->0) bb*=10;
			BigInteger looper = BigInteger.valueOf(aa);
			looper = looper.multiply(BigInteger.valueOf(bb));
			looper = looper.add(BigInteger.ONE);
			long startX = Long.parseLong(looper.toString(),2);
			long end = startX*2;
			BigInteger two = BigInteger.valueOf(2);
			StringBuilder sb = new StringBuilder("\n");
			while(J>0 && end > startX){
				boolean isJamcoin = true;
				String[] divs = new String[11];
				for(int i =10;i>1;i--){
					BigInteger bs = getBigInteger(looper,i);
					isJamcoin = false;
					int index = getRange(bs);
					if(prime[index].equals(bs)) break;
					for(int j=0;j<=index;j++){
						if(bs.remainder(prime[j]).equals(BigInteger.ZERO)){
							isJamcoin = true;
							divs[i] = prime[j].toString();
							break;
						}
						if(isJamcoin) break;
					}
					if(!isJamcoin){
						break;
					}
				}
				if(isJamcoin){
					sb.append(looper.toString());
					for(int j=2;j<= 10;j++){
						sb.append(" "+divs[j]);
					}
					if(J-- != 1) sb.append("\n");
					else break;
				}
				startX+=2;
				int sL = 0;
				long tS = startX;
				for(long s = startX;s>0;s/=2) sL++;
				looper = BigInteger.ZERO;
				for(int i=0;i<sL;i++){
					if((tS&1)==1){
						looper = looper.add(pow(10,i));
					}
					tS /= 2;
				}
			}
			return sb.toString();
		}
		int getRange(BigInteger value){
			int first  = 0;
			int last = prime.length-1;
			int middle = (first + last)/2;
			while( first <= last )
			{
				int compare = prime[middle].compareTo(value);
				if( compare  == -1 ) first = middle + 1;
				else if ( compare == 0 ) return middle;
				else last = middle - 1;
				middle = (first + last) >> 1;
			}
			if(first >= prime.length) return prime.length -1;
			return first; 
		}
		BigInteger getBigInteger(BigInteger value,int base){
			if(base==10) return value;
			String binary  = value.toString();
			long base2 = Long.parseLong(binary,2);			
			BigInteger bb = BigInteger.valueOf(base);
			BigInteger output = BigInteger.ZERO;
			for(int i=0,l=binary.length();i<l;i++){
				if((base2&1)==1){
					output = output.add(pow(base,i));
				}
				base2 /= 2;
			}
			return output;
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
				System.err.println("Case #" + (i+1) + ": "+data.toString());
				System.err.println("Case #" + (i+1) + ": "+s);
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
		
		long startPrimes = System.currentTimeMillis();
		buildPrimes();
		System.err.println("Time taken in primes: "+(System.currentTimeMillis()-startPrimes));
		// add a line to read from console and then download the file
		long start = System.currentTimeMillis();
		if(debug) new C().debug();
		else new C().run();
		System.err.println("Time taken : "+(System.currentTimeMillis()-start));
	}
}


