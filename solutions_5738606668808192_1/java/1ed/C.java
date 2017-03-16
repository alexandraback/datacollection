package Qualif16;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class C {
	// get Pb Letter for input/output file names.
	public static String pbLetter;
	static {
		pbLetter=new Object() { }.getClass().getEnclosingClass().getName();
		int idx = pbLetter.lastIndexOf('.');
		if(idx != -1) pbLetter = pbLetter.substring(idx+1);
		pbLetter = pbLetter.toUpperCase();
	}
	private static final BigInteger two = new BigInteger("2");
	private static final BigInteger three = new BigInteger("3");
	private static int MAX=10000;
	private static boolean[] isPrimeNumber= new boolean[MAX + 1];
	private static final ArrayList<BigInteger> primes = new ArrayList<BigInteger>();

	public static void main(String[] args) throws Throwable {
		Arrays.fill(isPrimeNumber,true);
	    for (int i = 2; i < MAX; i++) {
	      if (isPrimeNumber[i]) {
	    	primes.add(new BigInteger(Integer.toString(i)));
	        // now mark the multiple of i as non-prime number
	        int j=2*i;
	    	while(j <= MAX) {
	          isPrimeNumber[j] = false;
	          j+=i;
	        }
	      }
	    }
		//Scanner sc = new Scanner(new File("./"+pbLetter+"-small.in"));
		//System.out.println(System.getProperty("user.dir"));
		Scanner sc = new Scanner(new File("./"+pbLetter+"-small-attempt0.in"));

		//Scanner sc = new Scanner(new File("./"+pbLetter+"-large.in"));

		TeePrintStream out= new TeePrintStream(System.out, "./output-"+pbLetter+".txt");

		int testCount = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= testCount; i++) {
			out.format("Case #%d: ",i );
			solve(sc, out);
		}
		out.close();
	}
	public static BigInteger isPrime(BigInteger n) {

		for (BigInteger i:primes) {
			if (n.mod(i).equals(BigInteger.ZERO)) return i;
		}
		return BigInteger.ZERO;

	}

	private static BigInteger appxRoot(final BigInteger n) {
		BigInteger half = n.shiftRight(1);
		while (half.multiply(half).compareTo(n) > 0) {
			half = half.shiftRight(1);
		}
		return half.shiftLeft(1);
	}
	static void solve(Scanner sc, PrintStream out) {
		out.println();
		int N=sc.nextInt(),J=sc.nextInt();
		int[] d=new int[N];
		for(int i=0;i<N;++i) d[i]=0;
		d[0]=1;d[N-1]=1;
		while(J>0) {
			//for(int j=N-1;j>=0;--j) System.err.print(d[j]);
			//System.err.println();
			BigInteger mult,nb;
			int i;
			BigInteger bi=BigInteger.ONE;
			BigInteger[] factors=new BigInteger[11];
			for(i=2;i<=10;++i) {
				mult=BigInteger.ONE;
				nb=BigInteger.ZERO;
				bi = bi.add(mult);
				for(int n:d) {if(n==1) nb=nb.add(mult); mult=mult.multiply(bi);}
				BigInteger fact = isPrime(nb);
				if(fact.equals(BigInteger.ZERO)) break;
				factors[i]=fact;
				//System.err.println(i+"|"+nb);
			}
			if(i==11) {
				for(int j=N-1;j>=0;--j) out.print(d[j]);
				for(int j=2;j<=10;++j) {out.format(" %s", factors[j].toString(10));}
				out.println();
				--J;
			}
			 do {
				int j;
				for(j=0;j<N-1;++j) {
					if(d[j]==0) {d[j]=1; break;}
					d[j]=0;
				}
				//for(int k=N-1;k>=0;--k) System.err.print(d[k]);
				//System.err.println();
				if(j==N-1) return;
			} while(d[0]==0);
		}
	}



	static class TeePrintStream extends PrintStream {
		protected PrintStream parent;

		public TeePrintStream(PrintStream orig, OutputStream os, boolean flush)
				throws IOException {
			super(os, flush);
			parent = orig;
		}
		public TeePrintStream(PrintStream orig, String fn)
				throws IOException {
			this(orig, new FileOutputStream(fn), true);
		}

		public boolean checkError() {
			return parent.checkError() || super.checkError();
		}
		public void write(int x) {
			parent.write(x);
			super.write(x); 
		}

		/** override write(). This is the actual "tee" operation. */
		public void write(byte[] x, int o, int l) {
			parent.write(x, o, l); 
			super.write(x, o, l);
		}

		/** Close both streams. */
		public void close() {
			parent.close();
			super.close();
		}
		/** Flush both streams. */
		public void flush() {
			parent.flush();
			super.flush();
		}
	}
}