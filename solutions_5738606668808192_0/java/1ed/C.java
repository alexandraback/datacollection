package Qualif16;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
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
	public static void main(String[] args) throws Throwable {
		
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
	static boolean isPrime(long n) {
	    if(n < 2) return false;
	    if(n == 2 || n == 3) return true;
	    if(n%2 == 0 || n%3 == 0) return false;
	    long sqrtN = (long)Math.sqrt(n)+1;
	    for(long i = 6L; i <= sqrtN; i += 6) {
	        if(n%(i-1) == 0 || n%(i+1) == 0) return false;
	    }
	    return true;
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
			long mult,nb;
			int i;
			for(i=2;i<=10;++i) {
				mult=1;
				nb=0;
				for(int n:d) {nb+=mult*n;mult*=i;}
				if(isPrime(nb)) break;	
				//System.err.println(i+"|"+nb);
			}
			if(i==11) {
				for(int j=N-1;j>=0;--j) out.print(d[j]);
				for(int b=2;b<=10;++b) {
					mult=1;
					nb=0;
					for(int n:d) {nb+=mult*n;mult*=b;}
					for(int n=2; n<nb;++n) if(nb%n ==0) {out.format(" %d", n); break;}
				}
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