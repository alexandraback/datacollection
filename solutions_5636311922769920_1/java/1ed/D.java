package Qualif16;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class D {
	
	//public static String theFile="-small.in";
	//public static String theFile="-small-attempt1.in";
	public static String theFile="-large.in";
	

	
	// get Pb Letter for input/output file names.
	public static String pbLetter;
	static {
		pbLetter=new Object() { }.getClass().getEnclosingClass().getName();
		int idx = pbLetter.lastIndexOf('.');
		if(idx != -1) pbLetter = pbLetter.substring(idx+1);
		pbLetter = pbLetter.toUpperCase();
	}

	public static void main(String[] args) throws Throwable {
		Scanner sc = new Scanner(new File("./"+pbLetter+theFile));
		
		TeePrintStream out= new TeePrintStream(System.out, "./output-"+pbLetter+".txt");

		int testCount = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= testCount; i++) {
			out.format("Case #%d: ",i );
			solve(sc, out);
		}
		out.close();
	}
	static void solve(Scanner sc,PrintStream out) {
		final int K=sc.nextInt(),C=sc.nextInt(),S=sc.nextInt();
		if(K/C+(K%C==0?0:1) >S) {out.println("IMPOSSIBLE");return;}
		long mult,res;
		int idx=0;
		for(int i=0; i<K/C ;++i) {
			mult=1;res=0;
			for(int j=0;j<C;++j) {res+=idx++*mult; mult*=K;}
			out.print((res+1)+" ");
		}
		mult=1;res=0;
		if(idx<K) {
			for(int j=idx;j<K;++j) {res+=j*mult; mult*=K;}
			out.print((res+1)+" ");
		}
		out.println();
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